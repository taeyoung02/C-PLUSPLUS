#pragma once
#include<string>
using namespace std;
class teacher {
	string name;
public:
	teacher(string t_name) {
		name = t_name;
	}
	string getname() {
		return name;
	}
};
