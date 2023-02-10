/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_things.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 13:52:40 by mjarboua          #+#    #+#             */
/*   Updated: 2023/02/10 16:06:15 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

void	do_eat(t_data *pack)
{
	printf("%d picked up a fork\n", pack->i);
	printf("%d is eating\n", pack->i);
	usleep(60000);
}

void	do_think(t_data *pack)
{
	printf("%d is thinking\n", (pack->i % 2));
}

// void	do_sleep(t_data *pack)
// {
// 	printf("%d is sleeping\n", pack->i);
// }
