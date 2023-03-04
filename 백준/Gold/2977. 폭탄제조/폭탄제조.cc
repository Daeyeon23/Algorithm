#include <iostream>
using namespace std;

struct Package {
	int cnt;
	int cost;
};

int n; // 부품의 개수
int m; // 돈 
int parts[101]; // 필요한 부품의 수
int have[101];  // 이미 확보한 부품의 수
Package smallpkg[101]; // 작은 패키지
Package bigpkg[101]; //큰 패키지

int costsearch(int num, int bigcnt, int smallcnt, int need) {

	int cost = 2134567890;

	for (int i = 0; i <= bigcnt; i++) {
		int left = 0;
		int right = smallcnt;
		// 기준 : big package를 i개 구매했을때 필요한 부품의 개수
		int target = need - i * bigpkg[num].cnt;

		while (left <= right) {
			int mid = (left + right) / 2;
			// smallpkg를 mid개 구매했을때 필요한 부품의 개수를 넘어가는가? 
			if (mid * smallpkg[num].cnt >= target) {
				// 가능성을 찾았다! 
				int price = i * bigpkg[num].cost + mid * smallpkg[num].cost;
				// 최소 비용 갱신
				if (price < cost)
					cost = price;
				// 더 적게(싸게)구매할수 있는 방법이 잇는지 찾아보자
				right = mid - 1;
			}
			else
				// 필욯나 부품 개수를 충족하려면 더 많이 구매해야 한다. 
				left = mid + 1;
		}
	}
	return cost;
}

int psearch() {

	int left = 0;
	int right = 100000;
	int ans;

	while (left <= right) {
		int money = m;

		// 기준 :  mid개의 모델을 만들어보자!
		int mid = (left + right) / 2;

		for (int i = 0; i < n; i++) {
			// mid개의 모델을 만들기 위해서 필요한 i번째부품 개수
			// (i번 부품을 만들기 위한 개수 x mid)-보유한 부품 개수
			int need = (parts[i] * mid) - have[i];

			// 이미 가진 부품 수로 i번째 부품을 만들수 없다면
			if (need > 0) {

				// bigcnt : 최대 구매해야하는 bigpkg의 개수
				int bigcnt = need / bigpkg[i].cnt;
				if (need > bigcnt * bigpkg[i].cnt)
					bigcnt++;

				// smallcnt : 최대 구매해야하는 smallpkg의 개수
				int smallcnt = need / smallpkg[i].cnt;
				if (need > smallcnt * smallpkg[i].cnt)
					smallcnt++;

				// bigpkg, smallpkg를 가장 효율적으로 구매할수있는 방법 찾기
				int cost = costsearch(i, bigcnt, smallcnt, need);
				// 해당 비용만큼 용돈에서 차감 
				money -= cost;
			}
			// 여기까지 구매했는데 돈이 없다면 중단 -> 불가능한 조합이다!
			if (money < 0)
				break;
		}

		// 필요한 부품을 용돈 내에서 모두 구매할수 있다면:
		if (money >= 0) {
			// 가능성을 찾았다!
			ans = mid;
			// 더 많은 모델을 만들어보자
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	return ans;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> parts[i] >> have[i] >> smallpkg[i].cnt >> smallpkg[i].cost >> bigpkg[i].cnt >> bigpkg[i].cost;

	// solve 
	int ans = psearch();
	cout << ans;
}