닉네임 추천 서비스를 만드려고 시도했다
내가 가장 자신있는 c++로 만들었는데, 아무래도 웹사이트를 만들기에는 한계가 있는듯 하다
한글이 깨져보인다 ㅠ
처음 짠 알고리즘은 이렇다
#include <iostream>
#include <vector>
#include <cstdlib>  // rand(), srand()
#include <ctime>    // time()

using namespace std;

void key();  
void cat();  

int main() {
    cout << "1. 키워드 기반 추천" << '\n' << "2. 카테고리 기반 추천" << '\n';
    cout << "원하는 추천 서비스 번호를 입력하세요: ";

    int a;
    cin >> a;

    if (a == 1) {
        key();
    }
    else if (a == 2) {
        cat();
    }
    else {
        cout << "잘못된 번호입니다" << '\n';
        main();
    }
}

void key() {
    vector<string> words = {"고수", "바지", "마법", "개구리", "페이커", "유충", "벌레", "버스"};

    string keyword;
    cout << "원하는 키워드를 입력하세요: ";
    cin >> keyword;

    srand(time(0));  

    string randomWord = words[rand() % words.size()];  
    bool attachFront = rand() % 2;  

    string nickname = attachFront ? (randomWord + keyword) : (keyword + randomWord);

    cout << "추천 닉네임: " << nickname << endl;
}

void cat() {
    vector<string> animals = {"개구리", "조랑말", "강아지", "가나디", "표범", "라이거", "하마", "살쾡이", "호랑이", "물고기", "비단잉어", "미어캣", "흑동고래", "상어"};
    vector<string> food = {"케이크", "아메리카노", "자몽허니블랙티", "장어초밥", "튀김우동", "로제떡볶이", "탕화쿵푸마라탕", "신전떡볶이", "엽떡", "쉑쉑버거", "버거킹", "칼국수"};
    vector<string> family = {"엄마", "아빠", "여동생", "형", "오빠", "남동생", "누나", "언니", "형부", "외숙모", "할머니", "할부지", "사촌동생", "삼촌", "이모", "고조할머니", "증조할아버지"};
    vector<string> icecream = {"아몬드봉봉", "스크류바", "쌍쌍바", "엄마는외계인", "누가바", "투게더", "와일드바디"};

    vector<vector<string>> categories = {animals, food, family, icecream};

    cout << "1. 동물" << '\n' << "2. 음식" << '\n' << "3. 가족" << '\n' << "4. 아이스크림" << '\n';
    cout << "원하는 카테고리 두 개를 선택하세요 (예: 1 3): ";

    int x, y;
    cin >> x >> y;

    if (x < 1 || x > 4 || y < 1 || y > 4) {
        cout << "잘못된 입력입니다. 다시 시도하세요.\n";
        return;
    }

    srand(time(0));  

    string word1 = categories[x - 1][rand() % categories[x - 1].size()];  
    string word2 = categories[y - 1][rand() % categories[y - 1].size()];  

    bool swapWords = rand() % 2;  

    string nickname = swapWords ? (word2 + word1) : (word1 + word2);

    cout << "추천 닉네임: " << nickname << endl;
}

예시 (입력) 1 연욱 => (출력) 벌레연욱
     (입력) 2 2 3 => (출력) 엽떡할머니
     이런식으로 닉네임을 짜주는 알고리즘이다
최종목표는 이렇게 닉네임을 추천해주는 웹사이트를 만드는 거다 
다음번엔 자바로 시도해보겠다!!
