/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:26:13 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/10 05:26:15 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Checks if c is an ASCII letter.
*/

bool	ft_isalpha(int c)
{
	return (ft_isupper(c) || ft_islower(c));
}
