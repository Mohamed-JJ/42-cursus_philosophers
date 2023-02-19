/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_do.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 19:08:34 by mjarboua          #+#    #+#             */
/*   Updated: 2023/02/19 21:28:50 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	bucket_list(t_philo *p)
{
	long long	time;

	time = time_setter();
	if (p->id % 2 == 1)
		usleep(150);
	while (p)
	{
		to_do(p, time);
	}
}

void	put_out_info(char *str, long long past, int ip)
{
	long long	out_put;
	long long	current;

	current = time_setter();
	out_put = current - past;
	printf("%lld %d %s", out_put, ip, str);
}

void	do_sleep(t_philo *p, long long time)
{
	put_out_info("is sleeping\n", time, p->id);
	my_usleep(p->t_t_sleep);
}

void	do_think(t_philo *p, long long time)
{
	put_out_info("is thinking\n", time, p->id);
}
