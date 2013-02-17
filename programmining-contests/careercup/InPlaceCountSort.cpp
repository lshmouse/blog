#include <stdio.h>
#include <stdint.h>

void inPlaceCounterSort(int* array, uint32_t size) {
	for (uint32_t i = 0; i < size; i++) {
	   if (array[i] <= 0) continue;
		 int current = array[i] - 1;
		 array[i] = 0;
		 while (array[current] > 0) {
         int tmp = array[current] - 1;
				 array[current] = -1;
				 current = tmp;
     }
		 array[current]--;
	}
	for (uint32_t i = 0; i < size; i++) {
		array[i] = -array[i];
	}
}

void print(int* array, uint32_t size) {
  for (int i = 0; i < size; i++) {
    printf("%d ", array[i]);
  }
  printf("\n");
}

void inPlaceRecovery(int* array, uint32_t size) {
    int sum = 0;
    for (uint32_t i = 0; i < size; i++) {
        if (array[i] > 0) {
            sum += array[i];
            array[i] = sum;
        }
    }
    print(array, size);
    for (int32_t i = size - 1; i >= 0; i--) {
        if (array[i] > 0) array[array[i] - 1] = i;
    }
    print(array, size);
}

int main() {
  // case 1:
  int test1[] = {4, 4, 1, 4, 4};
  print(test1, 5);
  inPlaceCounterSort(test1, 5);
  print(test1, 5);
  inPlaceRecovery(test1, 5);

  // case 2:
  int test2[] = {2, 7, 5, 3, 7, 2, 6, 7, 2, 9};
  print(test2, 10);
  inPlaceCounterSort(test2, 10);
  print(test2, 10);

}
