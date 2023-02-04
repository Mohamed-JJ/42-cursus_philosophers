/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 14:01:20 by mjarboua          #+#    #+#             */
/*   Updated: 2023/02/04 21:54:36 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	to_do(void)
{
	printf("the philo is here\n")
}


t_philo	*ft_allocate(int philos)
{
	int		i;
	t_philo	*ptr;

	i = 0;
	while (i < philos)
	{
		ft_lstadd_back(&ptr, ft_lstnew(i));
		i++;
	}
	return (ptr);
}

void	creat_philo(t_philo **philo, int n_p)
{
	int	i;

	i = 0;
	while (i < n_p)
	{
		(*philo) = pthread_create(&(*philo)->philos, NULL, &to_do, NULL);
		pthread_join((*philo)->philos, NULL);
		i++;
	}
}


int	main(int c, char **v)
{
	int			i;
	int			num_philos;
	pthread_t	*philos;
	t_philo		*ph;

	i = 0;
	num_philos = ft_atoi(v[1]);
	ph = malloc(sizeof(t_philo));
	if (!ph)
		return (1);
	philos = malloc(sizeof(pthread_t) * num_philos + 1);
	creat_philo(&philos, num_philos);
	return (0);
}
