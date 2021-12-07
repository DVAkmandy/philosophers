/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmandy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:32:13 by kmandy            #+#    #+#             */
/*   Updated: 2021/12/06 16:32:16 by kmandy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	message(t_philo *philo, char *str)
{
	if (pthread_mutex_lock(&philo->common->message))
		print("Error: mutex_lock");
	printf("time (%lu) - philo (%d) : %s\n",
		(get_time() - philo->common->start_time), philo->id_thread, str);
	if (pthread_mutex_unlock(&philo->common->message))
		print("Error: mutex_unlock");
	return ;
}

void	time_cnt(unsigned long time)
{
	unsigned long	sum_time;

	sum_time = get_time() + time;
	usleep((time - 10) * 1000);
	while (get_time() <= sum_time)
		usleep(50);
}

int	val_dead(t_common *common, int cnt)
{
	unsigned long	dead;

	dead = get_time() - common->philo[cnt].time_finish;
	if ((int)(dead) > common->life_time)
	{
		pthread_mutex_lock(&common->message);
		printf("time (%lu) - Philo %d dead", dead, cnt + 1);
		return (1);
	}
	return (0);
}

void	*check_dead(void *common)
{
	t_common	*tmp;
	int			cnt;
	int			cnt_eat;

	tmp = (t_common *)common;
	while (1)
	{
		cnt = 0;
		cnt_eat = 0;
		while (cnt < tmp->philosopher)
		{
			if (val_dead(tmp, cnt) == 1)
				return (NULL);
			cnt_eat += tmp->philo[cnt++].eat_cnt;
		}
		if (cnt_eat == 0)
		{
			pthread_mutex_lock(&tmp->message);
			printf("%s ", "All the philosophers have eaten");
			return (NULL);
		}
	}
}
