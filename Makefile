# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pde-rent <pde-rent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/22 23:12:10 by pde-rent          #+#    #+#              #
#    Updated: 2018/04/11 18:20:40 by pde-rent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME2 = checker

all: $(NAME)

$(NAME):
	@$(MAKE) -C _solver/ all
	@$(MAKE) -C _checker/ all
	@cp _solver/push_swap .
	@cp _checker/checker .

clean:
	@$(MAKE) -C _solver/ clean
	@$(MAKE) -C _checker/ clean
	
fclean: clean
	@printf "[$(NAME)] erasing\t\t$(PINK)$(NAME)$(WHITE)"
	@rm -f $(NAME)
	@printf '\t\t\t'$(OK)'\n'
	@printf "[$(NAME2)] erasing\t\t$(PINK)$(NAME2)$(WHITE)"
	@rm -f $(NAME2)
	@printf '\t\t\t'$(OK)'\n'

re:
	@$(MAKE) -C _solver/ fclean
	@$(MAKE) -C _checker/ fclean
	
re: fclean all
