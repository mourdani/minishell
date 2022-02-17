/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:28:18 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/10 05:28:19 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_skip_number(char *digits)
{
	while (ft_is_plus_or_minus(*digits))
		digits++;
	while (ft_isdigit(*digits))
		digits++;
	return (digits);
}
