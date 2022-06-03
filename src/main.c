/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:35:54 by guderram          #+#    #+#             */
/*   Updated: 2022/06/01 07:34:54 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int		g_return;

int		ft_verif_pipe(t_pipe *p) // renvoie 1 si les pipe sont libres (== -10) sinon 0
{
	if(p->fd_i == -10 && p->fd_o == -10 && p->ofd_i == -10 && p->ofd_o == -10)
		return (1);
	else
		return (0);
}



void	prompt(t_data *data)
{
	int	i = 0;
	while (data->exit == 0)
	{
		/*	readline	*/
		i = 0;
		data->input = readline("~$ ");
		if (ft_strlen(data->input) == 0)
			break;
		add_history(data->input);		
		while (data->input[i])
		       	i++;

		/*	commande de parsing a inserer ici */
		if (ft_is_input_safe(data->input) == 0)
			data->err = 1;
		else
			ft_parse_input(data);

		/* commande d'execusion des tokens a inserer ici */
		if (data->err == 0 && data->exit == 0 && data->token != NULL)
			ft_read_token_list(data);
		ft_clear_for_new_input(data);
		if (data->exit != 0)
			ft_putstr("exit\n");
	}
	// write(0, "ex\n", 3);


}

int	main(int argc, char **argv, char **env)
{
	argc = 0;
	argv = NULL;
	t_data	*data;

	(void)argc;
	(void)argv;

	init_signals();

	printf("Bienvenue dans ce minishell realisé par guderram et mourdani\n");
	data = malloc(sizeof(t_data));
	// printf("OK 1\n");
	if (ft_init_data(data, env) == 0)
		return (0); // erreur
	prompt(data);
	/*	tests free : 	*/
	unlink(TMP_OUT);
	unlink(TMP_IN);
	return (0);
}
