/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mourdani <mourdani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 10:59:30 by mourdani          #+#    #+#             */
/*   Updated: 2022/02/18 11:50:38 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	print_cd(char *path)
{
	if (chdir(path) < 0)
		perror("chdir() error");
	printf("yup, dir crated\n");
//	if (closedir(dir) == -1)
//		perror("closedir");
	return (1); //ok
}

int	cut_cd(t_data *data)
{
	char *command;
	int i;

	i = 0;
	command = "cd";
	while (ft_is_whitespace(data->input[i]))
		i++;
	if (ft_strncmp((data->input + i), command, 2) == 0)
		return(1);
	return (0);
}
