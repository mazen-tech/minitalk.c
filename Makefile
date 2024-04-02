# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maabdela <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/29 13:58:10 by maabdela          #+#    #+#              #
#    Updated: 2024/03/29 13:59:27 by maabdela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

RESET = \033[0m       # Text Reset
GREEN = \033[1;32m       # Green
CYAN = \033[1;36m        # Cyan

# compiler
 LIBFT = libft/libft.a
 CC = gcc 

# Cflags
 CFLAGS = -Wextra -Wall -Werror

# target
 PRINTF = ./printf/libftprintf.a
 PRINTFDIR = ./printf
 
 SERVER = server 
 SER_OBJ = server.o 

 CLIENT = client 
 CLI_OBJ = client.o 

 UTILS = utils 
 UTI_OBJ = utils.o 

 all: $(SERVER) $(CLIENT)

$(SERVER): $(SER_OBJ) $(UTI_OBJ) $(LIBFT)
		$(CC) $(CFLAGS) $(SER_OBJ) $(UTI_OBJ) libft/libft.a -o $(SERVER) 
		@printf "server				$(green)[OK]$(RESET)\n"

$(CLIENT): $(CLI_OBJ) $(UTI_OBJ) $(LIBFT)
		$(CC) $(CFLAGS) $(CLI_OBJ) $(UTI_OBJ) libft/libft.a -o $(CLIENT)
		@printf "client				$(green)[OK]$(RESET)\n"
				
$(LIBFT):
		${MAKE} -C ./libft
		
clean: 
	          $(RM) $(CLIENT) $(CLI_OBJ) $(SERVER) $(SER_OBJ) $(UTI_OBJ)
	   	 @printf "clean				$(CYAN)[OK]$(RESET)\n"
	    
fclean: clean 
		$(RM) $(LIBFT) $(SERVER) $(CLIENT)

 re:		fclean all
.PHONY: clean fclean all re norm
