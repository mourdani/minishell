/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 14:46:04 by guderram          #+#    #+#             */
/*   Updated: 2022/05/26 19:37:35 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int		ft_create_open_file(t_data *data, char *name, int create) // cree ou ouvre un fichier. si create == 1 alors supprime le fichier. renvoie le fd du fichier ouvert.
{
	int	fd;

	// fd = -1;
	// printf("create open file : name <%s>\n", name);
	if (create == 1)
		unlink(name);
	fd = open(name, O_CREAT | O_RDWR | O_APPEND, 00777);
	if (fd < 0)
	{
		// printf("ft_create_open_file ERREUR : OPEN CRASH\n");
		data->err = 1234;
	}
	return (fd);
}

void	ft_fd_redir(t_data	*data, int fd_in, int fd_out) // redirige la sortie ou l'entree en fonction de ce qu'on lui passe
{
	if (fd_in > 0)
	{
		// printf("ft_fd_redir : fd_in %d\n", fd_in);
		data->pipe->ofd_i = dup(0);
		data->pipe->fd_i = fd_in;
		dup2(data->pipe->fd_i, 0);
	}
	if (fd_out > 0)
	{
		// printf("ft_fd_redir : fd_out %d\n", fd_out);
		data->pipe->ofd_o = dup(1);
		data->pipe->fd_o = fd_out;
		dup2(data->pipe->fd_o, 1);
	}
}
