#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

void print(int ar_size, int *  ar) {
    for (int i = 0 ; i < ar_size; i++) {
        if (i > 0) printf(" ");
        printf("%d", ar[i]);
    }
    printf("\n");
}

/* Head ends here */
void partition(int ar_size, int *  ar) {
    int s = 0;
    for(int i = 1; i < ar_size; i++) {
        if (ar[i] < ar[s]) {
            int tmp = ar[i];
            for (int j = i - 1; j >= s; j--) ar[j+1] = ar[j];
            ar[s] = tmp;
            s++;
        }
    }
    print(ar_size, ar);
}

/* Tail starts here */
int main() {
    int _ar_size;
    scanf("%d", &_ar_size);
    int _ar[_ar_size], _ar_i;
    for(_ar_i = 0; _ar_i < _ar_size; _ar_i++) { 
        scanf("%d", &_ar[_ar_i]); 
    }
    partition(_ar_size, _ar);
    return 0;
}

