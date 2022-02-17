/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:24:42 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/10 05:24:44 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Takes in a string and parses its digits characters into an integer.
*/

int	ft_atoi(const char *number_pointer)
{
	int	number;
	int	sign;
	int	previous_number;

	number = 0;
	sign = -1;
	previous_number = 0;
	while (ft_is_whitespace(*number_pointer))
		number_pointer++;
	if (ft_is_plus_or_minus(*number_pointer))
		if (*number_pointer++ == '-')
			sign = 1;
	while (ft_isdigit(*number_pointer))
	{
		number *= 10;
		number -= (*number_pointer++ - '0');
		if (previous_number < number)
		{
			if (sign < 0)
				return (-1);
			return (0);
		}
		previous_number = number;
	}
	return (number * sign);
}
