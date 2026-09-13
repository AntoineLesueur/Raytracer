CXX := g++

CXXFLAGS += -Wall -Wextra

CPPFLAGS +=	-I ./include

MAIN	:= 	main.cpp	\

SRC_DIR	:=	src/

OBJ_DIR	:=	obj/

SRC		:=		

SRC		:=	$(addprefix $(SRC_DIR), $(SRC:=.cpp))

OBJ_MAIN :=	$(patsubst %.cpp, $(OBJ_DIR)%.o, $(MAIN))

OBJ		:=	$(patsubst $(SRC_DIR)%.cpp, $(OBJ_DIR)%.o, $(SRC))

NAME	:=	raytracer

all: $(NAME)

$(NAME): $(OBJ_MAIN) $(OBJ)
	$(CXX) -o $(NAME) $(OBJ_MAIN) $(OBJ)

obj/%.o: %.cpp
	mkdir -p obj
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

obj/%.o: $(SRC_DIR)%.cpp
	mkdir -p obj
	$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)
	$(RM) $(OBJ) $(OBJ_MAIN)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all re clean fclean
