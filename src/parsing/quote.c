/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:04:56 by mourdani          #+#    #+#             */
/*   Updated: 2022/05/04 19:47:55 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*put_env(t_data *data, char *str, int i)
{
	char	*env;
	char	*env_val;
	t_var	*var;

	env = malloc(sizeof(char *));
	env_val = malloc(sizeof(char *));
	if (!env || !env_val)
		return(NULL);
	env = NULL;
	env_val = NULL;
	i++;
	while (str[i] != '"' && str[i]
	!= ' ' && str[i] != '\t' && str[i])
	{
		env = ft_straddc(env, str[i]);
		i++;
	}
	env = ft_straddc(env, '\0');
	var = ft_found_var_name(data, env);
	if (!var)
	{
		data->i = i;
		return (NULL);
	}
	env_val = var->value;
	if (!env_val || !var)		// if env variable doesnt exist.
	{
		data->i = 0;
		return (NULL);
	}
	data->i = i;
	return (env_val);
}

int	check_q_number(char q, char *str)     // checks validity of quotes (pair number of valid quotes)
{
	int i;
	int n;			//number of quotes

	i = -1;
	n = 0;
	while (str[++i])
	{
		if (str[i] == '\\' && (str[i+1] == '\\' || str[i+1] == q || str[i+1] == '$'))
			i += 2;
		if (str[i] == q)
			n++;
	}
	if (n % 2)
	{
		printf("dquote>\n");
		return (1);
	}
	return (0);
}

char	*s_quote(t_data *data, char *str, int i) // converts what's inside single quotes
{
	char	*unq;

	unq = malloc(sizeof(char *));
	if (!unq)
		return(NULL);
	unq = NULL;
	i++;
	if (str[i] == '\\' && str[i+1] == '0')
		i +=2;
	while (str[i] && str[i] != '\'')
		unq = ft_straddc(unq, str[i++]);
	unq = ft_straddc(unq, '\0');
	data->i = ++i;
	return (unq);
}

char	*d_quote(t_data *data, char *str, int i)  // converts what's inside double quotes
{
	char	*unq;

	unq = malloc(sizeof(char *));
	if (check_q_number('"', str) == 1)
		return(NULL);
	unq = NULL;
	i++;
	while (str[i] && str[i] != '"')
	{
		while (str[i] == '\\' && (str[i+1] == '\\'
			|| str[i+1] == '"' || str[i+1] == '$')) // when \\ or \" or \$.
		{
			unq = ft_straddc(unq, str[i+1]);					// add second char after \.
			i += 2;									// increment i and data->i with 2.
		}
		if (str[i] == '$')							
		{
			unq = ft_strjoin(unq, put_env(data, str, i));
			if (data->i == 0)
				return (NULL);
			i = data->i;
		}
		else 
			unq = ft_straddc(unq, str[i++]);
	}
	data->i = ++i;
	i = 0;
	if (unq)
	{
		while (unq[i])
			i++;
		if (unq[i] != '\0')
			unq = ft_straddc(unq, '\0');
	}
	else
		unq = ft_straddc(unq, '\0');
	return (unq);
}

char	*ft_quote(t_data *data, char *str, int i)
{
	char *unq; // new unquoted string

	unq = NULL;
	if (str[i] == '"')			// if first character of str is " enter d_quote();
		unq = d_quote(data, str, i);
	else if (str[i] == '\'')		// if first character of str is ' enter s_quote();
		unq = s_quote(data, str, i);
	i = data->i;
	return (unq);
}
