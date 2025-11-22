# **************************************************************************** #
#                                Makefile (C++)                                #
# **************************************************************************** #

NAME     := accounts
CXX      := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -g3

OBJ_DIR  := obj/

SRCS     := tests.cpp Account.cpp

OBJS     := $(SRCS:%.cpp=$(OBJ_DIR)%.o)
DEPS     := $(SRCS:%.cpp=$(OBJ_DIR)%.d)

# **************************************************************************** #
#                                 Build Rules                                  #
# **************************************************************************** #

all: $(NAME)
	@echo "🔥 $(NAME) built successfully!"

$(NAME): $(OBJS)
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $@
	@echo "✅ $(NAME) object files compiled."
	@echo "🚀 $(NAME) created!"

$(OBJ_DIR)%.o: %.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "🗑️ $(NAME) object files removed."

fclean: clean
	@rm -f $(NAME)
	@echo "😒 $(NAME) and binary removed."

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
.DELETE_ON_ERROR:
