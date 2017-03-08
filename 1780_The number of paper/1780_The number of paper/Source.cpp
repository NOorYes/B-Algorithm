#include <iostream>
#include <algorithm>

using namespace std;
void Do_Quad(const int& N_, int row, int col);// 반반 나누는 함수 N - 반토막, count = 4토막
bool is_Do(const int& N_, int row, int col); // 배열을 넘겨받아 모든 원소가 0인지 1인지 판단.
int mat[2187][2187]; // mat[N][N]

int is_1 = 0;
int is_0 = 0;
int is_M1 = 0;

int main()

{
	// 입력

	int N = 0; // 영상의 크기 1≤N ≤64 이다.
	int what = 0; // 입력값

	scanf("%d", &N);

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			scanf("%d", &mat[row][col]);
		}
	}
	// 출력

	/*
	1. 모든 원소가 1이나 0이 아니라면, 4등분함. (do_half())
	2. 괄호를 추가하는 조건은? -> 나누기 함수가 발동하면 괄호. 끝날 때 괄호 닫기.
	모든 원소가 0인지 1인지? - 아니면 나누기 함수 발동 (괄호 추가). - 나눈 거 가장 왼쪽에 대해 반복.
	나눈 4등분이 다 끝나면 괄호 닫음.
	*/

	Do_Quad(N, 0, 0);

	printf("%d\n", is_M1);
	printf("%d\n", is_0);
	printf("%d\n", is_1);

	return 0;
}


void Do_Quad(const int& N_, int row_, int col_) // 한 분면에 대해서 계속 탐색. 다하면 )닫고 넘어감 
{
	if (N_ < 1) { return; } // 기저조건

	if (!is_Do(N_, row_, col_)) { // row, col은 0인 상황.


		/*123
		  456
		  789
		*/

		Do_Quad(N_ / 3, row_, col_); 
		Do_Quad(N_ / 3, row_, (col_ + N_ / 3)); 
		Do_Quad(N_ / 3, row_, (col_ + 2*N_ / 3)); // 맨 위 - row 는 같음 
		
		Do_Quad(N_ / 3, (row_ + N_ / 3), col_); 
		Do_Quad(N_ / 3, (row_ + N_ / 3), (col_ + N_ / 3));
		Do_Quad(N_ / 3, (row_ + N_ / 3), (col_ + 2*N_ / 3)); // 중간
		
		Do_Quad(N_ / 3, (row_ + 2*N_ / 3), col_);
		Do_Quad(N_ / 3, (row_ + 2 * N_ / 3), (col_ + N_ / 3));
		Do_Quad(N_ / 3, (row_ + 2 * N_ / 3), (col_ + 2*N_ / 3)); // 아래
		
	}

}

bool is_Do(const int& N_, int row_, int col_) // 최대 32
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

	if (is_zero_ == count_) {// 모든 원소가 0
		is_0++;
		return true;
	}
	else if (is_one_ == count_) {// 모든 원소가 1
		is_1++;
		return true;
	}
	else if (is_Mone_ == count_) {// 모든 원소가 -1
		is_M1++;
		return true;
	}
	else
		return false;
}


/*
for (int row = 0; row < N_ / 2; row++) { // 왼쪽 위
for (int col = 0; col < N_ / 2; col++) {
element_ = mat[row][col];
temp_mat[row][col] = element_;
}
}

for (int row = 0; row < N_ / 2; row++) { // 오른쪽 위
for (int col = N_ / 2; col < N_; col++) {
element_ = mat_[row][col];
temp_mat[row][col] = element_;
Do_Quad(N, temp_mat);
}
}

for (int row = N_ / 2; row < N_; row++) { // 왼쪽 아래
for (int col = 0; col < N_ / 2; col++) {
element_ = mat_[row][col];
temp_mat[row][col] = element_;
Do_Quad(N, temp_mat);
}
}

for (int row = N_ / 2; row < N_; row++) { // 오른쪽 아래
for (int col = N_ / 2; col < N_; col++) {
element_ = mat_[row][col];
temp_mat[row][col] = element_;
Do_Quad(N, temp_mat);
}
}

*/