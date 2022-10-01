/*
The Longest Increasing Subsequence (LIS) problem is to find the length of the longest subsequence of a given sequence such that all elements of the 
subsequence are sorted in increasing order.
For example, the length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 
and LIS is {10, 22, 33, 50, 60, 80}. 
*/
#include <bits/stdc++.h>
using namespace std;
int longest_increasing_subsequence(vector<int>& arr)
{
	vector<int> ans;
	int n = arr.size();
	for (int i = 0; i < n; i++) {
		auto it
			= lower_bound(ans.begin(), ans.end(), arr[i]);
		if (it == ans.end()) {
			ans.push_back(arr[i]);
		}
		else {
			*it = arr[i];
		}
	}
	return ans.size();
}
int main()
{
	vector<int> a = { 10, 22, 9, 33, 21, 50, 41, 60 };
	int ans = longest_increasing_subsequence(a);
	cout << ans;
	return 0;
}
