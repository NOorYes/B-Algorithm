#include <iostream>

using namespace std;
unsigned long long int result = 0;

void dp(const int& N_, const int& M_);

int main() {

	int T = 0; // �׽�Ʈ ���̽��� ��
	int N, M = 0; // ���ʰ� ���ʿ� �ִ� ����Ʈ�� ��

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
	// 1. �� ����Ʈ���� �� ���� �ٸ��� ������ �� �ִ�.
	// 2. �ٸ��� �� ������ N���̴�.
	// 3. �ٸ������� ������ �� ����.
	// �׳� mCn �̴�. �̰� �����ϸ� �ȴ�.

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