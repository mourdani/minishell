/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:35:41 by guderram          #+#    #+#             */
/*   Updated: 2022/06/01 07:42:54 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h> // WRITE FORK
# include <stdio.h> // PRINTF READLINE
# include <stdlib.h> // MALLOC FREE EXIT
# include <dirent.h> // opendir() for "cd"

# include <sys/types.h> // WAITPID
# include <sys/wait.h> // WAITPID
#include <termios.h> // SIGNALS
#include <signal.h> // SIGNALS

#include <readline/readline.h> // READLINE
#include <readline/history.h> // READLINE


# include "../src/libft/includes/libft.h"

# define BUFFER_SIZE_GNL 128
# define TMP_OUT ".minishell_tmp_out" // fichier tempo de minishell pour tout ce qui concerne les sorties
# define TMP_IN ".minishell_tmp_in" // fichier tempo de minishell pour tout ce qui concerne les entrees
# define TMP_HERE ".minishell_tmp_here_doc" // fichier tempo de minishell pour tout ce qui concerne les entrees

/*	***********	*/
/*	   data		*/
/*	***********	*/

typedef struct p_data
{

	int				exit; // sortie forcee si exit == 1
	int				err; //
	int				i; // tete de lecture dans input
	char			**env; // argument env A NE PAS UTILISER (utiliser la strucure VAR)
	char			*input; // chaine de caractere recu brute dans le shell
	char			*pwd; // vraie pwd
	char			*opwd; // vraie old pwd
	struct p_token	*token; // adresse du premier token
	struct p_var	*var; // adresse du premier var
	struct p_pipe	*pipe; // structure des pipes
}				t_data;

/*	**************	*/
/*		token		*/
/*	**************	*/

typedef struct p_token
{
	int				sep; // separateurs, type "; | > < >> <<""
	int				cmd; // correspond a la fonctionn geree par minishell
	int				option; // correspond a l'option de la commande precedente
	char			**bin; // bin[0] : nom binaire, bin[0 + i] : arguments
	char			*arg; // correspond aux arguments gerer par cmd
	struct p_token	*next; // prochain token
	struct p_token	*prev; // precedent token

}				t_token;

/*	**********	*/
/*		pipe	*/
/*	**********	*/

typedef struct p_pipe
{
	int				ofd_o; // ancien fd out
	int				ofd_i; // ancien fd in
	int				fd_o; // fd out
	int				fd_i; // fd in
}				t_pipe;

/*	**********	*/
/*		var		*/
/*	**********	*/

typedef struct p_var
{
	char			*name;
	char			*value;
	struct p_var	*next; // prochain token
	struct p_var	*prev; // precedent token
}				t_var;



/*	***********	*/
/*	   global	*/
/*	***********	*/

//t_data	*glob;
extern int			g_return;

/*	*************	*/
/*		INIT		*/
/*	*************	*/

/*	ft_init_token.c	*/
void	ft_init_token(t_data *data); // initialise la liste
void	ft_add_new_token(t_data *data); // cree une nouvelle liste et la met au debut de la stack
void	ft_free_token(t_data *data, t_token *token); // free les mallocs dans une liste
void	ft_delete_token(t_data *data, t_token *delete); // supprime la tokene en relian si besoin les autres

/*	ft_init_data.c	*/
int	ft_init_data(t_data *data, char **env); // malloc env dans data
void	ft_init_pipe(t_data *data); // prepare la structure des pipes
// int	ft_init_data_bis(t_data *data, char **env, int i);
void	ft_create_var_var(t_data *data, char *str); // cree un maillon de chane dans la structure var
void	ft_init_data_pwd(t_data *data); // initialise les deux pwd dans la structure data

/*	ft_init_var.c	*/
void	ft_init_var(t_data *data); // initialise la liste
void	ft_add_new_var(t_data *data); // cree une nouvelle liste et la met au debut de la stack
void	ft_free_var(t_data *data, t_var *var); // free les mallocs dans une liste
void	ft_delete_var(t_data *data, t_var *delete); // supprime la var en relian si besoin les autres



/*	*************	*/
/*		UTILS		*/
/*	*************	*/

