#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// https://www.acmicpc.net/problem/10448

bool is_triple(vector<int>&p); // 삼각수 3개의 합으로 나타낼 수 있는지 아닌지.
int triangle_number(int n); // 삼각수 생성.
void picking(int num, vector<int>&p, int pick); // 삼각수들을 뽑아 더하는 함수.
int R_triangle_number(int Tn); // n 구하는 함수
//void print(vector<int>&p);

int Q_num = 0;
int A_num = 0;
vector<int> A_case; // 저장용 벡터

int z = 0; // 케이스의 번호


int main()
{
	int pick = 3;
	int T = 0; // 테스트 케이스.
	int number = 0; // 넘버
	vector<int> save; // 저장용 벡터


	scanf("%d", &T); // 케이스 입력

	for (int x = 0; x < T; x++) {
		A_case.push_back(0);
	}

	for (int i = 0; i < T; i++) { // 입력
		scanf("%d", &Q_num);
		
		if (Q_num < 3) {
			printf("no!");
		}

		number = R_triangle_number(Q_num) + 1;
		picking(number, save, pick);
		//printf("%d\n", A_num);
		Q_num = 0;
		//A_num = 0;
		z++; // 케이스 번호 1증가.
	}

	for (int i = 0; i < T; i++) {
		printf("%d\n",A_case[i]);
	}

	return 0;
	// 입력받은 수가 정확히 3개의 삼각수의 합으로 나오면 1,
	// 아니면 0을 출력하는 함수.
	// 0인 경우는 2개로만 나타낼 수 있거나, 그 자체가 삼각수이거나.
}

bool is_triple(vector<int>&p)
{
	int total = 0;

	for (int i = 0; i < p.size(); i++) { // 합을 구한다. 
		total = triangle_number(p[i]) + total;
	}

	if (Q_num == total) // 합이 3개로 표현되는 경우.
	{
		A_num = 1;
		A_case[z] = 1;
		return true;
	}
	else
		return false;
}

int triangle_number(int n) // 생각해보니까..Tn 에서 n을 차례대로 돌리면 됨; 3개임 인덱스수는
{
	int Tn = (n*(n + 1)) / 2;
	
	return Tn; // 여기서 어떤 수 x는 Tn 의 n보다 작은 삼각수의 합으로 나타내어 질 수 있다.
}

void picking(int num, vector<int>&p, int pick)
{
	// 기저조건 : 그 수보다 작은 삼각수들을 차례로 나열, 합이 정확히 그 숫자고 인덱스가 3이면 리턴
	// 삼각수들을 생성하면, T1 ~ 을 차례로 더해 나간다.
	// 만약 삼각수의 합이 3개면, 스톱.
	// 사이즈가 3이면 리턴하는
	// n을 차례로 선택하는 것이라 보면 됨, 그럼 저 위에 함수로 넘기고 Tn 의 합을 판단.
	if (p.size() == 3) {
		if (is_triple(p)) { return; } // 3개의 합이 나오면 스톱.
	}
		if (pick == 0) { return; }
		for (int next = 1; next < num; next++)
		{
			p.push_back(next);
			picking(num, p, pick - 1);
			p.pop_back();
		}
}

int R_triangle_number(int Tn) // 생각해보니까..Tn 에서 n을 차례대로 돌리면 됨; 3개임 인덱스수는
{
	int re= 1;
	int n = 1;

	for (n=1; n < 46; n++) // 여기가 문제엿음. <45 면 44까지잖아.
	{
		re = n *(n + 1) / 2;

		if (Tn - re <= 0) 
		{
			return (n - 1);
		}
		else
			continue;
	}
}

/*
void print(vector<int>&p)
{
	for (int i = 0; i < p.size(); i++)
	{
		printf("%d ", p[i]);
	}
	printf("\n");
}
*/
