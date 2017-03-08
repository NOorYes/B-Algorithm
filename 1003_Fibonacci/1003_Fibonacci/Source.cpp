#include <iostream>
#include <vector>

using namespace std;
void count_num(const int& N_);

int num_one = 0;
int num_zero = 0;

int main()
{
	int T = 0; // 테스트 케이스의 수
	int N = 0; // 0<= N <=40
	int result = 0; // 답

	scanf("%d",&T);
	
	for (int i = 0; i < T; i++) {

		scanf("%d", &N);
		count_num(N);
		printf("%d %d\n", num_zero, num_one);

	}
	
	return 0;
}

void count_num(const int& N_)
{
	vector <int> total_zero, total_one;

	total_one.push_back(0); // 0
	total_one.push_back(1); // 1
	
	total_zero.push_back(1); // 0
	total_zero.push_back(0); // 1

	if (2 > N_)
	{
		num_one = total_one[N_];
		num_zero = total_zero[N_];
	}
	
	else
	{
		for (int i = 2; i <= N_; i++)
		{
			total_one.push_back(total_one[i - 1] + total_one[i - 2]);
			total_zero.push_back(total_zero[i - 1] + total_zero[i - 2]);
		}

		num_one = total_one[N_];
		num_zero = total_zero[N_];
	}
}