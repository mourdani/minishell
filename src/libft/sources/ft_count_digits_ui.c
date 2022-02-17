/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digits_ui.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:25:45 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/10 05:25:48 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

unsigned int	ft_count_digits_ui(unsigned int number)
{
	int	digit_count;

	digit_count = 1;
	while (number)
	{
		number /= 10;
		digit_count++;
	}
	return (digit_count);
}
