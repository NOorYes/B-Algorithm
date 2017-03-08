#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
int main()
{
	int n = 0;
	int d = 0;
	int p = 0;
	vector<pair<int, int>>lecture;
	int result = 0;
	vector<int>number;
	vector<int>day;

	scanf("%d", &n);

	if (n == 0) {
		printf("%d\n", n);
		return 0;
	}

	for (int i = 0; i < n; i++)
	{
		scanf("%d %d", &d, &p);
		lecture.push_back(make_pair(p, d));
	}

	if (lecture.size() == 1)
		printf("%d", lecture.back().second);
	else {
		sort(lecture.begin(), lecture.end());
		reverse(lecture.begin(), lecture.end());
		// �Ÿ� ��, ��� ������ �������� ����.
		// first = d, second = p
		day.push_back(lecture[0].first);
		for (int j = 2; j < lecture.size(); j += 2) // 1�� ������ ���� ������ ��� X
		{
			if ((lecture[j - 1].first - lecture[j].first) == 0)
			{
				result += lecture[j - 1].first;
			}

			else if ((lecture[j - 1].first - lecture[j].first) == 1)  // �̰� �� ��¥�� ������ ���̿� �� �� �ִ� �ִ� ������ ����
			{
				//result += lecture[j - 1].second; // �� ���ۿ� ������ �翬�� ������ ū ���ǷḦ ���� �� �ִ� ���� ����.
				// ���⼭ ������ ���� ���� - �����̶�� �ؼ� �׻� ū ���� �ƴ�. �� �� ���Ƿᰡ ū ���� ���ؾ� �Ѵ�.
				result += max(lecture[j - 1].second, lecture[j].second);
			}

			else if ((lecture[j - 1].first - lecture[j].first) >= 2) // �� �̻� �� �� ������ �� �� ����.
			{
				result += lecture[j - 1].second;
				result += lecture[j].second;
			}
		} // ¦���� �� ������ ��� x 

		result += lecture[0].second; // ù ��° ���� ������ ���� ����.

		printf("%d\n", result);
	}
	return 0;
}
