target = tree forest
CFLAGS = -O3 -Wall
CPPFLAGS = -O3 -std=c++11 -Wall

all: $(target)

%: %.c
	gcc $(CFLAGS) $< -o $@

%: %.cpp
	g++ $(CPPFLAGS) $< -o $@

tree: tree.cpp
	g++ $(CPPFLAGS) tree.cpp -o $@

forest: forest.cpp
	g++ $(CPPFLAGS) forest.cpp -o $@

clean:
	rm -rf $(target)

