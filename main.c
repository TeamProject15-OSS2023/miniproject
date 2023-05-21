#include "manager.h"
#include "product.h"

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
        printf("8. 특정 상품의 가격 검색\n");
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
                char product[100];
                printf("검색할 상품을 입력하세요: ");
                scanf("%s", product);
                searchByName(cart, count, product);
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
