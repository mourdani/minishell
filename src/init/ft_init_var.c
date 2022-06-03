/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_var.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guderram <guderram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 17:41:03 by guderram          #+#    #+#             */
/*   Updated: 2022/02/24 02:39:05 by guderram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_init_var(t_data *data) // initialise la liste
{
	t_var	*var;

	var = malloc(sizeof(t_var));
	if(var == NULL)
		data->err = 1001; // erreur 1001 = malloc var
	else
	{
		var->name = NULL; // valeur initiale vide
		var->value = NULL; // valeur initiale vide
		var->next = NULL; // dernier var donc addresse suivante nulle
		var->prev = NULL; // premier var donc addresse precedente nulle
	}
	data->var = var;
}

void	ft_add_new_var(t_data *data) // cree une nouvelle liste et la met au debut de la stack
{
	t_var *new;

	new = malloc(sizeof(t_var));
	if (new == NULL)
		data->err = 101; // erreur 101 = malloc
	else
	{
		new->name = NULL; // valeur initiale vide
		new->value = NULL; // valeur initiale vide
		new->next = data->var; // indique la prochaine addresse a new
		data->var = new; // donne a data var la premiere adresse (donc celle de new)
		new->prev = NULL; // premier var dans la liste donc addresse precedente nulle
		new->next->prev = new;
	}
}

void	ft_free_var(t_data *data, t_var *var) // free les mallocs dans une liste
{
	if (var->name != NULL)
	{
		free (var->name);
		var->name = NULL;
		if (var->name != NULL)
			data->err = 1003;
	}
	if (var->value != NULL)
	{
		free (var->value);
		var->value = NULL;
		if (var->name != NULL)
			data->err = 1004;
	}
}

void	ft_delete_var(t_data *data, t_var *delete) // supprime la var en relian si besoin les autres
{
	if (delete == NULL)
		data->err = 102; // suppression d'un var inexistant
	if (data->var != NULL && delete != NULL)
	{
		ft_free_var(data, delete);
		if (delete->next == NULL && delete->prev != NULL) // si dernier et pas premier
			delete->prev->next = NULL;
		if (delete->prev == NULL && delete->next != NULL) // si premier et pas dernier
			data->var = delete->next;
		if (delete->prev == NULL && delete->next == NULL) // si premier et dernier
			data->var = NULL;
		if (delete->next != NULL && delete->prev != NULL) // si au milieu de deux
		{
			delete->prev->next = delete->next; // le precedent prend le suivant
			delete->next->prev = delete->prev; // le suivant prend le precedent
		}
		free (delete);
		delete = NULL;
	}
}
