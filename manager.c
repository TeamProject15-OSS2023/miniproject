#include "manager.h"

void displayProduct(Cart product) {
	int total = product.price - (product.price * ((0.01)*product.discount));
    printf("상품명: %s  가격: %d  할인적용된금액: %d\n", product.name,product.price, total);
}

void displayPrice(Cart product){
    int total = product.price -(product.price*((0.01)* product.discount));
    printf("상품명: %s    가격: %d  할인적용된금액: %d",product.name, product.price,total);
}

void displayProducts(Cart cart[], int count) {
    if (count == 0) {
        printf("현재 등록된 상품이 없습니다.\n");
        return;
    }
    printf("========== 상품 목록 ==========\n");
    printf("   상품명    가격     구역     할인율    할인적용된금액\n");
    for (int i = 0; i < count; i++) {
        int total = cart[i].price - (cart[i].price*((0.01)*cart[i].discount));
        printf("[%d] %4s %7d원 %7s %5d%% %9d원\n", i+1,cart[i].name,cart[i].price,cart[i].area,cart[i].discount,total);
    }
    printf("==============================\n");
}
void searchByArea(Cart cart[], int count, char *searchArea) {
    int found = 0;

    for (int i = 0; i < count; i++) {
        if (strcmp(cart[i].area, searchArea) == 0) {
            displayProduct(cart[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("일치하는 상품을 찾을 수 없습니다.\n");
    }
}

void searchByName(Cart cart[], int count, char *product) {
    int found = 0;

    for (int i = 0; i < count; i++) {
        if (strcmp(cart[i].name, product) == 0) {
            displayPrice(cart[i]);
            found = 1;
        }
    }

    if (!found) {
        printf("일치하는 상품을 찾을 수 없습니다.\n");
    }
}

int calculateTotalPrice(Cart cart[], int count) {
    int totalPrice = 0;

    for (int i = 0; i < count; i++) {
        int discountedPrice = cart[i].price - (cart[i].price * cart[i].discount / 100);
        totalPrice += discountedPrice;
    }

    return totalPrice;
}

