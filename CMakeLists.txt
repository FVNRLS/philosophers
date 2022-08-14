cmake_minimum_required(VERSION 3.22)
project(philosophers C)

set(CMAKE_C_STANDARD 99)
#set(GCC_COVERAGE_COMPILE_FLAGS "−Wall −Werror −Wextra")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

add_executable(

        #MAIN
        philosophers philo/src/main.c

        #INPUT PARSER
        philosophers philo/src/input_parser/input_parser.c
        philosophers philo/src/input_parser/args_checker.c

        #SIMULATOR
        philosophers philo/src/simulator/actions.c
        philosophers philo/src/simulator/simulator.c
        philosophers philo/src/simulator/killer.c

        #ERROR MANAGER
        philosophers philo/src/error_manager.c

        #TOOLS
        philo/tools/ft_atol.c
        philo/tools/ft_check_invalid_chars.c
        philo/tools/ft_is_digit.c
        philo/tools/ft_strlen.c


)