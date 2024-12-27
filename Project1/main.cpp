#include <iostream>
#define allout(MSG, X)	std::cout << " " << MSG << " "; for(auto w:X) std::cout << w << " "
#define line std::cout << "\n-------------------------------------------------------------\n"
#define endl "\n"

using namespace std;

void insert_sort(int* arr, size_t size, bool flag = true);
void bubble_sort(int* arr, size_t size, bool flag = true);
void select_sort(int* arr, size_t size, bool flag = true);

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

	// 삽입 정렬
	allout("Before insert_sort() = ", arr);
	insert_sort(arr, size);
	allout("\n After Ascending insert_sort() = ", arr);
	insert_sort(arr, size, 0);
	allout("\n After Descending insert_sort() = ", arr);
	line;

	// 교환 정렬
	select_sort(arr, size);
	allout("After Ascending bubble_sort() = ", arr);
	select_sort(arr, size, 0);
	allout("\n After Descending bubble_sort() = ", arr);
	line;

	// 선택 정렬
	select_sort(arr, size);
	allout("After Ascending select_sort() = ", arr);
	select_sort(arr, size, 0);
	allout("\n After Descending select_sort() = ", arr);
	line;

	return 0;
}

// 삽입 정렬 (Insert Sort)
void insert_sort(int* arr, size_t size, bool flag) {
	if (!flag) {
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

	if (!flag) {
		for (int i = 0; i < size; i++) arr[i] *= -1;
	}
}

// 교환 정렬 (Bubble Sort)
void bubble_sort(int* arr, size_t size, bool flag) {
	if (!flag) {
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

	if (!flag) {
		for (int i = 0; i < size; i++) arr[i] *= -1;
	}
}

// 선택 정렬 (Select Sort)
void select_sort(int* arr, size_t size, bool flag) {
	if (!flag) {
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

	if (!flag) {
		for (int i = 0; i < size; i++) arr[i] *= -1;
	}
}
