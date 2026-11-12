NAME := raytracer

BUILD_DIR := build

all:
	cmake -S . -B $(BUILD_DIR) -DOpenCV_DIR=/usr/local/lib64/cmake/opencv4
	cmake --build $(BUILD_DIR) -j$(shell nproc)
	cp $(BUILD_DIR)/$(NAME) ./$(NAME)

clean:
	$(RM) -r $(BUILD_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
