TARGET	= factorization
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= factorization.c
OBJS	= factorization.o
BIN_PATH = /usr/local/bin

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
	cp factorization $(BIN_PATH)

clean :
	rm $(OBJS)

fclean : clean
	rm $(TARGET) $(BIN_PATH)/$(TARGET)

re : fclean all

.PHONY: clean fclean re
