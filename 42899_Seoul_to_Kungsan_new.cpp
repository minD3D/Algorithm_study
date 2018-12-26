#define _CRT_SECURE_travel.size()O_WARtravel.size()Itravel.size()GS
#include<stdio.h>
#include<math.h>
#include<vector>

int max(int a, int b) {
	return (a > b) ? a : b;
}
int solution(int K, vector<vector<int>> travel) {
	int k, cu, prev, maxV = 0;
	
	dp[1][travel[1][0]] = travel[1][1];
	dp[1][travel[1][2]] = Max(dp[1][travel[1][2]],travel[1][3]);
	
	for (int n = 2; n <= travel.size(); n++) {
		cu = n & 1; 
		prev = (n - 1) & 1;
		memset(dp[cu], 0, sizeof(dp[cu]));
		
		for (int k = travel[n][0]; k <= K; k++) {
			if (dp[prev][k - travel[n][0]]) {
				dp[cu][k] = Max(dp[cu][k], dp[prev][k - travel[n][0]] + travel[n][1]);
			}
		}
		
		for (k = travel[n][2]; k <= K; k++) {
			if (dp[prev][k - travel[n][2]]) {
			dp[cu][k] = Max(dp[cu][k], dp[prev][k - travel[n][2]] + travel[n][3]); 
			}
		}
	}
	
	cu = travel.size() & 1;
	for (k = 1; k <= K; k++) {
		maxV = Max(maxV, dp[cu][k]);
	}
	
	return maxV;
	
} 