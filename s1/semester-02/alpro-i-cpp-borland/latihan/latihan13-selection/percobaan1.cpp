#include <conio.h>
// #include <stdio.h>
// #include <stdlib.h> 
#include <iostream.h>
// #include <string.h>
#define MAX_LEN 50
void selectionSort(char arr[][50], int n){
   int i, j;
   // Move boundary of unsorted subarray one by one
   char minStr[50];
   for (i = 0; i < n-1; i++){
      cout << "__________________________________\nTahab " << (i+1) << ". \n__________________________________\n";
      // Determine minimum element in unsorted array
      int mIndex = i;
      strcpy(minStr, arr[i]);
      // cout << "minSTR, arr[i]: "<< minStr << ", " << arr[i] << ", mIndex: " << mIndex << "\n";
      for (j = i + 1; j < n; j++){
         // check whether the min is greater than arr[j]
         // cout << "strcmp(minStr, arr[j]): " << strcmp(minStr, arr[j]) << " < 0 , mIndex: " << mIndex << "\n";
         if (strcmp(minStr, arr[j]) > 0){
            // Make arr[j] as minStr and update min_idx
            strcpy(minStr, arr[j]);
            mIndex = j;
            // cout << "hasil awal minSTR, arr[j]: "<< minStr << ", " << arr[i] << ", mIndex: " << mIndex << "\n";
         }
            // for (int a=0;a<n;a++) {
            //    // cout << arr[a] << "v";
            //    cout << minStr << ", ";
            // }
            // cout << "\n";
      }
         for (int a=0;a<n;a++) {
               cout << arr[a] << " v ";
               cout << minStr << ", ";
         }
      cout << "\n";
      // Swap the minimum with the first element
      if (mIndex != i){
            char temp[50];
            strcpy(temp, arr[i]); //swap item[pos] and item[i]
            strcpy(arr[i], arr[mIndex]);
            strcpy(arr[mIndex], temp);
      }
   }
}
void main(){
   char arr[][50] = {"Kirik", "Babi", "Asu" ,"Tuyul", "Slero", "Genderuwo", "Kunti"};
   int n = sizeof(arr)/sizeof(arr[0]);
   cout << n << " | " << sizeof(arr) << " || " << sizeof(arr[0]) << endl;
   int i;
   cout<<"Given String is:: ";
   for (int i = 0; i < n; i++)
   {
       cout << arr[i] << ", ";
   }
   cout << endl;
   selectionSort(arr, n);
   cout << "\nSelection Sorted is::\n";
   // for (i = n-1; i >= 0; i--) // Des
   for (i = 0; i < n; i++) //Ass
      cout << i << ": " << arr[i] << endl;
    getch();
}