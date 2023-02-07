/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:59:46 by mjarboua          #+#    #+#             */
/*   Updated: 2023/02/07 15:54:52 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct l_data
{
	int				i;
	int				j;
	int				number_of_philos;
	pthread_t		*philos;
	pthread_mutex_t	*ph;
}			t_data;

// typedef struct l_philo
// {
// 	int				p_id;
// 	int				l_or_r;
// 	pthread_t		*philos;
// 	pthread_mutex_t	ph;
// 	struct l_philo	*next;
// 	struct l_philo	*head;
// }				t_philo;

// utils functions

// list functions

// t_philo	*ft_last_node(t_philo *node);
// t_philo	*ft_lstnew(int content);
// void	ft_lstadd_back(t_philo **lst, t_philo *new);

// conversion functions

int		ft_atoi(char *str);

// time conversion functions (milisecond to microsecond)

#endif