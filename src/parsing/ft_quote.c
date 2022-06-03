/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quote.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 03:50:34 by guderram          #+#    #+#             */
/*   Updated: 2022/05/20 15:27:15 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*ft_ret_simple_quote(t_data *data, char *str, int incr) // renvoie la chaine entre simple quote. Applique PAS les $UN_TRUC si besoin
{
	int		i;
	char	*ret;

	i = 1;
	while (str[i] && str[i] != '\'')
		i++;
	if (incr == 1) // choisi ou pas d'incrementer data->i
		data->i = data->i + i;
	ret = ft_malloc_str(data, i);
	i = 1;
	while (str[i] && str[i] != '\'')
	{
		ret[i - 1] = str[i];
		i++;
	}
	ret[i - 1] = '\0';
	// printf ("ret smp quote <%s>\n", ret);
	return (ret);
}

char	*ft_ret_double_quote(t_data *data, char *str, int incr) // renvoie la chaine entre double quote. Applique les $UN_TRUC si besoin
{
	int		i;
	int 	u; // pour le malloc
	char	*ret;
	char	*tmp;

	// printf("double quote : entree\n");
	u = 0; // car ne prend pas le premier < " > dans le malloc
	i = 1; // pour skip le premier < " >
	// printf("double quote : str <%s>\n", str);
	while (str[i] && str[i] != '\"')
		i++;
	if (incr == 1) // choisi ou pas d'incrementer data->i
		data->i = data->i + i; // incre data avant tout pour pas bugger 
	i = 1;
	while (str[i] && str[i] != '\"')
	{
		if (str[i] == '$' && str[i + 1] == '"')
		{
			u = u + 1;
			// printf ("NON JEAN MICH\n");
			// tmp = malloc(sizeof(char*) * (2));
			// tmp[0] = '$';
			// tmp[1] = '\0';
			// return (tmp);
		}
		if (str[i] == '$')
		{
			// i++;
			// printf("dbl q if dol u %d i %d str[i] <%s>\n", u, i, &(str[i]));
			// printf ("TAILLER DU TRUC %d\n", ft_str_size(ft_ret_dollar(data, &str[i])));
			tmp = ft_ret_dollar(data, &str[i]);
			// printf("dbl q if dol tmp <%s>\n", tmp);
			// printf("u : %d tmp : %d\n",u , ft_str_size(tmp));
			u = u + ft_str_size(tmp);
			// printf("bro\n");
			ft_strdel(&tmp);
			// printf("dbl q if dol u <%d>\n", u);
			i++;
			while (str[i] && str[i] != ' ' && str[i] != '$' && ft_is_separator(str, i) == 0 && str[i] != '\"')
				i++;
			// printf("dbl q if dol end u %d i %d str[i] <%s>\n", u, i, &(str[i]));
		}
		else
		{
			u++;
			i++;
		}
	}
	// printf("dbl q size <%d>\n", u);
	ret = ft_malloc_str(data, u);
	// printf("double quote : ret : %d, u %d\n", ft_str_size(ret), u);
	i = 1;
	u = 0;
	// printf ("double quote : while remplissage :\n");
	// printf("----malloc ret ok----\n");
	// printf ("str <%s>\n", str);
	while (str[i] && str[i] != '\"')
	{
		// if (str[i] == '$' && str[i + 1] == '"')
		// {
		// 	tmp = malloc(sizeof(char*) * (2));
		// 	tmp[0] = '$';
		// 	tmp[1] = '\0';
		// 	return (tmp);
		// }
		// printf("<%c>\n", str[i]);
		if (str[i] == '$' && str[i + 1] != '"')
		{
			// printf ("LE PREMIER\n");
			// i++;
			// printf("dbl q if dol u <%d> str[i] <%s>\n", u, &(str[i]));
			tmp = ft_ret_dollar(data, &str[i]);
			// printf("dbl q if dol tmp <%s>\n", tmp);
			// if (ft_str_size(ret) > 0)
			ret = ft_strcpy(ret, tmp); // TEST DU COUP
			// printf("bro\n");
			// ft_copie_dest_src(data->token, tmp); // ICI LE PB GUILLAUME // merci guillaume du passé
			u = u + ft_str_size(tmp);
			ft_strdel(&tmp);
			// printf("dbl q if dol u <%d>\n", u);
			// ft_copie_dest_src(data->token, ft_ret_dollar(data, &str[i]));
			// u = u + ft_str_size(ft_ret_dollar(data, &str[i]));
			i++;
			while (str[i] && str[i] != ' ' && str[i] != '$' && ft_is_separator(str, i) == 0 && str[i] != '\"')
				i++;
		}
		else if (str[i] == '$' && str[i + 1] == '"')
		{
			// printf ("LE SECOND\n");
			tmp = malloc(sizeof(char*) * (2));
			tmp[0] = '$';
			tmp[1] = '\0';
			ret = ft_strcpy(ret, tmp); // TEST DU COUP
			u = u + 1;
			ft_strdel(&tmp);
			i++;
		}
		else
		{
			// printf ("double quote : else : <%s>\n", ret);
			ret[u] = str[i];
			u++;
			i++;
			// printf ("double quote : else : <%s>\n", ret);
		}
	}
	printf("\n");
	ret[u] = '\0';
	// printf("double quote : exit \n");
	// printf ("double quote : fin ret : <%s>\n", ret);
	return (ret);
}


// char	*ft_stra_strb()

char	*ft_ret_dollar(t_data *data, char *str) // renvoie la valeur directe de var name, si str n'existe pas renvoie un null
{
	int		i;
	char	*ret;
	t_var	*var;

	i = 1;
	// printf ("ret dollar str <%s>\n\n", str);
	if (str[1] == '\0' || str[1] == ' ' || str[1] == '\'' || str[1] == '\"')
	{
		ret = malloc(sizeof(char*) * (2));
		ret[0] = '$';
		ret[1] = '\0';
		return(ret);
	}
	// printf("ret dollard\n");
	// printf("i : %d\n", i);
	while (str[i] && str[i] != ' ' && str[i] != '$' && ft_is_separator(str, i) == 0 && str[i] != '\'' && str[i] != '\"')
		i++;
	// printf("i : %d\n", i);
	// printf ("dol i <%d>\n", i);
	ret = ft_malloc_str(data, i);
	i = 1;
	// ret[0] = '$';
	while (str[i] && str[i] != ' ' && str[i] != '$' && ft_is_separator(str, i) == 0 && str[i] != '\'' && str[i] != '\"')
	{
		// printf("ret <%c> str <%c>\n", ret[i], str[i]);
		ret[i - 1] = str[i];
		i++;
	}
	ret[i - 1] = '\0';
	// printf ("size of ret %d\n", ft_str_size(ret));
	if (ft_str_size(ret) == 0)
	{
		// printf("GGGGGGGGG ret == 0, <%s>\n", ret);
		return(ret);
	}
	// printf ("doll fin i <%d> ret[i] <%s>\n", i, &(str[i]));
	// printf ("dol ret <%s>\n", ret);
	var = ft_found_var_name(data, ret);
	//printf ("var N <%s> V <%s>\n", var->name, var->value);
	if (var == NULL)
	{
		// printf ("NO VAR FOUND\n");
		return (NULL);
	}
	// printf ("var N <%s> V <%s>\n", var->name, var->value);
	ft_strdel(&ret);
	ret = ft_malloc_str(data, ft_str_size(var->value));
	i = 0;
	while (var->value[i])
	{
		ret[i] = var->value[i];
		i++;
	}
	
	ret[i] = '\0';
	// printf("RET DOLL OK\n");
	return (ret);
}
