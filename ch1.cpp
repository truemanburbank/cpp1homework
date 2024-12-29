/*
필수 과제

- 사용자로부터 5개의 숫자를 입력 받아 배열에 저장하고 이들의 합계와 평균을 계산해서 출력하라.
- 합과 평균을 구하는 함수를 각각 만들어라.

평가 기준
- 5개의 숫자를 입력받아 배열에 저장한 뒤 합과 평균을 출력하는 기능이 정확히 동작하는지 확인                                                 
- 합과 평균을 구하는 부분을 함수로 정의해서 구현했는지 확인
- 5개가 아닌 N개의 입력을 받는다고 가정하고 재사용성을 고려한 코드를 작성했는지 확인

도전 과제

- 숫자 1을 입력 받으면 오름차순 정렬, 숫자 2를 입력 받으면 내림차순 정렬을 하도록 구현하라.
- `algorithm` 헤더의 `sort` 함수를 사용하지 않고 직접 구현하라.
- 오름차순 정렬과 내림차순 정렬 동작을 각각 함수로 구현하라.

평가 기준
- (오름차순/내림차순) 정렬 알고리즘이 정확히 동작하는지
- 자신이 작성한 알고리즘의 정렬 과정을 명확하게 설명할 수 있는지 확인
- 정렬 알고리즘 구현시 중복코드를 최소화 해서 코드를 작성했는지 확인
 */

#include <iostream>

int sum(int* arr, int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
        sum += arr[i];

    return sum;
}

double avg(int* arr, int size)
{
    return static_cast<double>(sum(arr, size)) / size;
}

void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Quick Sort -> divide and conquer
int AscendingPartition(int* arr, int start, int end)
{
    // 중앙값을 피벗으로 선정
    int pivot = arr[(start + end) / 2];
    
    // low, high 설정
    int low = start;
    int high = end;

    while (low <= high)
    {
        // 피벗보다 큰 수가 나올 때까지 반복
        while (pivot > arr[low]) low++;
        
        // 피벗보다 작은 수가 나올 때까지 반복
        while (pivot < arr[high]) high--;

        // 찾은 low와 high를 교환하기
        if (low <= high) swap(arr[low++], arr[high--]);
    }

    // 분할된 다음 정렬 시작점 반환
    return low;
}

void AscendingQuickSort(int* arr, int start, int end)
{
    // 계속 분할되는 것을 막기 위함.
    if (start < end)
    {
        int pivot = AscendingPartition(arr, start, end);
        AscendingQuickSort(arr, start, pivot - 1);
        AscendingQuickSort(arr, pivot + 1, end);
    }
}

int DescendingPartition(int* arr, int start, int end)
{
    // 중앙값을 피벗으로 선정
    int pivot = arr[(start + end) / 2];
    
    // low, high 설정
    int low = start;
    int high = end;
    
    while (low <= high)
    {
        // 피벗보다 작은 값 찾기
        while (pivot < arr[low]) low++;

        // 피벗보다 큰 값 찾기
        while (pivot > arr[high]) high--;
        
        // 찾은 low와 high를 교환하기
        if (low <= high) swap(arr[low++], arr[high--]);
    }

    // 분할된 다음 정렬 시작점 반환
    return low;
}

void DescendingQuickSort(int* arr, int start, int end)
{
    if (start < end)
    {
        int pivot = DescendingPartition(arr, start, end);
        DescendingQuickSort(arr, start, pivot - 1);
        DescendingQuickSort(arr, pivot + 1, end);
    }
}

void StartQuickSort(int n, int* arr, int size)
{
    switch (n)
    {
        case 1:
            AscendingQuickSort(arr, 0, size - 1);
            break;  
        case 2:
            DescendingQuickSort(arr, 0, size - 1);
            break;
        default:
            std::cout << "유효하지 않은 수를 선택하셨습니다." << '\n';
            std::cout << "Default: 오름차순 정렬." << '\n';
            AscendingQuickSort(arr, 0, size - 1);
            break;
    }
}


int main()
{
     const int SIZE = 5;
     int arr[SIZE] = {};
    
    std::cout << "숫자 5개를 입력하세요 >> ";
    
     for(int i = 0; i < SIZE; i++)
         std::cin >> arr[i];

    std::cout << "숫자를 선택하세요.\n 1 (오름차순 정렬) \n 2 (내림차순 정렬)\n";
    
    int n;
    std::cin >> n;
    
    StartQuickSort(n, arr, SIZE);

    std::cout << "정렬된 배열 >> ";
    for(int i = 0; i < SIZE; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
    std::cout << "배열의 합 >>"  << sum(arr, SIZE) << '\n';
    std::cout << "배열의 평균 >>" << avg(arr, SIZE) <<'\n';
}