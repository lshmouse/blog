#include <stdio.h>

int main() {
  char a[10];
  int b;
  
  for (b=0;b!=10;b++) {
    a[b]='a';
    printf("%c",a[b]);
  }
  printf("\n");
}

