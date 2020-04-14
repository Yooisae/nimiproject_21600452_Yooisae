#include"manager.h"
int selectmenu(){
        int menu;
        printf("\n");
        printf("1. 제품조회\n");
        printf("2. 제품추가\n");
        printf("3. 제품수정\n");
        printf("4. 제품삭제\n");
        printf("0. 종료\n");
        printf("==>원하는 메뉴를 선택하세요.");
        scanf("%d", &menu);
        printf("\n");
        return menu;
}
int main(){
	Product p[SIZE];
	int count=0;
	int culcount = 0;
	int menu;
	while(1){
		menu = selectmenu();
		if(menu==0){
			printf("==종료됨.==\n");
			break;
		}
		else if(menu==1){
			if(count==0){
			printf("==입력된 데이터가 없습니다.==\n");
				continue;
			}	
			else
				#ifdef DEBUG
					printf("debug[%s]: %d %s\n", __FILE__, __LINE__, __FUNCTION__);
				#endif
					list_product(p, culcount);
		}
		else if(menu==2){
			#ifdef DEBUG
				printf("debug[%s]: %d %s\n", __FILE__, __LINE__, __FUNCTION__);
			#endif
				count += add_product(&p[culcount]);
				culcount++;
				printf("==입력완료==\n");
			
		}
		else if(menu==3){
			if(count==0){
				printf("==입력된 데이터가 없습니다.==\n");
				continue;
			}
			else{		
				#ifdef DEBUG
					printf("debug[%s]: %d %s\n", __FILE__, __LINE__, __FUNCTION__);
				#endif
					int no=select_No(p, culcount);
					updata_product(&p[no-1]);
					printf("==수정완료==\n");
			}
		}
		else if(menu==4){
			if(count==0){
				printf("==삭제 할 데이터가 없습니다.==\n");
				continue;
			}
			else{
				#ifdef DEBUG
					printf("debug[%s]: %d %s\n", __FILE__, __LINE__, __FUNCTION__);
				#endif
					int no = select_No(p, culcount);
					delete_product(&p[no-1]);
					count--;
					printf("==삭제완료==\n");
			}		
		}
	}
}
