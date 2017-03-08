#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// https://www.acmicpc.net/problem/10448

bool is_triple(vector<int>&p); // �ﰢ�� 3���� ������ ��Ÿ�� �� �ִ��� �ƴ���.
int triangle_number(int n); // �ﰢ�� ����.
void picking(int num, vector<int>&p, int pick); // �ﰢ������ �̾� ���ϴ� �Լ�.
int R_triangle_number(int Tn); // n ���ϴ� �Լ�
//void print(vector<int>&p);

int Q_num = 0;
int A_num = 0;
vector<int> A_case; // ����� ����

int z = 0; // ���̽��� ��ȣ


int main()
{
	int pick = 3;
	int T = 0; // �׽�Ʈ ���̽�.
	int number = 0; // �ѹ�
	vector<int> save; // ����� ����


	scanf("%d", &T); // ���̽� �Է�

	for (int x = 0; x < T; x++) {
		A_case.push_back(0);
	}

	for (int i = 0; i < T; i++) { // �Է�
		scanf("%d", &Q_num);
		
		if (Q_num < 3) {
			printf("no!");
		}

		number = R_triangle_number(Q_num) + 1;
		picking(number, save, pick);
		//printf("%d\n", A_num);
		Q_num = 0;
		//A_num = 0;
		z++; // ���̽� ��ȣ 1����.
	}

	for (int i = 0; i < T; i++) {
		printf("%d\n",A_case[i]);
	}

	return 0;
	// �Է¹��� ���� ��Ȯ�� 3���� �ﰢ���� ������ ������ 1,
	// �ƴϸ� 0�� ����ϴ� �Լ�.
	// 0�� ���� 2���θ� ��Ÿ�� �� �ְų�, �� ��ü�� �ﰢ���̰ų�.
}

bool is_triple(vector<int>&p)
{
	int total = 0;

	for (int i = 0; i < p.size(); i++) { // ���� ���Ѵ�. 
		total = triangle_number(p[i]) + total;
	}

	if (Q_num == total) // ���� 3���� ǥ���Ǵ� ���.
	{
		A_num = 1;
		A_case[z] = 1;
		return true;
	}
	else
		return false;
}

int triangle_number(int n) // �����غ��ϱ�..Tn ���� n�� ���ʴ�� ������ ��; 3���� �ε�������
{
	int Tn = (n*(n + 1)) / 2;
	
	return Tn; // ���⼭ � �� x�� Tn �� n���� ���� �ﰢ���� ������ ��Ÿ���� �� �� �ִ�.
}

void picking(int num, vector<int>&p, int pick)
{
	// �������� : �� ������ ���� �ﰢ������ ���ʷ� ����, ���� ��Ȯ�� �� ���ڰ� �ε����� 3�̸� ����
	// �ﰢ������ �����ϸ�, T1 ~ �� ���ʷ� ���� ������.
	// ���� �ﰢ���� ���� 3����, ����.
	// ����� 3�̸� �����ϴ�
	// n�� ���ʷ� �����ϴ� ���̶� ���� ��, �׷� �� ���� �Լ��� �ѱ�� Tn �� ���� �Ǵ�.
	if (p.size() == 3) {
		if (is_triple(p)) { return; } // 3���� ���� ������ ����.
	}
		if (pick == 0) { return; }
		for (int next = 1; next < num; next++)
		{
			p.push_back(next);
			picking(num, p, pick - 1);
			p.pop_back();
		}
}

int R_triangle_number(int Tn) // �����غ��ϱ�..Tn ���� n�� ���ʴ�� ������ ��; 3���� �ε�������
{
	int re= 1;
	int n = 1;

	for (n=1; n < 46; n++) // ���Ⱑ ��������. <45 �� 44�����ݾ�.
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
