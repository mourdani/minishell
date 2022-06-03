/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_redirects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:58:24 by guderram          #+#    #+#             */
/*   Updated: 2022/05/30 12:16:18 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_cut_redirects(t_data *data) // ret 1 si une redirection est trouvee, sinon ret 0
{
	int i;
	int u; //compte les espaces

	i = data->i;
	u = 0;
	// printf("is redir\n");
	u = u + ft_space(data->input, i);
	// printf("sep : '%c' i : %d\n", data->input[i], i);
	if (ft_is_separator(data->input, (i + u)) != 0)
	{
		// printf("sep : '%c' i : %d\n", data->input[i], i);
		ft_create_redirects_token(data, ft_is_separator(data->input, (i + u)));
		if (ft_is_separator(data->input, (i + u)) > 4)
			data->i = data->i + u + 2;
		else
			data->i = data->i + u + 1;
		// printf("redir ok\n");
		return (1);
	}	
	return (0);
}


void	ft_create_redirects_token(t_data *data, int i) // cree le token de la commande redirect
{
	if (data->token == NULL)
		ft_init_token(data);
	else
		ft_add_new_token(data);
	data->token->sep = i; // valeur de la commande de sortie
	// printf("data->token->sep = %d\n", i);
}
