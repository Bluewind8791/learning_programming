#include <stdio.h>
#include <string.h>

char *Encrypt(const char *s);

int main(void)
{
	char str[256];
	char *encrypt_str = NULL;
	
	printf("원본 문자열 : ");
	gets(str);
	
	encrypt_str = Encrypt(str);
	printf("암호화된 문자열 : %s\n", encrypt_str);
	
	return 0;
}

char *Encrypt(const char *s)
{
	static char result[256];
	int len;
	char temp;
	int i;
	
	len = strlen(s);
	for(i=0; i<len; i++) {
		temp = toupper(s[i]);
		if(temp>='A' && temp<'Z') {
			result[i] = s[i] + 1;
		}
		else if(temp == 'Z') {
			result[i] = s[i] - 'Z' + 'A';
		}
		else {
			result[i] = s[i];
		}
	}
	result[i] = 0;
	return result;
}





