#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"product.h"
void list_product(Product p[], int count);//전체 등록된 제품을 리스트화해서 보여주는 함수

//삭제나 수정을 하기 위해 제품을 선택하는 함수.(제품의 순서를 return한다.)
int select_No(Product p[], int count);

//File 저장하는 함수.
void saveFile(Product p[], int count);

//File을 불러오는 함수.(파일에 저장된 제품의 수를 return한다.)
int loadFile();

//검색기능: 제품명을 검색 또는 표준가격과 가격의 범위를 입력해서 검색하는 기능.)
void find(Product p[], int count);

//sort기능: 제품명과 가격에 따라 sort해서 보여주는 기능. read기능과 검색기능에 추가해서 사용.
void sort(Product p[], int count);

