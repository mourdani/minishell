/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_li.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:28:00 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/10 05:28:01 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Writes ascii representation of number to file descriptor fd.
*/

void	ft_putnbr_li(long int number)
{
	ft_putnbr_base_li(number, DECIMAL_BASE);
}
