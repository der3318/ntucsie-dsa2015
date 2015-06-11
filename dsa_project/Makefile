target = final_project 
CFLAGS = -O3 -Wall
CPPFLAGS = -O3 -std=c++11 -Wall

all: $(target)

%.o:%.c
	gcc $(CFLAGS) $< -c

%: %.c
	gcc $(CFLAGS) $< -o $@

%.o:%.cpp
	g++ $(CFLAGS) $< -c

%: %.cpp
	g++ $(CPPFLAGS) $< -o $@

final_project: md5.o rb.o final_project.o
	g++ $(CPPFLAGS) final_project.o md5.o rb.o -o $@

clean:
	rm -rf $(target)

