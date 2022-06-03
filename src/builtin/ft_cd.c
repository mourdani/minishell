/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:47:58 by guderram          #+#    #+#             */
/*   Updated: 2022/03/25 07:39:45 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// void	ft_cd(t_data *data, t_token *token)
// {
// 	if (data->token->arg == NULL || !ft_strncmp(data->token->arg, "~\0", 2))
// 	{
// 		chdir(getenv("HOME"));
// 		if (data->pwd)
// 		{
// 			free(data->pwd);
// 			data->pwd = NULL;
// 		}
// 		data->pwd = getcwd(NULL, 0);
// 		return (1);
// 	}
// 	if (chdir(data->token->arg) < 0)
// 		perror(data->token->arg);        // printf error message
// 	if (data->pwd)
// 	{
// 		free(data->pwd);
// 		data->pwd = NULL;
// 	}
// 	data->pwd = getcwd(NULL, 0);
// 	return (1); //ok
// }


void	ft_cd(t_data *data, t_token *token)
{
	int i;

	i = 0;
	i = i + ft_space(token->arg, i);
	// printf ("PRE : pwd '%s' opwd '%s'\n", data->pwd, data->opwd);
	// printf("size of arg : %lu\n", ft_strlen(token->arg));
	if (token->arg[i] == '\0' || token->arg[i] == '~')
		ft_cd_home(data);
	else if (token->arg[i] == '-')
		ft_cd_goto_opwd(data, data->opwd);
	else
		ft_cd_goto_path(data, &token->arg[i]);
}



void	ft_cd_home(t_data *data) // si cd renvoie sur son home
{
	t_var	*var;

	var = ft_found_var_name(data, "HOME");
	if (var == NULL)
	{
		ft_putstr("Minishell: cd: HOME not set\n");
	}
	else
	{
		ft_cd_goto_path(data, var->value);
	}
}

void	ft_cd_goto_opwd(t_data *data, char *path) // execute la commande 'cd -'
{
	t_var	*opwd;

	opwd = ft_found_var_name(data, "OLDPWD");
	if (opwd == NULL)
	{
		ft_putstr("Minishell: cd: ");
		ft_putstr("OLDPWD not set\n");
	}
	else
	{
		chdir(path);
		ft_strdel(&data->opwd);
		data->opwd = ft_malloc_str(data, ft_strlen(data->pwd));
		data->opwd = ft_strncpy(data->opwd, data->pwd, ft_strlen(data->pwd));
		ft_strdel(&data->pwd);
		data->pwd = ft_malloc_str(data, ft_strlen(getcwd(NULL, 0)));
		data->pwd = ft_strncpy(data->pwd, getcwd(NULL, 0), ft_strlen(getcwd(NULL, 0)));
		ft_cd_from_data_to_var_opwd(data);
		ft_cd_from_data_to_var_pwd(data);
		ft_putstr(data->pwd);
		ft_putchar('\n');
	}
}

void	ft_cd_goto_path(t_data *data, char *path) // verifie la validitee du path et le stocke dans TOUT les endroits necesaires
{
	int		i;
	char	*npath;

	i = 0;
	while (path[i] && path[i] != ' ' && ft_is_separator(data->input, i) == 0)
		i++;
	npath = ft_malloc_str(data, i);
	npath = ft_strncpy(npath, path, i);
	if (chdir(npath) < 0)
	{
		ft_putstr("Minishell: cd: ");
		ft_putstr(npath);
		ft_putstr(": No such file or directory\n");
	}
	else
	{
		ft_strdel(&data->opwd);
		data->opwd = ft_malloc_str(data, ft_strlen(data->pwd));
		data->opwd = ft_strncpy(data->opwd, data->pwd, ft_strlen(data->pwd));
		ft_strdel(&data->pwd);
		data->pwd = ft_malloc_str(data, ft_strlen(getcwd(NULL, 0)));
		data->pwd = ft_strncpy(data->pwd, getcwd(NULL, 0), ft_strlen(getcwd(NULL, 0)));
		ft_cd_from_data_to_var_opwd(data);
		ft_cd_from_data_to_var_pwd(data);
	}
	ft_strdel(&npath);
}

void	ft_cd_from_data_to_var_opwd(t_data *data) // s'occupe de gerer opwd dans la structure var
{
	// t_var	*pwd;
	t_var	*opwd;

	// pwd = ft_found_var_name(data, "PWD");
	opwd = ft_found_var_name(data, "OLDPWD");
	if (opwd == NULL)
	{
		ft_add_new_var(data);
		data->var->name = ft_malloc_str(data, 6);
		data->var->name = ft_strncpy(data->var->name, "OLDPWD", 6);
		data->var->value = ft_malloc_str(data, ft_strlen(data->opwd));
		data->var->value = ft_strncpy(data->var->value, data->opwd, ft_strlen(data->opwd));
	}
	else
	{
		ft_strdel(&opwd->value);
		opwd->value = ft_malloc_str(data, ft_strlen(data->opwd));
		opwd->value = ft_strncpy(opwd->value, data->opwd, ft_strlen(data->opwd));
	}
}

void	ft_cd_from_data_to_var_pwd(t_data *data) // s'occupe de gerer pwd dans la structure var
{
	t_var	*pwd;
	// t_var	*opwd;

	pwd = ft_found_var_name(data, "PWD");
	// opwd = ft_found_var_name(data, "OPWD");
	if (pwd == NULL)
	{
		ft_add_new_var(data);
		data->var->name = ft_malloc_str(data, 3);
		data->var->name = ft_strncpy(data->var->name, "PWD", 3);
		data->var->value = ft_malloc_str(data, ft_strlen(data->pwd));
		data->var->value = ft_strncpy(data->var->value, data->pwd, ft_strlen(data->pwd));
	}
	else
	{
		ft_strdel(&pwd->value);
		pwd->value = ft_malloc_str(data, ft_strlen(data->pwd));
		pwd->value = ft_strncpy(pwd->value, data->pwd, ft_strlen(data->pwd));
	}
}