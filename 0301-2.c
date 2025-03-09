#include <stdio.h>
#include <time.h>
#define LEN 1000000
#define TARGET 500000

int binsearch2(int x, int v[], int n);

int main() {
  int arr[LEN];
  for (int i = 0; i < LEN; ++i) {
    arr[i] = i;
  }
  struct timespec start, end;
  double elapsed_time;

  clock_gettime(CLOCK_MONOTONIC, &start);
  int i = binsearch2(TARGET, arr, LEN);
  clock_gettime(CLOCK_MONOTONIC, &end);

  elapsed_time = (end.tv_sec - start.tv_sec) +
                 (end.tv_nsec - start.tv_nsec) / 1000000000.0;

  printf("%d\n%f sec.\n", i, elapsed_time);
}

int binsearch2(int x, int v[], int n) {
  int low, high, mid;
  low = 0;
  high = n - 1;
  while (low < high) {
    mid = (low + high) / 2 + 1;
    if (x < v[mid])
      high = mid - 1;
    else
      low = mid;
  }
  if (v[low] == x) {
    return low;
  } else
    return -1;
}