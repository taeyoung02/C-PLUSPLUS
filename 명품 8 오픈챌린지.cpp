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
		cout << "--- ��ǰID : " << getid() << endl;
		cout << "��ǰ���� : " << getex() << endl;
		cout << "������ : " << getmaker() << endl;
		cout << "���� : " << getprice() << endl;
		cout << "å���� : " << title << endl;
		cout << "���� : " << writer << endl;
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
		cout << "--- ��ǰID : " << getid() << endl;
		cout << "��ǰ���� : " << getex() << endl;
		cout << "������ : " << getmaker() << endl;
		cout << "���� : " << getprice() << endl;
		cout << "�ٹ����� : " << albumtitle << endl;
		cout << "���� : " << singer << endl;
	}
};
class converbook :public book {
	string language;
public:
	converbook(int id, int price, string ex, string maker, int isbn, string writer, string title, string language):book(id,price,ex,maker,isbn,writer,title) {
		this->language = language;
	}
	void show() {
		cout << "--- ��ǰID : " << getid() << endl;
		cout << "��ǰ���� : " << getex() << endl;
		cout << "������ : " << getmaker() << endl;
		cout << "���� : " << getprice() << endl;
		cout << "å���� : " << gettitle() << endl;
		cout << "���� : " << getwriter() << endl;
		cout << "��� : " << language << endl;
		cout << "ISBN : " << getisbn() << endl;
	}
};
int main() {
	product* p[100];
	int id = 0;
	int price, isbn;
	string writer, maker, language, title, singer, ex, albumtitle;
	cout << "***** ��ǰ ���� ���α׷��� �۵��մϴ� *****" << endl;
	while (id < 100) {
		cout << "��ǰ �߰�(1), ��� ��ǰ ��ȸ(2), ������(3) ? ";
		int n;
		cin >> n;
		switch (n) {
		case 1:
			cout << "��ǰ ���� å(1), ����CD(2), ȸȭå(3) ? ";
			cin >> n;
			cin.ignore(); // ������ ������ ���� ���������� �Է¿���
			if (n == 1) {
				cout << "��ǰ����>>"; getline(cin, ex);
				cout << "������>>"; getline(cin, maker);
				cout << "����>>"; cin >> price; cin.ignore();
				cout << "å����>>"; getline(cin, title);
				cout << "����>>"; getline(cin, writer);
				cout << "ISBN>>"; cin >> isbn;
				book *b = new book(id, price, ex, maker, isbn, writer, title);
				p[id] = b;
				++id;
			}
			else if (n == 2){
				cout << "��ǰ����>>"; getline(cin, ex);
				cout << "������>>"; getline(cin, maker);
				cout << "����>>"; cin >> price; cin.ignore();
				cout << "�ٹ�����>>"; getline(cin, albumtitle);
				cout << "����>>"; getline(cin, singer);
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
