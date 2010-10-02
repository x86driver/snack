TARGET = drink.cgi

CFLAGS = -Wall -g -lcgicc
all: $(TARGET)

drink.cgi:drink.cpp
	g++ $(CFLAGS) -o $@ $<

clean:
	rm -rf $(TARGET)

