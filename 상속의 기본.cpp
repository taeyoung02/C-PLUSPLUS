#include <iostream>
#include<string>
using namespace std;
class person {
	string name;
public:
	string getname() {
		return name;
	}
	void setname(string name_in) {
		name = name_in;
	}
};
class mother :public person{
	int i;
	string name;
public:
	mother(int i_in):i(i_in) {}
	int getvalue() {
		return i;
	}
};
class son : public mother {
	double d;
	string name;
public:
	son(int i_in, double d_in):mother(i_in),d(d_in){}
	double getvalue() {
		return d;
	}
};
int main() {
	mother m(1024);
	son s(2, 3.5);
	m.setname("tae");
	s.setname("young");
	cout << s.getname() << endl << m.getname();
}