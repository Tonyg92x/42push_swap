# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aguay <aguay@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/31 08:51:26 by mmondell          #+#    #+#              #
#    Updated: 2022/02/21 07:29:22 by aguay            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#*#######################################################
##*          ERASE COMMENTS FOR BONUS PARTS            ##
#*#######################################################

## -----  NAME OF THE PROGRAMM ----- ##
NAME 			= push_swap 

## ----- NAME OF THE BONUS PART ----- ##
B_NAME			= push_swap_bonus

## ----- CHOOSE COMPILER AND FLAGS ----- ##
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -g

## ----- PATH TO FOLDERS ----- ##
SRCS_DIR		= srcs/
#*B_SRCS_DIR		= 

OBJ_DIR			= obj/

INCLUDE_DIR		= includes/

LIBFT_DIR		= libft

LIBFT_OBJ		= libft/obj/

LIBFT_INC		= libft/includes/

## ----- SOURCE FILES ----- ##
SRCS_FILES		=				\
			main.c				\
			l_list.c			\
			l_list_utils.c		\
			ft_itol.c			\
			math.c				\
			ft_free2d.c			\
			push.c				\
			reverse_rotate.c	\
			rotate.c			\
			swap.c				\
			sort.c				\
			sort_utils.c		\
			sort_utils2.c		\

## ----- BONUS SOURCE FILES ----- ##
#*B_SRCS_FILES	= 

## ----- .C TO .O CONVERT ----- ##
OBJ_FILES		= $(SRCS_FILES:.c=.o)
#*B_OBJ_FILES		= $(B_SRCS_FILES:.c=.o)

## ----- ADDPREFIX TO FILES ----- ##
# MAIN PROGRAMM #
SRCS			= $(addprefix $(SRCS_DIR), $(SRCS_FILES))
OBJS			= $(addprefix $(OBJ_DIR), $(OBJ_FILES))
VPATH			= $(SRCS_DIR) #$(B_SRCS_DIR)

# BONUS PART #
#*B_SRCS			= $(addprefix $(B_SRCS_DIR), $(B_SRCS_FILES))
#*B_OBJS			= $(addprefix $(OBJ_DIR), $(B_OBJ_FILES))

#--------------------------------------------------------------#

## ----- TOOLS AND COLORS ----- ##
RM			= rm -Rf
NO_PRINT		= --no-print-directory
RED 			= \033[31m
GREEN 			= \033[32m
YELLOW 			= \033[33m
BLUE 			= \033[34m
PINK 			= \033[35m
AQUA 			= \033[36m
GREY 			= \033[37m
UNDERLINE 		= \033[4m
NORMAL 			= \033[0m

LIBFT			= make -C $(LIBFT_DIR)

## ----- ALL ACTION DEPENDENCIES AND RECIPE FOR MAIN PROGRAM ----- ##
all: obj $(NAME)
	@echo "$(GREEN)Compilation Completed Successfully$(NORMAL)"

$(OBJ_DIR)%.o:%.c
	$(CC) $(CFLAGS) -I $(LIBFT_OBJ) -I $(INCLUDE_DIR) -I $(LIBFT_INC) -o $@ -c $<

$(NAME): $(OBJS)
	$(LIBFT)
	$(CC) $(OBJS) libft/libft.a -o $(NAME)
obj:
	@mkdir -p $(OBJ_DIR)

## ----- ACTIONS FOR THE BONUS PART ----- ##
#*bonus: $(B_NAME)
#*	@echo "$(GREEN)Bonus Files Compiled!$(NORMAL)"
#*
#*$(B_NAME): $(B_OBJS)
#*	$(LIBFT)
#*	$(CC) $(B_OBJS) -L$(LIBFT_DIR) -lft -o $(B_NAME)
	
## ----- CLEAN COMMANDS ----- ##
clean:
	$(RM) $(OBJS) ##$(B_OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	@rm -f $(NAME)
#*	$(RM) $(B_NAME) $(OBJ_DIR)
	@make -C $(LIBFT_DIR) fclean

re: fclean all bonus

.PHONY: all clean fclean re
