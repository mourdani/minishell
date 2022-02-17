/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:27:32 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/10 05:27:34 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Writes char c to file descriptor fd.
*/

void	ft_putchar(char c)
{
	ft_putchar_fd(c, STDOUT_FILENO);
}
