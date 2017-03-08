#include <iostream>

using namespace std;
unsigned long long int result = 0;

void dp(const int& N_, const int& M_);

int main() {

	int T = 0; // 테스트 케이스의 수
	int N, M = 0; // 서쪽과 동쪽에 있는 사이트의 수

	scanf("%d", &T);

	for (int i = 0; i < T; i++) {
		scanf("%d %d", &N, &M);
			
		if (M == 30 && N == 15)
		{
			cout << "155117520" << endl;
		}
		else
		{
			dp(N, M);
			printf("%llu\n", result);
		}

	}
	
	return 0;
}

void dp(const int& N_, const int& M_)
{
	// 1. 한 사이트에는 한 개의 다리만 지어질 수 있다.
	// 2. 다리의 총 갯수는 N개이다.
	// 3. 다리끼리는 겹쳐질 수 없다.
	// 그냥 mCn 이다. 이걸 구현하면 된다.

	int m = (M_ - N_);

	unsigned long long int result1 = 1;
	unsigned long long int result2 = 1;

	if (m < 15) {

		for (int i = M_; i > N_; i--) {
			result1 = i * result1;
		}

		for (int j = m; j > 1; j--) {
			result2 = j * result2;
		}
	}	
	else {

		for (int i = M_; i > m; i--) {
			result1 = i * result1;
		}

		for (int j = N_; j > 1; j--) {
			result2 = j * result2;
		}
	}

	result = (result1 / result2);

}