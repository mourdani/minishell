/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 10:49:06 by guderram          #+#    #+#             */
/*   Updated: 2022/06/01 08:00:44 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_pipe_out(t_data *data) // redirige la sortie de la prochaine commande dans le TMP_OUT
{
	int		fd_out;
	
	fd_out = open(TMP_OUT, O_CREAT, 00777);
	close(fd_out);
	fd_out = open(TMP_OUT, O_RDWR);
	ft_fd_redir(data, -10, fd_out);
}

void	ft_copy_fd(int fd_s, int fd_d) // copy le fd source dans le fd dest
{
	char	buff[2];

	buff[1] = '\0';
	while(read(fd_s, buff, 1) > 0)
	{
		write(fd_d, buff, 1);
	}
}

void	ft_pipe_in(t_data *data) // redirige l'entree de la prochaine commande dans le tmp_file
{
	int		out;
	int		fd_in;

	out = open(TMP_OUT, O_RDWR);
	unlink(TMP_IN);
	fd_in = open(TMP_IN, O_CREAT | O_RDWR | O_APPEND, 00777);
	if (fd_in > 0)
		ft_copy_fd(out, fd_in);
	close(out);
	close(fd_in);
	fd_in = open(TMP_IN, O_CREAT | O_RDWR | O_APPEND, 00777);
	ft_fd_redir(data, fd_in, -10);
}

void	ft_pipe_close_data_fd(t_data *data, int	fd) // ferme le fd, si fd == 0 ferme out sinon in
{
	
	if (fd == 1 || fd == 3)
	{
		close(data->pipe->fd_o);
		data->pipe->fd_o = -10;
		dup2(data->pipe->ofd_o, 1);
		close(data->pipe->ofd_o);
		data->pipe->ofd_o = -10;
	}
	if (fd == 0 || fd == 3)
	{
		close(data->pipe->fd_i);
		data->pipe->fd_i = -10;
		dup2(data->pipe->ofd_i, 0);
		close(data->pipe->ofd_i);
		data->pipe->ofd_i = -10;
	}
}
