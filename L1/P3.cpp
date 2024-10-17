#include <iostream>
#include <cstring>

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
	FILE *fp1, *fp2;
	char str[100];
	int n;
	fp1 = fopen("init.txt", "r");
    if (fp1 == NULL) {
        printf("Error opening file\n");
    }
    else
    {
	    if (fgets(str, sizeof(str), fp1) != NULL) {
        n = strlen(str);
        
        fclose(fp1);
        fp2 = fopen("fin.txt", "w");
        if (fp2 == NULL) {
            printf("Error opening file\n");
        }
        else {
        fputs(reInit(str, n).c_str(), fp2);

        fclose(fp2);
	}
    }
    else {
        printf("Error reading from file\n");
    }
    return 0;
}
}
