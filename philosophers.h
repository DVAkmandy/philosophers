/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmandy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:31:41 by kmandy            #+#    #+#             */
/*   Updated: 2021/12/06 16:31:46 by kmandy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	pthread_mutex_t		*l_fork;
	pthread_mutex_t		*r_fork;
	struct s_common		*common;
	pthread_t			thread;
	int					id_thread;
	int					eat_cnt;
	unsigned long		time_finish;
}						t_philo;

typedef struct s_common
{
	pthread_mutex_t		*mutex;
	pthread_mutex_t		message;
	unsigned long		start_time;
	pthread_t			dead;
	t_philo				*philo;
	int					philosopher;
	int					life_time;
	int					eat_time;
	int					sleep_time;
	int					cnt_eat;
}						t_common;

unsigned long		get_time(void);
int					ft_atoi(const char *str);
int					check_parser(t_common *common, int argc);
void				create_mutex(t_common *common);
int					print(char *str);
void				create_tread(t_common *common);
void				*life_philo(void *argv);
void				message(t_philo *philo, char *str);
void				time_cnt(unsigned long time);
int					val_dead(t_common *common, int cnt);
void				*check_dead(void *common);

#endif
