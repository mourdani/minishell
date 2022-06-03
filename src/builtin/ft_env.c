/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 16:11:48 by guderram          #+#    #+#             */
/*   Updated: 2022/05/20 17:14:17 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_env(t_data *data, t_token *token) // commande env
{
	
	// token->str = getenv(NULL);
	// if (token->str == NULL)
	// 	data->err = 106;
	/*	sortie sur l'entree standard	*/
	// ft_putstr(token->str);
	// ft_putstr("\n");
	// data->i = data->i;
	// printf("env : entree : data erreur : %d\n", data->err);
	// printf("dans env :\n");
	token->cmd = token->cmd;
	ft_disp_all_var(data, '=', 0);
	ft_putstr("\n");
	
	data->i = data->i;
	// printf("env : sortie : data erreur : %d\n", data->err);
}
