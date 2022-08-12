cmake_minimum_required(VERSION 3.22)
project(philosophers C)

set(CMAKE_C_STANDARD 99)
#set(GCC_COVERAGE_COMPILE_FLAGS "−Wall −Werror −Wextra")
#set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

add_executable(

        #MAIN
        philosophers philo/src/main.c

        #PARSER
        philosophers philo/src/input_parser.c

        #INITIALIZERS
        philosophers philo/src/initializers/forks_initializer.c
        philosophers philo/src/initializers/phils_initilaizer.c

        #ERROR MANAGER
        philosophers philo/src/error_manager.c

        #TOOLS
        philo/tools/ft_strlen.c
)