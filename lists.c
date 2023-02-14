/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 21:13:15 by mjarboua          #+#    #+#             */
/*   Updated: 2023/02/14 21:25:35 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	make_it_ciculure(t_philo **p) // make it ciculure after you have all of your nodes allocated by taking the address of the head and giving it to the last node or making a small comparision inn case i wanted to stop the program
{
	t_philo	*h;

	h = p;
	while (*p)
		(*p) = (*p)->next;
}

t_philo	*ft_lstnew(char **info)
{
	t_philo	*new;

	new = malloc(sizeof(t_philo));
	if (!new)
		return (NULL);
	// fill the nodes with the required data
	new->next = NULL;
	return (new);
}

void	ft_lstadd_back(t_philo **lst, t_philo *new)
{
	t_philo	*node;

	node = *lst;
	if (*lst == NULL)
		*lst = new;
	else
	{
		while (node->next != NULL)
			node = node->next;
		node->next = new;
	}
}

void	ft_lstadd_front(t_philo **lst, t_philo *new)
{	
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

t_philo	*ft_last_philo(t_philo *node)
{
	if (!node)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

int	ft_lstsize(t_philo *d)
{
	int	i;

	i = 0;
	if (!d)
		return (0);
	while (d)
	{
		d = d->next;
		i++;
	}
	return (i);
}