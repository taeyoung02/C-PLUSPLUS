#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
struct member {
	int age;
	string name;
	int order;
};
int main() {
	int n; cin >> n;
	vector<member>arr(n);
	for (int i = 0; i < n; i++) {
		cin >> arr[i].age >> arr[i].name;
		arr[i].order = i;
	}
	sort(arr.begin(), arr.end(),[](member u,member v) {
		return (u.age < v.age) || (u.age == v.age) && (u.order < v.order);
		});
	for (int i = 0; i < n; i++)
		cout << arr[i].age << " " << arr[i].name << '\n';
}