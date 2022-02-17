/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:29:01 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/10 05:29:02 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Returns last occurence of char c in string or NULL.
*/

char	*ft_strrchr(const char *s, int c)
{
	char	*s_end;

	s_end = ft_strchr(s, '\0');
	while (*s_end != (char)c)
		if (s_end-- == s)
			return (NULL);
	return ((char *)s_end);
}
