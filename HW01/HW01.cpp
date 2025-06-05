// HW01.cpp
#include <iostream>

// --- 함수 선언 ---
void calculateSum(int arr[], int size, int& sum);
void calculateAverage(int arr[], int size, double& average);
void sortAscending(int arr[], int size);
void sortDescending(int arr[], int size);

// --- 메인 함수 ---
int main() {
    const int SIZE = 5;           // 배열의 크기
    int numbers[SIZE];            // 사용자로부터 입력받을 숫자 배열
    int sum = 0;                  // 합계를 저장할 변수
    double average = 0.0;         // 평균을 저장할 변수
    int choice;                   // 정렬 옵션 선택용 변수

    // --- 사용자 입력 ---
    std::cout << "정수 5개를 입력하세요:\n";
    for (int i = 0; i < SIZE; ++i) {
        std::cout << "  숫자 " << (i + 1) << ": ";
        std::cin >> numbers[i];
    }

    // --- 합계와 평균 계산 ---
    calculateSum(numbers, SIZE, sum);
    calculateAverage(numbers, SIZE, average);

    // --- 결과 출력 ---
    std::cout << "\n[결과 출력]\n";
    std::cout << "  합계: " << sum << "\n";
    std::cout << "  평균: " << average << "\n";

    // --- 정렬 방식 선택 ---
    std::cout << "\n[정렬 방식 선택] (1: 오름차순, 2: 내림차순): ";
    std::cin >> choice;

    if (choice == 1) {
        sortAscending(numbers, SIZE);
        std::cout << "\n[오름차순 정렬 결과]: ";
    }
    else if (choice == 2) {
        sortDescending(numbers, SIZE);
        std::cout << "\n[내림차순 정렬 결과]: ";
    }
    else {
        std::cout << "\n[오류] 잘못된 입력입니다. 프로그램을 종료합니다.\n";
        return 1;
    }

    // --- 정렬된 배열 출력 ---
    for (int i = 0; i < SIZE; ++i) {
        std::cout << numbers[i] << " ";
    }
    std::cout << "\n";

    return 0;
}

// --- 함수 정의부 ---

// 배열 원소 합계 계산
void calculateSum(int arr[], int size, int& sum) {
    sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
}

// 배열 원소 평균 계산
void calculateAverage(int arr[], int size, double& average) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    average = static_cast<double>(sum) / size;
}

// 오름차순 정렬
void sortAscending(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

// 내림차순 정렬
void sortDescending(int arr[], int size) {
    for (int i = 1; i < size; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}
