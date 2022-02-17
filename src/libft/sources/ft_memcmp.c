/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:27:10 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/10 05:27:11 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Compares n bytes after s1 with the n bytes after s2.
** If any are different it returns the difference.
*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*first_cast;
	unsigned char	*second_cast;

	first_cast = (unsigned char *)s1;
	second_cast = (unsigned char *)s2;
	while (n--)
	{
		if (*first_cast != *second_cast)
			return (*first_cast - *second_cast);
		first_cast++;
		second_cast++;
	}
	return (0);
}
