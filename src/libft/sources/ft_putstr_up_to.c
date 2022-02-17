/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_up_to.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:28:12 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/10 05:28:13 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Writes string s to file descriptor fd without null terminator.
*/

void	ft_putstr_up_to(char *s, size_t up_to)
{
	size_t	control;

	control = 0;
	if (s == NULL)
		return ;
	while (s[control] != '\0' && control < up_to)
		ft_putchar(s[control++]);
}
