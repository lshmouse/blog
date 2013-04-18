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
void insertionSort(int ar_size, int *  ar) {
    int tmp = ar[ar_size - 1];
    for (int i = ar_size - 2; i >= 0; i--) {
        if (ar[i] > tmp) ar[i + 1] = ar[i];
        else {
            ar[i+1] = tmp;
            break;
        }
        print(ar_size, ar);
    }
    if (ar[0] > tmp) ar[0] = tmp;
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
    insertionSort(_ar_size, _ar);
    return 0;
}

