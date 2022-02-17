/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:26:42 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/10 05:26:43 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Transforms a number n into an allocated string.
*/

static void	write_digits(char *string,
								unsigned int digit_count,
								unsigned int number,
								int is_negative)
{
	string[digit_count] = '\0';
	while (digit_count--)
	{
		string[digit_count] = '0' + (number % 10);
		number /= 10;
	}
	if (is_negative)
		string[0] = '-';
}

char	*ft_itoa(int n)
{
	unsigned int	digit_count;
	unsigned int	number;
	unsigned int	is_negative;
	char			*string;

	digit_count = ft_count_chars_i(n);
	number = (unsigned int)n;
	is_negative = 0;
	if (n < 0)
	{
		number *= -1;
		is_negative = 1;
	}
	string = malloc(sizeof(char) * (digit_count + 1));
	if (string == NULL)
		return (NULL);
	write_digits(string, digit_count, number, is_negative);
	return (string);
}
