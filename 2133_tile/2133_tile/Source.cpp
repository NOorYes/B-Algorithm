#include <iostream>

using namespace std;

void dp(const int& N_);
int tile[31]; // Ÿ���� ���̸�ŭ ����

int main()
{
	int N = 0; 

	scanf("%d", &N);
	
	if (N % 2 != 0) {
		printf("0\n");
	}
	else {
		dp(N);
		printf("%d\n", tile[N]);
	}
}

void dp(const int& N_) {
	
	tile[0] = 1;
	tile[2] = 3;

	if (2 >= N_) {
		return;
	}

	else {
		for (int j = 4; j <= N_; j += 2) { // 4 5 6..
	
			 tile[j] = tile[j - 2] * 3;
				
				for (int i = 4; i <= j; i += 2) {
					tile[j] += 2 * tile[j - i];
			}
		}
	}

}
