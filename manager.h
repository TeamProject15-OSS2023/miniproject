#include "product.h"

void displayProducts(Cart cart[], int count); //searchByarea 함수에서 쓰이는 제품 정보 출력
void displayPrice(Cart product); //상품 목록을 출력
void displayProduct(Cart product); //상품명과 가격을 출력
void searchByArea(Cart cart[], int count, char *searchArea); //특정 구역의 모든 상품 출력
void searchByName(Cart cart[], int count, char *product); //상품의 이름으로 가격 검색
int calculateTotalPrice(Cart cart[], int count); //모든 상품의 총금액 계산
