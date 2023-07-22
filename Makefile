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
CFLAGS = -Wall -Wextra -Werror -I $(INC)
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
SRC = map_reader.c map_aux.c window_manager.c aux_functions.c key_hooks.c\
	mouse_hooks.c plot.c bresenham.c matrix.c apply.c run.c color.c apply_aux.c\
	rotate.c print.c project.c mouse_hooks2.c main.c

OBJDIR = obj

FDF_OBJ := $(SRC:%.c=$(OBJDIR)/%.o)

$(OBJDIR)/%.o:%.c
	@mkdir -p $(@D)
	$(COMPILE.c) -o $@ $<

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(FDF_OBJ) $(LIBX)
	@echo "$(WHITE)Compiling" $@
	@$(CC) $(FDF_OBJ) $(LIBFT) $(PRINTF) -L$(MLX) $(FLAGX) -o $@
	@chmod +x fdf
	@echo "$(PURPLE)************DONE****************\n"

$(PRINTF) $(LIBFT) &:
	@echo "$(WHITE)Making Libft"
	@cd libft; make bonus;
	@echo "$(WHITE)Making ft_printf"
	@$(MAKE) -C ft_printf
	@echo "$(GREEN)Finished!!!"

$(LIBX): $(BETAX)
	@echo "$(LIGHTPURPLE)Building MLX"
	@$(MAKE) -C $(MLX) 2>/dev/null

$(BETAX):
	@$(MAKE) -C $(BETA) 2>/dev/null

fclean: clean
	@cd $(MLX); make clean;
	@cd $(BETA); make clean;
	@$(RM) $(NAME) fdf
	@echo "$(BLUE)\n*****************DONE Cleaning********************\n\n"

clean:
	@echo "$(RED)Cleaning libft and ft_printf"
	@(cd libft; make fclean)
	@(cd ft_printf; make fclean)
	@echo "$(YELLOW)Cleaning Object files"
	@$(RM) $(FDF_OBJ) $(OBJDIR)
	@echo "Cleaning fdf"
	

re: fclean all

.PHONY: all re fclean clean