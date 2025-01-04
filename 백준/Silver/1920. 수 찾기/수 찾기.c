#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

// qsort용 비교 함수 (오름차순 정렬)
int compare(const void* a, const void* b) {
    int A = *(int*)a;
    int B = *(int*)b;
    return (A > B) - (A < B);
}

// 이진 탐색 알고리즘
int BSearch(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (arr[mid] == target) {
            return 1; // 탐색 완료
        }
        else if (arr[mid] > target) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return 0; // 탐색 실패
}

int main(void) {
    int n;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    // 이진 탐색을 위한 정렬
    qsort(arr, n, sizeof(int), compare);

    int m;
    scanf("%d", &m);
    //int* target = (int*)malloc(m * sizeof(int));
    for (int i = 0; i < m; i++) {
        int check_value = 0;
        scanf("%d", &check_value);
        printf("%d\n", BSearch(arr, n, check_value));

    }

    // 메모리 해제
    free(arr);

    return 0;
}