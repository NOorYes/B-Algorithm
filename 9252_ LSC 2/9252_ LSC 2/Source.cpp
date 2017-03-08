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
	int result = 0; // ���� ����
	int dp[1001] = { 0, }; // LSC�� ���̸� ����
	int index[1001] = {-1, }; // �������� ���� �ε���
	int max_number = 0; // ���� ū ������ dp[]��
	int max_index = 0; // ���� ū ������ �ε���
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
			{	//max_number = max(max_number, dp[j - 1]); // ���� ū ���� ��� ����				

				if (dp[j - 1] >= max_number) { // ���� �ƽ� �ѹ����� dp[]�� �� ũ�ٸ�
					max_number = dp[j - 1]; // �ƽ� �ѹ��� dp[]�� �ٲٰ�
					max_index = (j - 1); // �ƽ� �ε����� [] ���� ������.
				}
				// �۴ٸ� �� �״�� ���� ��.
			}
				

		if (arr[i] == arr2[j]) { // ���� ��ġ�Ѵٸ�
				dp[j] = max_number + 1; // �ƽ� �ѹ� + 1�� ���� dp[] �� �����ϰ�,
				index[j] = max_index; // �ε����� �ƽ� �ε����� ����
			}
		}
	}

	if (dp[len - 1] < dp[len - 2]) { // ������ ���� ������ �ߺ��ȴٸ�
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

