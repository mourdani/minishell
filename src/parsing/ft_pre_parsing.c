/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_parsing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 23:15:08 by guderram          #+#    #+#             */
/*   Updated: 2022/06/01 07:56:08 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int		ft_is_input_safe(char *str) // verifie si le input respecte les demandes, telles que les quotes fermees
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\"')
		{
			i++;
			while (str[i] && str[i] != '\"')
				i++;
			if (str[i] == '\0')
				return (0);
		}
		else if (str[i] == '\'')
		{
			i++;
			while (str[i] && str[i] != '\'')
				i++;
			if (str[i] == '\0')
				return (0);
		}
		else if (str[i] == '\\')
			return(0);
		else if (str[i] == ';')
			return(0);
		i++;
	}
	return (1);
}

int		ft_verif_single_quote(char *str) // verifie la permeabilite des single quotes
{
	int	i;
	int sq;
	int dq;
	
	i = 0;
	sq = 0;
	dq = 0;
	while (str[i])
	{
		if (str[i] == '\'' && sq == 0)
		{printf("1 ");
			sq = 1;}
		else if (str[i] == '\'' && sq == 1)
		{printf("2 ");
			dq = 0;
			sq = 0;
		}
		else if (str[i] == '\"' && sq == 1)
		{printf("3 ");
			dq = 1;
		}
		i++;
	}
	if (dq == 1)
		return (dq);
	return (sq);
}

int		ft_verif_double_quote(char *str) // verifie la permeabilite des double quotes
{
	int	i;
	int dq;
	int	sq;
	
	i = 0;
	dq = 0;
	sq = 0;
	while (str[i])
	{
		if (str[i] == '\"' && dq == 0)
			dq = 1;
		else if (str[i] == '\"' && dq == 1)
		{
			sq = 0;
			dq = 0;
		}
		else if (str[i] == '\'' && dq == 1)
			sq = 1;
		i++;
	}
	if (sq == 1)
		return (sq);
	return (dq);
}

