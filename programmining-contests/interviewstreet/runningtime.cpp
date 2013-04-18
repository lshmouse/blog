#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>

int insertion(int ar_size, int *  ar) {
    int count = 0;
    int tmp = ar[ar_size - 1];
    for (int i = ar_size - 2; i >= 0; i--) {
        if (ar[i] > tmp) {
            ar[i + 1] = ar[i];
            count++;
        } else {
            ar[i+1] = tmp;
            break;
        }
    }
    if (ar[0] > tmp) ar[0] = tmp;
    return count;
}

/* Head ends here */
void insertionSort(int ar_size, int *  ar) {
    int sum = 0;
    for (int i = 2; i <= ar_size; i++) {
        sum += insertion(i, ar); 
    }
    printf("%d\n", sum);
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

