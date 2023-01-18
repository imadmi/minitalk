#ft_printf Variables:
LIBFTPRINTF	=	ft_printf/libftprintf.a

#minitalk variables
SRC_C	=	ft_client.c
SRC_S	=	ft_server.c
OBJ_S	=	ft_server.o
OBJ_C	=	ft_client.o
INC		=	ft_minitalk.h

#Compiling Variables:
CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

_SUCCESS	=	[\e[38;5;118mSUCCESS\e[0m]
_INFO		=	[\e[38;5;226mINFO\e[0m]

all: $(LIBFTPRINTF) client server

server: $(OBJ_S) $(INC)
	@ $(CC) $(CFLAGS) $(LIBFTPRINTF) -o $@ $(OBJ_S)
	@printf "$(_SUCCESS) server ready.\n"

client: $(OBJ_C) $(INC)
	@ $(CC) $(CFLAGS) $(LIBFTPRINTF) -o $@ $(OBJ_C)
	clear
	@printf "$(_SUCCESS) client ready.\n"

%.o: %.c
	@ $(CC) $(CFLAGS) -c $< -o $@

$(LIBFTPRINTF):
	$(MAKE) -C ft_printf

clean:
	@ $(MAKE) clean -C ft_printf
	@ $(RM) $(OBJ_C) $(OBJ_S)
	clear
	@printf "$(_INFO) object files removed.\n"

fclean: clean
	@ $(MAKE) fclean -C ft_printf
	@ $(RM) client server
	clear
	@printf "$(_INFO) client removed.\n"
	@printf "$(_INFO) server removed.\n"

re: fclean all

.PHONY: all clean fclean re