/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_export.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 08:25:07 by guderram          #+#    #+#             */
/*   Updated: 2022/02/18 11:06:58 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int		ft_cut_export(t_data *data) // cut la commande export
{
	char	*str;
	int		u;
	int		i;

	i = data->i;
	u = 0;
	str = "export";
	while (data->input[i] && data->input[i] != ' ')
	{
		if (ft_is_a_b(data->input[i], str[u]) == 1)
			u++;
		i++;
	}
	if (u == 6)
	{

		data->i = data->i + u;
		ft_create_export_token(data);
		return (1);
	}
	return (0);
}

void	ft_parse_export(t_data *data) // parse les arguments de export
{
	int	i;
	int	m;

	i = data->i;
	m = 0;
	while (data->input[i] && ft_is_separator(data->input, i) == 0)
	{
		if (ft_is_export(data->input, i) != 0)
		{
			m = ft_is_export(data->input, i);
			ft_str_join_input(data, i, m);
			i = i + m;
		}
		m = 0;
		i++;
	}
	data->i = data->i + i;
}

int		ft_is_export(char *str, int i) // verifie si l'argument d'export est valable
{
	int	equal; // compte le nombre de "=" present
	// int	pos; // retien la position de "="

	equal = 0;
	// pos = 0;
	while (str[i] && str[i] != ' ' && ft_is_separator(str, i) != 1)
	{
		if (str[i] == '=' && str[i + 1] != ';' && str[i + 1] != ' ' && str[i - 1] != ';' && str[i - 1] != ' ')
		{
			// pos = i;
			equal++;
		}
		i++;
	}
	if (equal == 1)
		return (i);
	return (0);
}

void	ft_create_export_token(t_data *data) // cree le token de la commande export
{

	if (data->first == NULL)
		ft_init_token(data);
	else
		ft_add_new_token(data);
	data->first->cmd = 3;
	data->first->str = ft_malloc_str(data, 0);
	ft_parse_export(data);
}
