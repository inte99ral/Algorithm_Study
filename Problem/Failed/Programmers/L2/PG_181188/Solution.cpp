#include <bits/stdc++.h>

#include <vector>

using namespace std;

// -- Header ====================
int solution(vector<vector<int>> nums);

// -- Local Input ====================
int main() {
  freopen("Problem\\Failed\\Programmers\\L2\\PG_181188\\input.txt", "rt", stdin);
  string rawInput;
  vector<vector<int>> input;
  string buffer;

  getline(cin, rawInput);

  regex regExp("[0-9]+");
  sregex_token_iterator iter(
    rawInput.begin(),
    rawInput.end(),
    regExp
  ), end;

  while (iter != end) {
    vector<int> tempVec = {stoi(*iter++), stoi(*iter++)};
    input.push_back(tempVec);
  }

  cout << solution(input) << '\n';
  return 0;
}

// -- Solution ====================
int solution(vector<vector<int>> targets) {
    vector<vector<int>> section;

    section.push_back({targets[0][0],targets[0][1]});

    for(vector<int> target : targets) {
      int index = 0;
      while(index <= section.size()) {
        if(index == section.size()) {
          section.push_back(target);
          continue;
        }
        
        if(target[1] <= section[index][0] || section[index][1] <= target[0]) continue;

        if(target[0] <= section[index][1] || section[index][0] >= target[1]) {

          break;
        }
      }


    }

    return answer;
}