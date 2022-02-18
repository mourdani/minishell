/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_a_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 05:52:44 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/18 05:57:27 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_is_a_b(char a, char b) // compare a et b, renvoie 1 si ils sont identiques sinon 0
{
	if (a == b)
		return (1);
	else
		return (0);
}
