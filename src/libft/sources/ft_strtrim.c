/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:29:03 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/10 05:29:04 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Removes set from beginning and end of s1.
*/

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	trimmed_end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	trimmed_end = ft_strlen(s1);
	while (trimmed_end && ft_strchr(set, s1[trimmed_end]))
		trimmed_end--;
	return (ft_substr(s1, 0, trimmed_end + 1));
}
