/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_echo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:16:44 by guderram          #+#    #+#             */
/*   Updated: 2022/02/11 17:23:27 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	ft_cut_echo(t_data *data, int i) // ret 1 si echo trouver, sinon ret 0. i est la tete de lecture ou demarre la lecture
{
	char	*str;
	int		u;

	u = 0;
	str = "echo";
	while (data->input[i] && data->input[i] != " ")
	{
		while (ft_is_a_b(data->input[i], str[u]) == 1)
			u++;
		i++;
	}
	if (u == 4)
	{
		// go tcheck si -n est apres puis mettre dans un token
		
		return (1);
	}
	return (0);
}

int	ft_cut_echo_option(t_data *data, int i)
{
	char	*str;
	int		u;

	str = "-n";
	u = 0;
	i = ft_space(data->input, i);
	while (data->input[i] && data->input[i] != " ")
	{
		while (ft_is_a_b(data->input[i], str[u]) == 1)
			u++;
		i++;
	}
	if (u == 2)
	{
		// active l'option -n de echo
	}
	

	
}

void	ft_create_echo_token(t_data *data, int option) // fonction qui cree le token echo avec ou sans option
{
	
}