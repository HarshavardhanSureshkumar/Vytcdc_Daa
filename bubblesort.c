#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define BUCKETS 10

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void Merge(int *arr, int start, int mid, int end) {
    int N = end - start + 1;
    int B[N];

    int i = start, j = mid, k = 0;

    while (i < mid && j <= end) {
        if (arr[i] < arr[j])
            B[k++] = arr[i++];
        else
            B[k++] = arr[j++];
    }

    while (i < mid)
        B[k++] = arr[i++];

    while (j <= end)
        B[k++] = arr[j++];

    for (i = 0; i < N; i++)
        arr[start + i] = B[i];
}

void MergeSort(int arr[], int start, int end) {
    if (start < end) {
        int mid = (start + end) / 2;
        MergeSort(arr, start, mid);
        MergeSort(arr, mid + 1, end);
        Merge(arr, start, mid + 1, end);
    }
}


struct node {
    int data;
    struct node *next;
};

void insertSorted(struct node **head, int value) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL || (*head)->data > value) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct node *temp = *head;
    while (temp->next != NULL && temp->next->data < value)
        temp = temp->next;

    newNode->next = temp->next;
    temp->next = newNode;
}

void BucketSort(int arr[], int n) {
    struct node *bucket[BUCKETS];

    for (int i = 0; i < BUCKETS; i++)
        bucket[i] = NULL;

    for (int i = 0; i < n; i++) {
        int index = arr[i] / 10;
        if (index >= BUCKETS)
            index = BUCKETS - 1;

        insertSorted(&bucket[index], arr[i]);
    }

    int k = 0;
    for (int i = 0; i < BUCKETS; i++) {
        struct node *temp = bucket[i];
        while (temp != NULL) {
            arr[k++] = temp->data;
            temp = temp->next;
        }
    }
}


int main() {
    int n, choice;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\nChoose Sorting Method:\n");
    printf("1. Bubble Sort\n");
    printf("2. Insertion Sort\n");
    printf("3. Merge Sort\n");
    printf("4. Bucket Sort\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            bubbleSort(arr, n);
            break;
        case 2:
            insertionSort(arr, n);
            break;
        case 3:
            MergeSort(arr, 0, n - 1);
            break;
        case 4:
            BucketSort(arr, n);
            break;
        default:
            printf("Invalid choice\n");
            return 1;
    }

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
