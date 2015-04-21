target = 3_4_1.out 3_4_2.out
CFLAGS = -O3 -Wall
CPPFLAGS = -O3 -std=c++11 -Wall

all: $(target)

%: %.c
	gcc $(CFLAGS) $< -o $@

%: %.cpp
	g++ $(CPPFLAGS) $< -o $@

3_4_1.out: hw3_4_1.cpp
	g++ $(CPPFLAGS) hw3_4_1.cpp -o $@

3_4_2.out: hw3_4_2.cpp
	g++ $(CPPFLAGS) hw3_4_2.cpp -o $@

clean:
	rm -rf $(target)

