CC = gcc
LFLAGS = -lncurses

OBJS = monitor.o display.o stat.o
NAME = monitor

all	: monitor

monitor	: $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LFLAGS)

%.o	: src/%.c
	$(CC) -c $< -o $@

clean	:
	rm -rf $(OBJS) $(NAME) core.*
