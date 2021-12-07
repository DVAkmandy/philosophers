/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmandy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:30:13 by kmandy            #+#    #+#             */
/*   Updated: 2021/12/06 16:30:25 by kmandy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	print(char *str)
{
	printf("%s", str);
	return (1);
}

int	check_parser(t_common *common, int argc)
{
	if (common -> philosopher < 0)
		return (print("Error: The philosopher value is negative\n"));
	if (common -> life_time < 0)
		return (print("Error: The lifetime value is negative\n"));
	if (common -> eat_time < 0)
		return (print("Error: The time to eat value is negative\n"));
	if (common -> sleep_time < 0)
		return (print("Error: The time to sleep value is negative\n"));
	if (common -> cnt_eat <= 0 && argc == 6)
		return (print("Error: The counter to eat value is negative or 0\n"));
	return (0);
}
