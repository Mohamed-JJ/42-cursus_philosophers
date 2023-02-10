/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:59:46 by mjarboua          #+#    #+#             */
/*   Updated: 2023/02/09 21:13:52 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <time.h>

#define SUCCESS 0

typedef struct l_data
{
	int				i;
	int				j;
	int				t_t_eat;
	int				t_t_sleep;
	int				t_t_think;
	int				t_t_die;
	int				e_t;
	int				phs_c;
	pthread_t		*phs;
	pthread_mutex_t	*forks;
}			t_data;

// utils functions

// list functions

// conversion functions

int		ft_atoi(char *str);

// time conversion functions (milisecond to microsecond)

// routine functions

// void	do_eat(t_data *pack);
// void	do_think(t_data *pack);
// void	do_sleep(t_data *pack);

#endif