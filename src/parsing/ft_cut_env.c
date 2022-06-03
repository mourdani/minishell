/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 07:12:42 by mourdani          #+#    #+#             */
/*   Updated: 2022/03/21 05:21:01 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// int	ft_cut_env(t_data *data) // ret 1 si env trouver, sinon ret 0.
// {
// 	char *command;
// 	int i;

// 	i = data->i;
// 	command = "env";
// 	printf("IN CUT ENV\n");
// 	while (ft_is_whitespace(data->input[i]))
// 		i++;
// 	if (ft_strncmp((data->input + i), command, 3) == 0)
// 	{
// 		data->i = data->i + 3 + ft_space(data->input, data->i);
// 		ft_create_env_token(data);
// 		return (1);
// 	}
// 	return (0);
// }

int	ft_cut_env(t_data *data, int i) // ret 1 si env trouver, sinon ret 0. i est la tete de lecture ou demarre la lecture
{
	char	*str;
	int		u;

	u = 0;
	str = "env";
	// printf("\nIN CUT ENV\n");
	// printf("i : %d", i);
	i = i + ft_space(data->input, i);
	// printf("i : %d, '%s'\n", i, &(data->input[i]));
	while (data->input[i] && data->input[i] != ' ' && ft_is_separator(data->input, i) == 0)
	{
		if (ft_is_a_b(data->input[i], str[u]) == 1)
			u++;
		i++;
	}
	if (u == 3)
	{
		data->i = data->i + 3 + ft_space(data->input, data->i);
		// data->i = data->i + ft_space(data->input, data->i);
		ft_create_env_token(data);
		// printf("IN OUT ENV\n");
		return (1);
	}
	return (0);
}

void	ft_create_env_token(t_data *data) // cree le token de la commande env.
{
	if (data->token == NULL)
		ft_init_token(data);
	else
		ft_add_new_token(data);
	data->token->cmd = 4;
	// printf ("TOKEN IN ENV %d\n", data->token->cmd);
}
