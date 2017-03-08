#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
char arr[1001];
char arr2[1001];
char temp[1001];
void LCS();

int main()
{
	scanf("%s", &arr);
	scanf("%s", &arr2);


	LCS();
	
	return 0;
}

void LCS()
{
	int len = strlen(arr);
	int len2 = strlen(arr2);
	int result = 0; // 최종 길이
	int dp[1001] = { 0, }; // LSC의 길이를 저장
	int index[1001] = {-1, }; // 역추적을 위한 인덱스
	int max_number = 0; // 가장 큰 숫자의 dp[]값
	int max_index = 0; // 가장 큰 숫자의 인덱스
	int count = 0;
	//char arr_temp[1];
	//char arr2_temp[1];


	for (int i = 0; i < len; i++) {
		//strcpy(arr_temp, &arr[i]);
		max_number = 0;
		max_index = 0;
		for (int j = 0; j < len2; j++) {
			//strcpy(arr2_temp, &arr2[j]);
			if (j > 0)
			{	//max_number = max(max_number, dp[j - 1]); // 가장 큰 값을 계속 갱신				

				if (dp[j - 1] >= max_number) { // 만약 맥스 넘버보다 dp[]가 더 크다면
					max_number = dp[j - 1]; // 맥스 넘버를 dp[]로 바꾸고
					max_index = (j - 1); // 맥스 인덱스를 [] 안의 값으로.
				}
				// 작다면 걍 그대로 가면 됨.
			}
				

		if (arr[i] == arr2[j]) { // 만약 일치한다면
				dp[j] = max_number + 1; // 맥스 넘버 + 1의 값을 dp[] 에 저장하고,
				index[j] = max_index; // 인덱스에 맥스 인덱스를 저장
			}
		}
	}

	if (dp[len - 1] < dp[len - 2]) { // 마지막 것이 적은데 중복된다면
		dp[len - 1] = max(dp[len - 1], dp[len - 2]);
		temp[len2] = arr2[len2 - 2];
	}
	else
	{
		temp[len2] = arr2[len2 - 1];
	}

	result = dp[len2 - 1];
	for (int y = (len2 - 1); y>=0 ; y--) {

		count = result - 1;
		count--;
		temp[y] = arr2[index[y]];

		if (count == 0) { break; }
	}
	
	
	printf("%d\n", result);
	
	for (int x = (len2 - result) + 1; x <= len2; x++)
		printf("%c", temp[x]);

}

