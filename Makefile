NAME = embed
SRCS =	srcs/main.cpp srcs/prgm_loop.cpp \
		srcs/sdl_init.cpp srcs/exit_prgm.cpp \
		srcs/load_media_main.cpp srcs/c_device_part.cpp srcs/txts_init.cpp \
		srcs/set_sprite_start_pos.cpp srcs/render.cpp srcs/input.cpp \
		srcs/render_dynamic.cpp


OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	g++ $(OBJS) -w -lSDL2 -lSDL2_image -o $(NAME)
#-r (recursive): deletes files before the folder
#-f (force): ignore non-existant files, and never prompt before removing.
clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
