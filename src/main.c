/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:35:54 by guderram          #+#    #+#             */
/*   Updated: 2022/02/17 09:09:31 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/minishell.h"

int	add_history(char *str, int param)
{
	static int	i;
	static char **history;
	int j;

	if (!history)
	{
		i = 0;
		history = malloc(sizeof(char **));
	}
	if (param == 1)
		history[i++] = ft_strdup(str);
	else
	{
		j = 0;
		while (j < i)
		{
			printf("%d   %s\n", j,  history[j]);
			j++;
		}
	}
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
		if (data->input[0] == 'h' && data->input[1] == 'i')
			add_history(data->input, 2);
		else
		{
			printf("text entered: %s\n", data->input);
			add_history(data->input, 1);
		}
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
