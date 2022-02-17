/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:27:23 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/10 05:27:24 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Set the memory from s to s + n to an unsigned char c.
*/

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*pointerator;
	unsigned char	casted_char;

	pointerator = s;
	casted_char = (unsigned char)c;
	while (n--)
	{
		*pointerator = casted_char;
		pointerator++;
	}
	return (s);
}
