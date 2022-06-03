/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_var.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 22:02:35 by guderram          #+#    #+#             */
/*   Updated: 2022/05/26 11:17:15 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"



t_var	*ft_found_var_name(t_data *data, char *str) // permet de trouver et de renvoyer l'adresse de la var qui contient la string "str" dans name. si rien n'est trouver renvoie "NULL"
{
	t_var	*var;
	int		i;

	i = 0;
	// printf("ft_found_var_name : str <%s>\n", str);
	while (str[i])
		i++;
	if (data->var != NULL)
		var = data->var;
	else
		return (NULL);
	if (i == 0)
		return (NULL);
	// printf("ft_found_var_name : str <%s>\n", str);
	while (var != NULL)
	{
		// printf("ft_found_var_name : dans while : var name <%s>\n", var->name);
		if (str[0] == '?' && str[1] == '\0')
		{
			// printf("ft_found_var_name : OUI\n");
			if (var->value != NULL)
				ft_strdel(&var->value);
			var->value = malloc(sizeof(char) * (ft_str_size(ft_itoa(g_return))));
			// printf("g_return %d ft_itoa : <%s>\n", g_return, ft_itoa(g_return));
			var->value = ft_itoa(g_return);
			return (var);
		}
		if (ft_strncmp(var->name, str, i) == 0)
		{
			// printf("ft_found_var_name : dans if\n");

			if(var->name[i] == '\0')
			{
				return (var);
			}
		}
		var = var->next;
	}
	// if (str[0] == '?' && str[1] == '\0')
	// {
	// 	if (var->value != NULL)
	// 		ft_strdel(var->value);
	// 	var->value = malloc(sizeof(char) * (ft_str_size(ft_itoa(g_return))));
	// 	var->value = ft_itoa(g_return);
	// }
	return (NULL);
}

void	ft_disp_all_var(t_data *data, char sep, int export) // permet d'afficher toutes les variables stockees avec en option un separateur entre nom et value, si export vaut 1 alors considere que la commande export a ete lancee sans arguments
{
	t_var	*var;
	
	var = data->var;
	while (var != NULL)
	{
		if (var->name[0] == '$' && var->name[1] == '\0')
			var = var->next;
		if (export == 1)
			ft_putstr("declare -x ");
		ft_putstr(var->name);
		ft_putchar(sep);
		if (export == 1)
			ft_putchar('"');
		ft_putstr(var->value);
		if (export == 1)
			ft_putchar('"');
		if (var->next != NULL)
			ft_putchar('\n');
		var = var->next;
	}
}
