/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:28:46 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/10 05:28:47 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Creates an allocated string joining s1 with s2.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_size;
	size_t	s1_size;
	char	*new_string;

	s1_size = ft_strlen(s1) + 1;
	total_size = s1_size + ft_strlen(s2);
	new_string = malloc(total_size * sizeof(char));
	if (new_string == NULL)
		return (NULL);
	ft_strlcpy(new_string, s1, s1_size);
	ft_strlcat(new_string, s2, total_size);
	return (new_string);
}
