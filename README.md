# philosophers

<br>**About the project**

This project is a training for multi-thread/multi-process programming with the use of mutex and semaphore.
Two different variants are used to simulate and solve the famous Dining Philosophers problem.
The project also teaches optimization and parralessing of processes. This is done directly with CPU control to ensure the existence of the philosophers.

The project is divided into 2 parts: Mandatory and Bonus.

If you are a 42 student visiting this project, please do not blindly copy the solution and make sure you always understand the code you write. 
The solution approach of the project lies in the basic understanding of the threads commands such as: 
usleep, gettimeofday, pthread_create, pthread_detach, pthread_join, thread_mutex_init, pthread_mutex_destroy, pthread_mutex_lock, pthread_mutex_unlock.

In addition, the following functions are allowed for the project:
memset, printf, malloc, free, write.

For the bonus part: waitpid, sem_open, sem_close, sem_post, sem_wait, sem_unlink, exit, kill, fork 


<br>**Getting started**

`git clone the project`

`cd to the project directory`

<br>to compile only the mandatory part:

`cd philo`

`make`

<br>to compile the bonus part:

`cd philo`

`make bonus`

<br>**Usage**

The program should simulate the philosopher's behaviour the behaviour (eat, sleep, think...die):

./philo <NUMBER_PHILOSOPHERS> <TIME_TO_DIE> <TIME_TO_EAT> <TIME_TO_SLEEP> (<OPTIONAL: MIN_NUM_TIMES_TO_EAT_FOR_EACH_PHILOSOPHER>

<br>Examples:

`./philo 3 310 200 100`

`./philo 3 800 200 200 7`




<br>
<details>
 <summary>Rules</summary>

![alt text](https://w3.cs.jmu.edu/kirkpams/OpenCSF/Books/csf/html/_images/CSF-Images.8.3.png)

* A number of philosophers are sitting at a round table doing one of three things:
eating, thinking or sleeping.

* While eating, they are not thinking or sleeping, while sleeping, they are not eating
or thinking and of course, while thinking, they are not eating or sleeping.

* The philosophers sit at a circular table with a large bowl of spaghetti in the center.
• There are some forks on the table.

* As spaghetti is difficult to serve and eat with a single fork, it is assumed that a
philosopher must eat with two forks, one for each hand.

* The philosophers must never be starving.

* Every philosopher needs to eat.

* Philosophers don’t speak with each other.

* Philosophers don’t know when another philosopher is about to die. 

* Each time a philosopher has finished eating, he will drop his forks and start sleeping.

* When a philosopher is done sleeping, he will start thinking.

* The simulation stops when a philosopher dies.

* Each program should have the same options: number_of_philosophers time_to_die
time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

* number_of_philosophers: is the number of philosophers and also the number
of forks

* time_to_die: is in milliseconds, if a philosopher doesn’t start eating ’time_to_die’
milliseconds after starting his last meal or the beginning of the simulation, it
dies

* time_to_eat: is in milliseconds and is the time it takes for a philosopher to
eat. During that time he will need to keep the two forks.

* time_to_sleep: is in milliseconds and is the time the philosopher will spend
sleeping.

* number_of_times_each_philosopher_must_eat: argument is optional, if all
philosophers eat at least ’number_of_times_each_philosopher_must_eat’ the
simulation will stop. If not specified, the simulation will stop only at the death
of a philosopher.

* Each philosopher should be given a number from 1 to ’number_of_philosophers’.

* Philosopher number 1 is next to philosopher number ’number_of_philosophers’.
Any other philosopher with number N is seated between philosopher N - 1 and
philosopher N + 1

* Any change of status of a philosopher must be written as follows (with X replaced
with the philosopher number and timestamp_in_ms the current timestamp in milliseconds)
  * timestamp_in_ms X has taken a fork
  * timestamp_in_ms X is sleeping
  * timestamp_in_ms X is thinking
  * timestamp_in_ms X died  

* The status printed should not be scrambled or intertwined with another philosopher’s status.

* You can’t have more than 10 ms between the death of a philosopher and when it
will print its death.

* Again, philosophers should avoid to die!

</details>

<br>
<details>
 <summary>Edge cases and useful testing parameters</summary>

One philosopher must take 1 fork and die before eating:
* 1 800 200 200

Run forever:
* 2 420 200 200 
* 4 410 200 200 
* 5 800 200 200 
* 30 600 200 200 
* 99 620 200 200 
* 198 440 200 200 
* 199 620 200 200

One must die:
* 4 310 200 100 
* 3 550 200 200

Must eat at least n times:
* 5 800 200 200 3 
* 30 800 200 200 7 
* 30 600 200 200 7

Types:
* INT_MIN   = -2147483648 
* INT_MAX   = 2147483647 
* UINT_MAX  = 4294967295 
* LONG_MIN  = -9223372036854775808 
* LONG_MAX  = 9223372036854775807

</details>


<br>**Contributing**

If you have a suggestion that would make this better, please fork the repo and create a pull request. You can also simply open an issue with the tag "enhancement". Don't forget to give the project a star! Thanks again!

<br>**Acknowledgments**

Good visualizer:

https://nafuka11.github.io/philosophers-visualizer/

<br>Many thanks for useful advices, support and patience to:

Didar [https://github.com/4funoO/]  

Ksenia  [[https://de.linkedin.com/in/ksenia-morunova](https://de.linkedin.com/in/ksenia-morunova)]
