/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjarboua <mjarboua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:36:27 by mjarboua          #+#    #+#             */
/*   Updated: 2023/02/03 20:11:38 by mjarboua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	overf(int res, int pre, int sign)
{
	if (res / 10 > pre)
	{
		if (sign == -1)
			return (0);
		return (-1);
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
