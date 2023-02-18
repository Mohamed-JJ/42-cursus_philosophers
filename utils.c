/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:36:27 by mjarboua          #+#    #+#             */
/*   Updated: 2023/02/17 19:11:57 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	overf(int res, int pre, int sign)
{
	if (res / 10 > pre)
	{
		if (sign == -1)
			return (-2);
		return (-2);
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int			i;
	int			sign;
	long long	pre;
	long long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		pre = result;
		result *= 10;
		result = result + str[i++] - 48;
		if (overf(result, pre, sign) != 1)
			return (overf(result, pre, sign));
	}
	result *= sign;
	return (result);
}

int	from_micro_to_milli(void)
{
	struct timeval	v;
	long long		ret;

	ret = v.tv_sec * 1000 + v.tv_usec / 1000;
	return ((int)ret);
}

int	not_number(int c)
{
	if (!(c >= '0' && c <= '9'))
		return (1);
	return (0);
}

int	parse_arguments(char **v)
{
	int	i;
	int	j;

	i = 0;
	while (v[i])
	{
		j = 0;
		while (v[i][j])
		{
			if (not_number(v[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