/*	ft_parse_arg.c	*/
int		ft_size_of_arg(t_data *data); // renvoie la taille d'un arg, pratique pour malloc tok->arg
void	ft_malloc_arg(t_data *data, t_token *tok); // malloc dans tok->arg l'argument

void	ft_malloc_builtin_arg(t_data *data, t_token *tok); // permet de malloc les arguments d'un builtin dans arg.
char	*ft_one_arg(t_data *data, int u); // renvoie le premier argument en partant de u dans data input
char	*ft_one_simple_arg(t_data *data, int i); // renvoie une chaine simple contenant des termes
int		ft_size_one_arg(t_data *data, int s); // renvoie la taille d'un seul argument
int		ft_incre_one_arg(t_data *data, int u); // incremente en fonction d'un 'argument' d'entree


/*	ft_write.c	*/
int		ft_is_a_b(char a, char b); // compare a et b, renvoie 1 si ils sont identiques sinon 0
int		ft_space(char *str, int i); // renvoie le nombre d espaces a sauter en partant de i
void	ft_print_one_var(t_var *var); // affiche le contenu d'une var pour export sans arg
int		ft_str_comp_ascii(char *str1, char *str2); // compare les deux chaines de caracteres et renvoie celle qui est premiere celon la table ascii


/*	ft_str.c	*/
void	ft_str_join_input(t_data *data, int i, int max); // malloc en recuperant la chaine token->str + la chaine input entre i et i + m
char	*ft_strncpy(char *dest, char *src, int n);
int		ft_is_separator(char *str, int i); // renvoie 0 si "c" n'est pqs un separateur, sinon son code specifique
char	*ft_malloc_str(t_data *data, int i); // malloc un str de taille i, le renplie de \0 et le return
int		ft_str_size(char *str); // renvoie la taille d'un str
int		ft_check_char(char *str, char c, int max); // verifie si c est dans str avec max
int		ft_str_comp(char *str1, char *str2); // compare les deux strings, renvoie 1 si strictement identiques, sinon 0.
int		ft_str_after_cut(char *str); // compare le premier caractere de str avec les caracteres devant se trouver apres un argument
void	ft_copie_dest_src(t_token *tok, char *src); // copie dans dest ce que contient source A LA SUITE DE DEST : SI PAS DE PLACE TEMPI !
char	*ft_src_in_dest(t_data *data, char *dest, char *src, char sep); // refais un malloc de dest de la taille dest + src, copie dest puis src a la suite. si sep est different de NULL, la fonction place le sep entre dest et src.


/*	**************	*/
/*		PARSING		*/
/*	**************	*/

/*	ft_cut_unset.c	*/
int		ft_cut_unset(t_data *data, int i); // ret 1 si unset trouver, sinon ret 0. i est la tete de lecture ou demarre la lecture
void	ft_create_unset_token(t_data *data); // fonction qui cree le token unset

/*	ft_cut_export.c	*/
void	ft_create_export_token(t_data *data); // cree le token de la commande export
int		ft_is_export(char *str, int i);// verifie si l'argument d'export est valable
void	ft_parse_export(t_data *data); // parse les arguments de export
int		ft_cut_export(t_data *data); // cut la commande export


void	ft_export_in_bin(t_data *data, int nb); // malloc chaques arguments VALIDES de export
int		ft_export_sizeof_arg(char	*str, int i); // renvoie la taille d'un arg de export en partant de i dans str
int		ft_export_count_equal(t_data *data); // compte le nombre valide d'arguments pour export

/*	ft_cut_pwd.c	*/
int		ft_cut_pwd(t_data *data); // cut la commande pwd
void	ft_create_pwd_token(t_data *data); // cree le token de la commande pwd

/*	ft_cut_input.c	*/
int		ft_parse_input(t_data *data); // return 0 si ok, sinon 1 ou numero specifique a l'erreur
int	ft_parse_cmd_not_found(t_data *data); // commande non trouvee

