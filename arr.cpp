#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <memory>
#include <stack>
#include <unordered_map>
#include <vector>

typedef struct langauges {
  std::string english;
  std::string french;
  std::string german;
  std::string spanish;
} laguages;

typedef union cpu {
  int a;
  float b;
  double c;
  char d;
} cpu;

typedef struct array {
  int a[100];
  int size;
  int length;
} array;

void reverse(array &arr) {
  // Reverses the array in place
  for (int i = 0, j = arr.length - 1; i < j; i++, j--) {
    std::swap(arr.a[i], arr.a[j]);
  }
}

int delete_element(array &arr, int &&index);

void left_shift(array &arr1) {
  for (int i = 0; i < arr1.length - 1; i++) {
    std::swap(arr1.a[i], arr1.a[i + 1]);
  }
  arr1.length--;
}

void right_shift(array &arr1) {
  for (int i = arr1.length - 1; i > 0; i--) {
    std::swap(arr1.a[i], arr1.a[i - 1]);
  }
  arr1.length--;
}

void reverse_array(array &arr1) {
  for (int i = 0, j = arr1.length - 1; i < j; i++, j--) {
    std::swap(arr1.a[i], arr1.a[j]);
  }
}

void sort_array(array arr1) {
  for (int i = 0; i < arr1.length; i++) {
    for (int j = i + 1; j < arr1.length; j++) {
      if (arr1.a[i] > arr1.a[j]) {
        std::swap(arr1.a[i], arr1.a[j]);
      }
    }
  }
}

int another_recursive_sum(array arr1, int index) {
  if (index == arr1.length) {
    return 0;
  }
  return arr1.a[index] + another_recursive_sum(arr1, index + 1);
}

int recursive_sum(array arr1, int index) {
  if (index < 0) {
    return 0;
  } else {
    return arr1.a[index] + recursive_sum(arr1, index - 1);
  }
}

int sum(const array &arr1) {
  int sum{0};
  for (int i = 0; i < arr1.length; i++) {
    sum += arr1.a[i];
  }
  return sum;
}

float avg(const array &arr1) {
  return static_cast<float>(sum(arr1)) / arr1.length;
}

int get(const array &arr, int &&index) {
  if (index < 0 || index >= arr.length) {
    std::cout << "Index out of bounds\n";
    return -1;
  }
  return arr.a[index];
}

int set(array &arr, int &&index, int &&value) {
  if (index < 0 || index >= arr.length) {
    std::cout << "Index out of bounds\n";
    return -1;
  }
  arr.a[index] = value;
  std::cout << "set() = Value at index " << index << " is now " << arr.a[index]
            << "\n";
  return arr.a[index];
}

int min(const array &arr) {
  int min = arr.a[0];
  for (int i = 1; i < arr.length; i++) {
    if (arr.a[i] < min) {
      min = arr.a[i];
    }
  }
  return min;
}

int max(const array &arr) {
  int max = arr.a[0];
  for (int i = 1; i < arr.length; i++) {
    if (arr.a[i] > max) {
      max = arr.a[i];
    }
  }
  return max;
}

int recursive_binary_search(array &arr, int &key, int low, int high) {
  static unsigned int c{0};

  if (low > high) {
    c++;
    std::cout << "c = " << c << "\n";
    return -1;
  }
  int mid = (low + high) / 2;
  if (arr.a[mid] == key) {
    c++;
    std::cout << "c = " << c << "\n";
    return mid;
  } else if (arr.a[mid] > key) {
    c++;
    return recursive_binary_search(arr, key, low, mid - 1);
  } else {
    c++;
    return recursive_binary_search(arr, key, mid + 1, high);
  }
}

void insert_sorted(array &arr, int &&key) {
  if (arr.length == arr.size) {
    std::cout << "invalid insert\n";
    return;
  } else {
    int i = arr.length - 1;
    while (key > arr.a[i]) {
      arr.a[i + 1] = arr.a[i];
      i--;
    }
    arr.a[i + 1] = key;
    arr.length++;
  }
}

void negative_positive(array &arr) {
  int i = 0;
  int j = arr.length - 1;
  while (i < j) {
    if (arr.a[i] < 0) {
      i++;
    } else if (arr.a[j] > 0) {
      j--;
    } else {
      std::swap(arr.a[i], arr.a[j]);
      i++;
      j--;
    }
  }
}

