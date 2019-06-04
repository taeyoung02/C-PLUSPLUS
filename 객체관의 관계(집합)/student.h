#pragma once
#include<string>
using namespace std;
class student {
	string name;
	int intel;
public:
	student(string s_name, int inteligence) {
		name = s_name;
		intel = inteligence;
	}
	int getintel() {
		return intel;
	}
	string getname() {
		return name;
	}
	void setintel(int value){
		intel = value;
	}
	friend ostream& operator <<(ostream& out, student& std) {
		out << std.name << "'s inteligence : " << std.intel;
		return out;
	}
};