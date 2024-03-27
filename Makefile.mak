# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maabdela-a <marvin@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/27 20:50:44 by maabdela-a          #+#    #+#            #
#    Updated: 2024/03/27 22:29:10 by maabdela-a         ###   ########.fr      #
#                                                                              #
# **************************************************************************** #
.SILENT:

# Colors
RESET = \033[0m       # Text Reset
BLACK = \033[1;30m       # Black
RED = \033[1;31m         # Red
GREEN = \033[1;32m       # Green
YELLOW = \033[1;33m      # Yellow
BLUE = \033[1;34m       # Blue
PURPLE = \033[1;35m     # Purple
CYAN = \033[1;36m        # Cyan
WHITE = \033[1;37m       # White

# compiler 
CC = gcc

# compiler flages
CFLAGS = -Wall -Wextra -Werror

# Target files
 SERVER = server 
 CLIENT = client 

 SER_OBJ = server.o 
 CLI_OBJ = client.o 

 UTILS = utils 
 UTL_OBJ = utils.o 

 $(SERVER): $(SER_OBJ) $(UTL_OBJ)
			$(cc) $(CFLAGS) $(SER_OBJ) $(UTL_OBJ) -o $(SERVER)
			printf "Server 			$(green)[SUCCESS]$(RESET)\n"

 $(client): $(CLI_OBJ) $(UTL_OBJ)
			$(cc) $(CFLAGS) $(CLI_OBJ) $(UTL_OBJ) -o $(CLIENT)
			printf "client			$(green)[SUCCESS]$(RESET)\n"

 clean:
		$(RM) $(CLIENT) $(SERVER)
		printf "fclean				$(CYAN)[SUCCESS]$(RESET)\n"

re:		fclean all
.PHONY: clean fclean all re norm		
