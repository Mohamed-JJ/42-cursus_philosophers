/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:01:20 by mjarboua          #+#    #+#             */
/*   Updated: 2023/02/07 16:10:35 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

pthread_mutex_t	nut;

void	*to_think(int *id)
{
	//int	*f;

//	f = id;
	printf("%d is thinking\n", *id);
	return (0);
}

void	create_phs(int phs)
{
	int	i;

	i = 0;
	pthread_t *philo;
	philo = malloc(sizeof(pthread_t)*phs);
	while (i < phs)
	{
		pthread_create(&philo[i], NULL, (void *)to_think, (void *)&i);
		usleep(50);
		i++;
	}
	i = 0;
	while (i < phs)
	{
		pthread_join(philo[i], NULL);
		i++;
	}
}

int	*init_resources(int num)
{
	int	i;
	int	*chops;

	chops = malloc(sizeof(int) * num);
	if (!chops)
		return (NULL);
	i = 0;
	while (i < num)
	{
		chops[i] = i;
		i++;
	}
	return (chops);
}

int	main(int c, char **v)
{
	pthread_mutex_t	f;
	int				*chopsticks;
	int				i;
	int				num_philos;
	pthread_t		*phs;

	i = 0;
	pthread_mutex_init(&nut, NULL);
	num_philos = ft_atoi(v[1]);
	create_phs(num_philos);
	printf("hello 2\n");
	return (0);
}
