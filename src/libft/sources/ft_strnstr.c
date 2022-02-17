/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:28:59 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/10 05:29:00 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Finds the first occurence of needle in haystack up to length.
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*haystack_start;
	char	*needle_pointerator;
	char	*possible_match;

	haystack_start = (char *)haystack;
	if (*needle == '\0')
		return (haystack_start);
	while (*haystack)
	{
		needle_pointerator = (char *)needle;
		possible_match = (char *)haystack;
		while (*needle_pointerator && *haystack
			== *needle_pointerator && (unsigned long)
			(haystack - haystack_start) < len)
		{
			needle_pointerator++;
			haystack++;
		}
		if (*needle_pointerator == '\0')
			return (possible_match);
		haystack = possible_match + 1;
	}
	return (NULL);
}
