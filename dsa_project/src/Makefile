target = final_project 
CFLAGS = -O3 -Wall -std=c99
CPPFLAGS = -O3 -std=c++11 -Wall

all: $(target)

bonus: final_project_bonus

%.o:%.c
	gcc $(CFLAGS) $< -c

%: %.c
	gcc $(CFLAGS) $< -o $@

%.o:%.cpp
	g++ $(CPPFLAGS) $< -c

%: %.cpp
	g++ $(CPPFLAGS) $< -o $@

final_project: md5.o rb.o wildcard.o final_project.o
	g++ $(CPPFLAGS) final_project.o md5.o rb.o wildcard.o -o $@

final_project_bonus: md5.o rb.o wildcard.o final_project_bonus.o
	g++ $(CPPFLAGS) final_project_bonus.o md5.o rb.o wildcard.o -o $@

clean:
	rm -rf $(target) final_project_bonus md5.o rb.o final_project.o wildcard.o final_project_bonus.o

