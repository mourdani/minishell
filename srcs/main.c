/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:35:54 by guderram          #+#    #+#             */
/*   Updated: 2022/02/11 05:23:04 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/minishell.h"


int	main(int argc, char **argv, char **env)
{
	argc = 0;
	argv = NULL;
	char *line;
	t_data	*data;

	int i = 0; // A SUPP

	data = malloc(sizeof(t_data));
	if (ft_init_env(data, env) == 0)
		return (0); // erreur
	
	/*		Tests		*/
	write(0, "~$ ", 3);
	while (get_next_line(0, &line) > 0)
	{
		ft_putstr(line);
		write(0, "~$ ", 3);
	}
	printf("\n");
	while (data->env[i])
	{
		printf("%s\n", data->env[i]);
		i++;
	}
	/*		Tests		*/

	return (0);
}
