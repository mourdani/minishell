/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_straddc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:51:32 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/21 18:26:45 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_straddc(char *s, char c)
{
	char	*s_new;
	int		len;

	if (s)
		len = ft_strlen(s);
	else
		len = 0;
	s_new = malloc(len + 2);
	if (!s_new)
		return (NULL);
	if (s)
	{
		ft_memcpy(s_new, s, len);
		free(s);
	}
	s_new[len] = c;
	s_new[len + 1] = 0;
	return (s_new);
}
