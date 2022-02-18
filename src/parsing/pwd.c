/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 07:52:00 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/18 11:14:03 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	print_wd(void)
{
	char *cwd;

	cwd = getcwd(NULL, 0);
	if (!cwd) // get working dir and put it in "cwd" of size 256.
	{
		perror("error getting current dit!\n");
		return (0); // error
	}
	else 
	{
		printf("%s\n", cwd);
		free(cwd);
	}
	return (1); //ok
}

int	cut_pwd(t_data *data)
{
	char *command;
	int i;

	i = 0;
	command = "pwd";
	while (ft_is_whitespace(data->input[i]))
		i++;
	if (ft_strncmp((data->input + i), command, 3) == 0)
		return(1);
	return (0);
}
