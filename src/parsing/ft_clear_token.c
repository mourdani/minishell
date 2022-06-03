/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_token.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:54:31 by guderram          #+#    #+#             */
/*   Updated: 2022/05/26 12:43:28 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_clear_token_list(t_data *data) // supprime tout les tokens de la liste
{
	// printf("clear_token_list entree\n");
	while (data->token != NULL)
	{
		ft_delete_token(data, data->token);
	}
	// printf("clear_token_list OK\n");
}

void	ft_clear_for_new_input(t_data *data) // reset la structure data pour reprendre un nouveau input
{
	ft_clear_token_list(data);
	ft_pipe_close_data_fd(data, 3);
	data->i = 0;
}
