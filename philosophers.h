/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 13:59:46 by mjarboua          #+#    #+#             */
/*   Updated: 2023/02/18 19:48:49 by mjarboua         ###   ########.fr       */
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
	int				phs_c;
	int				t_t_eat;
	int				t_t_die;
	int				t_t_sleep;
	int				e_t;
	int				t_e;
	int				id;
	long long		last_meal;
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

// long long	from_micro_to_milli(long long number);

void		my_usleep(t_philo *p);

// time conversion functions (milisecond to microsecond)

int	from_micro_to_milli(void);

// routine functions

void		bucket_list(t_philo *p);
void		do_sleep(t_philo *p, int *time);
void		do_think(t_philo *p, int *time);
void		to_do(t_philo *p, int timer);

#endif