#include <iostream>
using namespace std;

void merge(int A[], int l, int mid, int h) {
    int i = l;
    int j = mid + 1;
    int k = l;

    int B[h + 1];

    while (i <= mid && j <= h) {
        if (A[i] < A[j]) {
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }
    while (i <= mid) {
        B[k++] = A[i++];
    }
    while (j <= h) {
        B[k++] = A[j++];
    }
    for (i = l; i <= h; i++) {
        A[i] = B[i];
    }
}

void MergeSort(int A[], int l, int h) {
    if (l < h) {
        int mid = (l + h) / 2;
        MergeSort(A, l, mid);
        MergeSort(A, mid + 1, h);
        merge(A, l, mid, h);
    }
}

int main() {
    int A[] = {13, 12, 10, 4, 5, 7, 9};
    int n = sizeof(A) / sizeof(A[0]);

    MergeSort(A, 0, n - 1);

    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }

    return 0;
}
