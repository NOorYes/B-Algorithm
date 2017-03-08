#include <iostream>
#include <algorithm>

using namespace std;
void Do_Quad(const int& N_, int row, int col);// �ݹ� ������ �Լ� N - ���丷, count = 4�丷
bool is_Do(const int& N_, int row, int col); // �迭�� �Ѱܹ޾� ��� ���Ұ� 0���� 1���� �Ǵ�.
int mat[2187][2187]; // mat[N][N]

int is_1 = 0;
int is_0 = 0;
int is_M1 = 0;

int main()

{
	// �Է�

	int N = 0; // ������ ũ�� 1��N ��64 �̴�.
	int what = 0; // �Է°�

	scanf("%d", &N);

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			scanf("%d", &mat[row][col]);
		}
	}
	// ���

	/*
	1. ��� ���Ұ� 1�̳� 0�� �ƴ϶��, 4�����. (do_half())
	2. ��ȣ�� �߰��ϴ� ������? -> ������ �Լ��� �ߵ��ϸ� ��ȣ. ���� �� ��ȣ �ݱ�.
	��� ���Ұ� 0���� 1����? - �ƴϸ� ������ �Լ� �ߵ� (��ȣ �߰�). - ���� �� ���� ���ʿ� ���� �ݺ�.
	���� 4����� �� ������ ��ȣ ����.
	*/

	Do_Quad(N, 0, 0);

	printf("%d\n", is_M1);
	printf("%d\n", is_0);
	printf("%d\n", is_1);

	return 0;
}


void Do_Quad(const int& N_, int row_, int col_) // �� �и鿡 ���ؼ� ��� Ž��. ���ϸ� )�ݰ� �Ѿ 
{
	if (N_ < 1) { return; } // ��������

	if (!is_Do(N_, row_, col_)) { // row, col�� 0�� ��Ȳ.


		/*123
		  456
		  789
		*/

		Do_Quad(N_ / 3, row_, col_); 
		Do_Quad(N_ / 3, row_, (col_ + N_ / 3)); 
		Do_Quad(N_ / 3, row_, (col_ + 2*N_ / 3)); // �� �� - row �� ���� 
		
		Do_Quad(N_ / 3, (row_ + N_ / 3), col_); 
		Do_Quad(N_ / 3, (row_ + N_ / 3), (col_ + N_ / 3));
		Do_Quad(N_ / 3, (row_ + N_ / 3), (col_ + 2*N_ / 3)); // �߰�
		
		Do_Quad(N_ / 3, (row_ + 2*N_ / 3), col_);
		Do_Quad(N_ / 3, (row_ + 2 * N_ / 3), (col_ + N_ / 3));
		Do_Quad(N_ / 3, (row_ + 2 * N_ / 3), (col_ + 2*N_ / 3)); // �Ʒ�
		
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
			element = mat[row][col];
			if (element == 0) {
				is_zero_++;
			}
			else if (element == 1)
			{
				is_one_++;
			}
			else if (element == -1) {
				is_Mone_++;
			}
			else
				continue;
		}
	}

	if (is_zero_ == count_) {// ��� ���Ұ� 0
		is_0++;
		return true;
	}
	else if (is_one_ == count_) {// ��� ���Ұ� 1
		is_1++;
		return true;
	}
	else if (is_Mone_ == count_) {// ��� ���Ұ� -1
		is_M1++;
		return true;
	}
	else
		return false;
}


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