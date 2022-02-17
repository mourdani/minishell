/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:28:31 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/10 05:28:33 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_strdel(char **delete_me)
{
	if (delete_me == NULL || *delete_me == NULL)
		return ;
	free(*delete_me);
	*delete_me = NULL;
}
