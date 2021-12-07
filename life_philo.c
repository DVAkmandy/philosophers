/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmandy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:30:39 by kmandy            #+#    #+#             */
/*   Updated: 2021/12/06 16:30:42 by kmandy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	take_fork(t_philo *philo)
{
	pthread_mutex_lock(philo -> l_fork);
	message(philo, "has taken a l_fork");
	pthread_mutex_lock(philo->r_fork);
	message(philo, "has taken a r_fork");
}

void	put_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	*life_philo(void *argv)
{
	t_philo	*philo;

	philo = (t_philo *)argv;
	pthread_detach(philo -> thread);
	philo -> time_finish = philo -> common -> start_time;
	while (1)
	{
		if (philo -> eat_cnt != 0)
		{
			take_fork(philo);
			philo->time_finish = get_time();
			message(philo, "is eating");
			philo->eat_cnt--;
			time_cnt(philo->common->eat_time);
			put_fork(philo);
			message(philo, "is sleeping");
			time_cnt(philo->common->sleep_time);
			message(philo, "is thinking");
		}
		else
			break ;
	}
	return (NULL);
}
