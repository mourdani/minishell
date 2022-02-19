/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:35:54 by guderram          #+#    #+#             */
/*   Updated: 2022/02/19 09:01:38 by mourdani         ###   ########.fr       */
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
//	int i = 0; // A SUPP

	data = malloc(sizeof(t_data));
	if (ft_init_env(data, env) == 0)
		return (0); // erreur

	/*		Tests		*/
	write(0, "~$ ", 3);
	while (data->exit == 0 && get_next_line(0, &data->input) > 0)
	{

		/* commande de parsing a inserer ici */
		ft_parse_input(data);

		/* commande d'execusion des tokens a inserer ici */
		if ((data->exit == 0) && (data->first != NULL))
			ft_while_token(data);






			//if (cut_pwd(data))
				//print_wd();
			//else if (cut_cd(data))
				//print_cd("inc");
			//else if (cut_exit(data))
				//exit(0);
			//else if (cut_env(data))

			//if (cut_history(data))
				//add_history(data->input, 2);
			//else
				//add_history(data->input, 1);



			/*	test avec echo	*/
		ft_delete_token(data, data->first);

			/*	commande de reset de data	*/
		ft_clear_for_new_input(data);
		write(0, "~$ ", 3);
	}

	/*	fonction qui clear tout a faire	*/

	return (0);
}
