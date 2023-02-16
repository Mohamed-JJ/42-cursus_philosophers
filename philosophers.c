/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:01:20 by mjarboua          #+#    #+#             */
/*   Updated: 2023/02/16 13:14:18 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"



// long long	from_micro_to_milli(long long number)
// {
// 	long long	i;

// 	i = number / 1000;
// 	return (i);
// }

// int	do_philo(t_data *pack)
// {
// 	int	i;

// 	i = 0;
// 	while (i < pack->phs_c)
// 	{
// 		pthread_mutex_init(&pack->forks[i], NULL);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < pack->phs_c)
// 	{
// 		pthread_create(&pack->phs[i], NULL, (void *)to_do, (void *)pack);
// 		usleep(50);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < pack->phs_c)
// 	{
// 		pthread_join(pack->phs[i], NULL);
// 		i++;
// 	}
// 	return (0);
// }

// void	init_resources(t_data **p, char **v, int c)
// {
// }

// int	main(int c, char **v)
// {
// 	int		i;
// 	t_data	*pack;

// 	i = 0;
// 	pack = malloc(sizeof(t_data));
// 	if (!pack)
// 		return (1);
// 	init_resources(&pack, v + 1, c);
// 	return (0);
// }

// void	to_do_list(t_data *h)
// {
// 	// if (h->i%2)
// 	// 	usleep(20000);
// 	// h->i = 1;
// 	while (1)
// 	{
// 		printf("hello from philo number %d\n", h->i);	
// 	}
// }

// void	do_philo(t_data *d)
// {
// 	int	i;

// 	i = 0;
// 	while (i < d->phs_c)
// 	{
// 		pthread_mutex_init(&d->chops[i], NULL);
// 		i++;
// 	}
// 	i = 1;
// 	while (i <= d->phs_c)
// 	{
// 		d->i = i;
// 		pthread_create(&d->phs[i], NULL, (void *)to_do_list, (void *)d);
// 		usleep(50);
// 		// pthread_join(d->phs[i], NULL);
// 		i++;
// 	}
// }

void	put_fork(t_philo *p)
{
	pthread_mutex_unlock(&p->chops);
	printf("%d put down a fork\n", p->id);
	pthread_mutex_unlock(&p->next->chops);
	printf("%d put down a fork\n", p->id);
}

void	do_sleep(t_philo *p)
{
	printf("%d is sleeping\n", p->id);
}

void	do_think(t_philo *p)
{
	printf("%d is thinking\n", p->id);
}

void	bucket_list(t_philo *p)
{
	while (p)
	{
		pthread_mutex_lock(&p->chops);
		printf("%d picked up a fork\n", p->id);
		pthread_mutex_lock(&p->next->chops);
		printf("%d picked up a fork\n", p->id);
		printf("%d is eating\n", p->id);
		usleep(50000);
		pthread_mutex_unlock(&p->chops);
		pthread_mutex_unlock(&p->next->chops);
		p = p->next;
		// pthread_mutex_lock(&p->print);
		pthread_mutex_lock(&p->print);
		do_sleep(p);
		usleep(50000);
		pthread_mutex_unlock(&p->print);
		p = p->next;
		pthread_mutex_lock(&p->print);
		do_think(p);
		usleep(50000);
		pthread_mutex_unlock(&p->print);
		p = p->next;
		// p = p->next;
	}
}

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
		pthread_join(p->phs, NULL);
		p = p->next;
		if (p == p->head)
			break ;
	}
}

void	list_allocated(t_philo **head, char **v, int c)
{
	int		i;
	int		cc;

	i = 1;
	cc = ft_atoi(v[0]);
	while (i <= cc)
	{
		ft_lstadd_back(head, ft_lstnew(v, c, i));
		i++;
	}
	give_them_head(head);
	make_it_ciculure(head);
}


int	main(int c, char **v)
{
	t_philo	*p;

	if (c > 6 || c < 5)
		return (printf("check your ARGUMENTS and try again\n"), 1);
	// (void)c;
	list_allocated(&p, v + 1, c);
	do_philo(p);
}
