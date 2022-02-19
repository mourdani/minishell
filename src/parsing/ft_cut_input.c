/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 16:06:50 by guderram          #+#    #+#             */
/*   Updated: 2022/02/19 09:34:13 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_parse_input(t_data *data) // return 0 si ok, sinon 1 ou numero specifique a l'erreur
{
	int	found;

	found = 0;
	if (cut_history(data) == 1) // checks if command entered is "history and creates token"
		found++;
	else 
		add_history(data->input, 1); //adds line to history
	if (cut_env(data))
		found++;
	while (data->input[data->i])
	{
		ft_space(data->input, data->i);
//		if (ft_cut_echo(data, data->i) == 1)
//			found++;
		if (ft_cut_pwd(data) == 1)
			found++;
		if (ft_cut_export(data) == 1)
			found++;
		data->i += 1;
	}
	if (found == 0)
	{
		printf("minishell : command not found : %s\n", data->input);
		return (1); // pas de commande trouvee
	}
	return (0);
}