void negative_positive_v2(array &arr) {
  int i = 0;
  int j = arr.length - 1;
  while (i < j) {
    while (arr.a[i] > 0) i++;
    while (arr.a[j] < 0) j--;
    std::swap(arr.a[i], arr.a[j]);
    i++;
    j--;
  }
}

void is_sorted(array &arr) {
  for (int i = 0; i < arr.length - 1; i++) {
    if (arr.a[i] > arr.a[i + 1]) {
      std::cout << "not sorted\n";
      return;
    }
  }
  std::cout << "sorted\n";
}

int binary_search(array &arr, int &key) {
  unsigned int counter{0};
  int low = 0;
  int high = arr.length - 1;
  while (low <= high) {
    counter++;
    int mid = (low + high) / 2;
    if (arr.a[mid] == key) {
      return counter;
    } else if (arr.a[mid] > key) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  std::cout << "not found -Tries: " << counter << "\n";
  return counter;
}

int binary_search(array &arr, int &&key) {
  unsigned int counter{0};
  int low = 0;
  int high = arr.length - 1;
  while (low <= high) {
    counter++;
    int mid = (low + high) / 2;
    if (arr.a[mid] == key) {
      std::cout << "Tries: " << counter << "\n";
      return mid;
    } else if (arr.a[mid] > key) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  std::cout << "not found -Tries: " << counter << "\n";
  return -1;
}

int linear_search(array &arr, int &&key) {
  for (int i = 0; i < arr.length; i++) {
    if (arr.a[i] == key) {
      std::swap(arr.a[i], arr.a[i - 1]);
      return i;
    }
  }
  return -1;
}

void display(const array &a) {
  for (int i = 0; i < a.length; i++) {
    std::cout << "[" << a.a[i] << "]";
  }
  std::cout << "\n";
}

int delete_element(array &arr, int &&index) {
  int x = arr.a[index];
  if (index < 0 || index >= arr.length) {
    std::cout << "Invalid index\n";
    return -1;
  }
  for (int i = index; i < arr.length - 1; i++) {
    arr.a[i] = arr.a[i + 1];
  }
  arr.length--;
  return x;
}

void add(array &a, int &&temp) {
  if (a.length >= a.size)
    std::cout << "Array is full\n";
  else {
    a.a[a.length] = temp;
    a.length++;
  }
}

void print_lref_value(int &&lref) {
  std::cout << "lref value is " << lref << "\n";
}

void insert(array &a, int &&temp, int &&index) {
  if (index >= 0 && index <= a.length) {
    std::cout << "out of range\n";
    return;
  }

  for (int i = a.length; i > index; i--) {
    a.a[i] = a.a[i - 1];
  }
  a.a[index] = temp;
  a.length++;
}

array *merge(array arr1, array arr2) {
  int i, j, k;
  i = j = k = 0;
  array *final = new struct array;
  final->length = arr1.length + arr2.length;
  final->size = arr1.size + arr2.size;
  while (i < arr1.length && j < arr2.length) {
    if (arr1.a[i] < arr2.a[j]) {
      final->a[k++] = arr1.a[i++];
    } else {
      final->a[k++] = arr2.a[j++];
    }
  }
  for (; i < arr1.length; i++) {
    final->a[k++] = arr1.a[i++];
  }
  for (; j < arr2.length; j++) {
    final->a[k++] = arr1.a[j];
  }
  return final;
}

array *ArrIntersect(array arr1, array arr2) {
  int i, j, k;
  i = j = k = 0;
  array *final = new struct array;
  while (i < arr1.length && j < arr2.length) {
    if (arr1.a[i] < arr2.a[j]) {
      i++;
    } else if (arr1.a[i] > arr2.a[j]) {
      j++;
    } else {
      final->a[k++] = arr1.a[i++];
      j++;
    }
  }
  final->length = k;
  final->size = arr1.size + arr2.size;
  return final;
}

array *union_arr(array arr1, array arr2) {
  int i, j, k;
  i = j = k = 0;
  array *final = new struct array;
  final->size = arr1.size + arr2.size;
  final->length = arr1.length + arr2.length;
  unsigned int counter = 0;
  while (i < arr1.length && j < arr2.length) {
    if (arr1.a[i] == arr2.a[j]) {
      final->a[k++] = arr1.a[i];
      i++;
      j++;
      counter++;
    }
    if (arr1.a[i] < arr2.a[j]) {
      final->a[k++] = arr1.a[i++];
    } else if (arr1.a[i] > arr2.a[j]) {
      final->a[k++] = arr2.a[j++];
    }
  }
  final->length -= counter;
  return final;
}

array *intersection_array(array arr1, array arr2) {
  int i, j, k;
  i = j = k = 0;
  array *final = new struct array;
  final->size = arr1.size + arr2.size;
  unsigned int counter = 0;
  while (i < arr1.length && j < arr2.length) {
    if (arr1.a[i] == arr2.a[j]) {
      final->a[k++] = arr1.a[i];
      i++;
      j++;
    }
    counter++;
    if (arr1.a[i] < arr2.a[j]) {
      i++;
    } else {
      j++;
    }
  }
  final->length = counter;
  return final;
}

int *FindMissing(array arr1) {
  int *n = new int(0);
  bool isTrue =
      sum(arr1) == (arr1.a[arr1.length] * (arr1.a[arr1.length] + 1)) / 2;
  if (isTrue) {
    *n = -1;
    return n;
  } else {
    *n = ((arr1.a[arr1.length] * (arr1.a[arr1.length] + 1)) / 2) - sum(arr1);
  }
  return n;
}

void PrintMissing(array arr1, int l, int h) {
  int diff = arr1.a[0];
  l = arr1.a[0];
  h = arr1.length;
  for (int i = 0; i < h; i++) {
    if (arr1.a[i] - i != diff) {
      std::cout << "missing element is " << i + diff << std::endl;
      diff++;
    }
  }
}

void PrintUnsortedMissing(array arr1, int l, int h) {
  std::unordered_map<int, bool> hash;
  for (int i = 0; i <= h; i++) hash[i] = false;
  for (int i = 0; i < arr1.length; i++) {
    hash[arr1.a[i]] = true;
  }
  for (int i = l; i <= h; i++) {
    if (!hash[i]) {
      std::cout << "missing element is " << i << std::endl;
    }
  }
}

void PrintDuplicates(array arr1) {
  std::unordered_map<int, int> hash;
  for (int i = 0; i < arr1.length; i++) {
    hash[arr1.a[i]]++;
  }
  for (int i = 0; i < arr1.length; i++) {
    if (hash[arr1.a[i]] > 1) {
      std::cout << "Duplicate element is " << arr1.a[i] << " "
                << hash[arr1.a[i]] << std::endl;
    }
  }
}

void PrintPaireqten(array arr1) {
  std::unordered_map<int, int> hash;
  for (int i = 0; i < arr1.length; i++) {
    if (hash[10 - arr1.a[i]]) {
      std::cout << "Pair of elements whose difference is 10 are: " << arr1.a[i]
                << " and " << 10 - arr1.a[i] << std::endl;
    }
    hash[arr1.a[i]]++;
  }
}

void PrintPairSorted(array arr1) {
  int i = 0;
  int j = arr1.length - 1;
  while (i < j) {
    if (arr1.a[i] + arr1.a[j] == 10) {
      std::cout << "Pair of elements whose sum is 10 are: " << arr1.a[i]
                << " and " << arr1.a[j] << std::endl;
      i++;
      j--;
    } else if (arr1.a[i] + arr1.a[j] < 10) {
      i++;
    } else {
      j--;
    }
  }
}

void PrintMaxMin(array arr1) {
  std::sort(arr1.a, arr1.a + arr1.length);
  std::cout << "Max: " << arr1.a[arr1.length - 1] << std::endl;
  std::cout << "Min: " << arr1.a[0] << std::endl;
}

void printmaxmin2(array arr1) {
  int max = arr1.a[0];
  int min = arr1.a[0];
  for (int i = 1; i < arr1.length; i++) {
    if (arr1.a[i] > max) {
      max = arr1.a[i];
    }
    if (arr1.a[i] < min) {
      min = arr1.a[i];
    }
  }
  std::cout << "Max: " << max << std::endl;
  std::cout << "Min: " << min << std::endl;
}

int main(int argc, char const *argv[]) {
  array arr1 = {{10, 2, 3, 7, 8, 1, 0, 122}, 50, 8};
  printmaxmin2(arr1);
  return 0;
}