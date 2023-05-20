#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
        char name[100];
        int price;
        char area[100];
        int discount;
}Cart;

void displayProducts(Cart cart[], int count);
void displayProduct(Cart product);
void addProduct(Cart cart[], int *count);
void updateProduct(Cart cart[], int count);
void deleteProduct(Cart cart[], int *count);
void saveCartToFile(Cart cart[], int count, char *filename);
void loadCartFromFile(Cart cart[], int *count, char *filename);
void searchByArea(Cart cart[], int count, char *searchArea);
void searchByPrice(Cart cart[], int count, int maxPrice);
int calculateTotalPrice(Cart cart[], int count);

void displayProduct(Cart product) {
    printf("상품명: %s\n", product.name);
    printf("가격: %d\n", product.price);
    printf("구역: %s\n", product.area);
    printf("할인율: %d\n", product.discount);
}

void displayProducts(Cart cart[], int count) {
    if (count == 0) {
        printf("현재 등록된 상품이 없습니다.\n");
        return;
    }

    printf("========== 상품 목록 ==========\n");
    for (int i = 0; i < count; i++) {
        printf("상품명: %s\n", cart[i].name);
        printf("가격: %d\n", cart[i].price);
        printf("구역: %s\n", cart[i].area);
        printf("할인율: %d%%\n", cart[i].discount);
        printf("==============================\n");
    }
}

void addProduct(Cart cart[], int *count) {
    Cart newProduct;

    printf("상품명: ");
    scanf("%s", newProduct.name);
    printf("가격: ");
    scanf("%d", &newProduct.price);
    printf("구역: ");
    scanf("%s", newProduct.area);
    printf("할인율: ");
    scanf("%d", &newProduct.discount);

    cart[*count] = newProduct;
    (*count)++;
    printf("상품이 추가되었습니다.\n");
}

void updateProduct(Cart cart[], int count) {
    char productName[100];
    printf("수정할 상품의 이름을 입력하세요: ");
    scanf("%s", productName);

    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(cart[i].name, productName) == 0) {
            printf("새로운 가격: ");
            scanf("%d", &cart[i].price);
            printf("새로운 구역: ");
            scanf("%s", cart[i].area);
            printf("새로운 할인율: ");
            scanf("%d", &cart[i].discount);

            printf("상품이 수정되었습니다.\n");
            return;
        }
    }
    printf("일치하는 상품을 찾을 수 없습니다.\n");
}


void deleteProduct(Cart cart[], int *count) {
    char productName[100];
    printf("삭제할 상품의 이름을 입력하세요: ");
    scanf("%s", productName);

    int i, found = 0;
    for (i = 0; i < *count; i++) {
        if (strcmp(cart[i].name, productName) == 0) {
            found = 1;
            break;
        }
    }

    if (found) {
        for (int j = i; j < *count - 1; j++) {
            cart[j] = cart[j + 1];
        }
        (*count)--;
        printf("상품이 삭제되었습니다.\n");
    } else {
        printf("일치하는 상품을 찾을 수 없습니다.\n");
    }
}


void saveCartToFile(Cart cart[], int count, char *filename) {
    FILE *file = fopen(filename, "wb");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return;
    }

    fwrite(cart, sizeof(Cart), count, file);
    fclose(file);
    printf("카트 정보를 파일에 저장했습니다.\n");
}

void loadCartFromFile(Cart cart[], int *count, char *filename) {
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("파일을 열 수 없습니다.\n");
        return;
    }

    *count = fread(cart, sizeof(Cart), *count, file);
    fclose(file);
    printf("카트 정보를 파일에서 불러왔습니다.\n");
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

void searchByPrice(Cart cart[], int count, int maxPrice) {
    int found = 0;

    for (int i = 0; i < count; i++) {
        if (cart[i].price <= maxPrice) {
            displayProduct(cart[i]);
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

int main() {
    Cart cart[100];
    int count = 0;
    char filename[] = "cart.data";

    int choice;
    do {
        printf("\n=== 마트 카트 프로그램 ===\n");
        printf("1. 상품 조회\n");
        printf("2. 상품 추가\n");
        printf("3. 상품 수정\n");
        printf("4. 상품 삭제\n");
        printf("5. 카트 저장\n");
        printf("6. 카트 불러오기\n");
        printf("7. 구역별 상품 검색\n");
        printf("8. 가격별 상품 검색\n");
        printf("9. 총 상품 금액 계산\n");
        printf("0. 종료\n");
        printf("메뉴를 선택하세요: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                displayProducts(cart, count);
                break;
            case 2:
                addProduct(cart, &count);
                break;
            case 3:
                updateProduct(cart, count);
                break;
            case 4:
                deleteProduct(cart, &count);
                break;
            case 5:
                saveCartToFile(cart, count, filename);
                break;
            case 6:
                loadCartFromFile(cart, &count, filename);
                break;
            case 7: {
                char searchArea[100];
                printf("검색할 구역을 입력하세요: ");
                scanf("%s", searchArea);
                searchByArea(cart, count, searchArea);
                break;
            }
            case 8: {
                int maxPrice;
                printf("검색할 최대 가격을 입력하세요: ");
                scanf("%d", &maxPrice);
                searchByPrice(cart, count, maxPrice);
                break;
            }
            case 9:
                printf("총 상품 금액: %d\n", calculateTotalPrice(cart, count));
                break;
            case 0:
                printf("프로그램을 종료합니다.\n");
                break;
            default:
                printf("잘못된 메뉴를 선택하셨습니다.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
