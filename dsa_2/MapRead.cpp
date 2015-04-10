#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <unistd.h>
#include "DataStruct.h"

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
	while(data_start != data_end)
	{
		int click = 0, impression = 0, ad = 0, advertiser = 0, depth = 0, position = 0, query = 0, keyword = 0, title = 0, description = 0, user = 0;
		unsigned long long URL = 0;
		while(*data_start != '\t')
		{
			click *= 10;
			click += ((*data_start++) - '0');
		}
		data_start++;
		while(*data_start != '\t')
		{
			impression *= 10;
			impression += ((*data_start++) - '0');
		}
		data_start++;
		while(*data_start != '\t')
		{
			URL *= 10;
			URL += ((*data_start++) - '0');
		}
		data_start++;
		while(*data_start != '\t')
		{
			ad *= 10;
			ad += ((*data_start++) - '0');
		}
		data_start++;
		while(*data_start != '\t')
		{
			advertiser *= 10;
			advertiser += ((*data_start++) - '0');
		}
		data_start++;
		while(*data_start != '\t')
		{
			depth *= 10;
			depth += ((*data_start++) - '0');
		}
		data_start++;
		while(*data_start != '\t')
		{
			position *= 10;
			position += ((*data_start++) - '0');
		}
		data_start++;
		while(*data_start != '\t')
		{
			query *= 10;
			query += ((*data_start++) - '0');
		}
		data_start++;
		while(*data_start != '\t')
		{
			keyword *= 10;
			keyword += ((*data_start++) - '0');
		}
		data_start++;
		while(*data_start != '\t')
		{
			title *= 10;
			title += ((*data_start++) - '0');
		}
		data_start++;
		while(*data_start != '\t')
		{
			description *= 10;
			description += ((*data_start++) - '0');
		}
		data_start++;
		while(*data_start != '\n')
		{
			user *= 10;
			user += ((*data_start++) - '0');
		}
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
	if( close(fin) )
	{
		printf("Fail to close the file.\n");
		return -1;
	}
	return line;
}
