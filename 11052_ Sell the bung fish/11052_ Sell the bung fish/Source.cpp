#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

int dp(vector<int> PI_, const int& N_); // �ִ� ���� ���ϴ� �Լ�
int price[1000];

int main()
{
	vector<int> PI; // ��Ʈ�� �����ϴ� ����
	int N = 0; // �ؾ�� ����
	int number = 0; // �� ��Ʈ�� ���Ե� �ؾ�� ��
	int result = 0; // �ִ� ����

	while (1) {
		
		scanf("%d", &N);
		if (N < 1 || N> 1000) {
			continue;
		}
		else
			break;
	}

	PI.push_back(0);

	for (int i = 1; i <= N; i++) { // �ε�ȣ
		
		scanf("%d", &number);
		if (number < 1 || number> 10000) {
			i -= 1;
			continue;
		}
		else
			PI.push_back(number);
	}

	// �Է�

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


