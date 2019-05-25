#include<iostream>
#include<vector>
#include <string>
using namespace std;
class doc;//���漱��
class patient {
	vector<doc*>docs;//�����Ͱ� �ƴ϶� value�� �־��ָ� adddoc(doc d)���� �Ű������� docs[0]����
					 //�ּҰ� �ٸ��� ������ adddoc�� �� �����Լ����� doc��ü�� update�ǵ� docs[0]
					 //�� ��ȭ�� ���Ե�. ���� �����͸� �־� adddoc(doc &d)�Ű������� �ּڰ����޾�
					 //docs�� ����� doc��ü�� ����Ű�� ��������
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
		out << "�̸� : " << p->name;
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
		cout << name << "'s �ǻ���" << endl;
		for (auto& element : pats)
			cout << element << endl;
		cout << endl;
	}

	friend ostream& operator <<(ostream& out, const class doc *d) {
		out <<"�̸� : "<< d->name;
		return out;
	}
	friend class patient;
};
void patient::doclist() {//���漱���� ���ֱ������� �׾ȿ� ����� ���� �𸣹Ƿ� �ڷ� ����.
	cout << name << "'s ȯ�ڸ��" << endl;
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