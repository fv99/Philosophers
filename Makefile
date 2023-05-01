# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvonsovs <fvonsovs@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/24 15:47:13 by fvonsovs          #+#    #+#              #
#    Updated: 2023/05/01 14:57:32 by fvonsovs         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	gcc
CFLAGS		=	-pthread -lpthread -lrt -Wall -Wextra -Werror -g -fsanitize=address
NAME		=	philo
SRCS		=	main.c philo_utils.c libft_utils.c input_check.c philo.c
OBJS		=	${SRCS:.c=.o}
BONUS_NAME	=	philo_bonus
BONUS		=	main_bonus.c
BONUS_OBJS	=	$(BONUS:.c=.o)
LIBC		=	ar -cq
RM			=	rm -f

# Colors
GREEN		=	\033[0;32m
YELLOW		=	\033[0;33m
RESET		=	\033[0m

.c.o:
	@echo "${YELLOW}Compiling: ${GREEN}$<${RESET}"
	@${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I.

all: $(NAME)

$(NAME): ${OBJS}
	@echo "${YELLOW}Linking objects...${RESET}"
	@${CC} ${CFLAGS} -o ${NAME} ${OBJS}
	@echo "${GREEN}Compilation successful.${RESET}"

BONUS_OBJS_MAINLESS = $(filter-out main.o, ${OBJS})

$(BONUS_NAME): ${BONUS_OBJS} ${BONUS_OBJS_MAINLESS}
	@echo "${YELLOW}Linking objects...${RESET}"
	@${CC} ${CFLAGS} -o ${BONUS_NAME} ${BONUS_OBJS} ${BONUS_OBJS_MAINLESS}

bonus: ${BONUS_NAME}
	@echo "${YELLOW}Compiling bonus...${RESET}"
	@${MAKE} $(BONUS_NAME)
	@echo "${GREEN}Compilation successful.${RESET}"

clean: 
	@echo "${YELLOW}Removing object files...${RESET}"
	@${RM} ${OBJS} ${BONUS_OBJS}

fclean: clean
	@echo "${YELLOW}Removing executable...${RESET}"
	@${RM} ${NAME} ${BONUS_NAME}

re: fclean all

.PHONY:	all clean fclean re
