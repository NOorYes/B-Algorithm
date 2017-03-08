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
		// 거리 순, 비용 순으로 내림차순 정렬.
		// first = d, second = p
		day.push_back(lecture[0].first);
		for (int j = 2; j < lecture.size(); j += 2) // 1은 무조건 들어가기 때문에 고려 X
		{
			if ((lecture[j - 1].first - lecture[j].first) == 0)
			{
				result += lecture[j - 1].first;
			}

			else if ((lecture[j - 1].first - lecture[j].first) == 1)  // 이게 두 날짜를 포함한 사이에 들어갈 수 있는 최대 강의의 갯수
			{
				//result += lecture[j - 1].second; // 한 개밖에 못들어가면 당연히 이전의 큰 강의료를 얻을 수 있는 것을 고른다.
				// 여기서 오류를 범한 이유 - 이전이라고 해서 항상 큰 것은 아님. 둘 중 강의료가 큰 것을 더해야 한다.
				result += max(lecture[j - 1].second, lecture[j].second);
			}

			else if ((lecture[j - 1].first - lecture[j].first) >= 2) // 둘 이상 들어갈 수 있으면 둘 다 고른다.
			{
				result += lecture[j - 1].second;
				result += lecture[j].second;
			}
		} // 짝수일 때 마지막 고려 x 

		result += lecture[0].second; // 첫 번째 것은 무조건 들어가기 때문.

		printf("%d\n", result);
	}
	return 0;
}
