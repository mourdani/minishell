/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:27:07 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/10 05:27:09 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Scans first n bytes after s for c. Returns c's position if it finds it.
** Returns NULL otherwise.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*string_cast;

	string_cast = (unsigned char *)s;
	while (n--)
	{
		if (*string_cast == (unsigned char)c)
			return (string_cast);
		string_cast++;
	}
	return (NULL);
}
