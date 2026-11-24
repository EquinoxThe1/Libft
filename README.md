*This project has been created as part of the 42 curriculum by <matduart>.*

# Libft

## Description

Libft is my first C library. The idea is to rewrite some functions from the
standard C library, plus a few extra ones, so I understand how they really
work and can reuse them in my next 42 projects.

Everything ends up in a static library called libft.a, made with ar.
The functions are split in three parts.

Part 1 - libc functions
Same behaviour and prototypes as the originals, with the ft_ prefix.

	ft_isalpha, ft_isdigit, ft_isalnum, ft_isascii,ft_isprintft_toupper, ft_tolowerft_strlen, ft_strlcpy, ft_strlcat, ft_strchr,ft_strrchr, ft_strncmp, ft_strnstr, ft_strdupft_memset, ft_bzero, ft_memcpy, ft_memmove,ft_memchr, ft_memcmp, ft_callocft_atoi

Part 2 - additional functions
Things that are not in the libc, or that work differently.

    ft_substr      returns a substring of a string
    ft_strjoin     joins two strings into a new one
    ft_strtrim     removes a set of characters from both ends of a string
    ft_split       splits a string on a character into a NULL terminated array
    ft_itoa        turns an int into a string (negatives included)
    ft_strmapi     applies a function to each character, builds a new string
    ft_striteri    applies a function to each character, in place
    ft_putchar_fd  writes a character to a file descriptor
    ft_putstr_fd   writes a string to a file descriptor
    ft_putendl_fd  writes a string and a newline to a file descriptor
    ft_putnbr_fd   writes a number to a file descriptor

Part 3 - linked lists
Functions to work with a simple linked list, using this struct from libft.h:

    typedef struct s_list
    {
        void            *content;
        struct s_list   *next;
    }   t_list;

    ft_lstnew        creates a new node
    ft_lstadd_front  adds a node at the beginning
    ft_lstadd_back   adds a node at the end
    ft_lstsize       counts the nodes
    ft_lstlast       returns the last node
    ft_lstdelone     frees one node (content with del, then the node)
    ft_lstclear      frees a node and all the ones after it
    ft_lstiter       applies a function to the content of each node
    ft_lstmap        builds a new list from the result of a function

## Instructions

You need cc, make and ar.

To build the library, run this at the root of the repository:

    make

Other rules:

    make clean     #removes the .o files
    make fclean    #removes the .o files and libft.a
    make re        #fclean, then make

Files are compiled with -Wall -Wextra -Werror. Running make again without
changing anything does not relink.

To use the library in your own program, include the header:

    #include "libft.h"

and link it when compiling:

    cc -Wall -Wextra -Werror main.c -L. -lft -o my_program

If libft.h or libft.a are in another folder, add -I<path> and -L<path>.

To check what is inside the archive:

    ar -t libft.a
    nm libft.a | grep ft_strlen

## Resources

- man pages of each function (man 3 strlen, man 3 memmove, etc.)
- GNU Make manual: https://www.gnu.org/software/make/manual/make.html
- man ar and man nm
- GNU C Library manual: https://www.gnu.org/software/libc/manual/
- Talking with other 42 students

## How I used AI

I used AI only to help me understand the Makefile: how rules and pattern rules
work, what `.PHONY` and `ar rcs` do, and to check my Makefile for syntax mistakes.