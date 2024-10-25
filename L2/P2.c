#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void read_string(char** str, int* len, int increment) {
  int capacity = 5;
  *str = (char*)calloc(capacity, sizeof(char));
  int done = 0;
  if (*str == NULL) {
    printf("Memory allocation failed!\n");
  } else {
    while (1) {
      char c = getchar();

      if (c != '\n') {
        if (*len == capacity) {
          capacity += increment;
          *str = (char*)realloc(*str, capacity * sizeof(char));
          if (*str == NULL) {
            printf("Memory allocation failed!\n");
            break;
            done = 1;
          }
        }
        (*str)[(*len)++] = c;
      } else {
        break;
      }
    }
    if (done == 0) (*str)[*len] = '\0';
  }
}

void add_char_to_string(char* my_string, char character_to_add) {
  char char_as_string[2] = {character_to_add, '\0'};

  strcat(my_string, char_as_string);
}

char* remove_last_char(char* str) {
  if (str == NULL || strlen(str) == 0) {
    return str;
  }

  size_t len = strlen(str);

  char* new_str = (char*)malloc((len - 1) * sizeof(char));
  if (new_str == NULL) {
    printf("Memory allocation failed!\n");
    return NULL;
  }

  strncpy(new_str, str, len - 1);

  new_str[len - 1] = '\0';

  return new_str;
}

char* reInit(char* input, char* result) {
  int length = strlen(input);
  int count = 0;
  int done = 0;
  char addition[] = "###";

  for (int i = 0; i < length; ++i) {
    if (i > 0 && input[i] == input[i - 1]) {
      ++count;
    } else {
      count = 1;
    }

    if (count == 1) {
      add_char_to_string(result, input[i]);
    } else if (count > 3 && input[i] != input[i + 1] && done != 1) {
      result = remove_last_char(result);
      strcat(result, addition);
      done = 1;
    }
    done = 0;
  }

  return result;
}

int main() {
  char* str = NULL;
  char result[1000] = {""};
  int len = 0;
  int increment = 5;
  printf("Enter the array: \n");
  read_string(&str, &len, increment);
  char* fin = reInit(str, result);
  printf("Final array: %s\n", fin);
  free(str);
  free(fin);
}
