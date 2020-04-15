#include"manager.h"
int select_No(Product p[], int culcount){
	list_product(p, culcount);
	int no;
	printf("==>번호를 입력해주세요: ");
	scanf("%d", &no);
	if(no<1||no>=culcount||p[no-1].weight==-1)
		return 0;
	else
		return no;
}
void list_product(Product p[], int count){
       	printf("NO 제품명                                 중량     가격  표준가격  별점\n");
       	printf("=======================================================================\n");
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
        if(pf==NULL || feof(pf))
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
void find(Product p[], int count){
while(1){
        int select;
        printf("==>검색 할 항목을 입력 하세요.(이름:1, 가격:2, 별점:3, 종료:0): ");
        scanf("%d", &select);
        getchar();
        Product newp[50];
        if(select == 1){
                char find_name[50];
                printf("==>이름: ");
                scanf("%[^\n]", find_name);
                getchar();
                int j = 0;
                for(int i = 0 ; i < count ; i++){
                        if(strcmp(p[i].name, find_name)==0){
                                newp[j] = p[i];
                                j++;
                        }
                }
                if(j==0)
                        printf("==입력하신 이름과 동일한 제품이 없습니다.==\n");
                else
                        list_product(newp, j);
        }
        else if(select == 2){
                int find_price_min;
                int find_price_max;
                printf("==>가격의 범위를 입력해 주세요\n ");
                printf("최소가격: ");
                scanf("%d", &find_price_min);
                printf("최대가격: ");
                scanf("%d", &find_price_max);
                int j = 0;
                for(int i = 0 ; i < count ; i++){
                        if(p[i].price >= find_price_min && p[i].price <= find_price_max){
                                newp[j] = p[i];
                                j++;
                        }
                }
                if(j==0)
                        printf("==입력하신 범위에  제품이 없습니다.==\n");
                else
                        list_product(newp, j);
        }
        else if(select == 3){
                int find_e_score_min;
                int find_e_score_max;
                printf("==>별점의 범위를 입력해 주세요\n ");
                printf("최소별점: ");
                scanf("%d", &find_e_score_min);
                printf("최대별점: ");
                scanf("%d", &find_e_score_max);
                int j = 0;
                for(int i = 0 ; i < count ; i++){
                        if(p[i].e_score >= find_e_score_min && p[i].e_score <= find_e_score_max){
                                newp[j] = p[i];
                                j++;
                        }
                }
                if(j==0)
                        printf("==입력하신 범위에 제품이 없습니다.==\n");
                else
                        list_product(newp, j);
        }
        else if(select == 0)
                break;
        else{
                printf("==다시 입력해 주세요.==\n");
                continue;
        }
}
}
void sort(Product p[], int count){
        int num;
        printf("==>정렬 할 기준을 선택해 주세요.(제품명:1, 가격:2, 별점:3): ");
        scanf("%d", &num);
        if(num == 1){
                for(int i = 0 ; i < count-1 ; i++){
                        for(int j = i+1 ; j < count ; j++){
                                if(strcasecmp(p[i].name, p[j].name) > 0){
                                        Product temp;
                                        temp = p[i];
                                        p[i]=p[j];
                                        p[j] = temp;
                                }
                        }
                }
                list_product(p, count);
        }
        else if(num == 2){
                for(int i = 0 ; i < count-1 ; i++){
                        for(int j = i+1 ; j < count ; j++){
                                if(p[i].price > p[j].price){
                                        Product temp;
                                        temp = p[i];
                                        p[i]=p[j];
                                        p[j] = temp;
                                }
                        }
                }
                list_product(p, count);
        }
        else if(num == 3){
                for(int i = 0 ; i < count-1 ; i++){
                        for(int j = i+1 ; j < count ; j++){
                                if(p[i].e_score < p[j].e_score){
                                        Product temp;
                                        temp = p[i];
                                        p[i]=p[j];
                                        p[j] = temp;
                                }
                        }
                }
                list_product(p, count);
        }
}
