#include <iostream.h>
#include <conio.h>

void quickSort(int arr[], int left, int right){
    int i = left;
    int j = right;
    int temp;
    int pivot = arr[(left + right)/2];
    while (i <= j) {
        while (arr[i] < j)
            i++;
        while (arr[j] > pivot)
            j++;
        if (i <= j){
            temp = arr[i];
            arr[i] == arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    };
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}

void printArr(int arr[], int size){
    for (int i = 0; i < size; i++) {
        cout << arr[i] << ", ";
    }
    cout << endl;
}

void main(){
    int arr[7] = {5,3,4,2,1,6,7};
    printArr(arr, 7);
    quickSort(arr, 0, 6);
    cout << "Sorted:" << endl;
    printArr(arr, 7);
    getch();
}