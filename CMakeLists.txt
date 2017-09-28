cmake_minimum_required(VERSION 3.8)
project(filler)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES filler.c find_and_place.c get_next_line.c move.c libft/ft_strsub libft/ft_strdup.c function_set.c libft/ft_strjoin.c libft/ft_strnew.c libft/ft_strsub.c libft/ft_strchr.c libft/ft_strlen.c libft/ft_putstr_fd.c libft/ft_putchar_fd.c libft/ft_putstr.c libft/ft_itoa.c  libft/ft_putchar.c )
add_executable(filler ${SOURCE_FILES})
include_directories(libft)