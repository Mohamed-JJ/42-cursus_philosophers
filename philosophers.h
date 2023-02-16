/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:59:46 by mjarboua          #+#    #+#             */
/*   Updated: 2023/02/15 15:43:31 by mjarboua         ###   ########.fr       */
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

typedef struct l_philo
{
	int				phs_c;
	int				t_t_eat; //  an indicator for when the phs should eat
	int				t_t_die; // an indicator for when the phs should die
	int				t_t_sleep; // an indicator for when the phs should sleep or rather say for how long he should be asleep for
	int				t_t_think; // an indicator for when the phs should think or rather say for how long he should be think for
	int				e_t; // the fifth argument which tells us how many times all the phs should eat before the program terminates
	int				t_e;//a counter which counts how many times every phs ate
	int				id;//the id of each phs
	pthread_mutex_t	chops;
	pthread_mutex_t	print;
	pthread_t		phs;
	struct l_philo	*next;
	struct l_philo	*head;
}				t_philo; 

// utils functions

// list functions

t_philo		*ft_lstnew(char **v, int c, int id);
void		ft_lstadd_back(t_philo **lst, t_philo *new);
t_philo		*ft_last_philo(t_philo *node);
int			ft_lstsize(t_philo *d);
void		make_it_ciculure(t_philo **p);
void		give_them_head(t_philo **p);


// conversion functions

int			ft_atoi(char *str);
long long	from_micro_to_milli(long long number);

// time conversion functions (milisecond to microsecond)

// routine functions

// void	do_eat(t_data *pack);
// void	do_think(t_data *pack);
// void	do_sleep(t_data *pack);

#endif