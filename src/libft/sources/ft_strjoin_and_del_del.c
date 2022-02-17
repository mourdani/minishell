/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_and_del_del.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:28:37 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/10 05:28:40 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin_and_del_del(char *delete_me, char *delete_me_too)
{
	size_t	total_size;
	size_t	delete_me_size;
	char	*new_string;

	delete_me_size = ft_strlen(delete_me) + 1;
	total_size = delete_me_size + ft_strlen(delete_me_too);
	new_string = malloc(total_size * sizeof(char));
	if (new_string == NULL)
	{
		ft_strdel(&delete_me);
		ft_strdel(&delete_me_too);
		return (NULL);
	}
	ft_strcpy(new_string, delete_me);
	ft_strlcat(new_string, delete_me_too, total_size);
	ft_strdel(&delete_me);
	ft_strdel(&delete_me_too);
	return (new_string);
}
