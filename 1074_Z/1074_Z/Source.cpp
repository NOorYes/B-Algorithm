#include <iostream>
#include <algorithm>

using namespace std;
void Do_Quad(const int& N_, int row, int col);// �ݹ� ������ �Լ� N - ���丷, count = 4�丷
bool is_Do(const int& N_, int row, int col); // �迭�� �Ѱܹ޾� ��� ���Ұ� 0���� 1���� �Ǵ�.
int mat[2187][2187]; // mat[N][N]

int count_num = 0;
int r = 0; // x��ǥ
int c = 0; // y��ǥ 

// while (cin>>num>>r>>c) �Է��� �̷���.
int main()

{
	// �ϴ�, �Է��� N, ��ǥ r, c
	// ����� �ִ� 2^15*2^15�̰�, 15x15 ũ���� �迭�� �ʿ��ϳ� 
	// �迭�� �ִ��� �Ѿ�� ������ ����.
	// ������ 2^(N-1) 4����.
	// 2^3*2^3 = 2^6 ������ 
	// N) 1�϶� 0, 2�϶� 4, 3�϶� 16 0, 2^2 2^4, 2^6
	// N �̸� �ι�°�� 2^(N-1)*2^(N-1) ��°�� �湮�ϰ�, �׸�ŭ�� ������. = �� ������ ������ŭ.
	// 1�϶��� 0�� ����.
	// N�϶� 2

	// �Է�

	int Num = 0; // 2^Num ���� ���� �� 

	while (cin >> Num >> r >> c) {
		Do_Quad(pow(2, Num), 0, 0);
		printf("%d\n", count_num);

		for (int row = 0; row < pow(2, Num); row++) {
			printf("\n");
			for (int col = 0; col < pow(2, Num); col++) {
				printf("%d ", mat[row][col]);
			}
		}		

		count_num = 0;
	}

	// ���

	/*
	1. ��� ���Ұ� 1�̳� 0�� �ƴ϶��, 4�����. (do_half())
	2. ��ȣ�� �߰��ϴ� ������? -> ������ �Լ��� �ߵ��ϸ� ��ȣ. ���� �� ��ȣ �ݱ�.
	��� ���Ұ� 0���� 1����? - �ƴϸ� ������ �Լ� �ߵ� (��ȣ �߰�). - ���� �� ���� ���ʿ� ���� �ݺ�.
	���� 4����� �� ������ ��ȣ ����.
	*/
	return 0;
}


void Do_Quad(const int& N_, int row_, int col_) // �� �и鿡 ���ؼ� ��� Ž��. ���ϸ� )�ݰ� �Ѿ 
{ 
	// ���� ��ǥ�� ��� ������ ���ϴ����� �˾ƾ� �ϰ���.

	if (N_ < 1) { return; } // ��������
	
	if (!is_Do(N_, row_, col_)) { // row, col�� 0�� ��Ȳ.
		
		// �����ϴ� ���� ���� �� ��и��� �ݺ������� ����. 
		Do_Quad(N_ / 2, row_, col_); // ���� ��
		Do_Quad(N_ / 2, row_, (col_ + N_ / 2)); // ������ ��
		Do_Quad(N_ / 2, (row_ + N_ / 2), col_); // ���� �Ʒ�
		Do_Quad(N_ / 2, (row_ + N_ / 2), (col_ + N_ / 2)); // ������ �Ʒ�
	}
	
}

bool is_Do(const int& N_, int row_, int col_) // �ִ� 32
{
	int is_zero_ = 0;
	int is_one_ = 0;
	int is_Mone_ = 0;

	int count_ = N_*N_;
	int element = 0;

	for (int row = row_; row < row_ + N_; row++) {
		for (int col = col_; col < col_ + N_; col++) {
			mat[row][col] = count_num++;
			if (col < N_ / 2 || row < N_ / 2) {
				count_num--;
			}
			else if (col == (N_ / 2) + 1 && row == 3) {  // col == (N_ / 2) + 1 && row == N_/2 + 3 
				count_num--;
			}
				return false;
		}
	}
}
/*
int where(const int& N_)// ��� ��и鿡 �ִ��� Ž���ϴ� �Լ�.
{
	// 1 2 // ��� �����鼭 z�� ù��° ������ ��ȣ�� ����.
	// 3 4 // �̷��� ���� ������ ������, �ű⼭ z ������� ���ϸ� ���� ���� ����.

	if ()
		return 1; // �� 1��и�
	else if ()
		return 2; // �� 2��и�
	else if ()
		return 3; // �� 3��и�
	else
		return 4; // �� 4��и�
}
*/


/*
for (int row = 0; row < N_ / 2; row++) { // ���� ��
for (int col = 0; col < N_ / 2; col++) {
element_ = mat[row][col];
temp_mat[row][col] = element_;
}
}

for (int row = 0; row < N_ / 2; row++) { // ������ ��
for (int col = N_ / 2; col < N_; col++) {
element_ = mat_[row][col];
temp_mat[row][col] = element_;
Do_Quad(N, temp_mat);
}
}

for (int row = N_ / 2; row < N_; row++) { // ���� �Ʒ�
for (int col = 0; col < N_ / 2; col++) {
element_ = mat_[row][col];
temp_mat[row][col] = element_;
Do_Quad(N, temp_mat);
}
}

for (int row = N_ / 2; row < N_; row++) { // ������ �Ʒ�
for (int col = N_ / 2; col < N_; col++) {
element_ = mat_[row][col];
temp_mat[row][col] = element_;
Do_Quad(N, temp_mat);
}
}

*/

/*
if (col < N_ / 2 || row < N_ / 2) {
	count_num--;
}
else if (col == (N_ / 2) + 1 && row == 3) {  // col == (N_ / 2) + 1 && row == N_/2 + 3 
	count_num--;
}
*/