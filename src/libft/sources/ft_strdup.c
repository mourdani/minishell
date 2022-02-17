/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:28:33 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/10 05:28:35 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Creates an allocated string with the same chars of s.
*/

char	*ft_strdup(const char *s)
{
	size_t	original_size;
	char	*new_string;

	original_size = ft_strlen(s) + 1;
	new_string = malloc((original_size) * sizeof(char));
	if (new_string == NULL)
		return (NULL);
	ft_memcpy(new_string, s, original_size);
	return (new_string);
}
