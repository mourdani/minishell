/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:27:02 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/10 05:27:03 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
** Counts how many nodes are in a list.
*/

int	ft_lstsize(t_list *lst)
{
	int	list_size;

	if (lst == NULL)
		return (0);
	list_size = 1;
	while (lst->next != NULL)
	{
		list_size++;
		lst = lst->next;
	}
	return (list_size);
}