/*	ft_cut_echo.c	*/
int		ft_cut_echo(t_data *data, int i); // ret 1 si echo trouver, sinon ret 0. i est la tete de lecture ou demarre la lecture
void	ft_cut_echo_option(t_data *data, int i); // verifie si l'option "-n" est presente
void	ft_create_echo_token(t_data *data, int option); // fonction qui cree le token echo avec ou sans option : si u >= 2 alors option

/*	ft_clear_token.c	*/
void	ft_clear_token_list(t_data *data); // supprime tout les tokens de la liste
void	ft_clear_for_new_input(t_data *data); // reset la structure data pour reprendre un nouveau input

/*	ft_cut_env.c	*/
int	ft_cut_env(t_data *data, int i); // ret 1 si env trouver, sinon ret 0.
void	ft_create_env_token(t_data *data); // cree le token de la commande env.

/*	ft_cut_exit.c	*/
int	ft_cut_exit(t_data *data); // ret 1 si exti trouver, sinon ret 0
void	ft_create_exit_token(t_data *data); // cree le token de la commande pwd

/*	ft_cut_cd.c	*/
int		ft_cut_cd(t_data *data, int i); // ret 1 si exti trouver, sinon ret 0
void	ft_create_cd_token(t_data *data); // cree le token de la commande cd.

/*	ft_cut_bin.c	*/
int	ft_cut_bin(t_data *data); // ret 1 si echo trouver, sinon ret 0. i est la tete de lecture ou demarre la lecture
void	ft_create_bin_token(t_data *data); // fonction qui cree le token bin
void	ft_malloc_bin(t_data *data); // malloc le **bin
int		ft_bin_arg_size(t_data *data, int i); // renvoie la taille d'un argument
int		ft_bin_count(t_data *data, int i); // revoie le nombre de cases a malloc

int		ft_bin_size(t_data *data); // permet de malloc la strucure de bin

/*	history.c	*/
int		cut_history(t_data *data);
void	ft_create_history_token(t_data *data); // cree le token de la commande cd.

/*	cd.c		*/
int		cut_cd(t_data *data);
int		change_dir(t_data *data);
void		ft_create_cd_token(t_data *data);

/*	cut_str		*/
char		*cut_str(t_data *data, char *str); // function to parse str given to cmd


/*	 quotes		*/
char		*put_env(t_data *data, char *str, int i);
char		*ft_quote(t_data *data, char *str, int i);

/*		 ft_cut_redirects		*/
int	ft_cut_redirects(t_data *data); // ret 1 si une redirection est trouvee, sinon ret 0
void	ft_create_redirects_token(t_data *data, int i); // cree le token de la commande redirect
t_token		*ft_here_doc(t_data *data, t_token *t); // fonction de gestion de '<<'


/*		ft_pre_parsing.c		*/
int		ft_is_input_safe(char *str); // verifie si le input respecte les demandes, telles que les quotes fermees
int		ft_verif_single_quote(char *str); // verifie la permeabilite des single quotes
int		ft_verif_double_quote(char *str); // verifie la permeabilite des double quotes

/*		ft_quote.c		*/
char	*ft_ret_double_quote(t_data *data, char *str, int incr); // renvoie la chaine entre double quote. Applique les $UN_TRUC si besoin
char	*ft_ret_dollar(t_data *data, char *str); // renvoie la valeur directe de var name, si str n'existe pas renvoie un null
char	*ft_ret_simple_quote(t_data *data, char *str, int incr); // renvoie la chaine entre simple quote. Applique PAS les $UN_TRUC si besoin


/*	**************	*/
/*		BUILTIN		*/
/*	**************	*/
// int		add_history(char *str, int param);
int		print_wd(void);
int		print_cd(char *path);
/*	ft_echo.c	*/
void	ft_echo(t_data *data, t_token *token); // commande echo

/*	ft_read_token_list.c	*/
t_token		*ft_read_token_list_while_pipe(t_data *data, t_token *t); // lecture des tokens dans les pipes
void	ft_read_token_list(t_data *data); // lecture des tokens
void	ft_launch_cmd(t_data *data, t_token *token); // lance une cmd
t_token	*ft_ret_last_token(t_data *data); // renvoie l'adresse du dernier token.
void	ft_print_token_list(t_data *data); // affiche tout les token
t_token		*ft_read_token_list_while_redir(t_data *data, t_token *tok); // lecture des tokens pendant des redirections
t_token		*ft_redirect_input(t_data *data, t_token *tok); // redirige l'entree standart sur un fichier.


