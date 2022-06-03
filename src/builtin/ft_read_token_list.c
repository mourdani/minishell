/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_token_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 11:38:17 by guderram          #+#    #+#             */
/*   Updated: 2022/06/01 07:53:39 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_token	*ft_ret_last_token(t_data *data) // renvoie l'adresse du dernier token.
{
	t_token	*token;

	token = data->token;
	while (token->next != NULL)
		token = token->next;
	return (token);
}


void	ft_launch_cmd(t_data *data, t_token *token) // lance une cmd
{
	// if (token->prev != NULL && token->prev->sep == 2) // si le prochain token a un sep
	// 	{
	// 		printf("in pipe out\n");
	// 		ft_pipe_out(data);
	// 	}
	// if (token->next != NULL && token->next->sep == 2) // si le precedent token a un sep
	// 	ft_pipe_in(data);
	if (token->cmd == 1) // pour echo
		ft_echo(data, token);
	if (token->cmd == 2) // pour pwd
		ft_pwd(data);
	if (token->cmd == 3) // pour export
		ft_export(data, token);
	if (token->cmd == 4) // pour env
		ft_env(data, token);
	// if (token->cmd == 5) // pour history
	// 	add_history(NULL, 2);	// shows history with param == 2; adds to history with param == 1;
	if (token->cmd == 6)
		ft_cd(data, token);	// fill inside with path of directory to enter.
	if (token->cmd == 7) // pour exit
		data->exit = 1; // enclanche la sortie
	if (token->cmd == 8) // pour unset
		ft_unset(data, token);
	if (token->cmd == 9) // pour bin
		ft_is_bin(data, token);
	// ft_pipe_close_data_fd(data, 3);
}

t_token		*ft_read_token_list_while_pipe(t_data *data, t_token *t) // lecture des tokens dans les pipes
{
	ft_pipe_in(data);
	if (t->prev != NULL && t->prev->prev != NULL && t->prev->prev->prev != NULL)
	{
		// printf("REDIR INPUT : not null!\n");
		t = t->prev->prev->prev;
	}
	else
	{
		// printf("REDIR INPUT : null !\n");
		t = NULL;
	}
	// printf("REDIR INPUT : sortie !\n");
	return (t);
}

t_token		*ft_read_token_list_while_redir(t_data *data, t_token *tok) // lecture des tokens pendant des redirections
{
	int		fd;
	t_token	*t;
	//cmd sep fichier
	fd = -10;
	t = tok;
	int	max = 0; // A SUPP 
	// if (t->prev->prev == NULL || t->prev->prev->bin == NULL) // si ya par exemple `echo jean >` 
	// 	data->err = 1230; // correspond a : bash: erreur de syntaxe près du symbole inattendu « newline »

	
	while (max < 5 && data->err == 0 && t->prev != NULL && (t->prev->sep == 3 || t->prev->sep == 5)) // trouver le bon while a mettre ...
	{
		// printf ("ft_read_token_list_while_redir entree while\n");
		if (fd != -10)
		{
			// printf ("close fd\n");
			close (fd);
			fd = -10;
		}
		/*	partie creation de fichiers	*/
		if (t->prev->prev == NULL || t->prev->prev->bin == NULL) // si ya par exemple `echo jean >` 
			data->err = 1230; // correspond a : bash: erreur de syntaxe près du symbole inattendu « newline »
		// printf ("a\n");
		if (t->prev->sep == 3)
			fd = ft_create_open_file(data, t->prev->prev->bin[0], 1); // si sep = 3 alors supprime le fichiers
		else
			fd = ft_create_open_file(data, t->prev->prev->bin[0], 0); // si sep = 5 alors ecrit a la suite
		/*	partie analyse de la suite	*/
		// printf("b\n");
		// printf("t->prev->prev->prev->sep : %d\n", t->prev->prev->prev->sep);
		if (t->prev->prev != NULL && t->prev->prev->prev != NULL && (t->prev->prev->prev->sep == 3 || t->prev->prev->prev->sep == 5))
		{
			// printf("UP MULTI REDIR\n");
			t = t->prev->prev;
			// printf("")
		}
		// else if (t->prev != NULL)
		// 	t = t->prev;
		// else
		// 	t = NULL;
		max++;
	}
	// printf ("ft_read_token_list_while_redir sortie while\n");
	if (tok != NULL && tok->cmd != -1)
	{
		// printf("lancement redir\n");
		/*	partie redirection du fd	*/
		ft_fd_redir(data, -10, fd);
	
		/*	partie execution de tok	*/
	
		ft_launch_cmd(data, tok);
	
		/*	partie reset des redirections	*/
		ft_pipe_close_data_fd(data, 3);
	}
	return (t);
}

