/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:01:20 by mjarboua          #+#    #+#             */
/*   Updated: 2023/02/20 17:42:14 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	my_usleep(int time)
{
	int	i;

	i = time * 1000;
	usleep(i);
}





void	to_do(t_philo *p, long long x)
{
	pthread_mutex_lock(&p->chops);
	put_out_info("has taken a fork\n", x, p->id);
	pthread_mutex_lock(&p->next->chops);
	put_out_info("has taken a fork\n", x, p->id);
	put_out_info("is eating\n", x, p->id);
	my_usleep(p->t_t_eat);
	pthread_mutex_unlock(&p->chops);
	pthread_mutex_unlock(&p->next->chops);
	pthread_mutex_lock(&p->print);
	do_sleep(p, x);
	pthread_mutex_unlock(&p->print);
	pthread_mutex_lock(&p->print);
	do_think(p, x);
	pthread_mutex_unlock(&p->print);
}

void	bucket_list(t_philo *p)
{
	long long	time;

	time = time_setter();
	p->last_meal = time;
	if (p->id % 2 == 1)
		usleep(200);
	while (p)
		to_do(p, time);
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

void	do_philo(t_philo *p)
{
	pthread_mutex_t	h;

	pthread_mutex_init(&p->print, NULL);
	h = p->print;
	while (p)
	{
		pthread_mutex_init(&p->chops, NULL);
		p->print = h;
		p = p->next;
		if (p == p->head)
			break ;
	}
	while (p)
	{
		pthread_create(&p->phs, NULL, (void *)bucket_list, (void *)p);
		pthread_join(p->phs, NULL);
		p = p->next;
		if (p == p->head)
			break ;
	}
}

int	main(int c, char **v)
{
	t_philo	*p;

	if (c > 6 || c < 5)
		return (printf("check your ARGUMENTS and try again\n"), 1);
	if (parse_arguments(v + 1))
		return (printf("wrong type of input\n"), 1);
	list_allocated(&p, v + 1, c);
	do_philo(p);
	return (0);
}