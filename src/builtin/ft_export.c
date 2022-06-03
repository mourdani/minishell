/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 07:04:57 by guderram          #+#    #+#             */
/*   Updated: 2022/03/24 11:15:33 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// void	ft_export(t_data *data, t_token *token) // commande export
// {
// 	t_var	var;

// 	var = ft_found_var_name(data, token->arg);
// 	if (token->arg == NULL)
// 		printf("EXPORT : NO DATA NOT SET IN : src>builtin>ft_export.c\n");
// 	if (ft_)
// }


void	ft_export_in_var(t_data *data, t_token *token, int i)  // verifie si le name est dans var et fais en fonction
{
	t_var	*var;
	int		u;
	int		y;
	
	u = 0;
	y = 0;
	while (token->arg[y])
		y++;
	var = ft_found_var_name(data, token->arg);
	if (var != NULL)
		ft_delete_var(data, var);
	ft_add_new_var(data);
	data->var->name = ft_malloc_str(data, y);
	data->var->name = ft_strncpy(data->var->name, token->arg, y);
	y++;
	while (token->bin[i][y + u])
		u++;
	// printf("export_in_var : %d\n", u);
	data->var->value = ft_malloc_str(data, u);
	data->var->value = ft_strncpy(data->var->value, &(token->bin[i][y]), u);
}

void	ft_parse_export_name(t_data *data, t_token *token, int i) // parse et malloc dans token->arg le nom de la var. i est la position dans token->bin[i]
{
	int u;

	u = 0;
	if (token->arg != NULL)
		ft_strdel(&token->arg);
	while (token->bin[i][u] != '=')
		u++;
	token->arg = ft_malloc_str(data, u);
	if (token->arg != NULL)
		token->arg = ft_strncpy(token->arg, token->bin[i], u);
}

void	ft_export(t_data *data, t_token *token) // commande export
{
	int	i; // compteur dans bin[i]

	i = 0;
	if (token->bin[0] == NULL)
		ft_disp_all_var(data, '=', 1);
	while (token->bin[i] != NULL)
	{
		ft_parse_export_name(data, token, i);
		ft_export_in_var(data, token, i);
		i++;
	}
}
