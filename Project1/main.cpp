#include <iostream>
#define allout(MSG, X)	std::cout << " " << MSG << " "; for(auto w:X) std::cout << w << " "
#define line std::cout << "\n-------------------------------------------------------------\n"
#define endl "\n"

using namespace std;

void insert_sort(int* arr, size_t size, bool flag = true);
void bubble_sort(int* arr, size_t size, bool flag = true);
void select_sort(int* arr, size_t size, bool flag = true);

// �հ� ���ϱ�
int getSum(int* arr, size_t size) {
	int sum = 0;
	for (int i = 0;i < size;i++) sum += arr[i];

	return sum;
}

// ��� ���ϱ�
double getAverage(int* arr, size_t size) {
	return (double)getSum(arr, size) / size;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); cout.tie(nullptr);

	int arr[5];
	cout << "Enter 5 numbers seperated by spaces" << endl;

	// 5���� ���� �Է� �ޱ�
	for (int i = 0;i < 5;i++) {
		cin >> arr[i];
	}

	size_t size = sizeof(arr) / sizeof(arr[0]);

	// ���� �� ��� ����ϱ�
	cout << "The total of the array is " << getSum(arr, size) << endl;
	cout << "The average of the array is " << getAverage(arr, size) << endl;
	line;

	// ���� ����
	allout("Before insert_sort() = ", arr);
	insert_sort(arr, size);
	allout("\n After Ascending insert_sort() = ", arr);
	insert_sort(arr, size, 0);
	allout("\n After Descending insert_sort() = ", arr);
	line;

	// ��ȯ ����
	select_sort(arr, size);
	allout("After Ascending bubble_sort() = ", arr);
	select_sort(arr, size, 0);
	allout("\n After Descending bubble_sort() = ", arr);
	line;

	// ���� ����
	select_sort(arr, size);
	allout("After Ascending select_sort() = ", arr);
	select_sort(arr, size, 0);
	allout("\n After Descending select_sort() = ", arr);
	line;

	return 0;
}

// ���� ���� (Insert Sort)
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

// ��ȯ ���� (Bubble Sort)
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

// ���� ���� (Select Sort)
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
