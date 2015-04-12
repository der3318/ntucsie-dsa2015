target = demo
CFLAGS = -O3 -Wall
CPPFLAGS = -O3 -std=c++11 -Wall

all: $(target)

%: %.c
	gcc $(CFLAGS) $< -o $@

%: %.cpp
	g++ $(CPPFLAGS) $< -o $@

demo: demo.cpp DataStruct.cpp MapRead.cpp DataStruct.h MapRead.h
	g++ $(CPPFLAGS) demo.cpp DataStruct.cpp MapRead.cpp -o $@

clean:
	rm -rf $(target)

run:
	./$(target)
