#include <stdio.h>

int IsLower (char input);
int IsUpper (char input);
int IsAlphabetic (char input);

int main() {
	char input;
	while (1) {
		printf("한개의 문자만 입력하세요(0 입력 시 exit): ");
		scanf(" %c", &input);
		if (input == '0') {
			break;
		}
		else if (IsAlphabetic(input)==1) {
			printf("입력하신 값은 알파벳입니다.\n", input);
			if (IsLower(input)==1) {
				printf("입력하신 값은 알파벳 소문자입니다.\n\n", input);
			}
			else if (IsUpper (input)==1) {
				printf("입력하신 값은 알파벳 대문자입니다.\n\n", input);
			}
		}
		else {
			printf("입력하신 값은 알파벳이 아닙니다.\n\n");
		}
	}
	return 0;
}

int IsLower (char input) {
	/*
	1. Description : 인자가 소문자인지 판단하는 함수.
	2. Function : char input
	3. Return : 1이면 소문자, 0이면 소문자가 아님. 
	*/
	if (input >= 'a' && input <= 'z') {
		return 1;
	}
	return 0;
}

int IsUpper (char input) {
	/*
	1. Description : 인자가 대문자인지 판단하는 함수.
	2. Function : char input
	3. Return : 1이면 대문자, 0이면 대문자가 아님. 
	*/
	if (input >= 'A' && input <= 'Z') {
		return 1;
	}
	return 0;
}

int IsAlphabetic (char input) {
	/*
	1. Description : 인자가 알파벳인지 판단하는 함수.
	2. Function : char input
	3. Return : 1이면 알파벳, 0이면 알파벳이 아님. 
	*/
	if ( IsUpper(input) ) {
		return 1;
	}
	else if ( IsLower(input) ) {
		return 1;
	}
	return 0;
}


/*
문자를 입력으로 받아서
소문자인지 검사하는 IsLower 함수
대문자인지 검사하는 IsUpper 함수 정의 

IsLower 함수는 소문자면 1 아니면 0 return
IsUpper 함수도 마찬가지

또한 두 함수를 이용하여 알파벳인지 검사하는
IsAlphabetic 함수 정의

IsAlphabetic 함수는 알파벳이면 1, 아니면 0 return 
*/
