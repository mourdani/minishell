/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_i_to_buffer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:26:44 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/10 05:26:45 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Transforms a number n into an allocated string.
*/

static void	write_digits(char *string,
								unsigned int char_count,
								unsigned int number,
								int is_negative)
{
	string[char_count] = '\0';
	while (char_count--)
	{
		string[char_count] = '0' + (number % 10);
		number /= 10;
	}
	if (is_negative)
		string[0] = '-';
}

unsigned int	ft_i_to_buffer(int n, char *buffer)
{
	unsigned int	char_count;
	unsigned int	number;
	unsigned int	is_negative;

	char_count = ft_count_chars_i(n);
	number = (unsigned int)n;
	is_negative = 0;
	if (n < 0)
	{
		number *= -1;
		is_negative = 1;
	}
	write_digits(buffer, char_count, number, is_negative);
	return (char_count);
}
