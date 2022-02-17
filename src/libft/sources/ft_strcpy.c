/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:28:29 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/10 05:28:31 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strcpy(char *dest, char *src)
{
	char	*initial_destination;

	initial_destination = dest;
	while (*src != '\0')
		*dest++ = *src++;
	*dest = '\0';
	return (initial_destination);
}
