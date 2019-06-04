#include<iostream>
#include "lecture.h"
using namespace std;
int main() {
	student std1("taeyoung", 0);
	student std2("zayoung", 1);
	student std3("sex", 2);

	teacher tch1("hong.prof");
	teacher tch2("cheol.prof");

	lecture lct1("c++");
	lecture lct2("algorithm");

	lct1.assigntch(&tch1);
	lct2.assigntch(&tch2);

	lct1.registStd(&std1);
	lct1.registStd(&std3);

	lct2.registStd(&std1);
	lct2.registStd(&std2);

	lct1.study();
	cout << lct1 << endl << lct2 << endl;
	lct2.study();
	cout << lct1 << endl << lct2;
	system("pause");
	
}