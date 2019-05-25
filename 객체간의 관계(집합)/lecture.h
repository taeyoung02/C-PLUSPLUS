#pragma once
#include<string>
#include<vector>
#include "teacher.h"
#include "student.h"
using namespace std;
class lecture {
	string name;
	vector <student*> Student;
	teacher *Teacher;
public:
	lecture(const string &l_name) {
		name = l_name;
	}
	void registStd(student *const std) {
		Student.push_back(std);
	}
	void assigntch(teacher * const tch) {
		Teacher = tch;
	}
	void study() {
		for (auto & element : Student) {
			element->setintel(element-> getintel() + 1);
		}
		cout << name << " complete" << endl;
	}
	friend ostream& operator <<(ostream& out, lecture& lct) {
		for (auto element : lct.Student)
			cout << *element<<endl;
		return out;
	}
};