/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:27:05 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/10 05:27:06 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Copies upto to n bytes from src to dest, stopping at c if it finds it.
** Not overlap safe.
*/

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*source_cast;
	unsigned char	*destination_cast;

	if (dest == NULL && src == NULL)
		return (NULL);
	source_cast = (unsigned char *)src;
	destination_cast = (unsigned char *)dest;
	while (n--)
	{
		*destination_cast = *source_cast;
		if (*source_cast == (unsigned char)c)
			return (++destination_cast);
		destination_cast++;
		source_cast++;
	}
	return (NULL);
}
