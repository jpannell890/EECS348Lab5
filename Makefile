CC = gcc
CFLAGS = -Wall

OBJECTS = sales_report.o
all: prog

prog: $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o prog

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -rf *.o prog