/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:28:55 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/10 05:28:56 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Returns first occurence of char c in string up to limit or NULL.
*/

char	*ft_strnchr(const char *s, int c, unsigned int limit)
{
	unsigned int	current;

	current = 0;
	while (s[current] != (char)c)
	{
		if (s[current] == '\0' || current >= limit)
			return (NULL);
		current++;
	}
	return ((char *)(s + current));
}
