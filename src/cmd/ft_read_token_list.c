/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_token_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:38:17 by guderram          #+#    #+#             */
/*   Updated: 2022/02/19 09:13:09 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int		ft_while_token(t_data *data) // lecture des tokens
{
	int	i;

	i = 0;

	printf("data->first->cmd : %d\n", data->first->cmd);
	while (i < 5 && data->exit == 0 && data->first != NULL) // A SUPP : i garde fou
		i++;

	/*	faire des tests unitaires :		*/
	if (data->first->cmd == 1) // pour echo
		ft_echo(data, data->first);
	else if (data->first->cmd == 2) // pour pwd
		ft_pwd(data, data->first);
	else if (data->first->cmd == 3) // pour export
		printf("\n'%s'\n", data->first->str);
	else if (data->first->cmd == 4) // pour env
	{
		i = 0;
		while(data->env[i])
			printf("%s\n", data->env[i++]);
	}
	else if (data->first->cmd == 5) // pour history
	{
		printf("should print history \n");
		add_history(NULL, 2);
	}
	return (0);
}
