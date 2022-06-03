/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 17:28:56 by guderram          #+#    #+#             */
/*   Updated: 2022/06/01 08:07:44 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int		ft_size_of_arg(t_data *data) // renvoie la taille d'un arg, pratique pour malloc tok->arg
{
	int	u;
	int i = 0;

	u = 0;
	while (ft_is_separator(data->input, (data->i + u)) == 0 && data->input[data->i + u])
	{
		if (data->input[data->i + u] == '\"' && data->input[data->i + u + 1] != '\"' && data->input[data->i + u + 1] != '\0')
		{
			i = ft_str_size(ft_ret_double_quote(data, &data->input[data->i + u], 0));
			if (i != 0)
				u = u + i;
			while (i == 0 && data->input[data->i + u] != '\"')
				u++;
			if (i == 0)
				u++;
		}
		else if (data->input[data->i + u] == '\'' && data->input[data->i + u + 1] != '\'' && data->input[data->i + u + 1] != '\0')
			u = u + ft_str_size(ft_ret_simple_quote(data, &data->input[data->i + u], 0));
		else if ((data->input[data->i + u] == '\"' && data->input[data->i + u + 1] == '\"') || (data->input[data->i + u] == '\'' && data->input[data->i + u + 1] == '\''))
			{
				u = u + 2;
			}
		else if (data->input[data->i + u] == '$')
		{
			if (ft_str_size(ft_ret_dollar(data, &(data->input[data->i + u]))) > 0)
				u = u + ft_str_size(ft_ret_dollar(data, &(data->input[data->i + u])));
			else
				u++;
		}
		else
			u++;
	}
	if (i != 0 && u == 0)
		u++;
	return (u);
}

void	ft_malloc_arg(t_data *data, t_token *tok) // malloc dans tok->arg l'argument
{
	int		i;
	int		u;
	int		size;
	char	*tmp;


	i = 0;
	u = 0;
	size = ft_size_of_arg(data);
	tok->arg = ft_malloc_str(data, size);
	if (size > 0 && tok->arg != NULL)
	{
		while (data->input[data->i + u] && ft_is_separator(data->input, (data->i + u)) == 0)
		{
			if (data->input[data->i + u] == '\"' && data->input[data->i + u + 1] != '\"')
			{
				tmp = ft_ret_double_quote(data, &data->input[data->i + u], 0);
				if (ft_str_size(tmp) > 0)
					u = u + 2 + ft_str_size(tmp);
				while (data->input[data->i + u] && ft_str_size(tmp) > 0 && data->input[data->i + u] != '\"')
					u++;
				if (data->input[data->i + u] == '\"')
					u++;

				if (ft_str_size(tmp) > 0)
					ft_copie_dest_src(tok, tmp);
				ft_strdel(&tmp);
			}
			else if (data->input[data->i + u] == '\'' && data->input[data->i + u + 1] != '\'')
			{
				tmp = ft_ret_simple_quote(data, &data->input[data->i + u], 0);
				u = u + 2 + ft_str_size(tmp);
				ft_copie_dest_src(tok, tmp);
				ft_strdel(&tmp);
			}
			else if ((data->input[data->i + u] == '\"' && data->input[data->i + u + 1] == '\"') || (data->input[data->i + u] == '\'' && data->input[data->i + u + 1] == '\''))
				u = u + 2;
			else if (data->input[data->i + u] == '$')
			{

				tmp = ft_ret_dollar(data, &(data->input[data->i + u]));
				if (tmp != NULL)
					ft_copie_dest_src(tok, tmp);
				ft_strdel(&tmp);
				u++;
				while (data->input[data->i + u] && data->input[data->i + u] != ' ' && data->input[data->i + u] != '$' && ft_is_separator(data->input, (data->i + u)) == 0 && data->input[data->i + u] != '\"' && data->input[data->i + u] != '\'')
					u++;
			}
			else
			{
				i = 0;
				while (tok->arg[i] && tok->arg[i] != '\0')
					i++;
				tok->arg[i] = data->input[data->i + u];
				if (data->input[data->i + u] == ' ')
					u = u + ft_space(data->input, data->i + u);
				else
					u++;
			}
		}
		while (tok->arg[i] && tok->arg[i] != '\0')
			i++;
		tok->arg[i] = '\0';
		data->i = data->i + u;
	}
	if (size == 0 && data->input[data->i + u] == '\"')
	{
		u++;
		while (data->input[data->i + u] && data->input[data->i + u] != '\"')
			u++;
		if (data->input[data->i + u] == '\"')
			u++;
		data->i = data->i + u;
	}
	else if (size == 0)
		data->err = 200; // erreur malloc
}



/*	NOUVEAUX SYSTEME DE GESTION DES ARGUMENTS	*/



int		ft_incre_one_arg(t_data *data, int u) // incremente en fonction d'un 'argument' d'entree
{

	while (data->input[data->i + u] && data->input[data->i + u] != ' ' && ft_is_separator(data->input, data->i + u) == 0)
	{
		if (data->input[data->i + u] == '\'')
		{
			u++;
			while (data->input[data->i + u] && data->input[data->i + u] != '\'')
				u++;
			u++;
		}
		else if (data->input[data->i + u] == '\"')
		{
			u++;
			while (data->input[data->i + u] && data->input[data->i + u] != '\"')
				u++;
			u++;
		}
		else
			u++;
	}
	return (u);
}

