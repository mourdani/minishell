/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 07:10:53 by guderram          #+#    #+#             */
/*   Updated: 2022/02/18 07:34:12 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_cut_pwd(t_data *data) // cut la commande pwd
{
	char	*str;
	int		u;
	int		i;

	i = data->i;
	u = 0;
	str = "pwd";
	while (data->input[i] && data->input[i] != ' ')
	{
		if (ft_is_a_b(data->input[i], str[u]) == 1)
			u++;
		i++;
	}
	if (u == 3)
	{
		data->i = data->i + u;
		ft_create_pwd_token(data);
		return (1);
	}
	return (0);
}

void	ft_create_pwd_token(t_data *data) // cree le token de la commande pwd
{
	if (data->first == NULL)
		ft_init_token(data);
	else
		ft_add_new_token(data);
	data->first->cmd = 2;
	data->first->str = getenv("PWD");
	if (data->first->str == NULL)
		data->err = 106;
}