t_token		*ft_redirect_input(t_data *data, t_token *tok) // redirige l'entree standart sur un fichier.
{
	int		fd;

	// printf("REDIR INPUT :\n");
	if (tok->prev == NULL || tok->prev->prev == NULL || tok->prev->prev->arg == NULL)
	{
		// printf("ft_redirect_input ERROR\n");
		return (tok);
	}
	fd = open(tok->prev->prev->arg, O_RDWR);
	if (fd < 0)
	{
		ft_putstr("bash: ");
		ft_putstr(tok->prev->prev->arg);
		ft_putstr(": No such file or directory\n");
		g_return = 1;
		// return (tok);
	}
	else
	{

		// printf("tok : arg <%s>", tok->arg);
		ft_fd_redir(data, fd, -10);
		ft_launch_cmd(data, tok);
		ft_pipe_close_data_fd(data, 0);
		// printf("REDIR INPUT : OK !\n");
	}
	// printf("REDIR INPUT : partie 2\n");
	if (tok->prev != NULL && tok->prev->prev != NULL && tok->prev->prev->prev != NULL)
	{
		// printf("REDIR INPUT : not null!\n");
		tok = tok->prev->prev;
	}
	else
	{
		// printf("REDIR INPUT : null !\n");
		tok = NULL;
	}
	// printf("REDIR INPUT : sortie !\n"); 
	return(tok);
}

void	ft_read_token_list(t_data *data) // lecture des tokens
{
	t_token *t;

	int i = 0; // A SUPP

	ft_print_token_list(data);
	t = ft_ret_last_token(data);
	// printf("PTN DE PID: %d\n", getpid());
	ft_putchar('\'');
	// printf("'");
	ft_pipe_close_data_fd(data, 3);
	while (data->exit == 0 && t != NULL)
	{
		if (t != NULL && t->prev != NULL && (t->prev->sep == 3 || t->prev->sep == 5))
			t = ft_read_token_list_while_redir(data, t);
		if (t != NULL && t->prev != NULL && t->prev->sep == 4)
			t = ft_redirect_input(data, t);
		if (t != NULL && t->next != NULL && t->next->sep == 2)
		{
			ft_pipe_close_data_fd(data, 0);
			ft_pipe_in(data);
		}
		if (t != NULL && t->prev == NULL)
		{
			ft_pipe_close_data_fd(data, 1);
		}
		if (t != NULL && t->prev != NULL && t->prev->sep == 6)
			t = ft_here_doc(data, t);
		if (t != NULL && t->prev != NULL && t->prev->sep == 2)
		{
			ft_pipe_close_data_fd(data, 1);
			ft_pipe_out(data);
		}
		if (t != NULL && t->cmd != -1)
		{
			ft_launch_cmd(data, t);
		}
		if (t != NULL && t->prev != NULL)
			t = t->prev;
		else
			t = NULL;
		
		i++;
	}
}



void	ft_print_token_list(t_data *data) // affiche tout les token
{
	t_token *token;
	int		i;

	token = data->token;
	i = 0;
	printf("\n");
	while (token != NULL)
	{
		if (token->arg != NULL)
		while (token->bin != NULL && token->bin[i])
			i++;
		token = token->next;
	}
}
