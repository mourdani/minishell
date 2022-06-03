/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:26:42 by mourdani          #+#    #+#             */
/*   Updated: 2022/05/26 11:28:24 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Transforms a number n into an allocated string.
*/

// static void	write_digits(char *string,
// 								unsigned int digit_count,
// 								unsigned int number,
// 								int is_negative)
// {
// 	string[digit_count] = '\0';
// 	while (digit_count--)
// 	{
// 		string[digit_count] = '0' + (number % 10);
// 		number /= 10;
// 	}
// 	if (is_negative)
// 		string[0] = '-';
// }

// char	*ft_itoa(int n)
// {
// 	unsigned int	digit_count;
// 	unsigned int	number;
// 	unsigned int	is_negative;
// 	char			*string;

// 	digit_count = ft_count_chars_i(n);
// 	number = (unsigned int)n;
// 	is_negative = 0;
// 	if (n < 0)
// 	{
// 		number *= -1;
// 		is_negative = 1;
// 	}
// 	string = malloc(sizeof(char) * (digit_count + 1));
// 	if (string == NULL)
// 		return (NULL);
// 	write_digits(string, digit_count, number, is_negative);
// 	return (string);
// }

static	int		ft_size(long nb)
{
	long	i;

	i = 1;
	if (nb == 0)
		return (2);
	if (nb < 0)
	{
		i++;
		nb = -nb;
	}
	while (nb > 0)
	{
		i++;
		nb = nb / 10;
	}
	return (i);
}

static	char	*ft_is_zero(void)
{
	char	*zero;

	if (!(zero = malloc(sizeof(char) * 2)))
		return (NULL);
	zero[0] = '0';
	zero[1] = '\0';
	return (zero);
}

static	char	*ft_strnb(long size, long nb)
{
	char	*str;
	long	i;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	if (nb < 0)
	{
		nb = -nb;
		size--;
	}
	size--;
	if (nb == 0)
		str = ft_is_zero();
	while ((size > 0) && (nb > 0))
	{
		str[i] = (nb % 10) + 48;
		nb = nb / 10;
		i++;
		size--;
		str[i] = '\0';
	}
	return (str);
}

char			*ft_itoa(int n)
{
	char	*str;
	char	*cpystr;
	long	i;
	long	size;

	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * ft_size((long)n))))
		return (NULL);
	cpystr = ft_strnb(ft_size((long)n), (long)n);
	size = ft_size((long)n) - 1;
	if (n < 0)
	{
		str[i] = 45;
		i++;
		size--;
	}
	while (size > 0)
	{
		str[i] = cpystr[ft_size((long)n) - (i + 2)];
		i++;
		size--;
	}
	str[i] = '\0';
	return (str);
}
