/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:01:20 by mjarboua          #+#    #+#             */
/*   Updated: 2023/02/11 15:33:25 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


int	do_eat(t_data *pack)
{
	printf("%d picked up a fork\n", pack->i);
	printf("%d is eating\n", pack->i);
	// pack->i++;
	usleep(60000);
	return (SUCCESS);
}

long long	from_micro_to_milli(long long number)
{
	long long	i;

	i = number / 1000;
	return (i);
}

int	do_sleep(t_data *pack)
{
	printf("%d is sleeping\n", pack->i);
	return (SUCCESS);
}

int	to_do(void *p)
{
	t_data	*pack;

	pack = (t_data *)p;
	pack->i = 0;
	while (1)
	{
		pthread_mutex_lock(&pack->forks[pack->i]);
		if (pack->i > pack->phs_c - 1)
			pack->i = 0;
		do_eat(pack);
		usleep(500);
		pack->i++;
		pthread_mutex_unlock(&pack->forks[pack->i]);
		do_sleep(pack);
	}
	return (0);
}


int	do_philo(t_data *pack)
{
	int	i;

	i = 0;
	while (i < pack->phs_c)
	{
		pthread_mutex_init(&pack->forks[i], NULL);
		i++;
	}
	i = 0;
	while (i < pack->phs_c)
	{
		pthread_create(&pack->phs[i], NULL, (void *)to_do, (void *)pack);
		usleep(50);
		i++;
	}
	i = 0;
	while (i < pack->phs_c)
	{
		pthread_join(pack->phs[i], NULL);
		i++;
	}
	return (0);
}

void	init_resources(t_data **pack, char **v)
{
	int	i;

	i = 0;
	(*pack)->phs_c = ft_atoi(v[0]);
	(*pack)->forks = malloc(sizeof(pthread_mutex_t)
			* (*pack)->phs_c);
	(*pack)->t_t_die = ft_atoi(v[1]);
	(*pack)->t_t_eat = ft_atoi(v[2]);
	(*pack)->t_t_sleep = ft_atoi(v[3]);
	(*pack)->phs = malloc(sizeof(pthread_t) * (*pack)->phs_c);
	(*pack)->forks = malloc(sizeof(pthread_mutex_t) * (*pack)->phs_c);
	if (!(*pack)->phs || !(*pack)->forks)
		return ;
}

int	main(int c, char **v)
{
	int		i;
	t_data	*pack;

	i = 0;
	if (c != 5)
		return (printf("error in passing arguments\n"), 1);
	pack = malloc(sizeof(t_data));
	if (!pack)
		return (1);
	init_resources(&pack, v + 1);
	if (do_philo(pack))
		return (1);
	return (0);
}
