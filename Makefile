
#minitalk variables
SRC_C	=	ft_client.c
SRC_S	=	ft_server.c
OBJ_S	=	ft_server.o
OBJ_C	=	ft_client.o
INC		=	ft_minitalk.h

#Compiling Variables:
CC			=	gcc
CFLAG		=	-Wall -Wextra -Werror
RM			=	rm -rf

#Colors:
GREEN		=	\e[38;5;118m
YELLOW		=	\e[38;5;226m
RESET		=	\e[0m
_SUCCESS	=	[$(GREEN)SUCCESS$(RESET)]
_INFO		=	[$(YELLOW)INFO$(RESET)]

all: ft_printf/libftprintf.a client server

server: $(OBJ_S) $(INC)
	$(CC) $(CFLAGS) ft_printf/libftprintf.a -o $@ $(OBJ_S)
	@printf "$(_SUCCESS) server ready.\n"

client: $(OBJ_C) $(INC)
	$(CC) $(CFLAGS) ft_printf/libftprintf.a -o $@ $(OBJ_C)
	@printf "$(_SUCCESS) client ready.\n"

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

ft_printf/libftprintf.a:
	$(MAKE) -C ft_printf

clean:
	$(MAKE) clean -C ft_printf
	$(RM) $(OBJ_C) $(OBJ_S)
	@printf "$(_INFO) object files removed.\n"

fclean: clean
	$(MAKE) fclean -C ft_printf
	$(RM) client server
	@printf "$(_INFO) client removed.\n"
	@printf "$(_INFO) server removed.\n"

re: fclean all

.PHONY: all clean fclean re
