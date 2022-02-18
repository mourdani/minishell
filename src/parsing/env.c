/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 07:12:42 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/18 07:14:32 by mourdani         ###   ########.fr       */
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
		return(1);
	return (0);
}
