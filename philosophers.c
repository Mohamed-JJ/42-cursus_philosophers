/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:01:20 by mjarboua          #+#    #+#             */
/*   Updated: 2023/02/04 20:53:43 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	to_do(void)
{
}

// void	do_think(t_philo *ph)

void	creat_philo(pthread_t **ph, int philos)
{
	int	i;

	i = 0;
	while (i < philos)
	{
		(*ph)[i] = pthread_create(&(*ph)[i], NULL, &to_do, NULL);
		usleep(1);
		pthread_join((*ph)[i], NULL);
		i++;
	}
}

// void	do_think(int p_id, )
// {
// }

int	main(int c, char **v)
{
	int			i;
	int			num_philos;
	pthread_t	*philos;

	i = 0;
	num_philos = ft_atoi(v[1]);
	philos = malloc(sizeof(pthread_t) * num_philos + 1);
	creat_philo(&philos, num_philos);
	while (1)
	{
		printf("%d %d is took a fork\n", )
	}
	return (0);
}
