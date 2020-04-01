TARGET	= factorization
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= factorization.c
OBJS	= factorization.o

$(TARGET) : $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

all : $(TARGET)

clean :
	rm $(OBJS)

fclean : clean
	rm $(TARGET)

re : fclean all

.PHONY: $(TARGET) all clean fclean re
