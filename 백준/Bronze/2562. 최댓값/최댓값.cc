#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	
	int arr[9];

	int max = 0;
	int idx = 0;
	for (int i = 0; i < 9; i++) {
		cin >> arr[i];
		if (max < arr[i]) {
			max = arr[i];
			idx = i + 1;
		}
	}
	
	cout << max << '\n';
	cout << idx;
	return 0;
}