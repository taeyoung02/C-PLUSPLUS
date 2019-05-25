#include<iostream>
#include<vector>
#include <string>
using namespace std;
class doc;//전방선언
class patient {
	vector<doc*>docs;//포인터가 아니라 value를 넣어주면 adddoc(doc d)에서 매개변수와 docs[0]과의
					 //주소가 다르기 때문에 adddoc에 들어간 메인함수안의 doc객체가 update되도 docs[0]
					 //은 변화가 없게됨. 따라서 포인터를 넣어 adddoc(doc &d)매개변수로 주솟값을받아
					 //docs의 멤버가 doc객체를 가리키게 만들어야함
	string name;
public:
	patient(string p_name) {
		name = p_name;
	}
	void adddoc(doc* d) {
		docs.push_back(d);
	}
	void doclist();
	friend ostream& operator <<(ostream & out, const class patient* p) {
		out << "이름 : " << p->name;
		return out;
	}
	friend class doc;
};
class doc {
	vector<patient*>pats;
	string name;
public:
	doc(string d_name) {
		name = d_name;
	}
	void addpat(patient* p) {
		pats.push_back(p);
	}
	void patlist() {
		cout << name << "'s 의사목록" << endl;
		for (auto& element : pats)
			cout << element << endl;
		cout << endl;
	}

	friend ostream& operator <<(ostream& out, const class doc *d) {
		out <<"이름 : "<< d->name;
		return out;
	}
	friend class patient;
};
void patient::doclist() {//전방선언을 해주긴했지만 그안에 멤버는 아직 모르므로 뒤로 빼줌.
	cout << name << "'s 환자목록" << endl;
	for (auto& element : docs)
		cout << element << endl;
	cout << endl;
}

int main() {
	
	
	patient p1("za");
	patient p2("young");
	patient p3("song");
	doc d1("tae");
	doc d2("young");
	p1.adddoc(&d1);
	d1.addpat(&p1);
	
	p2.adddoc(&d1);
	d1.addpat(&p2);

	p1.adddoc(&d2);

	d2.addpat(&p1);
	
	d2.addpat(&p3);
	p3.adddoc(&d2);

	p1.doclist();
	p2.doclist();
	p3.doclist();

	d1.patlist();
	d2.patlist();

}