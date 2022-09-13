// Derek Thibert
// 07/19/2022
// 110080944

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

clock_t start, end;

void buildHeap(int a[], int);
void heapSort(int a[], int);
void heapify(int a[], int, int);
int partition(int list[], int, int);
void quickSort(int list[], int, int);

int main(void){
    srand(time(NULL));
    int listSize;
    int i;
    printf("Please print in the size of your array: ");
    scanf("%d", &listSize);
    int *list = (int *)calloc(listSize, sizeof(int));

    printf("\n\nHEAPSORT\n\n");
    printf("Before\n");
    for(i = 0; i < listSize; i++){
        list[i] = rand() % 10000;
        printf("%d ", list[i]);
    }
    printf("\n");
    start = clock();
    heapSort(list, listSize);
    printf("\nAfter\n");
    for(i=0; i<listSize; i++){
        printf("%d ", list[i]);
    }

    end = clock();
    double elapsedTime = (double)(end-start) / CLOCKS_PER_SEC;
    printf("\n\nTime it took in seconds is: %.9f\n", elapsedTime);
   
     for(i = 0; i < listSize; i++){
        list[i] = rand() % 10000;
    }
    printf("\n\nQUICK SORT\n\n");

    printf("Before\n");
    for(i = 0; i < listSize; ++i){
        printf("%d ", list[i]);
    }
    printf("\n");
    start = clock();
    quickSort(list, 0, listSize - 1);
    printf("\nAfter\n");
    for (i = 0; i < listSize; ++i){
        printf("%d ", list[i]);
    }
    end = clock();
    elapsedTime = (double)(end-start) / CLOCKS_PER_SEC;
    printf("\n\nTime it took in seconds is: %.9f\n", elapsedTime);
   

     return 0;
}

void buildHeap(int a[], int n) {
    int i;
    for(i = n; i >= 0; i--){
        heapify(a, i, n-1);
    }
}

void heapSort(int a[], int n) {

    buildHeap(a, n);
    int temp;

    for(int i = n-1; i >= 0; i--){
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        heapify(a, 0, i-1);
    }

}

void heapify(int a[], int i, int j){

    int k, temp;
    // k holds the value of the larger child.
    if (j < 2*i+1){
        return;
    }
    if( j == 2*i+1){
        k = 2*i+1;
    } else {
        if (a[2*i+1] > a[2*i+2]){
            k = 2*i+1;
        } else {
            k = 2*i+2;
        }
    }
    if(a[k]>a[i]){
        temp = a[i];
        a[i] = a[k];
        a[k] = temp;
        heapify(a, k, j);
    }
    // int temp;
    // int k;
    // if (j < i*2){
    //     return;
    // }
    // if (j == i*2){
    //     k = i*2;
    // } else {
    //     if(a[i*2] >= a[i*2+1]){
    //         k = i*2;
    //     } else {
    //         k = i*2 + 1;
    //     }
    // }
    // if (a[k] > a[i]){
    //     temp = a[i];
    //     a[i] = a[k];
    //     a[k] = temp;
    //     heapify(a[], k, j);
    // }
}

int partition(int a[], int p, int q){
    int i, j, x, temp, flag;
    i = p;
    j = q;
    x = a[p];

    flag = 1;

    while(flag){

        while(a[i] <= x){
            i = i + 1;
        }
        //printf("i: %d ", i);

        while (a[j] > x){
            j = j - 1;
        }
       // printf("j: %d ", j);
        if(i<j){
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        } else{
        flag = 0;
        }
    }
    temp = a[p];
    a[p] = a[j];
    a[j] = temp;
    return j;
}

void quickSort(int a[], int p, int q){
 int pivot;
 
 if (p < q){
    pivot = partition(a, p, q);
    //printf("PIVOT: %d ", pivot);
    quickSort(a, p, pivot - 1);
    quickSort(a, pivot + 1, q);
 }
}