TARGET=market
DTARGET=market_debug
CFLAGS=-W -Wall
OBJECTS=main.c product.o manager.o
CC=gcc

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

$(DTARGET): $(OBJECTS)
	$(CC) -DDEBUG $(CFLAGS) $^ -o $@ 
clean : 
	rm -r *.o $(TARGET) $(DTARGET)
