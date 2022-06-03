/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 03:14:08 by guderram          #+#    #+#             */
/*   Updated: 2022/05/20 17:26:49 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_init_token(t_data *data) // initialise la liste
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if(token == NULL)
		data->err = 101; // erreur 101 = malloc
	else
	{
		token->sep = -1; // valeur initiale vide
		token->cmd = -1; // valeur initiale vide
		token->option = -1; // valeur initiale vide
		token->arg = NULL; // valeur initiale vide
		token->bin = NULL; // valeur initiale vide
		token->next = NULL; // dernier token donc addresse suivante nulle
		token->prev = NULL; // premier token donc addresse precedente nulle
	}
	data->token = token;
}

void	ft_add_new_token(t_data *data) // cree une nouvelle liste et la met au debut de la stack
{
	t_token *new;

	new = malloc(sizeof(t_token));
	if (new == NULL)
		data->err = 101; // erreur 101 = malloc
	else
	{
		new->sep = -1; // valeur initiale vide
		new->cmd = -1; // valeur initiale vide
		new->option = -1; // valeur initiale vide
		new->arg = NULL; // valeur initiale vide
		new->bin = NULL; // valeur initiale vide
		new->next = data->token; // indique la prochaine addresse a new
		// data->token->prev = new; // donne a list + 1 son adresse precedente (donc celle de new)
		data->token = new; // donne a data token la premiere adresse (donc celle de new)
		new->prev = NULL; // premier token dans la liste donc addresse precedente nulle
		new->next->prev = new;
	}
}

void	ft_free_token(t_data *data, t_token *token) // free les mallocs dans une liste
{
	int	i;

	i = 0;
	// printf ("ft_free_token : cmd %d\n", token->cmd);
	if (token->arg != NULL)
	{
		// printf ("ft_free_token : arg <%s>\n", token->arg);
		free (token->arg);
		token->arg = NULL;
	}
	// printf ("1\n");
	while (token->bin && token->bin[i] != NULL)
	{
		// printf ("ft_free_token : bin <%s>\n", token->bin[i]);
		free (token->bin[i]);
		token->bin[i] = NULL;
		// printf ("ft_free_token : bin <%s>\n", token->bin[i]);
		i++;
	}
	// printf ("2\n");
	if (token->bin != NULL)
	{
		// printf ("ft_free_token : bin\n");
		free (token->bin);
		token->bin = NULL;
	}
	// printf ("3\n");
	// printf("free_token OK\n");
	data->i = data->i;
	// else
	// {
	// 	if (token->cmd != 2)
	// 		data->err = 103; // free d'un str deja free
	// 	else
	// 		token->arg = NULL;
	// }
	// if (token->cmd != 2 && token->arg != NULL)
	// {
	// 	free (token->arg);
	// 	token->arg = NULL;
	// }
	// else
	// {
	// 	if (token->cmd != 2)
	// 		data->err = 103; // free d'un str deja free
	// 	else
	// 		token->arg = NULL;
	// }
}

void	ft_delete_token(t_data *data, t_token *delete) // supprime la tokene en relian si besoin les autres
{
	if (delete == NULL)
		data->err = 102; // suppression d'un token inexistant
	if (data->token != NULL && delete != NULL)
	{
		// if (delete->cmd != 4 && delete->cmd != 2)
		ft_free_token(data, delete);
		// printf("after delete in\n");
		if (delete->next == NULL && delete->prev != NULL) // si dernier et pas premier
		{
			// printf("1\n");
			delete->prev->next = NULL;
		}
		if (delete->prev == NULL && delete->next != NULL) // si premier et pas dernier
		{
			// printf("2\n");
			data->token = delete->next;
			delete->next->prev = NULL;
		}
		if (delete->prev == NULL && delete->next == NULL) // si premier et dernier
		{
			// printf ("\nfirst and last\n");
			data->token = NULL;
		}
		if (delete->next != NULL && delete->prev != NULL) // si au milieu de deux
		{
			// printf("3\n");
			delete->prev->next = delete->next; // le precedent prend le suivant
			delete->next->prev = delete->prev; // le suivant prend le precedent
		}
		// printf("before free\n");
		if (delete && delete != NULL)
		{
			// printf ("free delete '%p'\n", delete);
			free (delete);
			delete = NULL;
			// printf ("delete status '%p'\n", delete);
		}
		// printf("after free\n");
	}
}
