#include <iostream>
#include <vector>
#include <thread>
#include <algorithm>
#include <mutex>

using namespace std;

mutex mtx;

// Функция для вывода массива
void printSortedArray(const string& sortName, const vector<int>& arr) {
    lock_guard<mutex> guard(mtx);
    cout << "Сортировка: " << sortName << "\nРезультат: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

// Быстрая сортировка
void quickSort(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    printSortedArray("быстрая", arr);
}

// Пузырьковая сортировка
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
    printSortedArray("пузырьком", arr);
}

int main() {
    setlocale(LC_ALL, "rus");

    vector<int> numbers = { 4, 2, 3, 1, 5, 7, 6 };

    thread t1(quickSort, ref(numbers));
    thread t2(bubbleSort, ref(numbers));

    t1.join();
    t2.join();

    return 0;
}