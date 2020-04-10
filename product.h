#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//제품의 내용을 하나로 묶기 위한 struct
typedef struct{
    char name[50];//제품명
    int weight;//중량(g)
    int price;//가격(원)
    int s_price;//표준가격(10g당 가격)
    int e_score;//별점수(1~5)
}Product;

//creat기능 : 제품의 이름과, 제품명, 중량, 가격, 표준가격, 별점수를 추가하는 함수.
int add_product(Product *p);

//read기능
void read_product(Product p);//한나의 제품을 출력하는 함수

/*updata기능 : 제품의 이름과, 제품명, 중량, 가격, 표준가격, 별점수를 수정하는 함수.
 수정을 해야하는 항목이 많기 때문에 수정 할 항목별로 번호를 주고 그 번호에 따라서 수정 실행.*/
int updata_product(Product *p);

//delete기능 : 삭제할 제품에 대하여 내용을 -1로 바꿔서 읽지 못하게 만드는 함수.
int delete_product(Product *p);

//삭제나 수정을 하기 위해 제품을 선택하는 함수.(제품의 순서를 return한다.)
