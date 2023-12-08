#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <chrono>
#include <math.h>

using namespace std;
using namespace chrono;

void quicksort(int* arr, int end, int begin) {
    int mid;
    int f = begin;
    int l = end;

    mid = arr[(f + l) / 2];

    while (f < l) {

        while (arr[f] < mid) {
            f += 1;
        }
        while (arr[l] > mid) {
            l -= 1;
        }
        if (f <= l) {
            swap(arr[f], arr[l]);
            f++;
            l--;
        }
    }
    if (begin < l) {
        quicksort(arr, l, begin);
    }
    if (f < end) {
        quicksort(arr, end, f);
    }
}

int main()
{
    time_point<steady_clock, duration<__int64, ratio<1, 1000000000>>> start, end;
    nanoseconds result;
    srand(time(NULL));

    int const N = 100;
    int sortArray[N];
    int unsortedArray[N];
    for (int i = 0; i < N; i++) {    // Создаем массив и заполняем его
        unsortedArray[i] = sortArray[i] = rand() % 199 - 99;

    }

    cout << " Unsorted Array" << endl;

    for (int i = 0; i < N; i++) {
        cout << unsortedArray[i] << " ";   // вывод неотсортированного массива
    }

    cout << endl;

    int end1 = N - 1;
    int begin = 0;
    start = steady_clock::now();
    quicksort(sortArray, end1, begin);
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);
    cout << "Time sorted " << result.count() << " nanoseconds" << endl;

    cout << '\n';

    cout << "Sorted Array" << endl;
    for (int i = 0; i < N; i++) {
        cout << sortArray[i] << " ";
    }

    cout << '\n';

    cout << endl;
    start = steady_clock::now();
    cout << "The max element: " << sortArray[N - 1] << endl;
    cout << "The min element: " << sortArray[0] << endl;
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);
    cout << "Time search min and max in sorted array " << result.count() << " nanoseconds" << endl;

    cout << endl;

    start = steady_clock::now();
    int max = unsortedArray[0];
    int min = unsortedArray[0];

    for (int i = 1; i < N; i++) {
        if (unsortedArray[i] >= max) {
            max = unsortedArray[i];
        }
        if (unsortedArray[i] <= min) {
            min = unsortedArray[i];
        }
    }
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);

    cout << "The max element in unsorted array: " << max << endl;
    cout << "The min element in unsorted array: " << min << endl;

    cout << "Time search min and max in unsorted array " << result.count() << " nanoseconds" << endl;

    cout << endl;
    cout << "Avg sorted array is " << round(float((sortArray[N - 1] + sortArray[0])) / 2) << endl;


    int avg = round(float((min + max)) / 2);

    cout << endl;
    cout << "Avg in unsorted array is " << round(float((min + max)) / 2) << endl;


    cout << endl;
    start = steady_clock::now();
    int countAvg = 0;
    int countFind = 0;

    for (int i = 0; i < N || sortArray[i] <= avg; i++) {
        if (sortArray[i] == avg) {
            if (countFind == 0) {
                cout << "Indices: ";
            }
            cout << i << ' ';
            countAvg += 1;
            countFind += 1;
        }
    }

    if (countFind == 0) {
        cout << "Index is not defind" << endl;
    }

    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);
    cout << "Average index search time " << result.count() << " nanoseconds" << endl;

    cout << endl;
    cout << "Number found: " << countAvg << " times" << endl;
    cout << endl;

    cout << "Enter a number to get how many elements in the sorted array are less than that number: ";

    int smallNumber;
    cin >> smallNumber;
    int countSmallNumber = 0;

    for (int i = 0; i < N; i++) {
        if (sortArray[i] < smallNumber) {
            countSmallNumber += 1;
        }
        else {
            break;
        }
    }
    cout << "The number of elements in the sorted array that are less than the entered value is " << countSmallNumber << endl;

    cout << endl;

    cout << "Enter a number to find out how many elements in the sorted array are greater than that number: ";

    int bigNumber;
    cin >> bigNumber;
    int countBigNumber = 0;

    for (int i = N - 1; i > -1; i--) {
        if (sortArray[i] > bigNumber) {
            countBigNumber += 1;
        }
        else {
            break;
        }
    }
    cout << "The number of elements in the sorted array that are greater than the entered value is " << countBigNumber << endl;

    cout << endl;

    int numBinSearch;
    cout << "Enter the number whose index you want to find: ";
    cin >> numBinSearch;

    start = steady_clock::now();
    for (int i = 0; i < N; i++) {
        if (sortArray[i] == numBinSearch) {
            cout << "Index of the entered number is " << i << endl;
            break;
        }
        if (i == (N - 1)) {
            if (sortArray[i] != numBinSearch) {
                cout << "Number not found" << endl;
            }
        }
    }
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);
    cout << "Time search in unsorted array " << result.count() << endl;
    cout << endl;

    start = steady_clock::now();
    int low = 0;
    int high = N - 1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int guess = sortArray[mid];

        if (guess == numBinSearch) {
            cout << "Index of the entered number is " << mid << endl;
            break;
        }

        if (guess > numBinSearch) {
            high = mid - 1;
        }

        else {
            low = mid + 1;
        }
    }
    if (low > high) {
        cout << "Number not found" << endl;
    }
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);
    cout << "Time search in sorted array " << result.count() << " nanoseconds" << endl;
    cout << endl;

    int index1;
    int index2;

    cout << "Enter the first index you want to change: ";
    cin >> index1;
    cout << "Enter the second index you want to change: ";
    cin >> index2;
    cout << endl;

    start = steady_clock::now();
    swap(sortArray[index1], sortArray[index2]);
    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);
    cout << "Time swap " << result.count() << " nanoseconds" << endl;

    for (int i = 0; i < N; i++) {
        cout << sortArray[i] << " ";
    }

    cout << endl;
    cout << endl;
    cout << "Idz Shell sort" << endl;
    int step;
    int temp;
    start = steady_clock::now();

    for (step = N / 2; step > 0; step /= 2) {
        for (int i = step; i < N; i++) {
            temp = unsortedArray[i];
            for (int j = i; j >= step; j -= step) {
                if (temp < unsortedArray[j - step]) {
                    swap(unsortedArray[j], unsortedArray[j - step]);
                }
                else {
                    break;
                }
            }
        }
    }

    end = steady_clock::now();
    result = duration_cast<nanoseconds>(end - start);
    cout << "Time sorted " << result.count() << " nanoseconds" << endl;

    for (int i = 0; i < N; i++) {
        cout << unsortedArray[i] << " ";
    }
}
