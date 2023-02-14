/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:59:46 by mjarboua          #+#    #+#             */
/*   Updated: 2023/02/14 21:17:48 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <time.h>

# define SUCCESS 0
# define FAILURE 1

typedef struct l_data
{
	int				t_t_eat;
	int				t_t_die;
	int				t_t_sleep;
	int				t_t_think;
	int				e_t;
}				t_data;

typedef struct l_philo
{
	int				t_e;
	int				id;
	int				phs_c;
	pthread_mutex_t	chops;
	pthread_mutex_t	print;
	pthread_t		phs;
	struct l_philo	*next;
	struct l_philo	*head;
	t_data			*d;
}				t_philo;

// utils functions

// list functions

// conversion functions

int			ft_atoi(char *str);
long long	from_micro_to_milli(long long number);

// time conversion functions (milisecond to microsecond)

// routine functions

// void	do_eat(t_data *pack);
// void	do_think(t_data *pack);
// void	do_sleep(t_data *pack);

#endif