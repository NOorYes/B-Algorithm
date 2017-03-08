#include <iostream>
#include <vector>

using namespace std;
void dp(vector<int> value_);

vector <int> price; // 동전의 가치
int k = 0; // 합
int memo[11000] = {1, 0}; // 메모이제이션용 배열 - 인덱스를 넉넉하게 잡아야 함.

int main()
{
	int n = 0; // 테스트 케이스의 수
	int a = 0; // 0<= N <=40

	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {

		scanf("%d", &a);
		price.push_back(a); // 벡터에 차례로 집어넣음. 
	}

	dp(price);
	printf("%d\n", memo[k]);

	return 0;
}

void dp(vector<int> value_)
{ // memo[0] = 1, memo[1] = 0 인 상태
	for (int i = 0; i < value_.size(); i++) // 0부터 동전의 수만큼 반복해서. 
	{ // 예시에선 0 1 2 . 각각의 벡터엔 1 2 5 가 들어가 있다.
		for (int j = value_[i]; j <= k; j++) // 초깃값은 동전의 가치이다. 
		{ // 예시에선 value_[i] = 1 2 5 인데, 1~10 / 2~10 / 5~10 으로 j값이 변하게 됨.
			memo[j] += memo[j- value_[i]];
		} 
	} // 시작할 때 코인값으로 시작한 후, coin값만큼 뒤에 있는 인덱스를 더하는 것을 반복.
} 

  // value_[0] = 1) memo[1] += memo[1 - 1] / memo[2] += memo[2 - 1] / .. memo[10] = memo[10 - 1] 에서 memo[10] = 1이다.
  // value_[1] = 2) memo[2] += memo[2 - 2] / memo[3] += memo[3 - 2] / memo[4] += memo[4 - 2] .. 에서 memo[10] = 
  // value_[2] = 5) 

  // 핵심) memo[n] = n원을 만드는 방법이다. 
// 처음엔 1원만 사용, 2원과 1원을 사용, 1원과 2원과 5원을 사용..
// 코인 개수만큼 건너뛰는 이유는 2원은 1+1, 5원은 1+1+1+1+1 이기 때문이다.
// 예를 들어 memo[5] 는 1과 2만을 사용해서 만드는 방법에 5짜리를 사용하는 방법 1개를 더하게 된다.