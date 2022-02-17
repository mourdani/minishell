/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_and_free.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:28:42 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/10 05:28:43 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin_and_free(char *free_me, char const *dont_free_me)
{
	size_t	total_size;
	size_t	free_me_size;
	char	*new_string;

	free_me_size = ft_strlen(free_me) + 1;
	total_size = free_me_size + ft_strlen(dont_free_me);
	new_string = malloc(total_size * sizeof(char));
	if (new_string == NULL)
	{
		free(free_me);
		return (NULL);
	}
	ft_strcpy(new_string, free_me);
	ft_strlcat(new_string, dont_free_me, total_size);
	free(free_me);
	return (new_string);
}
