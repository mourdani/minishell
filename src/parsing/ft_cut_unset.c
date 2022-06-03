/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 00:04:56 by guderram          #+#    #+#             */
/*   Updated: 2022/06/01 07:44:12 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_cut_unset(t_data *data, int i) // ret 1 si unset trouver, sinon ret 0. i est la tete de lecture ou demarre la lecture
{
	char	*str;
	int		u;

	u = 0;
	str = "unset";
	i = i + ft_space(data->input, i);
	// printf("UNSET :\n");
	// printf("%d, '%s'\n", i, &(data->input[i]));
	while (data->input[i] && data->input[i] != ' ' && ft_is_separator(data->input, i) == 0)
	{
		if (ft_is_a_b(data->input[i], str[u]) == 1)
			u++;
		i++;
	}
	// printf("%d, '%s'\n", i, &(data->input[i]));
	if (u == 5)
	{
		data->i = data->i + 5;
		// data->i = data->i + ft_space(data->input, data->i);
		ft_create_unset_token(data);
		return (1);
	}
	return (0);
}

void	ft_create_unset_token(t_data *data) // fonction qui cree le token unset
{
	if (data->token == NULL)
		ft_init_token(data);
	else
		ft_add_new_token(data);
	data->token->cmd = 8;
	ft_malloc_builtin_arg(data, data->token);
	printf("Unset arg : <%s>\n", data->token->arg);
}
