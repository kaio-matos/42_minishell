LIBFT_DIR			= libft
OBJS_DIR			= objects
SRC_DIR				= src
MANDATORY_DIR		= mandatory
BONUS_DIR			= bonus

CC					= cc
CCF_STRICT			= -Wall -Wextra -Werror
CCF_DEBUG			= -g3 -D VERBOSE=1

LIBFT				= $(LIBFT_DIR)/libft.a
LIBS				= $(LIBFT) -lreadline
RM					= rm -rf

ifdef VERBOSE
	CCF_STRICT += $CCF_DEBUG
endif

################################################################################
# MANDATORY
################################################################################

NAME				= minishell
CCF_INCL_MANDATORY	= -I ./$(LIBFT_DIR)/includes -I ./$(SRC_DIR)/$(MANDATORY_DIR)/includes

C_BOOTSTRAP			= $(addprefix bootstrap/, bootstrap.c)
C_BUILTINS			= $(addprefix builtins/, cd.c echo.c env.c exit.c export.c pwd.c unset.c)
C_VARIABLES			= $(addprefix variables/, dollar.c)
C_INPUT				= $(addprefix input/, i__request_command.c i__parse_command.c)
C_CASTING			= $(addprefix casting/, c__int.c c__str.c)

C_FILES_MANDATORY	= main.c $(C_BOOTSTRAP) $(C_BUILTINS) $(C_VARIABLES) $(C_INPUT) $(C_CASTING)
FILES_MANDATORY		= $(addprefix $(MANDATORY_DIR)/,$(C_FILES_MANDATORY))
SRCS_MANDATORY		= $(addprefix src/,$(FILES_MANDATORY))
OBJS_MANDATORY		= $(addprefix $(OBJS_DIR)/,$(FILES_MANDATORY:.c=.o))

all: $(NAME)

$(NAME): $(OBJS_MANDATORY) $(LIBFT)
	$(CC) $(OBJS_MANDATORY) $(LIBS) -o $(NAME)

$(OBJS_DIR)/$(MANDATORY_DIR)/%.o: $(SRC_DIR)/$(MANDATORY_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CCF_STRICT) $(CCF_INCL_MANDATORY) -c $< -o $@

debug:
	@echo "Compiling..."
	@make debug -C $(LIBFT_DIR) --no-print-directory
	@$(CC) $(CCF_DEBUG) $(CCF_INCL_MANDATORY) $(SRCS_MANDATORY) $(LIBFT_DIR)/libft_debug.a -o $(NAME)

rebuild:
	@make all -C $(LIBFT_DIR) --no-print-directory
	@$(CC) $(CCF_STRICT) $(CCF_INCL_MANDATORY) $(SRCS_MANDATORY) $(LIBS) -o $(NAME)

################################################################################
# BONUS
################################################################################

# NAME_B				= $(NAME)__bonus
# CCF_INCL_BONUS		= -I ./$(SRC_DIR)/$(BONUS_DIR)/includes -I $(LIBFT_DIR)
# C_FILES_BONUS		= main_bonus.c

# FILES_BONUS			= $(addprefix $(BONUS_DIR)/,$(C_FILES_BONUS))
# SRCS_BONUS			= $(addprefix src/,$(FILES_BONUS))
# OBJS_BONUS			= $(addprefix $(OBJS_DIR)/,$(FILES_BONUS:.c=.o))

# bonus: $(NAME_B)

# $(NAME_B): $(OBJS_BONUS) $(LIBFT)
# 	$(CC) $(OBJS_BONUS) $(LIBS) -o $(NAME_B)

# $(OBJS_DIR)/$(BONUS_DIR)/%.o : $(SRC_DIR)/$(BONUS_DIR)/%.c
# 	mkdir -p $(dir $@)
# 	$(CC) $(CCF_STRICT) $(CCF_INCL_BONUS) -c $< -o $@

################################################################################
# LIBFT
################################################################################

$(LIBFT):
	make all -C $(LIBFT_DIR)

################################################################################
# CLEAN UP
################################################################################

clean:
	make clean -C $(LIBFT_DIR)
	$(RM) $(OBJS_DIR)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	$(RM) $(NAME_B)
	$(RM) $(NAME)

re:	fclean all

################################################################################
# CONFIGURATION
################################################################################

.PHONY: all bonus clean libft fclean re rebuild debug

################################################################################
# Colors
################################################################################

# Black, Red, Green, Yellow, Blue, Purple, Cyan, White
BK = \033[0;30m
R = \033[0;31m
G = \033[0;32m
Y = \033[0;33m
B = \033[0;34m
P = \033[0;35m
C = \033[0;36m
W = \033[0;37m
# Bold
BKB = \033[1;30m
RB = \033[1;31m
GB = \033[1;32m
YB = \033[1;33m
BB = \033[1;34m
PB = \033[1;35m
CB = \033[1;36m
WB = \033[1;37m
# Reset Color
RC = \033[0m
