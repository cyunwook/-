#include "httplib.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

// index.html 파일 읽기
string get_file_content(const string& path) {
    ifstream file(path);
    stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

// 키워드 기반 추천
void getNicknameByKeyword(const httplib::Request& req, httplib::Response& res) {
    string keyword = req.get_param_value("keyword");

    vector<string> words = { "고수", "바지", "마법", "개구리", "페이커", "유충", "벌레", "버스" };
    srand(time(0));
    string randomWord = words[rand() % words.size()];
    bool attachFront = rand() % 2;

    string nickname = attachFront ? (randomWord + keyword) : (keyword + randomWord);
    res.set_content("추천 닉네임: " + nickname, "text/plain");
}

// 카테고리 기반 추천
void getNicknameByCategory(const httplib::Request& req, httplib::Response& res) {
    int x = stoi(req.get_param_value("x"));
    int y = stoi(req.get_param_value("y"));

    vector<string> animals = { "개구리", "조랑말", "강아지", "가나디", "표범", "라이거", "하마", "살쾡이", "호랑이", "물고기" };
    vector<string> food = { "케이크", "아메리카노", "자몽허니블랙티", "장어초밥", "튀김우동" };
    vector<string> family = { "엄마", "아빠", "여동생", "형", "오빠" };
    vector<string> icecream = { "아몬드봉봉", "스크류바", "쌍쌍바", "엄마는외계인" };

    vector<vector<string>> categories = { animals, food, family, icecream };

    srand(time(0));
    string word1 = categories[x - 1][rand() % categories[x - 1].size()];
    string word2 = categories[y - 1][rand() % categories[y - 1].size()];

    bool swapWords = rand() % 2;
    string nickname = swapWords ? (word2 + word1) : (word1 + word2);

    res.set_content("추천 닉네임: " + nickname, "text/plain");
}

// index.html 파일 제공
void serve_index_page(const httplib::Request& req, httplib::Response& res) {
    string html_content = get_file_content("index.html");  // index.html 파일 경로
    res.set_content(html_content, "text/html");
}

int main() {
    httplib::Server svr;

    // 루트 경로에 대한 요청 처리 (index.html 제공)
    svr.Get("/", serve_index_page);

    // 키워드 기반 추천
    svr.Get("/nickname_key", getNicknameByKeyword);

    // 카테고리 기반 추천
    svr.Get("/nickname_cat", getNicknameByCategory);

    cout << "서버 실행 중... 8080 포트 대기" << endl;
    svr.listen("0.0.0.0", 8080);  // 8080 포트에서 서버 대기

    return 0;
}
return 0;
}


