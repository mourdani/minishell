/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 07:12:42 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/19 09:22:25 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	cut_env(t_data *data)
{
	char *command;
	int i;

	i = 0;
	command = "env";
	while (ft_is_whitespace(data->input[i]))
		i++;
	if (ft_strncmp((data->input + i), command, 3) == 0)
	{
		data->i += 3;
		ft_create_env_token(data);
		return (1);
	}
	return (0);
}

void	ft_create_env_token(t_data *data) // cree le token de la commande env.
{
	if (data->first == NULL)
		ft_init_token(data);
	else
		ft_add_new_token(data);
	data->first->cmd = 4;
}
