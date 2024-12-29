# 도전 과제 1

### 필수 과제

- 사용자로부터 5개의 숫자를 입력 받아 배열에 저장하고 이들의 합계와 평균을 계산해서 출력하라.
- 합과 평균을 구하는 함수를 각각 만들어라.

### 도전 과제
- 숫자 1을 입력 받으면 오름차순 정렬, 숫자 2를 입력 받으면 내림차순 정렬을 하도록 구현하라.
- `algorithm` 헤더의 `sort` 함수를 사용하지 않고 직접 구현하라.
- 오름차순 정렬과 내림차순 정렬 동작을 각각 함수로 구현해봐요!

### 평가 기준

| **필수** | 5개의 숫자를 입력받아 배열에 저장한 뒤 합과 평균을 출력하는 기능이 정확히 동작하는지 확인                                                  |
| --- | --- |
| **도전** | (오름차순/내림차순) 정렬 알고리즘이 정확히 동작하는지 |
| **필수** | 합과 평균을 구하는 부분을 함수로 정의해서 구현했는지 확인 |
| **도전** | 자신이 작성한 알고리즘의 정렬 과정을 명확하게 설명할 수 있는지 확인 |
| **필수** | 5개가 아닌 N개의 입력을 받는다고 가정하고 재사용성을 고려한 코드를 작성했는지 확인 |
| **도전** | 정렬 알고리즘 구현시 중복코드를 최소화 해서 코드를 작성했는지 확인 |
- static_cast (C++ 스타일의 캐스팅 방법)
- 퀵 소트 구현

## 전체 구현 코드

```cpp
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
    // 계속 분할되는 것을 막기 위함.
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
```

## 결과

