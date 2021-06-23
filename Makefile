.PHONEY: all clean fclean re

CLIENT_NAME		= client
SERVER_NAME		= server

CLIENT_SRC 	= src/client.c
SERVER_SRC 	= src/server.c

FLAGS		= -Werror -Wextra -Wall

all: $(CLIENT_NAME) $(SERVER_NAME)

$(SERVER_NAME):
	@gcc $(FLAGS) $(SERVER_SRC) -o server
$(CLIENT_NAME):
	@gcc $(FLAGS) $(CLIENT_SRC) -o client

clean:
	@echo "No object files to be cleaned!"

fclean:
	@rm -rf client server

re: fclean all
