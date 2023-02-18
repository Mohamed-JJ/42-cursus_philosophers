/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_do.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:08:34 by mjarboua          #+#    #+#             */
/*   Updated: 2023/02/17 22:50:28 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	bucket_list(t_philo *p)
{
	int	time;

	time = from_micro_to_milli();
	if (p->id % 2 == 1)
		usleep(15000);
	while (p)
	{
		to_do(p, &time); //make sure to add a timer to ypur function
	}
}

void	do_sleep(t_philo *p, int *time)
{
	printf("%d %d is sleeping\n", *time, p->id);
	my_usleep(p);
	*time += p->t_t_sleep;
}

void	do_think(t_philo *p, int *time)
{
	printf("%d %d is thinking\n", *time, p->id);
	// my_usleep(p);
	// *time += p->t_t_think;
}
