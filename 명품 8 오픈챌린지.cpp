#include<iostream>
#include<string>
using namespace std;

class product {
	int id,price;
	string ex,maker;
public:	
	product() {};
	product(int id, int price, string ex, string maker) {
		this->id = id;
		this->price = price;
		this->ex = ex;
		this->maker = maker;
	}
	virtual void show()=0;
	int getid() { return id; }
	int getprice() { return price; }
	string getmaker(){ return maker; }
	string getex() { return ex; }
};

class book :public product {
	int isbn;
	string writer;
	string title;
public:
	book() {};
	book(int id, int price, string ex, string maker,int isbn, string writer, string title):product(id,price,ex,maker){
		this->isbn = isbn;
		this->writer = writer;
		this->title = title;
	}
	int getisbn() { return isbn; }
	string getwriter() { return writer; }
	string gettitle() { return title; }
	void show(){
		cout << "--- 상품ID : " << getid() << endl;
		cout << "상품설명 : " << getex() << endl;
		cout << "생산자 : " << getmaker() << endl;
		cout << "가격 : " << getprice() << endl;
		cout << "책제목 : " << title << endl;
		cout << "저자 : " << writer << endl;
		cout << "ISBN : " << isbn << endl;
	}
};
class compactdisk :public product {
	string albumtitle;
	string singer;
public:
	compactdisk(int id, int price, string ex, string maker, string albumtitle, string singer) :product(id, price, ex, maker) {
		this->albumtitle = albumtitle;
		this->singer = singer;
	}
	void show() {
		cout << "--- 상품ID : " << getid() << endl;
		cout << "상품설명 : " << getex() << endl;
		cout << "생산자 : " << getmaker() << endl;
		cout << "가격 : " << getprice() << endl;
		cout << "앨범제목 : " << albumtitle << endl;
		cout << "가수 : " << singer << endl;
	}
};
class converbook :public book {
	string language;
public:
	converbook(int id, int price, string ex, string maker, int isbn, string writer, string title, string language):book(id,price,ex,maker,isbn,writer,title) {
		this->language = language;
	}
	void show() {
		cout << "--- 상품ID : " << getid() << endl;
		cout << "상품설명 : " << getex() << endl;
		cout << "생산자 : " << getmaker() << endl;
		cout << "가격 : " << getprice() << endl;
		cout << "책제목 : " << gettitle() << endl;
		cout << "저자 : " << getwriter() << endl;
		cout << "언어 : " << language << endl;
		cout << "ISBN : " << getisbn() << endl;
	}
};
int main() {
	product* p[100];
	int id = 0;
	int price, isbn;
	string writer, maker, language, title, singer, ex, albumtitle;
	cout << "***** 상품 관리 프로그램을 작동합니다 *****" << endl;
	while (id < 100) {
		cout << "상품 추가(1), 모든 상품 조회(2), 끝내기(3) ? ";
		int n;
		cin >> n;
		switch (n) {
		case 1:
			cout << "상품 종류 책(1), 음악CD(2), 회화책(3) ? ";
			cin >> n;
			cin.ignore(); // 해주지 않으면 버퍼 문제때문에 입력오류
			if (n == 1) {
				cout << "상품설명>>"; getline(cin, ex);
				cout << "생산자>>"; getline(cin, maker);
				cout << "가격>>"; cin >> price; cin.ignore();
				cout << "책제목>>"; getline(cin, title);
				cout << "저자>>"; getline(cin, writer);
				cout << "ISBN>>"; cin >> isbn;
				book *b = new book(id, price, ex, maker, isbn, writer, title);
				p[id] = b;
				++id;
			}
			else if (n == 2){
				cout << "상품설명>>"; getline(cin, ex);
				cout << "생산자>>"; getline(cin, maker);
				cout << "가격>>"; cin >> price; cin.ignore();
				cout << "앨범제목>>"; getline(cin, albumtitle);
				cout << "가수>>"; getline(cin, singer);
				compactdisk *c = new compactdisk(id, price, ex, maker, albumtitle, singer);
				p[id] = c;
				id++;
		}
			break;
		case 2:
			for (int i = 0; i < id; i++) {
				p[i]->show();
		}
			break;
		case 3: 
			id = 100;
			break;
}
}
}
