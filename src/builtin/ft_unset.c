/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 02:12:33 by guderram          #+#    #+#             */
/*   Updated: 2022/03/21 05:36:05 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*ft_unset_malloc_str(t_data *data, char *str) // renvoie une chaine de str
{
	char	*string;
	int		u;

	u = 0;
	while (str[u] && str[u] != ' ' && ft_is_separator(str, u) == 0)
		u++;
	string = ft_malloc_str(data, u);
	if (string != NULL)
		string = ft_strncpy(string, str, u);
	return (string);
}


void	ft_unset(t_data *data, t_token *token) // fonction principale de unset
{
	t_var	*var;
	int		i;
	char	*str;

	i = 0;
	while (token->arg[i])
	{
		i = i + ft_space(token->arg, i);
		str = ft_unset_malloc_str(data, &(token->arg[i]));
		if (str != NULL)
			var = ft_found_var_name(data, str);
		if (str != NULL && var != NULL)
			ft_delete_var(data, var);
		ft_strdel(&str);
		i++;
	}

	// var = ft_found_var_name(data, token->arg);
	// printf("var name '%s' : var value '%s'\n", var->name, var->value);
	// if (var != NULL)
	// 	ft_delete_var(data, var);
}
