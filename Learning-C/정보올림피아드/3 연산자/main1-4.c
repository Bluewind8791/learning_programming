#include <stdio.h>
int main(int argc, char *argv[]) 
{


int minsu_t, minsu_w, giyoung_t, giyoung_w;

scanf(" %d %d %d %d", &minsu_t, &minsu_w, &giyoung_t, &giyoung_w);

printf("%d", (minsu_t > giyoung_t) && (minsu_w > giyoung_w) );



	return 0;
}
