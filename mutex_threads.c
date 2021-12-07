/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_threads.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmandy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:30:58 by kmandy            #+#    #+#             */
/*   Updated: 2021/12/06 16:31:02 by kmandy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	destroy(t_common *common)
{
	int	cnt;

	cnt = 0;
	while (cnt < common->philosopher)
		pthread_mutex_destroy(&common->mutex[cnt++]);
	pthread_mutex_destroy(&common->message);
}

unsigned long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) < 0)
		print("Error: time\n");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	create_mutex(t_common *common)
{
	int		cnt;

	cnt = -1;
	while (++cnt < common -> philosopher)
	{
		if (pthread_mutex_init(&common -> mutex[cnt], NULL) != 0)
			print("Error: mutex_init\n");
		common -> philo[cnt].id_thread = cnt + 1;
		common -> philo[cnt].eat_cnt = common -> cnt_eat;
		common -> philo[cnt].common = common;
		common -> philo[cnt].l_fork = &common -> mutex[cnt];
		if (cnt != common -> philosopher - 1)
			common -> philo[cnt].r_fork = &common -> mutex [cnt + 1];
		else
			common -> philo[cnt].r_fork = &common ->mutex[0];
	}
	if (common -> philosopher == 1)
		common -> philo[0].r_fork = &common->mutex[0];
	if (pthread_mutex_init(&common -> message, NULL) != 0)
		print("Error: mutex_init\n");
}

void	create_tread(t_common *common)
{
	int		cnt;

	common -> start_time = get_time();
	cnt = -1;
	while (++cnt < common -> philosopher)
	{
		if (cnt % 2 == 0)
			pthread_create(&common -> philo[cnt].thread, NULL,
				&life_philo, &common -> philo[cnt]);
		usleep(30);
	}
	usleep(30);
	cnt = -1;
	while (++cnt < common -> philosopher)
	{
		if (cnt % 2 == 1)
			pthread_create(&common -> philo[cnt].thread, NULL,
				&life_philo, &common -> philo[cnt]);
		usleep(30);
	}
	pthread_create(&common->dead, NULL, &check_dead, common);
	pthread_join(common->dead, NULL);
	destroy(common);
}
