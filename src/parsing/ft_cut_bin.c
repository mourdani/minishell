/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut_bin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:45:12 by guderram          #+#    #+#             */
/*   Updated: 2022/06/01 07:34:15 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_cut_bin(t_data *data) // ret 1 si echo trouver, sinon ret 0. i est la tete de lecture ou demarre la lecture
{
	int	u;
	int i;

	i = 0;
	u = ft_bin_size(data);
	if (data->token == NULL)
		ft_init_token(data);
	else
		ft_add_new_token(data);
	data->token->cmd = 9;
	data->token->bin = malloc(sizeof(char*) * (u));
	data->token->bin[u] = NULL;
	u = 0;
	u = u + ft_space(data->input, data->i + u);
	data->token->arg = ft_src_in_dest(data, data->token->arg, ft_one_arg(data, u), 0);
	u = u + ft_space(data->input, data->i + u);
	// printf("BIN : data->token->arg : <%s>\n", data->token->arg);
	while (data->input[data->i + u] && ft_is_separator(data->input, data->i + u) == 0)
	{
		// printf("malloc builtin : debut while\n");
		u = u + ft_space(data->input, data->i + u);
		// printf("malloc builtin : one arg\n");
		data->token->bin[i] = ft_src_in_dest(data, NULL, ft_one_arg(data, u), 0);
		// printf("malloc builtin : incre one arg : u %d <%s>\n", u, &data->input[data->i + u]);
		u = ft_incre_one_arg(data, u);
		
		u = u + ft_space(data->input, data->i + u);
		// printf("malloc builtin : fin while : u %d <%s>\n", u, &data->input[data->i + u]);
		i++;
	}
	data->i = data->i + u;
	return (1);
}

int	ft_bin_size(t_data *data) // permet de malloc la strucure de bin
{
	int		u;
	int max = 0;
	int nbr = 0;

	u = 0;
	while (data->input[data->i + u] && ft_is_separator(data->input, data->i + u) == 0 && max < 20)
	{
		// printf("malloc builtin : debut while\n");
		u = u + ft_space(data->input, data->i + u);
		// printf("malloc builtin : one arg\n");
		// tok->arg = ft_src_in_dest(data, tok->arg, ft_one_arg(data, u), ' ');
		// printf("malloc builtin : incre one arg : u %d <%s>\n", u, &data->input[data->i + u]);
		u = ft_incre_one_arg(data, u);
		
		u = u + ft_space(data->input, data->i + u);
		// printf("malloc builtin : fin while : u %d <%s>\n", u, &data->input[data->i + u]);
		max ++;
		nbr++;
	}
	return (nbr);
	// printf("bin : nbr arg : %d\n", nbr);
	// data->i = data->i + u;
}
