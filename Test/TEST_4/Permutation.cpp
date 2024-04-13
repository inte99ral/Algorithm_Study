#include <array>
#include <cstdarg>
#include <deque>
#include <iostream>
#include <regex>

using namespace std;

// # Prototype Declaration ====================
// ## 0. Default ===============================
template <typename T, size_t N>
void printArr(T (&arr)[N], int begin = 0, ...);
void printArrRecur(int* arr, deque<int> arrData);


// # Implements Definition ====================
// ## 0. Default ===============================

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  const int N = 5;
  const int R = 3;

  int origin[N][3] = {{1, 11, 111}, {2, 22, 222}, {3, 33, 333}, {4, 44, 444}, {5, 55, 555}};

  // ## 3. Inline : While Loop ===================
  goto section3end;
  {
    int select[R][3] = {};
    int count = 0;
    int size = 0;
    int data[R] = {0, -1, -1};
    bool isSelected = false;

    cout << "\n[CASES]:\n";

    while (data[0] != N) {
      if (size == R) {
        printArr(select);
        count++;
        size--;
        data[size]++;
        continue;
      }

      copy((int*)origin[data[size]], (int*)origin[data[size] + 1], (int*)select[size]);

      if (data[size] == N) {
        data[size] = 0;
        size--;
        data[size]++;
        continue;
      }

      isSelected = false;

      for (int i = 0; i < size; i++) {
        if (data[i] == data[size]) {
          isSelected = true;
          continue;
        }
      }

      if (isSelected) {
        data[size]++;
      }
      else {
        size++;
        data[size] = 0;
      }
    }

    cout << "[ANSWER]: " << count << '\n';
  }
  section3end:

  // ## 4. Inline Stack & Bitwise Operator =======
  // goto section4end;

  {
    // 비트 연산자를 사용하기 때문에 Int = 32bit, 32개 이상 선택 불가. bool 배열로 대체 가능
    int count = 0;
    int select[R][3] = {};
    deque<array<int, 3>> task = {{0, 0, 0}};

    cout << "\n[CASES]:\n";

    while (!task.empty()) {
      int data = task.back()[0];
      int size = task.back()[1];
      int curr = task.back()[2];

      task.pop_back();

      if (size == R) {
        printArr(select);
        count++;
        continue;
      }

      if (curr == N) {
        continue;
      }

      task.push_back({data, size, curr + 1});
      if (data & (1 << curr)) continue;
      copy((int*)origin[curr], (int*)origin[curr + 1], (int*)select[size]);
      task.push_back({data | (1 << curr), size + 1, 0});
  }
  section4end:



  return 0;
}

// ## 0. Default ===============================
template <typename T, size_t N>
void printArr(T (&arr)[N], int begin, ...) {
  deque<int> arrData;
  string arrType = typeid(arr).name();

  regex regExp("A[0-9]+_", regex::optimize);
  sregex_token_iterator iter(arrType.begin(), arrType.end(), regExp), end;

  va_list ap;
  va_start(ap, begin);
  int buffer = begin;

  while (iter != end) {
    string token = (string)*iter++;
    if (buffer) {
      arrData.push_back(buffer);
      buffer = va_arg(ap, int);
    }
    else {
      arrData.push_back(stoi(token.substr(1, token.size() - 2)));
    }
  }

  va_end(ap);

  printArrRecur((int*)arr, arrData);
  cout << "\b\b  " << endl;
}

void printArrRecur(int* arr, deque<int> arrData) {
  if (arrData.size() == 0) cout << "\033[0m" << *arr << ", ";
  else {
    int N = arrData.front();
    arrData.pop_front();
    int gap = 1;
    int color = 31 + (arrData.size() % 6);
    for (int i : arrData) gap *= i;
    cout << "\033[" << color << "m[";

    for (int n = 0; n < N; n++) {
      printArrRecur(arr, arrData);
      arr += gap;
    }
    cout << "\033[" << color << "m\b\b]\033[0m, ";
  }
}