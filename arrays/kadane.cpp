#include <bits/stdc++.h>
#include <string>
using namespace std;

int maxSubArray(vector<int>& nums) {

	int local_max = 0, global_max = INT_MIN;

	for (int i = 0; i < nums.size(); i++) {

		local_max = max(nums[i], nums[i] + local_max);
		global_max = max(local_max, global_max);
	}
	return global_max;
}

int main()
{
#ifndef ONLINE_JUDGE
	// for getting input from input1.txt
	freopen("input1.txt", "r", stdin);
	// for writing output from output1.txt
	freopen("output1.txt", "w", stdout);
#endif

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<int> arr1 = { -2, 1, 3, 4, -1, 2, 1, -5, 4};


	cout << maxSubArray(arr1);
	return 0;
} s