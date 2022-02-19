/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 19:54:31 by guderram          #+#    #+#             */
/*   Updated: 2022/02/17 19:58:26 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_clear_token_list(t_data *data) // supprime tout les tokens de la liste
{
	while (data->first != NULL)
	{
		ft_delete_token(data, data->first);
	}
}

void	ft_clear_for_new_input(t_data *data) // reset la structure data pour reprendre un nouveau input
{
	ft_clear_token_list(data);
	data->i = 0;
}
