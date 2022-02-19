/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:35:41 by guderram          #+#    #+#             */
/*   Updated: 2022/02/19 09:29:42 by mourdani         ###   ########.fr       */
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
	int				exit; // sortie forcee si exit == 1
	int				err; //
	int				i; // tete de lecture dans input
	char			**env; // argument env
	char			*input; // chaine de caractere recu brute dans le shell
	struct p_token	*first; // adresse du premier token
}				t_data;

/*	**************	*/
/*	token		*/
/*	**************	*/

typedef struct p_token
{
	int				sep; // separateurs, type "; | > < >> <<""
	int				cmd; // correspond a la fonctionn geree par minishell
	int				option; // correspond a l'option de la commande precedente
	char			*str; // correspond a la string gerer par cmd
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

/*	ft_str.c	*/
void	ft_str_join_input(t_data *data, int i, int max); // malloc en recuperant la chaine token->str + la chaine input entre i et i + m
char	*ft_strncpy(char *dest, char *src, int n);
int		ft_is_separator(char *str, int i); // renvoie 0 si "c" n'est pqs un separateur, sinon son code specifique
char	*ft_malloc_str(t_data *data, int i); // malloc un str de taille i, le renplie de \0 et le return


/*	**************	*/
/*	PARSING		*/
/*	**************	*/

/*	ft_cut_export.c	*/
void	ft_create_export_token(t_data *data); // cree le token de la commande export
int		ft_is_export(char *str, int i);// verifie si l'argument d'export est valable
void	ft_parse_export(t_data *data); // parse les arguments de export
int		ft_cut_export(t_data *data); // cut la commande export

/*	ft_cut_pwd.c	*/
int		ft_cut_pwd(t_data *data); // cut la commande pwd
void	ft_create_pwd_token(t_data *data); // cree le token de la commande pwd

/*	ft_cut_input.c	*/
int		ft_parse_input(t_data *data); // return 0 si ok, sinon 1 ou numero specifique a l'erreur

/*	ft_cut_echo.c	*/
int		ft_cut_echo(t_data *data, int i); // ret 1 si echo trouver, sinon ret 0. i est la tete de lecture ou demarre la lecture
void	ft_cut_echo_option(t_data *data, int i); // verifie si l'option "-n" est presente
void	ft_create_echo_token(t_data *data, int option); // fonction qui cree le token echo avec ou sans option : si u >= 2 alors option

/*	ft_exit.c	*/
void	ft_clear_token_list(t_data *data); // supprime tout les tokens de la liste
void	ft_clear_for_new_input(t_data *data); // reset la structure data pour reprendre un nouveau input


int		cut_history(t_data *data);
void		ft_create_history_token(t_data *data);

int		cut_exit(t_data *data);

int		cut_env(t_data *data);
void		ft_create_env_token(t_data *data);

int		cut_pwd(t_data *data);

int		cut_cd(t_data *data);

/*	**********	*/
/*		CMD				*/
/*	**********	*/
int		add_history(char *str, int param);
int		print_wd(void);
int		print_cd(char *path);
/*	ft_echo.c	*/
void	ft_echo(t_data *data, t_token *token); // commande echo

/*	ft_read_token_list.c	*/
int	ft_while_token(t_data *data); // lecture des tokens

/*	ft_pwd.c	*/
void	ft_pwd(t_data *data, t_token *token); // commande pwd


#endif
