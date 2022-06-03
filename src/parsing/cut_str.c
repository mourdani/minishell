/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cut_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 23:51:35 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/24 12:05:30 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*cut_str(t_data *data, char *str)
{
	char *ret;
	char *quote;
	int	i;

	i = 0;
	ret = malloc(sizeof(char *));
	quote = malloc(sizeof(char *));
	if (!ret || !quote)
		return(NULL);
	ret = NULL;
	quote = NULL;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
			i++;
		if (str[i] == '\\' && (str[i+1] == ' ' || str[i+1] == '\\' || str[i+1] == '"' || str[i+1] == '\'' ||str[i+1] == '$')) // when \\ or \" or \$.
		{
			ret = ft_straddc(ret, str[i+1]);					// add second char after \.
			i += 2;									// increment i and data->i with 2.
		}
		if (str[i-1] != '\\' && (str[i] == '"' || str[i] == '\''))
		{
//			ret = ft_quote(data, str, i);
   			ret = ft_strjoin(ret, ft_quote(data, str, i));
			if (data->i == 0)
				return (NULL);
	    		i = data->i;
		}
		else 
		{
			if (str[i] == '$')
			{
				ret = ft_strjoin(ret, put_env(data, str, i));
				if (data->i == 0)
					return (NULL);
				i = data->i;
			}
			else
				ret = ft_straddc(ret, str[i++]);
		}
	}
	return (ret);
}
