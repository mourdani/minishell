/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_valid_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 05:26:37 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/10 05:26:38 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

bool	ft_is_valid_base(const char *base, const size_t base_length)
{
	size_t	used_position;
	char	*used_characters;

	used_characters = malloc((base_length + 1) * sizeof(char));
	if (base_length == 0 || base_length == 1 || !used_characters)
		return (false);
	used_characters[0] = '\0';
	while (*base != '\0')
	{
		if (*base == '+' || *base == '-')
			return (false);
		used_position = 0;
		while (used_characters[used_position] != '\0')
		{
			if (used_characters[used_position] == *base)
				return (false);
			used_position++;
		}
		used_characters[used_position] = *base;
		used_characters[used_position + 1] = '\0';
		base++;
	}
	free(used_characters);
	return (true);
}
