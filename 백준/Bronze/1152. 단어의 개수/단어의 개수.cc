#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<string>
#include<sstream>
using namespace std;



int main() {

	string str;
	getline(cin, str);
	istringstream iss(str);
	string tmp;
	int cnt = 0;
	while (getline(iss, tmp, ' ')) {
		if (tmp == "") continue;
		cnt++;
	}
	cout << cnt << '\n';
	return 0;
}