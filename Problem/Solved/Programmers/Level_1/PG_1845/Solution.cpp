// #include <bits/stdc++.h>
#include <iostream>
#include <map>
#include <sstream>
#include <vector>
#include <unordered_set>

using namespace std;

// -- Header ====================
int solution(vector<int> nums);

// -- Local Input ====================
int main() {
  freopen("Problem\\Solved\\Programmers\\Level1\\PG_1845\\question\\input.txt", "rt", stdin);
  string rawData;
  string buffer;
  vector<int> input;

  getline(cin, rawData);
  stringstream ss(rawData.substr(1,rawData.size() - 2));

  while(getline(ss, buffer, ',')) input.push_back(stoi(buffer));

  cout << solution(input) << '\n';
  return 0;
}

// -- Solution ====================
int solution(vector<int> nums) {
  unordered_set<int> s(nums.begin(), nums.end());
  return min(nums.size() / 2, s.size());
}