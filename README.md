## 💻My Cart의 주제
<html>
     <img src= "https://cdn.pixabay.com/photo/2013/07/12/14/53/cart-148964_960_720.png" width="200" height = "200">
     </html>
- 마트에서 쇼핑을 할 때 장바구니를 관리하는 프로그램

## 🛠Made by My Cart
<html>
    <div align="center">
    <img src="https://img.shields.io/badge/C-EAEAEA?style=for-the-badge&logo=C&logoColor=black">
    <img src="https://img.shields.io/badge/html-E34F26?style=for-the-badge&logo=html5&logoColor=white">
     <img src="https://img.shields.io/badge/Visual%20Studio%20Code-007ACC?style=for-the-badge&logo=VisualStudioCode&logoColor=white">
        </div>
    </html>


## 💻My Cart의 주제에 대한 소개
- 편리한 쇼핑을 도와주는 My Cart 입니다.
- 쇼핑을 하는 중 총 금액을 계산해주고, 그 상품의 구역 등 상품의 정보를 알려줍니다.

## 💻My Cart의 대략적인 기능 설명
-장바구니에 상품을 추가하는 기능

-장바구니에 있는 상품의 정보를 수정하는 기능

-장바구니에 있는 상품을 삭제하는 기능

-장바구니에 있는 특정 상품의 정보를 조회하는 기능

-장바구니에 있는 모든 상품을 보여주는 기능

-모든 상품의 총 금액을 계산해주는 기능(금액 할인율도 고려 예정)

-상품들을 알파벳이나 가나다 순서별로 정렬하거나 카테고리 별로 정렬하는 기능


## 💻My Cart CRUD
~~~C
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
void displayProducts(Cart cart[], int count); //searchByarea 함수에서 쓰이는 제품 정보 출력
void displayPrice(Cart product); //상품 목록을 출력
void displayProduct(Cart product); //상품명과 가격을 출력
void searchByArea(Cart cart[], int count, char *searchArea); //특정 구역의 모든 상품 출력
void searchByName(Cart cart[], int count, char *product); //상품의 이름으로 가격 검색
int calculateTotalPrice(Cart cart[], int count); //모든 상품의 총금액 계산
~~~

## 💻개발환경 및 언어
-git

-Visual Studio Code



## 💻팀소개 및 팀원이 맡은 역할
### 팀원
#### 류찬미(22학번) [chanmi12 GITHUB LINK](https://github.com/chanmi12?tab=repositories)
-Repo Owner

-CRUD 구현


#### 김영빈(22학번)  [KimYoungKong GITHUB LINK](https://github.com/KimYoungKong)
-Contributer

-CRUD 구현



   
