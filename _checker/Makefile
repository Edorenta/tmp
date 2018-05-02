# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/22 23:12:10 by pde-rent          #+#    #+#              #
#    Updated: 2018/04/11 18:23:27 by pde-rent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= checker

SRCS_PATH	= ./srcs
OBJS_PATH	= ./objs

# src / obj files
SRCS		= main.c

OBJS		= $(addprefix $(OBJS_PATH)/,$(SRCS:.c=.o))

# compiler
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

#color
YELLOW		= "\\033[33m"
BLUE		= "\\033[34m"
RED			= "\\033[31m"
WHITE		= "\\033[0m"
CYAN		= "\\033[36m"
GREEN		= "\\033[32m"
BOLD		= "\\033[1m"
PINK		= "\\033[95m"

#command
EOLCLR		= "\\033[0K"

#unicode
CHECK		= "\\xE2\\x9C\\x94"
OK			= " $(CYAN)$(CHECK)$(WHITE)"

all: obj_dir $(NAME)

obj_dir:
	@mkdir -p $(OBJS_PATH) 
	
$(OBJS_PATH)/%.o:$(SRCS_PATH)/%.c
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME): $(OBJS)
	@$(CC) $(OBJS) -o $(NAME)
	@printf "$(EOLCLR)[$(NAME)] >>>>>>>>>>>>>>>>>\t$(GREEN)$(BOLD)"\
	"$(NAME) compiled\t"$(OK)'\n'

clean:
	@printf "[$(NAME)] cleaning\t\t$(PINK)all obj file$(WHITE)"
	@rm -rf $(OBJS_PATH)
	@printf '\t\t'$(OK)'\n'

fclean: clean
	@printf "[$(NAME)] erasing\t\t$(PINK)$(NAME)$(WHITE)"
	@rm -f $(NAME)
	@printf '\t\t\t'$(OK)'\n'

re: fclean all
