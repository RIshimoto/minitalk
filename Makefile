NAME = client server
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBS = -lft
LDFLAGS = -L./libft
LIBFT = libft/libft.a
CLIENT = client.c
SERVER = server.c
CLIENT_OBJ = $(CLIENT:.c=.o)
SERVER_OBJ = $(SERVER:.c=.o)

all: $(NAME)

clean:
	$(MAKE) clean -C ./libft
	rm -rf $(CLIENT_OBJ)
	rm -rf $(SERVER_OBJ)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re: fclean all

client: $(CLIENT_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(LDFLAGS) $(CLIENT_OBJ) $(LIBS) 	

server : $(SERVER_OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(LDFLAGS) $(SERVER_OBJ) $(LIBS) 	

$(LIBFT):
	$(MAKE) -C ./libft

.PHONY: clean fclean re all
