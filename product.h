#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct{
        char name[100];
        int price;
        char area[100];
        int discount;
}Cart;

void addProduct(Cart cart[], int *count); //상품 추가
void updateProduct(Cart cart[], int count); //상품 수정
void deleteProduct(Cart cart[], int *count); //상품 삭제
void saveCartToFile(Cart cart[], int count, char *filename); //파일 저장
void loadCartFromFile(Cart cart[], int *count, char *filename); //파일을  불러옴
