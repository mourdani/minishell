/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 07:26:19 by guderram          #+#    #+#             */
/*   Updated: 2022/03/21 17:50:15 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// void	ft_pwd(t_data *data, t_token *token) // commande pwd
// {
// 	(void)data;
// 	(void)token;
// 		// token->str = getenv("PWD");
// 	// if (token->str == NULL)
// 	// 	data->err = 106;
// 	/*	sortie sur l'entree standard	*/
// 	// ft_putstr(token->str);
// 	// ft_putstr("\n");
// 	token->cmd = token->cmd;
// 	// ft_disp_all_var(data, '=');
// 	// ft_putstr("\n");
// 	// data->i = data->i;
// 	printf("%s\n", data->pwd);
// 	//printf("%s\n", getcwd(NULL, 0));

// }

void	ft_pwd(t_data *data) // commande pwd
{
	ft_putstr(data->pwd);
	ft_putchar('\n');
}
