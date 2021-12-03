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
	//content_type과 category_type의 비트 or로 조합한 값
	//(e_book이면서 nonfiction이면 e_book|nonfiction이므로 0x21) 
};

int main()
{
	struct item_info item1 = {
		"개념을 콕콕 잡아주는 C Programming",
		"도서,교재" 
	};
	
	printf("Item Information\n");
	printf("	title : %s\n", item1.title);	
	printf("	type  : %s\n", item1.type);
	
	return 0;
}

