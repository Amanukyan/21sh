/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_variables.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amanukya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 16:12:07 by amanukya          #+#    #+#             */
/*   Updated: 2016/04/21 16:12:09 by amanukya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../21sh.h"

void	print_env(t_env *head)
{
	while (head)
	{
		ft_putstr(head->name);
		ft_putchar('=');
		ft_putstr(head->value);
		ft_putchar('\n');
		head = head->next;
	}
}

char	*search_in_env(char *name, t_env *list)
{
	t_env	*ptr;

	ptr = list;
	if (!name)
		return (NULL);
	while (ptr)
	{
		if (ft_strcmp(name, ptr->name) == 0)
		{
			if (ptr->value)
				return (ptr->value);
			else
				return ("(null)");
		}
		ptr = ptr->next;
	}
	return (NULL);
}

int		ft_setenv(char *name, char *value, t_env **head)
{
	t_env	*ptr;
	t_env	*new;

	if (!head || !name)
		return (0);
	if (search_in_env(name, *head))
	{
		change_env_variable(name, value, *head);
		return (1);
	}
	new = (t_env *)ft_memalloc(sizeof(t_env));
	new->name = name;
	new->value = value;
	new->next = NULL;
	if (*head == NULL)
		*head = new;
	else
	{
		ptr = *head;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
	return (0);
}

int		ft_unsetenv(char *name, t_env **list)
{
	t_env	*ptr;
	t_env	*previous;

	if (!search_in_env(name, *list))
		return (0);
	ptr = *list;
	previous = *list;
	while (ptr)
	{
		if (ft_strcmp(name, ptr->name) == 0)
		{
			if (ptr == *list)
				*list = (*list)->next;
			else
				previous->next = ptr->next;
			break ;
		}
		previous = ptr;
		ptr = ptr->next;
	}
	return (1);
}

void	change_env_variable(char *name, char *new_value, t_env *list)
{
	t_env	*ptr;

	ptr = list;
	while (ptr)
	{
		if (ft_strcmp(name, ptr->name) == 0)
		{
			if (new_value)
				ptr->value = ft_strdup(new_value);
			else
				ptr->value = NULL;
		}
		ptr = ptr->next;
	}
}
