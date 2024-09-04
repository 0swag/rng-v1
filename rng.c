#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
  int variable = 1337;
  int* address = &variable;

  printf("[+] Address: %p\n", address);
  long seed = (int)address;

  printf("[+] Seed: %d\n", seed);

  char* string = malloc(sizeof(char) * 11);
  sprintf(string, "%d", seed);
  int len = strlen(string);

  char* str1 = malloc(len/2);
  char* str2 = malloc(len - (len/2));

  for(int i = 0; i<len; i++)
  {
    int half = len/2;
    if(i < half)
    {
      str1[i] = string[i];
    }
    else
    {
      str2[i-half] = string[i];
    }
  }
  printf("[~] Half 1: %s\n[~] Half 2: %s\n", str1, str2);
  long num1 = strtol(str1, NULL, 10);
  long num2 = strtol(str2, NULL, 10);
  long result = num1 * num2;
  printf("[+] %d * %d: %d", num1, num2, result);
  free(str1);
  free(str2);
  free(string);

  return 0;
}
