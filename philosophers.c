/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:01:20 by mjarboua          #+#    #+#             */
/*   Updated: 2023/02/19 16:24:39 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	my_usleep(int time)
{
	int	i;

	i = time * 1000;
	usleep(i);
}

long long	time_setter(void)
{
	long long		i;
	struct timeval	ml;

	gettimeofday(&ml, NULL);
	i = (ml.tv_sec * 1000) + (ml.tv_usec / 1000);
	return (i);
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

// void	my_usleep(int timer)
// {
// 	int	buffering_time;

// 	buffering_time = timer / 1000;
// 	usleep(buffering_time);
// }

void	do_philo(t_philo *p)
{
	while (p)
	{
		pthread_mutex_init(&p->chops, NULL);
		pthread_mutex_init(&p->print, NULL);
		p = p->next;
		if (p == p->head)
			break ;
	}
	p = p->head;
	while (p)
	{
		pthread_create(&p->phs, NULL, (void *)bucket_list, (void *)p);
		usleep(50);
		p = p->next;
		if (p == p->head)
			break ;
	}
	p = p->head;
	while (p)
	{
		pthread_join(p->phs, NULL);
		p = p->next;
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


/*you ahve to configure timing soo when you can print it out on the terminal*/
/*ps : try taking a look at gettimeofday*/ 