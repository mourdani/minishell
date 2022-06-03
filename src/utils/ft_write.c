/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 05:07:01 by guderram          #+#    #+#             */
/*   Updated: 2022/03/24 11:13:46 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

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
	while (str[i + u] && str[i + u] == ' ')
	{
		u++;
	}
	return (u);
}

void	ft_print_one_var(t_var *var) // affiche le contenu d'une var pour export sans arg
{
		ft_putstr("declare -x ");
		ft_putstr(var->name);
		ft_putchar('=');
		ft_putchar('"');
		ft_putstr(var->value);
		ft_putchar('"');
		ft_putchar('\n');
}

int		ft_str_comp_ascii(char *str1, char *str2) // compare les deux chaines de caracteres et renvoie celle qui est premiere celon la table ascii
{
	int	i;

	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	if (str1[i] < str2[i])
		return (1); // premiere chaine inferieure
	else
		return (2); // seconde chaine inferieure
}
