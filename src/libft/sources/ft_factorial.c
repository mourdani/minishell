/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:26:04 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/10 05:26:06 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_factorial(int number)
{
	int	factorial;

	if (number < 0)
		return (0);
	if (number == 0 || number == 1)
		return (1);
	factorial = number * ft_factorial(number - 1);
	return (factorial);
}
