################################################################################
######                             PROPERTIES                             ######
################################################################################

CC			= cc
RM			= rm -rf
CFLAGS		= -Wall -Wextra -Werror -MD -MP -g -I $(INCLUDES)
MAKEFLAGS	= -j$(nproc) --no-print-directory

NAME		= so_long
NAME_B		= so_long_bonus

SRCSDIR		= srcs
INCLUDES	= includes

SRCS		= \
			$(SRCSDIR)/main.c \
			$(SRCSDIR)/display.c \
			$(SRCSDIR)/display_utils.c \
			$(SRCSDIR)/map.c \
			$(SRCSDIR)/map_utils.c \
			$(SRCSDIR)/free.c \
			$(SRCSDIR)/put_border.c \
			$(SRCSDIR)/movements.c \
			$(SRCSDIR)/flood_fill.c \
			$(SRCSDIR)/symbol_check.c \

SRCS_B		= \
			$(SRCSDIR)/main_bonus.c \
			$(SRCSDIR)/display_bonus.c \
			$(SRCSDIR)/display_utils.c \
			$(SRCSDIR)/map.c \
			$(SRCSDIR)/map_utils.c \
			$(SRCSDIR)/free.c \
			$(SRCSDIR)/put_border.c \
			$(SRCSDIR)/movements_bonus.c \
			$(SRCSDIR)/flood_fill.c \
			$(SRCSDIR)/symbol_check_bouns.c \

OBJSDIR		= objs
OBJS		= $(addprefix $(OBJSDIR)/, $(SRCS:.c=.o))
DEPS		= $(addprefix $(OBJSDIR)/, $(SRCS:.c=.d))

OBJSDIR_B	= objs_bonus
OBJS_B		= $(addprefix $(OBJSDIR_B)/, $(SRCS_B:.c=.o))
DEPS_B		= $(addprefix $(OBJSDIR_B)/, $(SRCS_B:.c=.d))

################################################################################
######                               LIBFT                                ######
################################################################################

LIBDIR		= ./libft
LIBFT		= ${LIBDIR}/libft.a

################################################################################
######                               RULES                                ######
################################################################################

all		: $(NAME)

bonus	: $(NAME_B)

$(NAME)	: ${OBJS}
		$(MAKE) -C ${LIBDIR} all
		$(CC) ${CFLAGS} -o $@ $^ -L. ${LIBFT} -lX11 -lXext -lmlx

# -Lminilibx-linux -lmlx_Linux -lX11 -lXext
# -lX11 -lXext -lmlx

$(NAME_B)	: ${OBJS_B}
		$(MAKE) -C ${LIBDIR} all
		$(CC) ${CFLAGS} -o $@ $^ -L. ${LIBFT} -lX11 -lXext -lmlx

${OBJSDIR}/%.o	: %.c
		@mkdir -p $(dir $@)
		${CC} ${CFLAGS} -c $< -o $@

${OBJSDIR_B}/%.o	: %.c
		@mkdir -p $(dir $@)
		${CC} ${CFLAGS} -c $< -o $@

clean	:
		$(MAKE) -C ${LIBDIR} clean
		$(RM) $(OBJSDIR) $(OBJSDIR_B)

fclean	:
		$(MAKE) -C ${LIBDIR} fclean
		$(RM) $(OBJSDIR) $(NAME) $(OBJSDIR_B) $(NAME_B)

re		:
		$(MAKE) -C ${LIBDIR} fclean
		$(RM) $(OBJSDIR) $(NAME)
		$(MAKE) all

reb		:
		$(MAKE) -C ${LIBDIR} fclean
		$(RM) $(OBJSDIR_B) $(NAME_B)
		$(MAKE) bonus

-include $(DEPS)

.PHONY	: all clean fclean re bonus reb
