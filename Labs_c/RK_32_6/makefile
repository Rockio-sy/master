CC := gcc
CFLAGS := -Wall -Werror -std=gnu99

%.o : %.c %.h
	@$(CC) $(CFLAGS) -o $@ -c $<

app : main.c io.c
	@$(CC) $(CFLAGS) -o $@ $^

clean :
	@rm -f *.o app