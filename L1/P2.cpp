#include <cstring>
#include <iostream>

using namespace std;

string reInit(char input[], int length) {
  string result = "";
  int count = 0;

  for (int i = 0; i < length; ++i) {
    if (i > 0 && input[i] == input[i - 1]) {
      ++count;
    } else {
      count = 1;
    }

    if (count == 1) {
      result += input[i];
    } else if (count > 3) {
      result.pop_back();
      result += "###";
    }
  }

  return result;
}

int main() {
  char str[100];
  int n;
  cout << "Enter the array: " << endl;
  cin >> str;
  n = strlen(str);
  string res = reInit(str, n);
  cout << res << endl;
}
