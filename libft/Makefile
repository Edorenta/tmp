#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/07 17:38:00 by pde-rent          #+#    #+#              #
#    Updated: 2018/03/15 12:55:18 by pde-rent         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME    	= libft.a
SRCS_PATH	= srcs/
OBJS_PATH	= objs/
I_PATH		= include/
FLAGS		= -Wall -Werror -Wextra -g -I$(I_PATH) -Wpedantic
CC			= gcc $(FLAGS)
SRC_SUBDIRS	= $(shell find $(SRCS_PATH) -type d)
SRCS		= $(shell find $(SRCS_PATH) -type f -name "*.c")
OBJS		= $(shell find $(SRCS_PATH) -type f -name "*.o")
NAME_P		= $(shell echo $(NAME) | tr ' ' '\n' |\
				sed "s/\.[acoh]$///g" | tr '\n' ' ' | sed "s/ $///g")
OBJS_TRACKER= .objs_exist
#MAKEFLAGS	+=-j

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

# ONLY FOR LONG TERM IMPROVEMENT
all: $(NAME)

$(NAME): $(OBJS_TRACKER)
	@printf "\r$(EOLCLR)[$(NAME_P)] >>>>>>>>>>>>>>>\t$(YELLOW)$(BOLD)"\
	"all binaries compiled\t"$(OK)'\n'
	@cp $(OBJS) $(OBJS_PATH)
	@printf "[$(NAME_P)] running\t\t$(WHITE)ar rc $@$(WHITE)"
	@ar rc $(NAME) $(OBJS)
	@printf '\t\t'$(OK)'\n'
	@printf "[$(NAME_P)] running\t\t$(WHITE)ranlib $@$(WHITE)"
	@ranlib	$(NAME)
	@printf '\t\t'$(OK)'\n'
	@printf "\r$(EOLCLR)[$(NAME_P)] >>>>>>>>>>>>>>>\t$(GREEN)$(BOLD)"\
	"build successful\t"$(OK)'\n'

$(OBJS_TRACKER): $(SRCS) #| $(OBJS)
	@mkdir -p $(OBJS_PATH)
	@touch $(OBJS_TRACKER)
	@$(MAKE) -C srcs/array_container/
	@$(MAKE) -C srcs/list_container/
	@$(MAKE) -C srcs/string_container/
	@$(MAKE) -C srcs/char_class/
	@$(MAKE) -C srcs/maths_op/
	@$(MAKE) -C srcs/memory_mgmt/
	@$(MAKE) -C srcs/string_mgmt/
	@$(MAKE) -C srcs/stream_mgmt/
	@$(MAKE) -C srcs/table_mgmt/
	@$(MAKE) -C srcs/output_mgmt/
	@$(MAKE) -C srcs/tree_nodes/
	@$(MAKE) -C srcs/unicode/
	@$(MAKE) -C srcs/parsing/

clean:
	@printf "[$(NAME_P)] cleaning\t$(PINK)all obj files$(WHITE)"
	@$(MAKE) -C srcs/array_container/ clean
	@$(MAKE) -C srcs/list_container/ clean
	@$(MAKE) -C srcs/string_container/ clean
	@$(MAKE) -C srcs/char_class/ clean
	@$(MAKE) -C srcs/maths_op/ clean
	@$(MAKE) -C srcs/memory_mgmt/ clean
	@$(MAKE) -C srcs/string_mgmt/ clean
	@$(MAKE) -C srcs/stream_mgmt/ clean
	@$(MAKE) -C srcs/table_mgmt/ clean
	@$(MAKE) -C srcs/output_mgmt/ clean
	@$(MAKE) -C srcs/tree_nodes/ clean
	@$(MAKE) -C srcs/unicode/ clean
	@$(MAKE) -C srcs/parsing/ clean
	@rm -rf $(OBJS_PATH)
	@rm -f $(OBJS_TRACKER)
	@printf '\t\t'$(OK)'\n'

fclean: clean
	@$(MAKE) -C srcs/array_container/ fclean
	@$(MAKE) -C srcs/list_container/ fclean
	@$(MAKE) -C srcs/string_container/ fclean
	@$(MAKE) -C srcs/char_class/ fclean
	@$(MAKE) -C srcs/maths_op/ fclean
	@$(MAKE) -C srcs/memory_mgmt/ fclean
	@$(MAKE) -C srcs/string_mgmt/ fclean
	@$(MAKE) -C srcs/stream_mgmt/ fclean
	@$(MAKE) -C srcs/table_mgmt/ fclean
	@$(MAKE) -C srcs/output_mgmt/ fclean
	@$(MAKE) -C srcs/tree_nodes/ fclean
	@$(MAKE) -C srcs/unicode/ fclean
	@$(MAKE) -C srcs/parsing/ fclean
	@printf "[$(NAME_P)] erasing\t\t$(PINK)$(NAME)$(WHITE)"
	@rm -f $(NAME)
	@printf '\t\t\t'$(OK)'\n'

re: fclean all

norm :
	@norminette $(SRCS_PATH) $(I_PATH)

.PHONY: all clean fclean re test norm
