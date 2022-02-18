/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 05:20:34 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/18 06:54:43 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	add_history(char *str, int param)
{
	static int	i;
	static char **history;
	int j;

	if (!history)
	{
		i = 0;
		history = malloc(sizeof(char *) * 100);
	}
	if (param == 1)
		history[i++] = ft_strdup(str);
	else if (param == 2) 
	{
		j = -1;
		while (++j < i)
			printf("%d\t%s\n", j,  history[j]);
	}
	return (0);
}

int	cut_history(t_data *data)
{
	char *command;
	int i;

	i = 0;
	command = "history";
	while (ft_is_whitespace(data->input[i]))
		i++;
	if (ft_strncmp((data->input + i), command, 7) == 0)
		return(1);
	return (0);
}
