#include <stdio.h>

//enum content_type {
//	book = 0x10, ebook = 0x20 
//};
//enum category_type {
//	fiction, nonfiction, textbook, children
//};

struct item_info {
	char title[128];
	char type[128];
	//content_type�� category_type�� ��Ʈ or�� ������ ��
	//(e_book�̸鼭 nonfiction�̸� e_book|nonfiction�̹Ƿ� 0x21) 
};

int main()
{
	struct item_info item1 = {
		"������ ���� ����ִ� C Programming",
		"����,����" 
	};
	
	printf("Item Information\n");
	printf("	title : %s\n", item1.title);	
	printf("	type  : %s\n", item1.type);
	
	return 0;
}

