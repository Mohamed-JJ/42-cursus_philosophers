/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:59:46 by mjarboua          #+#    #+#             */
/*   Updated: 2023/02/20 17:43:01 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <time.h>
# include <sys/time.h>

# define SUCCESS 0
# define FAILURE 1

typedef struct l_philo
{
	long long		phs_c;
	long long		t_t_eat;
	long long		t_t_die;
	long long		t_t_sleep;
	long long		e_t;
	long long		t_e;
	long long		id;
	long long		last_meal;
	long long		*time_s;
	pthread_mutex_t	chops;
	pthread_mutex_t	print;
	pthread_t		phs;
	struct l_philo	*next;
	struct l_philo	*head;
}				t_philo;

// utils functions

int			parse_arguments(char **v);
int			not_number(int c);

// list functions

t_philo		*ft_lstnew(char **v, int c, int id);
void		ft_lstadd_back(t_philo **lst, t_philo *new);
void		make_it_ciculure(t_philo **p);
void		give_them_head(t_philo **p);
void		list_allocated(t_philo **head, char **v, int c);

// conversion functions

int			ft_atoi(char *str);
long long	time_setter(void);
// long long	from_micro_to_milli(long long number);

void		my_usleep(int time);

// time conversion functions (milisecond to microsecond)

long long	time_setter(void);

// routine functions

void		put_out_info(char *str, long long past, int ip);
void		bucket_list(t_philo *p);
void		do_sleep(t_philo *p, long long time);
void		do_think(t_philo *p, long long time);
void		to_do(t_philo *p, long long timer);

#endif