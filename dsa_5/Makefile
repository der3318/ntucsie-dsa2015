target = system
CFLAGS = -O3 -Wall
CPPFLAGS = -O3 -std=c++11 -Wall

all: $(target)

%: %.c
	gcc $(CFLAGS) $< -o $@

%: %.cpp
	g++ $(CPPFLAGS) $< -o $@

system: system.cpp binomial_heap.h
	g++ $(CPPFLAGS) system.cpp -o $@

clean:
	rm -rf $(target)

