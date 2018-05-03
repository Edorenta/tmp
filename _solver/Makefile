# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pde-rent <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/12 12:43:59 by pde-rent          #+#    #+#              #
#    Updated: 2018/04/11 18:22:26 by pde-rent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= push_swap
NAME_P		= $(shell echo $(NAME) | tr ' ' '\n' |\
				sed "s/\.[acoh]$///g" | tr '\n' ' ' | sed "s/ $///g")
SRCS_PATH	= srcs/
OBJS_PATH	= objs/
INCLUDE		= -Iincludes
FLAGS		= -Wall
FLAGS_DBG	= -Wall -Werror -Wextra #-g -fsanitize=address
CC			= gcc $(FLAGS)
#CC_DBG		= gcc $(FLAGS

SRCS_SUFFIX  = .c
#SRCS_PREFIX =
SRCS_RAW     =  main				output_mgmt								\
				sort_mgmt			swap_operations		rot_operations		\
				rev_operations		get_stack			ai_push_min			\
				ai_preliminaries	ai_bubble_sort		ai_quick_sort		\
				libft_extract		libft_extract2

#SRCS_RAW2   = $(addprefix ${SRCS_PREFIX},${SRCS_RAW})
SRCS_FILES  = $(addsuffix $(SRCS_SUFFIX),$(SRCS_RAW))
OBJS_FILES	= $(SRCS_FILES:.c=.o)
SRCS		= $(addprefix $(SRCS_PATH),$(SRCS_FILES))
OBJS		= $(addprefix $(OBJS_PATH),$(OBJS_FILES))

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
#\033[<L>;<C>H puts the cursor at line L and column C
#\033[<N>A Move the cursor up N lines
#\033[<N>B Move the cursor down N lines
#\033[<N>C Move the cursor forward N columns
#\033[<N>D Move the cursor backward N columns
#\033[2J Clear the screen, move to (0,0)
#\033[K Erase to end of line
#\033[s Save cursor position
#\033[u Restore cursor position

TRACKER		= .project_built
#MAKEFLAGS	+= -j #multitasking

all : $(NAME)

$(NAME) : $(OBJS)
	@printf "$(EOLCLR)[$(NAME_P)] >>>>>>>>>>>>>>>\t$(YELLOW)$(BOLD)"\
	"dependencies compiled\t"$(OK)'\n'
	@$(CC) $(OBJS) -o $(NAME)
	@printf "$(EOLCLR)[$(NAME_P)] >>>>>>>>>>>>>>>\t$(GREEN)$(BOLD)"\
	"$(NAME) compiled\t"$(OK)'\n'

$(OBJS_PATH)%.o : $(SRCS_PATH)%.c | $(TRACKER)
	@printf "$(EOLCLR)[$(NAME_P)] compiling\t\t$(BOLD)$(YELLOW)$<$(WHITE)\r"
	@$(CC) $(INCLUDE) -o $@ -c $<

%.c:
	@printf "$(RED)Missing file : $@$(WHITE)\n"

$(TRACKER): $(SRCS)
	@touch $(TRACKER)
	@mkdir -p $(OBJS_PATH)

clean :
	@printf "[$(NAME_P)] cleaning\t\t$(PINK)all obj file$(WHITE)"
	@rm -rf $(OBJS_PATH)
	@rm -f $(TRACKER)
	@printf '\t\t'$(OK)'\n'

fclean : clean
	@printf "[$(NAME_P)] erasing\t\t$(PINK)$(NAME)$(WHITE)"
	@rm -f $(NAME)
	@printf '\t\t'$(OK)'\n'

re : fclean
	@$(MAKE) all

norm :
	@norminette srcs/ includes/

.PHONY : all clean fclean re norm
