// https://www.educative.io/collection/page/5668639101419520/5633779737559040/5666387129270272

#include<iostream>
#include<vector>
using namespace std;

int calculateProfit(vector<int> &W, vector<int> &P, int C) {
  int dp[W.size()][C+1], i, c, profit1, profit2;
  for(i=0; i<W.size(); i++) {
    dp[i][0] = 0;
  }
  for(c=1; c<=C; c++) {
    dp[0][c] = 1;
  }
  for(i=1; i<W.size(); i++) {
    for(c=1; c<=C; c++) {
      profit1 = 0;
      profit2 = 0;
      if(c-W[i] >= 0) {
        profit1 = P[i] + dp[i-1][c-W[i]];
      }
      profit2 = dp[i-1][c];
      dp[i][c] = max(profit1, profit2);
    }
  }
  return dp[W.size()-1][C];
}

int main(void) {
  vector<int> weights, profits;
  int capacity, profit;

  // Weights
  weights.push_back(1);
  weights.push_back(2);
  weights.push_back(3);
  weights.push_back(5);

  // Profits
  profits.push_back(1);
  profits.push_back(6);
  profits.push_back(10);
  profits.push_back(16);

  // Capacity
  capacity = 7;

  profit = calculateProfit(weights, profits, capacity);

  cout<<profit<<'\n';

  return 0;
}