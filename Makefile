# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yzaytoun <yzaytoun@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/03 19:16:59 by yzaytoun          #+#    #+#              #
#    Updated: 2022/11/02 21:07:52by yzaytoun         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

vpath %.c src
vpath %.h include
vpath %_bonus.c bonus
vpath %.o obj


# ************************ Colors ***********************************
ifneq (,$(findstring xterm,${TERM}))
	BLACK        := $(shell tput -Txterm setaf 0)
	RED          := $(shell tput -Txterm setaf 1)
	GREEN        := $(shell tput -Txterm setaf 2)
	YELLOW       := $(shell tput -Txterm setaf 3)
	LIGHTPURPLE  := $(shell tput -Txterm setaf 4)
	PURPLE       := $(shell tput -Txterm setaf 5)
	BLUE         := $(shell tput -Txterm setaf 6)
	WHITE        := $(shell tput -Txterm setaf 7)
	RESET := $(shell tput -Txterm sgr0)
else
	BLACK        := ""
	RED          := ""
	GREEN        := ""
	YELLOW       := ""
	LIGHTPURPLE  := ""
	PURPLE       := ""
	BLUE         := ""
	WHITE        := ""
	RESET        := ""
endif

# --------------------- Definitions ------------------------------------
CC = gcc 
AR = ar
ARFLAGS = -rcs
INC = include
CFLAGS = -Wall -Wextra -Werror -I $(INC) -g3
RM = rm -fr
SANITIAZE = -fsanitize=address -g3
# --------------------- MLX  ------------------------------------
FLAGX = -lmlx -framework OpenGL -framework AppKit
MLX = minilibx_macos
LIBX = minilibx_macos/libmlx.a
BETA = minilibx_mms_20191025_beta
BETAX = minilibx_mms_20191025_beta/libmlx.dylib
# ------------------ Libft and printf ------------------------------
PRINTF = ft_printf/libftprintf.a
LIBFT = libft/libft.a
# ------------------------ FDF ------------------------------
SRC = map_reader.c map_aux.c window_manager.c aux_functions.c key_events.c\
	mouse_events.c plot.c bresenham.c matrix.c apply.c matrix_aux.c run.c\
	rotate.c print.c project.c matrix_operations.c

OBJDIR = obj

FDF_OBJ := $(SRC:%.c=$(OBJDIR)/%.o)

$(OBJDIR)/%.o:%.c
	@mkdir -p $(@D)
	$(COMPILE.c) -o $@ $<

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(FDF_OBJ) $(LIBX)
	@echo "$(YELLOW)Compiling" $@
	@$(CC) $(FDF_OBJ) $(LIBFT) $(PRINTF) -L$(MLX) $(FLAGX) main.c -o $@ $(SANITIAZE)
	@chmod +x fdf
	@echo "$(PURPLE)************DONE****************\n"

$(PRINTF) $(LIBFT) &:
	@echo "$(YELLOW)Making Libft"
	@cd libft; make bonus;
	@echo "$(YELLOW)Making ft_printf"
	@$(MAKE) -C ft_printf
	@echo "$(GREEN)Finished!!!"

$(LIBX): $(BETAX)
	@$(MAKE) -C $(MLX)

$(BETAX):
	@$(MAKE) -C $(BETA)

fclean: clean
	@cd $(MLX); make clean;
	@cd $(BETA); make clean;
	@$(RM) $(NAME) fdf

clean:
	@echo "$(RED)Cleaning libft and ft_printf"
	@(cd libft; make fclean)
	@(cd ft_printf; make fclean)
	@echo "$(YELLOW)Cleaning Object files"
	@$(RM) $(FDF_OBJ) $(OBJDIR)
	@echo "Cleaning fdf"
	@echo "$(BLUE)\n*****************DONE Cleaning********************\n\n"

re: fclean all #bonus

#Add bonus
.PHONY: all re fclean clean