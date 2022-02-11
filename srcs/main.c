/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:35:54 by guderram          #+#    #+#             */
/*   Updated: 2022/02/10 23:56:55 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/minishell.h"


int	main(int argc, char **argv, char **env)
{
	argc = 0;
	argv = NULL;
	char *line;
	t_data	*data;

	data = malloc(sizeof(t_data));

	/*		Tests		*/
	write(0, "~$ ", 3);
	while (get_next_line(0, &line) > 0)
	{
		write(0, "~$ ", 3);
	}
	printf("test\n");
	printf("%s\n", env[0]);
	/*		Tests		*/
	
	return (0);
}
