cmake_minimum_required(VERSION 3.22)
project(philosophers C)

set(CMAKE_C_STANDARD 99)

add_executable(philosophers ./philo/src/main.c

        #INPUT PARSER
        ./philo/src/input_parser/input_parser.c
        ./philo/src/input_parser/args_checker.c

        #SIMULATOR
        ./philo/src/simulator/actions.c
        ./philo/src/simulator/simulator.c
        ./philo/src/simulator/killer.c
        ./philo/src/simulator/mutex_controller.c

        #ERROR MANAGER
        philo/src/message_printer.c

        #TOOLS
        philo/tools/ft_atol.c
        philo/tools/ft_check_invalid_chars.c
        philo/tools/ft_is_digit.c
        philo/tools/ft_usleep.c
)
