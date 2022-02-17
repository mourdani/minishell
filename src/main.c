/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:35:54 by guderram          #+#    #+#             */
/*   Updated: 2022/02/17 07:08:32 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/minishell.h"

int	history_fill(char *str, int param)
{
	static char *history;

	if (param == 1)
		history = ft_strjoin(str, history);
	if (param == 2)
		printf("\n\n\nhistory : %s\n", history);
	return (0);
}


int	main(int argc, char **argv, char **env)
{
	argc = 0;
	argv = NULL;
	// char *line;
	t_data	*data;

	int i = 0; // A SUPP

	data = malloc(sizeof(t_data));
//	if (ft_init_env(data, env) == 0)
//		return (0); // erreur
//	
	/*		Tests		*/
	write(0, "~$ ", 3);
	while (get_next_line(0, &data->input) > 0)
	{
		printf("text entered: %s\n", data->input);
		history_fill(data->input, 1);
		write(0, "~$ ", 3);
	}
	// printf("\n");
	// while (data->env[i])
	// {
	// 	printf("%s\n", data->env[i]);
	// 	i++;
	// }
	/*		Tests		*/

	return (0);
}
