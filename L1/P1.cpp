#include <cstring>
#include <iostream>

using namespace std;

string reInit(char input[], int length) {
  string result = "";
  int count = 0;
  int done = 0;

  for (int i = 0; i < length; ++i) {
    if (i > 0 && input[i] == input[i - 1]) {
      ++count;
    } else {
      count = 1;
    }

    if (count == 1) {
      result += input[i];
    } else if (count > 3 && input[i] != input[i + 1] && done != 1) {
      result.pop_back();
      result += "###";
      done = 1;
    }
    done = 0;
  }

  return result;
}

int main() {
  int n;
  char str[100];
  char temp;
  cout << "Enter the array: " << endl;
  temp = getchar();
  while (temp != '\n') {
    str[n] = temp;
    n++;
    temp = getchar();
  }
  string res = reInit(str, n);
  cout << res << endl;
}
