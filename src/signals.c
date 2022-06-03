/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 23:58:29 by mourdani          #+#    #+#             */
/*   Updated: 2022/05/18 18:58:41 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"


void	handler_c()
{
	printf("\n");
	write(0, "~$ ", 3);
}

void	handler_q()
{
	;	
}

void init_signals(void)
{
	signal(SIGINT, handler_c);
	signal(SIGQUIT, handler_q);
}
