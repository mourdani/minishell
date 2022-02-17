/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 05:03:09 by guderram          #+#    #+#             */
/*   Updated: 2022/02/11 05:21:36 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_init_env_bis(t_data *data, char **env, int i)
{
	int	u;

	u = 0;
	while (env[i][u] && env[i][u] != '\n' )
		u++;
	data->env[i] = malloc(sizeof(char) * (u + 1));
	if (data->env[i] == NULL)
		return (0); // erreur malloc
	u = 0;
	while (env[i][u] && env[i][u] != '\n' )
	{
		data->env[i][u] = env[i][u];
		u++;
	}
	data->env[i][u] = '\0';
	return (1); // OK
}

int	ft_init_env(t_data *data, char **env) // malloc env dans data
{
	int	i;
	int	u;

	i = 0;
	u = 0;
	while (env[i])
		i++;
	data->env = malloc(sizeof(char *) * (i + 1));
	if (data->env == NULL)
		return (0); // erreur malloc
	i = 0;
	while (env[i])
	{
		if (ft_init_env_bis(data, env, i) == 0)
			return (0); // erreur malloc
		i++;
	}
	data->env[i] = NULL;
	return (1); // 1 = OK
}
