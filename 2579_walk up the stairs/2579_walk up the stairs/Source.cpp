#include <iostream>
#include <vector>
using namespace std;

int result = 0; // �����
int dp(vector<int>stair_); // ������ȹ��

int main()
{
	int N = 0; // ����� ����
	int reward = 0; // ����� ����
	vector<int> stair; // ��� ����
	int result = 0; // ������

	while (1) {

	scanf("\%d", &N);
	if (N > 300) {
		printf("no!\n");
		continue;
	}
	else
		break;
	}

	stair.push_back(0); // 0��° - �ٴ��� �ϴ� ä��� ����

	for (int i = 1; i <= N; i++) {// ���� �Ʒ��� ���� ��ܺ��� �������.
		scanf("%d", &reward);
		if (reward <= 10000) {
			stair.push_back(reward);
		}
		else {
			printf("no!\n");
			i -= 1;
			continue;
		}
	}

// �̻� �Է� �Ϸ�

	// ������ȹ��
	result = dp(stair);

	printf("%d", result); // ����� ���.

	return 0;
}

int dp(vector<int>stair_)
{
	int temp = 0;
	int total = 0;
	vector <int> one;
	vector <int> two;
	
	one.push_back(0);
	two.push_back(0);

	// ������ ����� �ݵ��! ��ƾ� �Ѵ�. - �߿��ϴ�!
	// �迭�� ũ��� ����� ������ ����.
	// 1�� �ε����� 1�� ����̴�.

	one.push_back(stair_[1]);
	two.push_back(0); // ó�� ��.

	one.push_back(stair_[1]+stair_[2]);
	two.push_back(stair_[2]);

	for (int i = 3; i < stair_.size(); i++) {
		
		temp = two[i - 1];
		one.push_back(temp+stair_[i]);
		temp = (one[i - 2] > two[i - 2]) ? one[i - 2] : two[i - 2];
		two.push_back(temp+stair_[i]);

		temp = 0;
	}

	total = (one[stair_.size()-1] > two[stair_.size()-1]) ? one[stair_.size()-1] : two[stair_.size()-1];

	return total;
}