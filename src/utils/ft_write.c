/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 05:07:01 by guderram          #+#    #+#             */
/*   Updated: 2022/02/11 16:42:35 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_putchar(char *c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_is_a_b(char a, char b) // compare a et b, renvoie 1 si ils sont identiques sinon 0
{
	if (a == b)
		return (1);
	else
		return (0);
}

int	ft_space(char *str, int i) // renvoie le nombre d espaces a sauter en partant de i
{
	int	u;

	u = 0;
	while (str[i + u] && str[i + u] == " ")
	{
		u++;
	}
	return (u);
}
