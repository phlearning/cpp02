# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pvong <marvin@42lausanne.ch>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/06 16:22:47 by pvong             #+#    #+#              #
#    Updated: 2023/11/06 16:28:21 by pvong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Fixed

# Compilation 
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

# Headers

INC = -I include

# Build

SRC_DIR = src
OBJ_DIR = obj

SRC = Fixed.cpp \
		main.cpp

SRC := $(addprefix $(SRC_DIR)/, $(SRC))
OBJ := $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(INC) $(CXXFLAGS) -c $< -o $@ 

$(NAME): $(OBJ)
	$(CXX) $(INC) $(CXXFLAGS) -o $@ $^

run: $(NAME)
	./$(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re