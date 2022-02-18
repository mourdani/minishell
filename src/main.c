/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:35:54 by guderram          #+#    #+#             */
/*   Updated: 2022/02/18 11:49:36 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../inc/minishell.h"

int	main(int argc, char **argv, char **env)
{
	argc = 0;
	argv = NULL;
	// char *line;
	t_data	*data;

	(void)argc;
	(void)argv;
	int i = 0; // A SUPP

	data = malloc(sizeof(t_data));
//	if (ft_init_env(data, env) == 0)
//		return (0); // erreur
//	
	/*		Tests		*/
	write(0, "~$ ", 3);
	while (get_next_line(0, &data->input) > 0)
	{
		if (cut_pwd(data))
			print_wd();
		else if (cut_cd(data))
			print_cd("inc");
		else if (cut_exit(data))
			exit(0);
		else if (cut_env(data))
		{
			while(env[i])
				printf("%s\n", env[i++]);
			i = 0;
		}
		if (cut_history(data))
			add_history(data->input, 2);
		else
			add_history(data->input, 1);
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
