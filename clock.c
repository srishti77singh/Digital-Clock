// digital clock
/*
choose thr time format:
1. 24 Hour format
2. 12 Hour format (default)
make a choice(1/2):
output-
current time : 19:43:12pm
date ;MONDAY AUGUST 10 2025
*/
#include<stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
void fill_time(char* buffer,size_t size,int format)
{
    time_t raw_time;
    struct tm *current_time;

    time(&raw_time);
    current_time = localtime(&raw_time);
	if(format==1)
	{
		strftime(buffer,size,"Current Time : %H:%M:%S\nDATE: %A %B % d %Y",current_time);
	}
	else
	{
		strftime(buffer, size,"Current Time :  %I:%M:%S %p\nDate : %A %B %d %Y", current_time);
	}	
}
void clear_screen()
{
	#ifdef _WIN32
	 system("cls");
	#else
		system("clear");
	#endif
}
int main()
{
	char buffer[100];
	int choice;
	printf("Choose the time format:\n");
	printf("1. 24 Hour format\n");
	printf("2. 12 Hour format (default)\n");
	printf("Make a choice(1/2)");
	scanf("%d",&choice);
	while(1)
	{
		
		fill_time(buffer,sizeof(buffer),choice);
		clear_screen();
		printf("%s\n",buffer);
		sleep(1);
	}
    return 0;
}
