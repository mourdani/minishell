/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_var_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 10:59:08 by guderram          #+#    #+#             */
/*   Updated: 2022/03/24 14:03:19 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"


void	ft_export_no_arg(t_data *data)
{
	int	i;
	t_var *var;

	i = 0;
	var = data->var;
	while (var != NULL)
	{
		var = var->next;
		i++;
	}
	var = ft_found_first_var(data);
	while (i > 0)
	{
		ft_print_one_var(var);
		
		i--;
	}
	
}

t_var	*ft_found_next_min_var(t_data *data)
{
	t_var	*var;
	t_var	*head;

	head = data->var;
	var = data->var;
	while (head != NULL)
	{
		if (ft_str_comp_ascii(var->name, head->name) == 2)
			var = head;
		head = head->next;
	}
	return (var);
}

t_var	*ft_found_first_var(t_data *data) // cherche la premiere variable selon la table ascii
{
	t_var	*var;
	t_var	*head;

	head = data->var;
	var = data->var;
	while (head != NULL)
	{
		if (ft_str_comp_ascii(var->name, head->name) == 2)
			var = head;
		head = head->next;
	}
	return (var);
}
