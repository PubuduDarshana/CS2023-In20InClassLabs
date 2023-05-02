#include <iostream>
#include <cstdlib> // for rand()
#include <ctime> // for time()
#include <chrono> // for timing

using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
   int largest = root;
   int left = 2 * root + 1;
   int right = 2 * root + 2;

   if (left<n && arr[left] > arr[largest]){
      largest = left;
   }

   if (right<n && arr[right] > arr[largest]){
        largest = right;
   }

   if (largest != root){
      swap(arr[root], arr[largest]);

      heapify(arr, n, largest);
   }   

}
  
// implementing heap sort
void heapSort(int arr[], int n)
{
   // build heap
   for (int i = n/2-1; i>=0; i--)
        heapify(arr, n, i);


   // extracting elements from heap one by one

   for (int i = n-1; i>0; i--)
    {
        swap(arr[0], arr[i]);

        heapify(arr, i, 0);
    }
   
}
  
/* print contents of array */
void displayArray(int arr[], int n)
{
   for (int i=0; i<n; ++i)
   cout << arr[i] << " ";
   cout << "\n";
}
  
// main program
int main()
{
    const int m = 6;
    int heap_arr[m];
    srand(time(0));

    for (int i = 0; i < m; i++) {
        heap_arr[i] = rand() % 100; // generate random integers between 0 and 99
    }

   // int heap_arr[] = {4,17,3,12,9,6};
   int n = sizeof(heap_arr)/sizeof(heap_arr[0]);

   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);
  
   heapSort(heap_arr, n);
  
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}