![image](https://github.com/user-attachments/assets/d6045dba-ad57-4c12-99ca-93d3dd5908d0)


## **`static_cast`란?**

`static_cast`는 C++에서 사용되는 **명시적 형 변환 연산자**입니다.

주로 컴파일 타임에 수행되는 형 변환을 나타내며, 타입 간 변환이 가능한 경우 안전하게 변환합니다.

```cpp
static_cast<new_type>(value)
```

---

### **사용 목적**

1. **기본 자료형 변환**
    - 정수 → 실수, 실수 → 정수, 문자 → 정수 등 기본 자료형 간 변환.
    
    ```cpp
    int a = 10;
    double b = static_cast<double>(a); // int → double
    ```
    
2. **포인터 변환**
    - 서로 관련 있는 타입의 포인터 변환.
    
    ```cpp
    void* p = &a;
    int* q = static_cast<int*>(p); // void* → int*
    ```
    
3. **상수성 제거** (`const_cast`와는 다름)
    - `const`가 없는 타입으로 변환.
    
    ```cpp
    const int a = 10;
    int b = static_cast<int>(a); // const 속성을 유지하며 변환
    ```
    
4. **열거형 변환**
    - 열거형 → 정수형, 또는 그 반대로 변환.
    
    ```cpp
    enum Color { Red, Green, Blue };
    int value = static_cast<int>(Color::Red); // 열거형 → 정수형
    ```
    
5. **클래스 타입 변환**
    - 클래스 간의 업캐스팅(부모로 변환)이나 명시적으로 정의된 변환 연산자 호출.
    
    ```cpp
    class Base {};
    class Derived : public Base {};
    Derived d;
    Base* b = static_cast<Base*>(&d); // Derived → Base (업캐스팅)
    ```
    

---

### **`static_cast`를 사용하는 이유**

1. **안전성**
    - C 스타일 형 변환(`(new_type)value`)보다 명확하고 안전하게 작동한.
    - **변환 가능성**을 컴파일러가 검사하므로, 잘못된 변환을 방지.
2. **가독성**
    - 형 변환의 의도를 명확히 표현.
3. **최적화**
    - 컴파일 타임에 변환을 수행하므로 런타임 비용 없음.

---

### **주의사항**

- 변환할 수 없는 타입 간 변환을 시도하면 **컴파일 에러**가 발생한다.
- 논리적으로 맞지 않는 변환(예: 정수 포인터를 정수로 변환)은 `reinterpret_cast`를 사용해야 한다.

## 퀵 소트 구현

정렬 알고리즘으로 퀵 소트를 선택했다. 퀵 소트(Quick Sort)는 **분할 정복(Divide and Conquer)** 방식을 기반으로 한 알고리즘으로 시간 복잡도가 O(n log n)이다. 최악의 경우에는 O(n²)의 시간 복잡도를 가지지만, 실제로는 대부분의 경우 평균적인 성능을 보이며 빠르다.

### 퀵 소트의 작동 원리

1. **피벗 선택(Pivot Selection)**:
    
    배열에서 임의의 원소를 피벗(pivot)으로 선택한다. 이 원소를 기준으로 배열을 분할한다. 피벗의 선택 방식은 여러 가지가 있으며, 보통 배열의 첫 번째 원소, 마지막 원소, 중간 원소 등을 선택할 수 있다.
    
2. **배열 분할(Partitioning)**:
    
    피벗을 기준으로 배열을 두 개의 부분으로 나눈다.
    
    - 왼쪽 부분은 피벗보다 작은 원소들.
    - 오른쪽 부분은 피벗보다 큰 원소들.
    
    이 과정에서 피벗은 이미 정렬된 위치에 놓이게 된다.
    
3. **재귀 호출(Recursion)**:
    
    분할된 두 부분에 대해 각각 퀵 소트를 재귀적으로 적용한다. 이 과정을 반복하여 배열이 완전히 정렬될 때까지 계속한다.
    

---

### 퀵 소트 과정 예시

### 1. 배열 준비

 퀵 소트를 적용할 배열이 있다고 가정해 보자.

```cpp

[10, 7, 8, 9, 1, 5]
```

### 2. 피벗 선택

배열의 **중앙 원소**를 피벗으로 선택한다. 중앙 원소를 선택하는 이유는 피벗을 선택할 때, 배열의 극단적인 값 (첫 번째나 마지막 원소)보다는 중앙 원소를 선택하는 것이 **일반적으로 더 균형잡힌 분할**을 만들기 때문이다.

- 배열의 인덱스는 0부터 시작하고, 배열의 길이는 6이다. 그러므로 중앙 인덱스는 `(0 + 5) / 2 = 2`이다.
- 그래서 **중앙 원소**인 `8`을 피벗으로 선택한다.

### 3. 배열 분할

피벗을 기준으로 배열을 **두 개의 부분으로 나눈다**. 퀵 소트의 목표는, 피벗보다 작은 원소들은 왼쪽에, 피벗보다 큰 원소들은 오른쪽에 배치하는 것이다.

1. **low: 피벗보다 작은 값을 찾을 때까지 배열을 왼쪽에서 오른쪽으로 탐색**한다.
2. **high: 피벗보다 큰 값을 찾을 때까지 배열을 오른쪽에서 왼쪽으로 탐색**한다.
3. 두 조건을 만족하는 값들이 있으면 **두 값을 교환**한다.
4. 계속해서 왼쪽과 오른쪽을 이동하여 탐색을 진행하다가, low가 high와 겹친 후에 low를 반환 시켜 다음 퀵 소트의 기준점으로 사용한다.

### 4. 재귀적 호출

이후 **분할된 두 부분**에 대해서 다시 퀵 소트를 재귀적으로 적용한다. 각각의 부분에서 또다시 중앙 원소를 피벗으로 선택하고, 위 과정을 반복하면서 배열을 점차적으로 정렬해 나간다.

---

### 퀵 소트의 특징

- **평균 시간 복잡도**: O(n log n)
- **최악 시간 복잡도**: O(n²) (하지만, 최악의 경우를 피하기 위한 최적화 기법이 많이 존재)
- **공간 복잡도**: O(log n) (재귀 호출에 의한 스택 공간)
- **제자리 정렬(In-place Sort)**: 추가적인 배열을 생성하지 않고 기존 배열을 수정하여 정렬한다.
- **비안정 정렬(Unstable Sort)**: 원소의 상대적인 순서가 보장되지 않는다. 예를 들어, 동일한 값들이 있을 때 원래의 순서가 유지되지 않을 수 있다.

---

### 퀵 소트의 최적화 기법

1. **피벗 선택 방식**:
    
    피벗을 선택할 때 배열의 첫 번째 원소나 마지막 원소를 선택하는 방식은 최악의 경우 O(n²)의 성능을 보일 수 있다. 대신 **중앙값**을 피벗으로 선택하거나, **랜덤 피벗**을 선택하는 방법을 사용하여 최악의 경우를 피할 수 있다.
    
2. **배열 크기가 작을 때 삽입 정렬 사용**:
    
    배열 크기가 작을 때는 퀵 소트보다 삽입 정렬이 더 효율적일 수 있다. 따라서, 배열의 크기가 일정 이하일 때는 삽입 정렬을 사용하는 방법을 채택할 수 있다.
    
3. **후보 선택**:
    
    피벗을 선택할 때 배열의 앞, 중간, 뒤의 원소들 중에서 **중앙값을 피벗으로 선택**하는 방법이 자주 사용된다. 이를 통해 퀵 소트의 성능을 안정적으로 개선할 수 있다.