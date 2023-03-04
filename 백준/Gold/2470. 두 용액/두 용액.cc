#include<iostream>
#include<algorithm>
using namespace std;

int N;
int arr[100000];

int main() {

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + N);

	int left = 0;
	int right = N - 1;

	int sum = arr[left] + arr[right];
	int min_left = 0;
	int min_right = N - 1;
	int min_sum = abs(sum);

	while (left != right) {
		if (abs(sum) < min_sum) {
			min_sum = abs(sum);
			min_left = left;
			min_right = right;
		}

		if (sum >= 0) {
			sum -= arr[right];
			right--;
			sum += arr[right];
		}
		else {
			sum -= arr[left];
			left++;
			sum += arr[left];
		}
	}

	cout << arr[min_left] << ' ' << arr[min_right];

	return 0;
}