/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_atoi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anaqvi <anaqvi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:24:46 by anaqvi            #+#    #+#             */
/*   Updated: 2024/11/10 17:29:59 by anaqvi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	determine_sign(char *str)
{
	if (*str == '-')
		return (-1);
	return (1);
}

int	ft_atoi_error(char *str, int *num)
{
	long long	result;
	int			sign;

	result = 0;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	sign = determine_sign(str);
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (-1);
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			result = result * 10 + (*str - '0');
		else
			return (-1);
		if ((sign == 1 && result > INT_MAX)
			|| (sign == -1 && (-1 * result) < INT_MIN))
			return (-1);
		str++;
	}
	*num = result * sign;
	return (0);
}
