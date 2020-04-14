#include"manager.h"
int select_No(Product p[], int culcount){
	list_product(p, culcount);
	int no;
	printf("==>번호를 입력해주세요: ");
	scanf("%d", &no);
	return no;
}
void list_product(Product p[], int count){
       	printf("NO 제품명                             중량  가격  표준가격  별점\n");
       	printf("================================================================\n");
       	for(int i=0;i<count;i++){
		if(p[i].weight != -1){
			printf("%d.", i+1);
			read_product(p[i]);
		}
	}
}
void saveFile(Product p[], int count){
	FILE *product;
	product = fopen("product.txt", "wt");
	for(int i = 0 ; i < count ; i++){
		if(p[i].weight != -1){
			fprintf(product,"%s\n %d %d %d\n", p[i].name, p[i].weight, p[i].price, p[i].e_score);
		}
	}
	fclose(product);
}
int file_exist(){
        FILE *pf;
        pf = fopen("product.txt", "rt");
        if(feof(pf)||pf==NULL)
                return 0;
        return 1;
}
int loadFile(Product p[]){
        int count = 0;
        FILE *product;
        product = fopen("product.txt", "rt");
        while(1){
                fscanf(product,"%[^\n]\n", p[count].name);
                fscanf(product,"%d %d %d\n", &p[count].weight, &p[count].price, &p[count].e_score);
                count++;
                if(feof(product)) break;
        }
        fclose(product);
        return count;
}
