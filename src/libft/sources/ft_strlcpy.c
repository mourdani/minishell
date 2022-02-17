/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:28:49 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/10 05:28:51 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Copy first size chars from src to dst. Not overlap safe.
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	char			current_char;
	unsigned int	iterator;

	if (src == NULL)
		return (0);
	if (size > 0)
	{
		iterator = 0;
		current_char = src[iterator];
		while (current_char != '\0' && iterator < (size - 1))
		{
			dst[iterator] = current_char;
			iterator++;
			current_char = src[iterator];
		}
		dst[iterator] = '\0';
	}
	return (ft_strlen(src));
}
