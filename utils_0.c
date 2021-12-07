/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_0.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmandy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:31:56 by kmandy            #+#    #+#             */
/*   Updated: 2021/12/06 16:31:59 by kmandy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	error(void)
{
	write(1, "Error: The value isn't int\n", 27);
	exit(0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		error();
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	sign;
	long	n;

	i = 0;
	sign = 1;
	n = 0;
	while (str[i])
	{
		if (str[i] == '-')
		{
			sign *= -1;
			i++;
		}
		if (ft_isdigit(str[i]) == 1)
		{
			n = (n * 10) + (str[i++] - 48);
			if ((n * sign) < -2147483648)
				error();
			if ((n * sign) > 2147483647)
				error();
		}
	}
	return ((int)(sign * n));
}