int		ft_size_one_arg(t_data *data, int s) // renvoie la taille d'un seul argument
{
	int	u;
	int	ret;

	u = 0;
	s = s + data->i;
	ret = 0;
	while (ft_is_separator(data->input, (s + u)) == 0 && data->input[s + u] && data->input[s + u] != ' ')
	{
		if (data->input[s + u] == '\"' && data->input[s + u + 1] != '\"' && data->input[s + u + 1] != '\0')
		{
			ret = ret + ft_str_size(ft_ret_double_quote(data, &data->input[s + u], 0));
			u++;
			while (data->input[s + u] != '\"')
				u++;
			u++;
		}
		else if (data->input[s + u] == '\'' && data->input[s + u + 1] != '\'' && data->input[s + u + 1] != '\0')
		{
			ret = ret + ft_str_size(ft_ret_simple_quote(data, &data->input[s + u], 0));
			while (data->input[s + u] != '\'')
				u++;
			u++;
		}
		else if ((data->input[s + u] == '\"' && data->input[s + u + 1] == '\"') || (data->input[s + u] == '\'' && data->input[s + u + 1] == '\''))
			u = u + 2;
		else if (data->input[s + u] == '$')
		{
			if (ft_str_size(ft_ret_dollar(data, &(data->input[s + u]))) > 0)
			{
				ret = ret + ft_str_size(ft_ret_dollar(data, &(data->input[s + u])));
				u++;
				while (ft_is_separator(data->input, (s + u)) == 0 && data->input[s + u] && data->input[s + u] != ' ' && data->input[s + u] != '$')
					u++;
			}
			else
			{
				ret++;
				u++;
			}
		}
		else
		{
			u++;
			ret++;
		}
	}
	return (ret);
}

char	*ft_one_simple_arg(t_data *data, int i) // renvoie une chaine simple contenant des termes
{
	char	*ret;
	int		j;

	j = 0;
	while (data->input[i + j] && data->input[i + j] != ' ' && ft_is_separator(data->input, i + j) == 0 && data->input[i + j] != '\'' && data->input[i + j] != '\"' && data->input[i + j] != '$')
		j++;
	ret = ft_malloc_str(data, j);
	j = 0;
	while (data->input[i + j] && data->input[i + j] != ' ' && ft_is_separator(data->input, i + j) == 0 && data->input[i + j] != '\'' && data->input[i + j] != '\"' && data->input[i + j] != '$')
	{
		ret [j] = data->input[i + j];
		j++;
	}
	ret [j] = '\0';
	return (ret);
}

char	*ft_one_arg(t_data *data, int u) // renvoie le premier argument en partant de u dans data input
{
	char	*ret;
	int		i;

	i = 0;
	ret = ft_malloc_str(data, ft_size_one_arg(data, u));
	u = u + data->i;
	while (data->input[i + u] && data->input[i + u] != ' ' && ft_is_separator(data->input, i + u) == 0)
	{
		if (data->input[i + u] == '\"' && data->input[i + u + 1] != '\"' && data->input[i + u + 1] != '\0')
		{
			ret = ft_src_in_dest(data, ret, ft_ret_double_quote(data, &data->input[i + u], 0), 0);
			i++;
			while (data->input[i + u] != '\"')
				i++;
			i++;
		}
		else if (data->input[i + u] == '\'' && data->input[i + u + 1] != '\'' && data->input[i + u + 1] != '\0')
		{
			ret = ft_src_in_dest(data, ret, ft_ret_simple_quote(data, &data->input[i + u], 0), 0);
			i++;
			while (data->input[i + u] != '\'')
				i++;
			i++;

		}
		else if ((data->input[i + u] == '\"' && data->input[i + u + 1] == '\"') || (data->input[i + u] == '\'' && data->input[i + u + 1] == '\''))
			i = i + 2;
		else if (data->input[i + u] == '$')
		{
			if (ft_str_size(ft_ret_dollar(data, &(data->input[i + u]))) > 0) // A FAIRE : ajouter la gestion de un seul doll directement dans la fonction ret_dollar
			{
				ret = ft_src_in_dest(data, ret, ft_ret_dollar(data, &(data->input[i + u])), 0);
			}
			i++;
			while (ft_is_separator(data->input, (i + u)) == 0 && data->input[i + u] && data->input[i + u] != ' ' && data->input[i + u] != '$')
				i++;
		}
		else
		{
			ret = ft_src_in_dest(data, ret, ft_one_simple_arg(data, i + u), 0);
			while (data->input[i + u] && data->input[i + u] != ' ' && ft_is_separator(data->input, i + u) == 0 && data->input[i + u] != '\'' && data->input[i + u] != '\"' && data->input[i + u] != '$')
			i++;
		}
	}
	return (ret);
}

void	ft_malloc_builtin_arg(t_data *data, t_token *tok) // permet de malloc les arguments d'un builtin dans arg.
{
	int		u;
	int max = 0;

	u = 0;
	while (data->input[data->i + u] && ft_is_separator(data->input, data->i + u) == 0 && max < 20)
	{
		u = u + ft_space(data->input, data->i + u);
		tok->arg = ft_src_in_dest(data, tok->arg, ft_one_arg(data, u), ' ');
		u = ft_incre_one_arg(data, u);
		max ++;
	}
	data->i = data->i + u;
}
