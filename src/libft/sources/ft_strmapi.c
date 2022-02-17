/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:28:53 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/10 05:28:55 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Returns an allocated string with each char modified by f.
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*map_start;
	char	*map;

	map_start = ft_strdup(s);
	if (map_start == NULL)
		return (NULL);
	map = map_start;
	while (*map)
	{
		*map = f(map - map_start, *map);
		map++;
	}
	return (map_start);
}
