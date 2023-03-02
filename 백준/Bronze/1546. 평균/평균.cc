#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
using namespace std;



int main() {

	int N;
	cin >> N;

	double score[1000];
	double Max = 0;
	for (int i = 0;i < N;i++) {
		cin >> score[i];
		Max = max(Max, score[i]);
	}

	double sum = 0;

	for (int i = 0;i < N;i++) {
		score[i] = score[i] / Max * 100;
		sum += score[i];
	}

	cout << sum / N;
	

	return 0;
}