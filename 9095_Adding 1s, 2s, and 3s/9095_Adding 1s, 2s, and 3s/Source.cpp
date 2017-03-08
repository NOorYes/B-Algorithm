#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;
void picking(int num, vector<int>&p, int pick);
void print(vector<int>&p);
bool is_Answer(vector<int>&p);
vector<int> Q;
vector<int> A;
int T = 0; // 케이스의 수
int z = 0; // 인덱스

int main()
{
	// 
	// 넘버는 3으로 고정. 
	// 1개를 뽑는 경우, 2개를 뽑는 경우, 3개를 뽑는 경우.
	// pick 의 숫자를 123으로 돌려 가면서 집어넣으면 됨.
	// 질문을 받아서 써넣는 사람, 숫자 조합들 몽땅 넣는 사람, 합이 n인지 확인하고 맞으면 개수를 늘려 나가는 사람
	
	int pick = 4; // 이걸 주어진 숫자만큼 바꾸면 됨.
	vector<int> picked;
	int number = 4;
	
	int what= 0;

	scanf("%d", &T);

	for(int y = 0; y<T ;y++) // 결과 벡터 공간 생성
	A.push_back(0);

	for (int j = 0; j < T; j++)
	{
		scanf("%d", &what);
		Q.push_back(what);
	}
	
	for (z = 0; z < T; z++)
	{
		pick = Q[z];
		picking(number,picked,pick);
	}

	for (int x = 0; x < T; x++)
	printf("%d\n", A[x]);

} 
void picking(int num, vector<int>&p, int pick) //  num 개의 숫자중, pick개를 뽑는 조합(중복 x)
{
	if (is_Answer(p)) { return; }
	if (pick == 0) { return; }
	for (int next=1; next < num; next++)
	{
		p.push_back(next);
		picking(num, p, pick - 1);
		p.pop_back();
	}
}

void print(vector<int>&p)
{
	for (int i = 0; i < p.size(); i++)
	{
		printf("%d ", p[i]);
	}
	printf("\n");
}

bool is_Answer(vector<int>&p)
{
	int total = 0;
	
	for (int i = 0; i < p.size(); i++) 
	{
		total = p[i] + total;
	}

		if (total == Q[z]) 
		{
			A[z]++;
			return true;
		}
		else
			return false;
}