int	ft_while_token(t_data *data); // lecture des tokens

/*	ft_pwd.c	*/
void	ft_pwd(t_data *data); // commande pwd

/*	ft_env.c	*/
void	ft_env(t_data *data, t_token *token); // commande env

/*	ft_unset.c	*/
void	ft_unset(t_data *data, t_token *token); // fonction principale de unset
char	*ft_unset_malloc_str(t_data *data, char *str); // renvoie une chaine de str

/*	ft_export.c	*/
void	ft_export_in_var(t_data *data, t_token *token, int i);  // verifie si le name est dans var et fais en fonction
void	ft_parse_export_name(t_data *data, t_token *token, int i); // parse et malloc dans token->arg le nom de la var. i est la position dans token->bin[i]
void	ft_export(t_data *data, t_token *token); // commande export

/*	ft_cd.c	*/
void	ft_cd(t_data *data, t_token *token);
void	ft_cd_home(t_data *data); // si cd renvoie sur son home
void	ft_cd_goto_path(t_data *data, char *path); // verifie la validitee du path et le stocke dans TOUT les endroits necesaires
void	ft_cd_from_data_to_var_opwd(t_data *data); // s'occupe de gerer opwd dans la structure var
void	ft_cd_from_data_to_var_pwd(t_data *data); // s'occupe de gerer pwd dans la structure var
void	ft_cd_goto_opwd(t_data *data, char *path); // execute la commande 'cd -'
/*	**********	*/
/*		VAR		*/
/*	**********	*/

/*	ft_var.c	*/
t_var	*ft_found_var_name(t_data *data, char *str); // permet de trouver et de renvoyer l'adresse de la var qui contient la string "str" dans name. si rien n'est trouver renvoie "NULL"
void	ft_disp_all_var(t_data *data, char sep, int export); // permet d'afficher toutes les variables stockees avec en option un separateur entre nom et value, si export vaut 1 alors considere que la commande export a ete lancee sans arguments

/*	ft_var_sort.c	*/
t_var	*ft_found_first_var(t_data *data); // cherche la premiere variable selon la table ascii



/*	**********	*/
/*		BIN		*/
/*	**********	*/

/*	ft_bin.c	*/
void	ft_test(t_data *data); // TEST

char	*ft_malloc_one_var(t_data *data, t_var *var); // malloc une ligne dans data->env
void	ft_malloc_var(t_data *data); // malloc et renvoie var dans un char **
int		ft_bin_path(t_data *data, t_var *var, t_token *tok, int i); // stocke et malloc un path dans token->arg
void	ft_is_bin(t_data *data, t_token *token); //
void	ft_bin_execve(t_data *data, t_token *token); //
void	ft_free_tab_char(char **str); // free un tableau de char
void	ft_arg_path_bin(t_data *data, t_token *token); // cherche si la string est un binaire


/*	**********	*/
/*	 Signals	*/
/*	**********	*/
void	handler();
void	init_signals(void);


/*	*******	*/
/*	 REDIR	*/
/*	*******	*/

/*	ft_pipe.c	*/
void	ft_pipe_out(t_data *data); // redirige la sortie de la prochaine commande dans le TMP_OUT
void	ft_pipe_in(t_data *data); // redirige l'entree de la prochaine commande dans le tmp_file
void	ft_pipe_close_data_fd(t_data *data, int	fd); // ferme le fd, si fd == 0 ferme out sinon in
void	ft_copy_fd(int fd_s, int fd_d); // copy le fd source dans le fd dest

/*	ft_in_file.c	*/
int		ft_create_open_file(t_data *data, char *name, int create); // cree ou ouvre un fichier. si create == 1 alors supprime le fichier. renvoie le fd du fichier ouvert.
void	ft_fd_redir(t_data	*data, int fd_in, int fd_out); // redirige la sortie ou l'entree en fonction de ce qu'on lui passe

#endif
