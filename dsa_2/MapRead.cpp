#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include "MapRead.h"

int map_read(char filename[], Data& mydata)
{
	int fin = open(filename, O_RDONLY);
	if(fin < 0)
	{
		printf("Fail to open the file.\n");
		return -1;
	}
	struct stat stat_buf;
	if( fstat(fin, &stat_buf) )
	{
		printf("Fail to stat the file.\n");
		return -1;
	}
	char *data_start = (char*)mmap(NULL, stat_buf.st_size, PROT_READ, MAP_SHARED, fin, 0);
	if(data_start == MAP_FAILED)
	{
		printf("Fail to map the file.\n");
		return -1;
	}
	char *data_end = data_start + stat_buf.st_size;
	int line = 0;
	while(data_start < data_end - 10)
	{
		int click = 0, impression = 0, ad = 0, advertiser = 0, depth = 0, position = 0, query = 0, keyword = 0, title = 0, description = 0, user = 0;
		unsigned long long URL = 0;
		while(*data_start != '\t')	click = click * 10 + ((*data_start++) - '0');
		data_start++;
		while(*data_start != '\t')	impression = click * 10 + ((*data_start++) - '0');
		data_start++;
		while(*data_start != '\t')	URL = URL * 10 + ((*data_start++) - '0');
		data_start++;
		while(*data_start != '\t')	ad = ad * 10 + ((*data_start++) - '0');
		data_start++;
		while(*data_start != '\t')	advertiser = advertiser * 10 + ((*data_start++) - '0');
		data_start++;
		while(*data_start != '\t')	depth = click * 10 + ((*data_start++) - '0');
		data_start++;
		while(*data_start != '\t')	position = position * 10 + ((*data_start++) - '0');
		data_start++;
		while(*data_start != '\t')	query = query * 10 + ((*data_start++) - '0');
		data_start++;
		while(*data_start != '\t')	keyword = keyword * 10 + ((*data_start++) - '0');
		data_start++;
		while(*data_start != '\t')	title = title * 10 + ((*data_start++) - '0');
		data_start++;
		while(*data_start != '\t')	description = description * 10 + ((*data_start++) - '0');
		data_start++;
		while(*data_start != '\n')	user = user * 10 + ((*data_start++) - '0');
		data_start++;
		mydata.line[line].user = user;
		mydata.line[line].ad = ad;
		mydata.line[line].advertiser = advertiser;
		mydata.line[line].URL = URL;
		mydata.line[line].click = click;
		mydata.line[line].impression = impression;
		mydata.line[line].depth = depth;
		mydata.line[line].position = position;
		mydata.line[line].query = query;
		mydata.line[line].keyword = keyword;
		mydata.line[line].title = title;
		mydata.line[line].description = description;
		line++;
	}
	munmap(data_end - stat_buf.st_size, stat_buf.st_size);
	if( close(fin) )
	{
		printf("Fail to close the file.\n");
		return -1;
	}
	return line;
}
