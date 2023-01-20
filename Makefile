SERVER	=	server
CLIENT	=	client
SERVERB	=	server_bonus
CLIENTB	=	client_bonus
#ft_printf Variables:
LIBFTPRINTF	=	ft_printf/libftprintf.a

#minitalk variables
SRC_C	=	ft_client.c
SRC_S	=	ft_server.c
SRCB_C	=	ft_client_bonus.c
SRCB_S	=	ft_server_bonus.c
OBJ_S	=	ft_server.o
OBJ_C	=	ft_client.o
OBJB_S	=	ft_server_bonus.o
OBJB_C	=	ft_client_bonus.o
INC		=	ft_minitalk.h
INCB	=	ft_minitalk_bonus.h

#Compiling Variables:
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

_SUCCESS	=	\e[38;5;118m[SUCCESS]\e[0m
_INFO		=	\e[38;5;226m[INFO]\e[0m

all: $(LIBFTPRINTF) $(CLIENT) $(SERVER)

bonus: $(LIBFTPRINTF) $(CLIENTB) $(SERVERB)

$(SERVERB): $(OBJB_S) $(INCB)
	@ $(CC) $(CFLAGS) $(LIBFTPRINTF) -o $@ $(OBJB_S)
	@printf "$(_SUCCESS) server ready.\n"

$(CLIENTB): $(OBJB_C) $(INCB)
	@ $(CC) $(CFLAGS) $(LIBFTPRINTF) -o $@ $(OBJB_C)
	clear
	@printf "$(_SUCCESS) client ready.\n"

$(SERVER): $(OBJ_S) $(INC)
	@ $(CC) $(CFLAGS) $(LIBFTPRINTF) -o $@ $(OBJ_S)
	@printf "$(_SUCCESS) server ready.\n"

$(CLIENT): $(OBJ_C) $(INC)
	@ $(CC) $(CFLAGS) $(LIBFTPRINTF) -o $@ $(OBJ_C)
	clear
	@printf "$(_SUCCESS) client ready.\n"

%.o: %.c
	@ $(CC) $(CFLAGS) -c $< -o $@

$(LIBFTPRINTF):
	$(MAKE) -C ft_printf

clean:
	@ $(MAKE) clean -C ft_printf
	@ $(RM) $(OBJ_C) $(OBJ_S) $(OBJB_C) $(OBJB_S)
	clear
	@printf "$(_INFO) object files removed.\n"

fclean: clean
	@ $(MAKE) fclean -C ft_printf
	@ $(RM) client server client_bonus server_bonus
	clear
	@printf "$(_INFO) client removed.\n"
	@printf "$(_INFO) server removed.\n"

re: fclean all

.PHONY: all clean fclean re