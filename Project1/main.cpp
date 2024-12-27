#include <iostream>
#include <algorithm>
#define allout(MSG, X)	std::cout << " " << MSG << " "; for(auto w:X) std::cout << w << " "
#define line std::cout << "\n-------------------------------------------------------------\n"
#define endl "\n"

using namespace std;

void insert_sort(int* arr, size_t size, int flag);
void bubble_sort(int* arr, size_t size, int flag);
void select_sort(int* arr, size_t size, int flag);

// 합계 구하기
int getSum(int* arr, size_t size) {
	int sum = 0;
	for (int i = 0;i < size;i++) sum += arr[i];

	return sum;
}

// 평균 구하기
double getAverage(int* arr, size_t size) {
	return (double)getSum(arr, size) / size;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int arr[5];
	cout << "Enter 5 numbers seperated by spaces" << endl;

	// 5개의 숫자 입력 받기
	for (int i = 0;i < 5;i++) {
		cin >> arr[i];
	}

	size_t size = sizeof(arr) / sizeof(arr[0]);

	// 총합 및 평균 출력하기
	cout << "The total of the array is " << getSum(arr, size) << endl;
	cout << "The average of the array is " << getAverage(arr, size) << endl;
	line;

	cout << "Select the sorting method (1: Ascending, 2: Descending)" << endl;
	int method;
	cin >> method;
	while (method != 0 && method != 1) {
		cout << "Wrong selection! Select the sorting method (1: Ascending, 2: Descending)" << endl;
		cin >> method;
	}

	allout("Before sorting() = ", arr);
	line;

	// 삽입 정렬
	int arr1[5];
	copy(arr, arr + size, arr1);
	insert_sort(arr1, size, method);
	allout("\n After insert_sort() = ", arr1);
	line;

	// 교환 정렬
	int arr2[5];
	copy(arr, arr + size, arr2);
	select_sort(arr2, size, method);
	allout("After bubble_sort() = ", arr2);
	line;

	// 선택 정렬
	int arr3[5];
	copy(arr, arr + size, arr3);
	select_sort(arr3, size, method);
	allout("After select_sort() = ", arr3);
	line;

	return 0;
}

// 삽입 정렬 (Insert Sort)
void insert_sort(int* arr, size_t size, int flag) {
	if (flag == 2) {
		for (int i = 0; i < size; i++) arr[i] *= -1;
	}

	for (int i = 1;i < size;i++) {
		int key = arr[i];
		int j = i - 1;

		for (; j >= 0 && arr[j] > key; j--) {
			arr[j + 1] = arr[j];
		}

		arr[j + 1] = key;
	}

	if (flag == 2) {
		for (int i = 0; i < size; i++) arr[i] *= -1;
	}
}

// 교환 정렬 (Bubble Sort)
void bubble_sort(int* arr, size_t size, int flag) {
	if (flag == 2) {
		for (int i = 0; i < size; i++) arr[i] *= -1;
	}

	for (int i = size - 1; i > 0; i--) {
		bool isSorted = true;

		for (int j = 0;j < i;j++) {
			if (arr[j] > arr[j + 1]) {
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				isSorted = false;
			}
		}
		if (isSorted) break;
	}

	if (flag == 2) {
		for (int i = 0; i < size; i++) arr[i] *= -1;
	}
}

// 선택 정렬 (Select Sort)
void select_sort(int* arr, size_t size, int flag) {
	if (flag == 2) {
		for (int i = 0; i < size; i++) arr[i] *= -1;
	}

	for (int i = 0; i < size;i++) {
		int valmin = 0xffffff, minidx = size - 1;

		for (int j = i;j < size;j++) {
			if (arr[j] < valmin) {
				valmin = arr[j];
				minidx = j;
			}
		}

		int tmp = arr[i];
		arr[i] = valmin;
		arr[minidx] = tmp;
	}

	if (flag == 2) {
		for (int i = 0; i < size; i++) arr[i] *= -1;
	}
}
