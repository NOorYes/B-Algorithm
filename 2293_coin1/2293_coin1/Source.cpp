#include <iostream>
#include <vector>

using namespace std;
void dp(vector<int> value_);

vector <int> price; // ������ ��ġ
int k = 0; // ��
int memo[11000] = {1, 0}; // �޸������̼ǿ� �迭 - �ε����� �˳��ϰ� ��ƾ� ��.

int main()
{
	int n = 0; // �׽�Ʈ ���̽��� ��
	int a = 0; // 0<= N <=40

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {

		scanf("%d", &a);
		price.push_back(a); // ���Ϳ� ���ʷ� �������. 
	}

	dp(price);
	printf("%d\n", memo[k]);

	return 0;
}

void dp(vector<int> value_)
{ // memo[0] = 1, memo[1] = 0 �� ����
	for (int i = 0; i < value_.size(); i++) // 0���� ������ ����ŭ �ݺ��ؼ�. 
	{ // ���ÿ��� 0 1 2 . ������ ���Ϳ� 1 2 5 �� �� �ִ�.
		for (int j = value_[i]; j <= k; j++) // �ʱ갪�� ������ ��ġ�̴�. 
		{ // ���ÿ��� value_[i] = 1 2 5 �ε�, 1~10 / 2~10 / 5~10 ���� j���� ���ϰ� ��.
			memo[j] += memo[j- value_[i]];
		} 
	} // ������ �� ���ΰ����� ������ ��, coin����ŭ �ڿ� �ִ� �ε����� ���ϴ� ���� �ݺ�.
} 

  // value_[0] = 1) memo[1] += memo[1 - 1] / memo[2] += memo[2 - 1] / .. memo[10] = memo[10 - 1] ���� memo[10] = 1�̴�.
  // value_[1] = 2) memo[2] += memo[2 - 2] / memo[3] += memo[3 - 2] / memo[4] += memo[4 - 2] .. ���� memo[10] = 
  // value_[2] = 5) 

  // �ٽ�) memo[n] = n���� ����� ����̴�. 
// ó���� 1���� ���, 2���� 1���� ���, 1���� 2���� 5���� ���..
// ���� ������ŭ �ǳʶٴ� ������ 2���� 1+1, 5���� 1+1+1+1+1 �̱� �����̴�.
// ���� ��� memo[5] �� 1�� 2���� ����ؼ� ����� ����� 5¥���� ����ϴ� ��� 1���� ���ϰ� �ȴ�.