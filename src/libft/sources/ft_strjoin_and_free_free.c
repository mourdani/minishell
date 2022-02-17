/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_and_free_free.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:28:44 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/10 05:28:45 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin_and_free_free(char *free_me, char *free_me_too)
{
	size_t	total_size;
	size_t	free_me_size;
	char	*new_string;

	free_me_size = ft_strlen(free_me) + 1;
	total_size = free_me_size + ft_strlen(free_me_too);
	new_string = malloc(total_size * sizeof(char));
	if (new_string == NULL)
	{
		free(free_me);
		free(free_me_too);
		return (NULL);
	}
	ft_strcpy(new_string, free_me);
	ft_strlcat(new_string, free_me_too, total_size);
	free(free_me);
	free(free_me_too);
	return (new_string);
}
