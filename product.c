#include"product.h"
int add_product(Product *p){
	printf("==>제품명을 입력해주세요.\n");
	scanf(" %[^\n]", p->name);
	getchar();
	printf("==>제품의 중량을 입력해주세요.\n");
	scanf("%d", &p->weight);
	printf("==>제품의 가격을 입력해주세요.\n");
	scanf("%d", &p->price);
	printf("==>제품의 별점을 입력해주세요(0~5).\n");
	scanf("%d", &p->e_score);
	if(p->e_score>5 || p->e_score<0)
		return 0;
	return 1;
}

void read_product(Product p){
	int avr=0;
	avr = (int)((double)p.price/((double)p.weight/10));
	printf("%-35s %dg %5d원 %5d원 %5d\n", p.name, p.weight, p.price, avr, p.e_score);
}

int updata_product(Product *p){
	printf("==>새 제품명을 입력해주세요.\n");
	scanf(" %[^\n]", p->name);
	getchar();
	printf("==>새 제품의 중량을 입력해주세요.\n");
	scanf("%d", &p->weight);
	printf("==>새 제품의 가격을 입력해주세요.\n");
	scanf("%d", &p->price);
	printf("==>새 제품의 별점을 입력해주세요.\n");
	scanf("%d", &p->e_score);
	return 1;
}


int delete_product(Product *p){
	*p->name= - 1;
	p->weight = -1;
	p->price = -1;
	p->e_score = -1;
	return 1;
}
