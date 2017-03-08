#include <iostream>
#include <vector>
using namespace std;
void greedy(vector<long>value_, const long& K_);
int number = 0;
int main()
{
	int N = 0; // 동전의 갯수
	long K = 0; // 동전의 가치 합
	long A = 0; // 각 동전의 가치들 
	vector<long>value;

	scanf("%d %ld", &N, &K);

	for (int i = 0; i<N; i++) {
		scanf("%ld", &A);
		value.push_back(A);
	}
	greedy(value, K);

	printf("%d\n", number);
}

void greedy(vector<long>value_, const long& K_) // 리절트와 템프를 분리
{
	long temp = 0; // 여긴 동전의 값 저장
	int result = K_; // 값을 저장
	int count = 0;

	if (result == 0) { return; } // 0이 되면 탈출.

	for (int i = 0; i < value_.size(); i++) {

		if (value_[i] > result) {
			temp = value_[i - 1];
			count++;
			break;
		}
		else if (value_[i] == result)
		{
			temp = value_[i];
			count++;
		}
	}

	if (count == 0)
		temp = value_[value_.size() - 1];
		value_.pop_back();

	for (int j = 1; 1; j++) {
		if (K_ - (temp * j) < 0) {
				result = (K_ - (temp * (j - 1)));
				number += (j - 1);
				greedy(value_, result);
				break;
			}
			else if (K_ - (temp * j) == 0) {
				result = 0;
				number += j;
				break;
			}
		}
}