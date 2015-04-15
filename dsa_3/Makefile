target = hw3_1 hw3_2
CFLAGS = -O3 -Wall
CPPFLAGS = -O3 -std=c++11 -Wall

all: $(target)

%: %.c
	gcc $(CFLAGS) $< -o $@

%: %.cpp
	g++ $(CPPFLAGS) $< -o $@

hw3_1: hw3_1.cpp
	g++ $(CPPFLAGS) hw3_1.cpp -o $@

hw3_2: hw3_2.cpp
	g++ $(CPPFLAGS) hw3_2.cpp -o $@

clean:
	rm -rf $(target)

run1:
	./hw3_1 < ./input > ./output

run2:
	./hw3_2 < ./input > ./output
