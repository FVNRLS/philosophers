/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:11:48 by rmazurit          #+#    #+#             */
/*   Updated: 2022/08/11 14:58:47 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incl/philo.h"

pthread_mutex_t mutex;

void* routine_lock(void* arg) 
{
    pthread_mutex_lock(&mutex); 
	printf("Got lock\n");
	sleep(1);
	pthread_mutex_unlock(&mutex);	
	return (NULL);
}

void	*routine_trylock(void* arg) 
{
    if (pthread_mutex_trylock(&mutex) == 0) 
	{
        printf("Got lock\n");
        sleep(1);
        pthread_mutex_unlock(&mutex);
	}
    else
        printf("Didn't get lock\n");
	return (NULL);
}

int main(int argc, char* argv[]) 
{
    pthread_t th[4];
    pthread_mutex_init(&mutex, NULL);
    for (int i = 0; i < 4; i++) 
	{
        if (pthread_create(&th[i], NULL, &routine_lock, NULL) != 0) 
            perror("Error at creating thread");
    }
    for (int i = 0; i < 4; i++) 
	{
        if (pthread_join(th[i], NULL) != 0)
            perror("Error at joining thread");
	}
    pthread_mutex_destroy(&mutex);
    return 0;
}

// int main(int argc, char **argv)
// {
// //	t_phil	phil;
// //	t_args	args;
// //
// //	phil.args = &args;
// //	args.ac = argc;
// //	args.av = argv;

// 	return (0);
// }
