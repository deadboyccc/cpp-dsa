#include <cstdint>
#include <iostream>
// Bubble Sort, Adaptive, Stable, o(n2), can be used to get the biggest element
// in 1 pass
void bubbleSort(int a[], int n) {
  bool isSorted = true;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - 1 - i; j++) {
      if (a[j] > a[j + 1]) {
        std::swap(a[j], a[j + 1]);
        isSorted = false;
      }
    }
    if (isSorted) { return; }
  }
}
// Insertion Sort, Adaptive, Stable , o(n2), no useful n pass
void insertSort(int a[], int n) {
  for (int i = 1; i < n; i++) {
    int j = i - 1;
    int x = a[i];
    while (j > -1 && a[j] > x) {
      a[j + 1] = a[j];
      j--;
    }
    a[j + 1] = x;
  }
}
// Selection Sort,
void selectionSort(int a[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int k = i;

    for (int j = i + 1; j < n; j++) {
      if (a[j] < a[k]) { k = j; }
    }
    if (k != i) std::swap(a[k], a[i]);
  }
}
int partition(int a[], int l, int h) {
  int pivot = a[l];
  int i = l, j = h;
  do {
    do { i++; } while (a[i] <= pivot);
    do { j--; } while (a[j] > pivot);
    if (i < j) { std::swap(a[i], a[j]); }
  } while (i < j);
  std::swap(a[l], a[j]);
  return j;
}
void quickSort(int a[], int l, int h) {
  int j;
  if (l < h) {
    j = partition(a, l, h);
    // left side
    quickSort(a, l, j);
    // right side
    quickSort(a, j + 1, h);
  }
}
int *countSort(int a[], int n) {
  int *final = new int[20];
  std::fill(final, final + 20, 0);
  for (int i = 0; i < n; i++) { final[a[i]]++; }
  return final;
}
// merge function : assume :divide one array into 2(has to be sorted)  and merge
// sort them as if they were separate entities just like we did in array merge
void merge(int a[], int l, int mid, int h) {
  // l 1 2 3 mid 4 5 6 h
  int b[100];
  int i = l, j = mid + 1, k = l;
  while (i <= mid && j <= h) {
    if (a[i] < a[j]) {
      b[k++] = a[i++];
    } else {
      b[k++] = a[j++];
    }
  }
  for (; i <= mid; i++) { b[k++] = a[i]; }
  for (; j <= h; j++) { b[k++] = a[j]; }
  for (i = l; i <= h; i++) { a[i] = b[i]; }
}
// iterative merge sort
void IMergeSort(int a[], int n) {
  // p= passes log2n
  int p, i, l, mid, h;
  for (p = 2; p <= h; p *= 2) {
    for (i = 0; i + p - 1 < n; i += p) {
      l = i;
      h = i + p - 1;
      mid = (l + h) / 2;
      merge(a, l, mid, h);
    }
  }
  if ((p / 2) < n) { merge(a, 0, p / 2, n - 1); }
}
// recursive merge sort
void RMergeSort(int a[], int l, int h) {
  if (l < h) {
    int mid = (l + h) / 2;
    RMergeSort(a, l, mid);
    RMergeSort(a, mid + 1, h);
    merge(a, l, mid, h);
  }
}
// shell sort

void ShellSort(int A[], int n) {
  int gap, i, j;

  for (gap = n / 2; gap > 1; gap /= 2) // out loop for passes from gap = n/2 as
                                       // long as it is bigger than 1 2/2=1
  {
    for (i = gap; i < n; i++) // the item to be shifted back is in a[i]
    {
      int temp = A[i]; // item to be shifted back
      j = i - gap; // item behind a[i] by gap for the initial a[i] it will go
                   // back by gay(minus gap) each iteration

      while (j >= 0 &&
             A[j] > temp) // if item behind a[i](temp) by gap (j[i]) is smaller
                          // and as long as there is a valid j index
      {
        // if so
        // a[j+gap] = a[i] but since is changing we call it this way
        A[j + gap] = A[j];
        j -= gap;
      }

      A[j + gap] = temp;
    }
  }
}

int main(int argc, char const *argv[]) {
  int a[] = {};

  int n = sizeof(a) / sizeof(int);
  //   bubbleSort(a, n);
  // insertSort(a, n);
  // selectionSort(a, n);[kkkkkkkkkkkkk]
  // quickSort(a, 0, n - 1);
  // IMergeSort(a, n);
  //   RMergeSort(a, 0, n - 1);
  //   ShellSort(a, n);

  for (auto &&element : a) {
    if (element == INT32_MAX) { break; }
    std::cout << element << " ";
  }
  std::cout << "\n";
  // testing count sort (my idea)
  // int *ptr = countSort(a, n);
  // for (int i = 0; i < 20; i++)
  // {
  //     if (ptr[i])
  //     {

  //         do
  //         {
  //             std::cout << i << " ";
  //             ptr[i]--;
  //         } while (ptr[i] > 0);
  //     }
  // }
  // std::cout << "\n";
  return 0;
}
11->15 -
    16 web dev html / css / js /
        jquery

            data science->python -
    ai
