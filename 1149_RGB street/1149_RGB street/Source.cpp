#include<iostream>
#include<algorithm>

using namespace std;
int result = 0;
void dp(int R_[], int G_[], int B_[]);
int N = 0; // 집의 수

int main()
{
	int R, G, B = 0; // 빨강, 초록, 노랑
	int R_[31];
	int G_[31];
	int B_[31]; // 각각을 저장하는 벡터

	scanf("%d", &N);

	for (int i = 1; i<=N; i++) {
		
		scanf("%d %d %d", &R, &G, &B);
		
		R_[i] = R;
		G_[i] = G;
		B_[i] = B;
	}

	dp(R_, G_, B_);

	printf("%d", result);

	return 0;
}

void dp(int R_[], int G_[], int B_[])
{
	if(N == 1) { result = min(min(R_[1], G_[1]), B_[1]); }

	else {

		for (int i = 1; i < N; i++) {

			R_[i + 1] = R_[i + 1] + min(G_[i], B_[i]);
		    G_[i + 1] = G_[i + 1] + min(R_[i], B_[i]);
			B_[i + 1] = B_[i + 1] + min(R_[i], G_[i]);

		}
	
		result = min(min(R_[N], G_[N]), B_[N]);
	}
}
