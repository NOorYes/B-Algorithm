#include <iostream>
#include <algorithm>

using namespace std;
void Do_Quad(const int& N_, int row, int col);// 반반 나누는 함수 N - 반토막, count = 4토막
bool is_Do(const int& N_, int row, int col); // 배열을 넘겨받아 모든 원소가 0인지 1인지 판단.
int mat[2187][2187]; // mat[N][N]

int count_num = 0;
int r = 0; // x좌표
int c = 0; // y좌표 

// while (cin>>num>>r>>c) 입력은 이렇게.
int main()

{
	// 일단, 입력은 N, 좌표 r, c
	// 행렬은 최대 2^15*2^15이고, 15x15 크기의 배열이 필요하나 
	// 배열의 최댓값을 넘어서서 오류가 난다.
	// 나누면 2^(N-1) 4개로.
	// 2^3*2^3 = 2^6 나누면 
	// N) 1일때 0, 2일때 4, 3일때 16 0, 2^2 2^4, 2^6
	// N 이면 두번째는 2^(N-1)*2^(N-1) 번째로 방문하고, 그만큼씩 더해짐. = 즉 원소의 개수만큼.
	// 1일때는 0임 예외.
	// N일때 2

	// 입력

	int Num = 0; // 2^Num 으로 들어가야 함 

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

	// 출력

	/*
	1. 모든 원소가 1이나 0이 아니라면, 4등분함. (do_half())
	2. 괄호를 추가하는 조건은? -> 나누기 함수가 발동하면 괄호. 끝날 때 괄호 닫기.
	모든 원소가 0인지 1인지? - 아니면 나누기 함수 발동 (괄호 추가). - 나눈 거 가장 왼쪽에 대해 반복.
	나눈 4등분이 다 끝나면 괄호 닫음.
	*/
	return 0;
}


void Do_Quad(const int& N_, int row_, int col_) // 한 분면에 대해서 계속 탐색. 다하면 )닫고 넘어감 
{ 
	// 들어온 좌표가 어느 영역에 속하는지를 알아야 하겠죠.

	if (N_ < 1) { return; } // 기저조건
	
	if (!is_Do(N_, row_, col_)) { // row, col은 0인 상황.
		
		// 리턴하는 값에 따라 그 사분면을 반복적으로 분할. 
		Do_Quad(N_ / 2, row_, col_); // 왼쪽 위
		Do_Quad(N_ / 2, row_, (col_ + N_ / 2)); // 오른쪽 위
		Do_Quad(N_ / 2, (row_ + N_ / 2), col_); // 왼쪽 아래
		Do_Quad(N_ / 2, (row_ + N_ / 2), (col_ + N_ / 2)); // 오른쪽 아래
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
int where(const int& N_)// 어느 사분면에 있는지 탐색하는 함수.
{
	// 1 2 // 계속 나누면서 z의 첫번째 원소의 번호를 먹임.
	// 3 4 // 이렇게 남을 때까지 나누고, 거기서 z 모양으로 더하며 최종 숫자 산출.

	if ()
		return 1; // 제 1사분면
	else if ()
		return 2; // 제 2사분면
	else if ()
		return 3; // 제 3사분면
	else
		return 4; // 제 4사분면
}
*/


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

/*
if (col < N_ / 2 || row < N_ / 2) {
	count_num--;
}
else if (col == (N_ / 2) + 1 && row == 3) {  // col == (N_ / 2) + 1 && row == N_/2 + 3 
	count_num--;
}
*/