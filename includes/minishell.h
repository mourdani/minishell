/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 19:35:41 by guderram          #+#    #+#             */
/*   Updated: 2022/02/11 03:17:52 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h> // WRITE
# include <stdio.h> // PRINTF
# include <stdlib.h> // MALLOC FREE

# define BUFFER_SIZE_GNL 128

/*	***********	*/
/*	   data		*/
/*	***********	*/

typedef struct p_data
{
	int				err;
	struct p_token	*first;
}				t_data;

/*	**************	*/
/*		token		*/
/*	**************	*/

typedef struct p_token
{
	int	cmd; // correspond a la fonctionn geree par minishell
	int	option; // correspond a l'option de la commande precedente
	char	*str; // correspond a la string gerer par cmd
	struct p_token	*next; // prochain token
	struct p_token	*prev; // precedent token
	
}				t_token;

/*	**********	*/
/*		GNL		*/
/*	**********	*/

/*	get_next_line.c	*/
int	get_next_line(int fd, char **line);
int	get_next_line_bis(int error, int ret, char *str);
void	ft_read(char **str, char **line, int ret, int *error);
char	*ft_strsub(char const *s, unsigned int start, size_t len, int **error);
char	*ft_strsub_bis(int **error);

/*	get_next_line_bis.c	*/
int	ft_exerror(char **str, int error);
void	ft_strdel(char **as);

/*	get_next_line_utils.c	*/
void	ft_strjoin(char **str, const char *buff, int buff_size, int *error);
int	ft_strcount(char *str);
int	ft_strchr(char *str);
char	*ft_strnew(int *error);
int	ft_strlen(char *str);


/*	*************	*/
/*		UTILS		*/
/*	*************	*/

/*	ft_token.c	*/
void	ft_init_token(t_data *data); // initialise la liste
void	ft_add_new_token(t_data *data); // cree une nouvelle liste et la met au debut de la stack
void	ft_free_token(t_data *data, t_token *token); // free les mallocs dans une liste
void	ft_delete_token(t_data *data, t_token *delete); // supprime la tokene en relian si besoin les autres


#endif
