# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: schmurz <schmurz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/01 16:28:01 by schmurz           #+#    #+#              #
#    Updated: 2018/03/02 13:40:30 by schmurz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

null :=
space := ${null} ${null}

LIBDIR = ./libft
LIBS = -lft
LIBNAME = libft.a
INCLUDES = ./includes
CHECKER = checker
PUSH_SWAP = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes
SRCDIR = ./
SRCFILES = check_input.c checker_operations.c push_swap_init.c verificators.c \
						extract_max_tab.c last_dist_and_cppile.c visualizator.c \
						calc_dists.c checker_operations2.c verificators2.c
CHECKER_FILES = $(SRCFILES) checker.c
PUSH_SWAP_FILES = $(SRCFILES) push_swap.c
CHECKER_SRC = $(subst ${space}, $(SRCDIR), $(CHECKER_FILES))
PUSH_SWAP_SRC = $(subst ${space}, $(SRCDIR), $(PUSH_SWAP_FILES))
CHECKER_OBJ = $(CHECKER_SRC:.c=.o)
PUSH_SWAP_OBJ = $(PUSH_SWAP_SRC:.c=.o)

all: $(LIBNAME) $(CHECKER) $(PUSH_SWAP)
		@printf "%b" "$(OK_COLOR)Finished : OK$(NO_COLOR)\n"

$(CHECKER): $(CHECKER_OBJ)
						@printf "%b" "$(COM_COLOR)Compiling : $(OBJ_COLOR)$(@)$(NO_COLOR)\n"
						@$(CC) -o $(CHECKER) -L$(LIBDIR) $(LIBS) $(CFLAGS) $(CHECKER_OBJ)

$(PUSH_SWAP): $(PUSH_SWAP_OBJ)
							@printf "%b" "$(COM_COLOR)Compiling : $(OBJ_COLOR)$(@)$(NO_COLOR)\n"
							@$(CC) -o $(PUSH_SWAP) -L$(LIBDIR) $(LIBS) $(CFLAGS) $(PUSH_SWAP_OBJ)

$(LIBNAME):
					@printf "%b" "$(COM_COLOR)Compiling : $(OBJ_COLOR)$(@)$(NO_COLOR)\n"
					@make -C $(LIBDIR)

clean:
	@rm -f $(CHECKER_OBJ) $(PUSH_SWAP_OBJ)
	@make clean -C $(LIBDIR)
	@printf "%b" "$(WARN_COLOR)Cleaned : All .o file are annihilated$(NO_COLOR)\n"

fclean: clean
	@rm -f $(CHECKER) $(PUSH_SWAP)
	@make fclean -C $(LIBDIR)
	@printf "%b" "$(WARN_COLOR)Fcleaned : Still there remains some ashes...$(NO_COLOR)\n"

re: fclean all

.SILENT: $(PUSH_SWAP_OBJ) $(CHECKER_OBJ)
