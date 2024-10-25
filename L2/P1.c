#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* read_string() {
  char* str = NULL;
  size_t size = 0;
  size_t len = 0;
  char c;

  while ((c = getchar()) != '\n') {
    size_t new_size = size + 1;
    char* new_str = (char*)malloc(new_size * sizeof(char));

    if (new_str == NULL) {
      printf("Memory allocation failed!\n");
      if (str != NULL) free(str);
      return NULL;
    }

    if (size > 0) {
      memcpy(new_str, str, len);
      free(str);
    }

    new_str[len] = c;
    new_str[len + 1] = '\0';
    str = new_str;
    size = new_size;
    len++;
    free(new_str);
  }

  return str;
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
  char result[1000] = {""};
  printf("Enter the array: \n");
  char* input_string = read_string();
  char* fin = reInit(input_string, result);
  printf("Final array: %s\n", fin);
}
