#include<iostream>
#include<vector>
#include <algorithm>

using namespace std;
void picking(int num, vector<int>&p, int pick);
void print(vector<int>&p);
bool is_Answer(vector<int>&p);
vector<int> Q;
vector<int> A;
int T = 0; // ���̽��� ��
int z = 0; // �ε���

int main()
{
	// 
	// �ѹ��� 3���� ����. 
	// 1���� �̴� ���, 2���� �̴� ���, 3���� �̴� ���.
	// pick �� ���ڸ� 123���� ���� ���鼭 ��������� ��.
	// ������ �޾Ƽ� ��ִ� ���, ���� ���յ� ���� �ִ� ���, ���� n���� Ȯ���ϰ� ������ ������ �÷� ������ ���
	
	int pick = 4; // �̰� �־��� ���ڸ�ŭ �ٲٸ� ��.
	vector<int> picked;
	int number = 4;
	
	int what= 0;

	scanf("%d", &T);

	for(int y = 0; y<T ;y++) // ��� ���� ���� ����
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
void picking(int num, vector<int>&p, int pick) //  num ���� ������, pick���� �̴� ����(�ߺ� x)
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




