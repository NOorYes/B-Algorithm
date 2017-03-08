#include <iostream>
#include <vector>
using namespace std;

int result = 0; // 결과값
int dp(vector<int>stair_); // 동적계획법

int main()
{
	int N = 0; // 계단의 개수
	int reward = 0; // 계단의 점수
	vector<int> stair; // 계단 벡터
	int result = 0; // 최종값

	while (1) {

	scanf("\%d", &N);
	if (N > 300) {
		printf("no!\n");
		continue;
	}
	else
		break;
	}

	stair.push_back(0); // 0번째 - 바닥을 일단 채우고 시작

	for (int i = 1; i <= N; i++) {// 제일 아래에 놓은 계단부터 순서대로.
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

// 이상 입력 완료

	// 동적계획법
	result = dp(stair);

	printf("%d", result); // 결과값 출력.

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

	// 마지막 계단은 반드시! 밟아야 한다. - 중요하다!
	// 배열의 크기는 계단의 개수와 같다.
	// 1번 인덱스는 1번 계단이다.

	one.push_back(stair_[1]);
	two.push_back(0); // 처음 값.

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