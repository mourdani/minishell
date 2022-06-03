/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 09:56:24 by guderram          #+#    #+#             */
/*   Updated: 2022/06/01 07:47:59 by mourdani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	ft_is_separator(char *str, int i) // renvoie 0 si "c" n'est pas un separateur, sinon son code specifique
{
	if (str[i] == ';') // ; 1
		return (1);
	if (str[i] == '|') // | 2
		return (2);
	if (str[i] == '>' && str[i + 1] != '>') // > 3
		return (3);
	if (str[i] == '<' && str[i + 1] != '<') // < 4
		return (4);
	if (str[i] == '>' && str[i + 1] == '>') // >> 5
		return (5);
	if (str[i] == '<' && str[i + 1] == '<') // << 6
		return (6);
	return (0);
}

char	*ft_malloc_str(t_data *data, int i) // malloc un str de taille i, le renplie de \0 et le return
{
	char	*str;
	int		u;

	u = 0;
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
	{
		data->err = 100;
		return (NULL);
	}
	while (u < i)
	{
		str[u] = '\0';
		u++;
	}
	str[u] = '\0';
	return (str);
}

void	ft_str_join_input(t_data *data, int i, int max) // malloc en recuperant la chaine token->str + la chaine input entre i et i + m
{
	int	u;
	char	*tmp;

	u = 0;
	while (data->token->arg[u])
		u++;
	tmp = ft_malloc_str(data, (u + max));
	u = 0;
	while (data->token->arg[u])
	{
		tmp[u] = data->token->arg[u];
		u++;
	}
	while (max > 0)
	{
		tmp[u] = data->input[i];
		u++;
		i++;
		max--;
	}
	ft_strdel(&data->token->arg);
	data->token->arg = tmp;
}


char	*ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	// printf("strncpy : %d\n", n);
	// printf("strncpy 1 : %s\n", dest);
	while ((src[i]) && (i < n))
	{
		dest[i] = src[i];
		i++;
	}
	// printf("strncpy 2 : %s\n", dest);
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	// printf("strncpy 3 : %s\n", dest);
	return (dest);
}

int		ft_str_size(char *str) // renvoie la taille d'un str
{
	int	i;

	i = 0;
	// printf("str size entree <%p>\n", str);
	if (str == NULL)
		return (0);
	// printf("str size mid\n");
	while (str != NULL && str[i] && str[i] != '\0')
		i++;
	// printf("str size sortie\n");
	return (i);
}

int		ft_check_char(char *str, char c, int max) // verifie si c est dans str avec max
{
	int	i;

	i = 0;
	while (str[i] && i < max)
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_str_comp(char *str1, char *str2) // compare les deux strings, renvoie 1 si strictement identiques, sinon 0.
{
	if (ft_strncmp(str1, str2, ft_strlen(str1)) == 0
		&& ft_strncmp(str1, str2, ft_strlen(str2)) == 0)
		return (1);
	return (0);
}

int		ft_str_after_cut(char *str) // compare le premier caractere de str avec les caracteres devant se trouver apres un argument
{
	// printf ("str after cut '%s'\n", str);
	if (str[0] == '\0')
		return (1);
	if (str[0] == ' ')
		return (1);
	if (ft_is_separator(str, 0) != 0)
		return (1);
	return (0);
}

void	ft_copie_dest_src(t_token *tok, char *src) // copie dans dest ce que contient source A LA SUITE DE DEST : SI PAS DE PLACE TEMPI !
{
	int	i;
	int	u;

	i = 0;
	u = 0;
	while (tok->arg[i] != '\0')
		i++;
	while (src[u] != '\0')
	{
		tok->arg[i + u] = src[u];
		u++;
	}
}

char	*ft_src_in_dest(t_data *data, char *dest, char *src, char sep) // refais un malloc de dest de la taille dest + src, copie dest puis src a la suite. si sep est different de NULL, la fonction place le sep entre dest et src.
{
	int	sd; // size dest
	int	ss; //  size src
	char *ret;

	sd = ft_str_size(dest);
	ss = ft_str_size(src);
	// printf("src in dest : sep\n");
	if (sep != 0)
		ret = ft_malloc_str(data, sd + ss + 1);
	else
		ret = ft_malloc_str(data, sd + ss);
	sd = 0;
	ss = 0;
	// printf("src in dest : while\n");
	while (dest && dest[sd] && dest[sd] != '\0')
	{
		ret[sd] = dest[sd];
		sd++;
	}
	// printf("src in dest : if\n");
	if (sd > 0 && sep != 0)
	{
		ret[sd] = sep;
		sd++;
	}
	// printf("src in dest : while 2\n");
	while (src[ss] != '\0')
	{
		ret[sd + ss] = src[ss];
		ss++;
	}
	ret[sd + ss] = '\0';
	// printf("src in dest : fin : ret <%s>\n", ret);
	return (ret);
}
