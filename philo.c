/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmandy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:31:21 by kmandy            #+#    #+#             */
/*   Updated: 2021/12/06 16:31:24 by kmandy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	parser(t_common *common, int argc, char **argv)
{
	common -> philosopher = ft_atoi(argv[1]);
	common -> life_time = ft_atoi(argv[2]);
	common -> eat_time = ft_atoi(argv[3]);
	common -> sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
		common -> cnt_eat = ft_atoi(argv[5]);
	else
	common -> cnt_eat = -1;
}

void	allocation_memory(t_common *common)
{
	common -> philo = malloc(sizeof(t_philo) * common -> philosopher);
	common -> mutex = malloc(sizeof(pthread_mutex_t) * common -> philosopher);
	if (!common->philo || !common->mutex)
		print("Error: Malloc can't allocate\n");
}

int	main(int argc, char **argv)
{
	t_common	common;

	memset(&common, 0, sizeof(common));
	if (argc != 5 && argc != 6)
	{
		printf("the number of arguments should be 5 or 6\n");
		return (1);
	}
	parser(&common, argc, argv);
	if (check_parser(&common, argc))
		return (1);
	allocation_memory(&common);
	create_mutex(&common);
	create_tread(&common);
	free(common.philo);
	free(common.mutex);
	return (0);
}
