#include <iostream>
#include <cstring>

#define MAX_N 51
#define MAX_DAYS 10

int dfs(int start, 
		int end,
		int n,
		int depth, 
		int d, 
		int routs[MAX_N][MAX_N], 
		bool used[MAX_DAYS]) 
{
	int result = 0;

	if (depth > d) {
		return 0;
	}

	if (start == end) {
		return 1;
	}
	used[start] = 1;

	for (int i = 1; i <= n; ++i) {
		if (routs[start][i] && !used[i]) {
			result += dfs(i, end, n, depth + 1, d, routs, used);
		}
	}
	used[start] = 0;

	return result;
}

int main() 
{
	int n, k, a, b, d;
	int routs[MAX_N][MAX_N];
	bool used[MAX_N];

	memset(routs, 0, sizeof(routs));
	memset(used, 0, sizeof(used));

	std::cin >> n >> k >> a >> b >> d;

	for (int i = 0; i < k; ++i) {	
		int first, second;
		std::cin >> first >> second;
		routs[first][second] = 1;
	}

	std::cout << dfs(a, b , n, 0, d, routs, used);

	return 0;
}
