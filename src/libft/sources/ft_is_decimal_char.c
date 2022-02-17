/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_decimal_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:26:23 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/10 05:26:24 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

bool	ft_is_decimal_char(char character)
{
	if (ft_isdigit(character))
		return (true);
	if (ft_is_plus_or_minus(character))
		return (true);
	return (false);
}
