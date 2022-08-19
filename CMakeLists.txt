cmake_minimum_required(VERSION 3.22)
project(philosophers C)

set(CMAKE_C_STANDARD 99)

add_executable(
#       ******** BONUS PART ********
        philosophers philo_bonus/main_bonus.c

        #INPUT PARSER
        ./philo_bonus/src/input_parser/input_parser.c
        ./philo_bonus/src/input_parser/args_checker.c
        #SIMULATOR
        ./philo_bonus/src/simulator/actions.c
        ./philo_bonus/src/simulator/simulator.c
        ./philo_bonus/src/simulator/watcher.c
        ./philo_bonus/src/simulator/mutex_controller.c
        #ERROR MANAGER
        ./philo_bonus/src/message_printer.c
        #TOOLS
        ./philo_bonus/tools/ft_atol.c
        ./philo_bonus/tools/ft_check_invalid_chars.c
        ./philo_bonus/tools/ft_is_digit.c
        ./philo_bonus/tools/ft_usleep.c
        ./philo_bonus/tools/ft_free_phils.c






#       ******** MANDATORY PART ********
#        philosophers philo/main.c

#        #INPUT PARSER
#        ./philo/src/input_parser/input_parser.c
#        ./philo/src/input_parser/args_checker.c
#        #SIMULATOR
#        ./philo/src/simulator/actions.c
#        ./philo/src/simulator/simulator.c
#        ./philo/src/simulator/watcher.c
#        ./philo/src/simulator/mutex_controller.c
#        #ERROR MANAGER
#        ./philo/src/message_printer.c
#        #TOOLS
#        ./philo/tools/ft_atol.c
#        ./philo/tools/ft_check_invalid_chars.c
#        ./philo/tools/ft_is_digit.c
#        ./philo/tools/ft_usleep.c
#        ./philo/tools/ft_free_phils.c
#

)
