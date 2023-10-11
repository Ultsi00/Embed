NAME = embed
SRCS =	srcs/main.cpp srcs/prgm_loop.cpp srcs/c_parameters.cpp \
		srcs/sdl_init.cpp srcs/exit_prgm.cpp srcs/key_events.cpp \
		srcs/load_media.cpp srcs/c_device_part.cpp srcs/txts_init.cpp

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
