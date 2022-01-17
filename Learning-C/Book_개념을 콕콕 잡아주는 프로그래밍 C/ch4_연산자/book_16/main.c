#include <stdio.h>
int main(int argc, char *argv[]) 
{

int hour, min, sec, spare;

scanf(" %d", &sec);

hour = sec/3600;
min = (sec - (hour*3600) )/60;
spare = (sec - (hour*3600) ) % 60;


printf("%d sec = %d hour %d min %d sec", sec, hour, min, spare);


	return 0;
}
