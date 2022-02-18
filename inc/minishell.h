/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:35:41 by guderram          #+#    #+#             */
/*   Updated: 2022/02/18 11:48:25 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h> // WRITE
# include <stdio.h> // PRINTF
# include <stdlib.h> // MALLOC FREE
#include <dirent.h> // opendir() for "cd"
# include "../src/libft/includes/libft.h"

# define BUFFER_SIZE_GNL 128

/*	***********	*/
/*	   data		*/
/*	***********	*/

typedef struct p_data
{
	int				err; // 
	char			**env; // argument env
	char			*input; // chaine de caractere recu brute dans le shell
	struct p_token	*first; // adresse du premier token
}				t_data;

/*	**************	*/
/*	token		*/
/*	**************	*/

typedef struct p_token
{
	int	cmd; // correspond a la fonctionn geree par minishell
	int	option; // correspond a l'option de la commande precedente
	char	*str; // correspond a la string gerer par cmd
	struct p_token	*next; // prochain token
	struct p_token	*prev; // precedent token
	
}				t_token;

/*	*************	*/
/*	INIT		*/
/*	*************	*/

/*	ft_token.c	*/
void	ft_init_token(t_data *data); // initialise la liste
void	ft_add_new_token(t_data *data); // cree une nouvelle liste et la met au debut de la stack
void	ft_free_token(t_data *data, t_token *token); // free les mallocs dans une liste
void	ft_delete_token(t_data *data, t_token *delete); // supprime la tokene en relian si besoin les autres

/*	ft_env.c	*/
int	ft_init_env(t_data *data, char **env); // malloc env dans data
int	ft_init_env_bis(t_data *data, char **env, int i);

/*	*************	*/
/*	UTILS		*/
/*	*************	*/

/*	ft_write.c	*/
int		ft_is_a_b(char a, char b); // compare a et b, renvoie 1 si ils sont identiques sinon 0
int		ft_space(char *str, int i); // renvoie le nombre d espaces a sauter en partant de i

/*	**************	*/
/*	PARSING		*/
/*	**************	*/

/*	ft_cut_echo.c	*/
int		cut_history(t_data *data);
int		cut_exit(t_data *data);
int		cut_env(t_data *data);
int		cut_pwd(t_data *data);
int		cut_cd(t_data *data);
int		add_history(char *str, int param);
int		print_wd(void);
int		print_cd(char *path);

#endif
