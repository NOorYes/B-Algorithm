#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int dp(vector<int> PI_, const int& N_); // 최대 수익 구하는 함수
int price[1000];

int main()
{
	vector<int> PI; // 세트를 저장하는 벡터
	int N = 0; // 붕어빵의 개수
	int number = 0; // 한 세트에 포함된 붕어빵의 수
	int result = 0; // 최대 수익

	while (1) {
		
		scanf("%d", &N);
		if (N < 1 || N> 1000) {
			continue;
		}
		else
			break;
	}

	PI.push_back(0);

	for (int i = 1; i <= N; i++) { // 부등호
		
		scanf("%d", &number);
		if (number < 1 || number> 10000) {
			i -= 1;
			continue;
		}
		else
			PI.push_back(number);
	}

	// 입력

	result = dp(PI, N);
	printf("%d\n", result);
}

int dp(vector<int> PI_, const int& N_)
{
	int result = 0;
	// PI_ 1 5 6 7 // N_ = 5 // size = 6

	for (int i = 1;i <= N_; i++) {
		for (int j = 0; j < i; j++) {
			price[i] = max(price[i], price[j]+PI_[i-j]);
		} // 0 1 
	}
	return price[N_];
}


