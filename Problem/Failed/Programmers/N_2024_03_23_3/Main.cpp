// #include <iostream>
// #include <cstdlib>
// #include <vector>
// #include <deque>
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  freopen("Problem\\Failed\\Baekjoon\\Gold\\3\\BJ_17135\\question\\input.txt", "rt", stdin);

  int N, M;
  cin >> N >> M;

  vector<pair<int, int>> enemy;

  for(int n = 0; n < N; n++) {
    for(int m = 0; m < M; m++) {
      int temp;
      cin >> temp;
      if(temp == 1) enemy.push_back({n, m});
    }
  }

  { // _TEST
    // for(const auto& a : enemy) {
    //   cout << a.first << ", " << a.second << '\n';
    // }
  }
  

  { // DFS COMB
    int archer[3] = {0, };

    // 1부터 M 에서 3 개 뽑기
    deque<pair<int, int>> task;
    task.push_back({0, 0});

    while(!task.empty()) {
      int size = task.back().first;
      int prev = task.back().second;
      task.pop_back();


      if(size >= 3) {
        cout << archer[0] << " : " << archer[1] << " : " << archer[2] << endl;
        
        { //_ 적 잡는 연산
          // 사수가 위로 올라가는 연산
          
          vector<pair<int, int>> enemyCopy = enemy;
          for(int y = N - 1; y >= 0; y--) {
            for(int x : archer) {
              int min = 2 * (M + N);
              for(const auto& a : enemyCopy) {
                
              }
            }
          }
        }
        
        continue;
      }

      if(prev >= M) {
        continue;
      }

      task.push_back({size, prev + 1});
      task.push_back({size + 1, prev + 1});
      archer[size] = prev;
    }

  }
  
  return 0;
}