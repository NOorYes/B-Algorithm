#include <iostream>
#include <vector>
using namespace std;
void greedy(vector<long>value_, const long& K_);
int number = 0;
int main()
{
	int N = 0; // ������ ����
	long K = 0; // ������ ��ġ ��
	long A = 0; // �� ������ ��ġ�� 
	vector<long>value;

	scanf("%d %ld", &N, &K);

	for (int i = 0; i<N; i++) {
		scanf("%ld", &A);
		value.push_back(A);
	}
	greedy(value, K);

	printf("%d\n", number);
}

void greedy(vector<long>value_, const long& K_) // ����Ʈ�� ������ �и�
{
	long temp = 0; // ���� ������ �� ����
	int result = K_; // ���� ����
	int count = 0;

	if (result == 0) { return; } // 0�� �Ǹ� Ż��.

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