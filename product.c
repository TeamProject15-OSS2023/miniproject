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

