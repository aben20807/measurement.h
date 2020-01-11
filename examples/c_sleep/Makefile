CC := gcc
CFLAGS := -std=gnu99 -Wall

TARGET := sleep.out

$(TARGET): sleep.c
	$(CC) $(CFLAGS) -o $@ $<

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)
