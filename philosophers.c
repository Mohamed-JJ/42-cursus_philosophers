/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:01:20 by mjarboua          #+#    #+#             */
/*   Updated: 2023/02/14 21:18:33 by mjarboua         ###   ########.fr       */
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

// int	main(int c, char **v)
// {
// 	pack = malloc(sizeof(t_data));
// 	if (!pack)
// 		return (1);
// 	(void)c;
// 	pack->i = 1;
// 	pack->phs_c = ft_atoi(v[1]);
// 	pack->phs = malloc(sizeof(pthread_t) * ft_atoi(v[1]));
// 	pack->chops = malloc(sizeof(pthread_mutex_t) * ft_atoi(v[1]));
// 	// pack->print = malloc(sizeof(pthread_mutex_t) * ft_atoi(v[1]));
// 	if (!pack->phs || !pack->chops)
// 		return (1);
// 	do_philo(pack);
// }
