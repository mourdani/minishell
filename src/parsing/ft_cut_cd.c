/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 10:59:30 by mourdani          #+#    #+#             */
/*   Updated: 2022/06/01 07:43:50 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	change_dir(t_data *data)                 // changes directory
{
	if (data->token->arg == NULL || !ft_strncmp(data->token->arg, "~\0", 2))
	{
		chdir(getenv("HOME"));
		if (data->pwd)
		{
			free(data->pwd);
			data->pwd = NULL;
		}
		data->pwd = getcwd(NULL, 0);
		return (1);
	}
	if (chdir(data->token->arg) < 0)
		perror(data->token->arg);        // printf error message
	if (data->pwd)
	{
		free(data->pwd);
		data->pwd = NULL;
	}
	data->pwd = getcwd(NULL, 0);
	return (1); //ok
}



int	ft_cut_cd(t_data *data, int i) // ret 1 si cd est trouvé, sinon ret 0
{
	if (ft_strncmp(&data->input[i], "cd", 2) != 0)
		return (0);
	i = i + 2;
	if (ft_str_after_cut(&data->input[i]) != 1)
		return (0);
	// printf("\necho ok\n");
	i = i + ft_space(data->input, i);
	data->i = i;
	ft_create_cd_token(data);
	return (1);


	
}

void	ft_create_cd_token(t_data *data) // cree le token de la commande cd.
{
	if (data->token == NULL)
		ft_init_token(data);
	else
		ft_add_new_token(data);
	data->token->cmd = 6;
	// u = ft_space(data->input, data->i);

	ft_malloc_builtin_arg(data, data->token);

	// while (data->input[data->i + u] && ft_is_separator(data->input, (data->i + u)) == 0 && data->input[data->i + u] != ' ')
	// 	u++;
	// // while (ft_is_separator(data->input, (data->i + u)) == 0 && data->input[data->i + u])
	// // 	u++;
	// data->token->arg = ft_malloc_str(data, u);
	// if (data->token->arg != NULL)
	// {
	// 	data->token->arg = ft_strncpy(data->token->arg, &(data->input[data->i]), u);
	// 	// data->token->arg = cut_str(data, data->token->arg);
	// 	while (data->input[data->i + u] && ft_is_separator(data->input, (data->i + u)) == 0)
	// 		u++;
	// 	data->i = data->i + u;
	// }
	// else
	// 	data->err = 200; // erreur malloc
}
