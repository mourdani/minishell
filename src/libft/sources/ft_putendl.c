/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:27:36 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/10 05:27:38 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Writes string s to file descriptor fd followed by an endline.
*/

void	ft_putendl(char *s)
{
	ft_putstr(s);
	ft_putchar('\n');
}
