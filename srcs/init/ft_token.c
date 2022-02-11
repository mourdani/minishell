/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_token.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 03:14:08 by guderram          #+#    #+#             */
/*   Updated: 2022/02/11 03:20:27 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_init_token(t_data *data) // initialise la liste
{
	t_token	*token;
	
	token = malloc(sizeof(t_token));
	if(token == NULL)
		data->err = 101; // erreur 101 = malloc
	else
	{
		token->cmd = -1; // valeur initiale vide
		token->option = -1; // valeur initiale vide
		token->str = NULL; // valeur initiale vide
		token->next = NULL; // dernier token donc addresse suivante nulle
		token->prev = NULL; // premier token donc addresse precedente nulle
	}	
}

void	ft_add_new_token(t_data *data) // cree une nouvelle liste et la met au debut de la stack
{
	t_token *new;

	new = malloc(sizeof(t_token));
	if (new == NULL)
		data->err = 101; // erreur 101 = malloc
	else
	{
		new->cmd = -1; // valeur initiale vide
		new->option = -1; // valeur initiale vide
		new->str = NULL; // valeur initiale vide
		new->next = data->first; // indique la prochaine addresse a new
		data->first->prev = new; // donne a list + 1 son adresse precedente (donc celle de new)
		data->first = new; // donne a data first la premiere adresse (donc celle de new)
		new->prev = NULL; // premier token dans la liste donc addresse precedente nulle
	}
}

void	ft_free_token(t_data *data, t_token *token) // free les mallocs dans une liste
{
	if (token->str != NULL)
	{
		free (token->str);
		token->str = NULL;
	}
	else
		data->err = 103; // free d'un str deja free
}

void	ft_delete_token(t_data *data, t_token *delete) // supprime la tokene en relian si besoin les autres
{
	if (delete == NULL)
		data->err = 102; // suppression d'un token inexistant
	if (data->first != NULL && delete != NULL)
	{
		ft_free_token(data, delete);
		if (delete->next == NULL && delete->prev != NULL) // si dernier et pas premier
			delete->prev->next = NULL;
		if (delete->prev == NULL && delete->next != NULL) // si premier et pas dernier
			data->first = delete->next;
		if (delete->prev == NULL && delete->next == NULL) // si premier et dernier
			data->first = NULL;
		if (delete->next != NULL && delete->prev != NULL) // si au milieu de deux
		{
			delete->prev->next = delete->next; // le precedent prend le suivant
			delete->next->prev = delete->prev; // le suivant prend le precedent
		}
		free (delete);
		delete = NULL;
	}
}
