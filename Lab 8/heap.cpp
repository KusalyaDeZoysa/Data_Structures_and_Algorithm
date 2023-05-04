#include <iostream>
using namespace std;

// function to heapify the tree
void heapify(int arr[], int n, int root)
{
    int maximum= root;
    int left= 2*root;
    int right= 2*root+1;

    if(left<n && arr[left]>arr[maximum]){
        maximum = left;
    }
    if(right<n && arr[right]>arr[maximum]){
        maximum = right;
    }
    if(maximum!=root){
        swap(arr[root],arr[maximum]);
        heapify(arr,n,maximum);
    }


}

// implementing heap sort
void heapSort(int arr[], int n)
{
   int start=(n/2)-1;
   for (int i = start; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for(int i=n-1; i>=0; i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
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
   int n;
   cout << "Number of inputs: " ;
   cin >> n;
   int heap_arr[n];
   cout << "Enter the array as space separated values: " << endl;
   for(int i=0;  i<n; i++){
    cin >> heap_arr[i];
   }
   cout << endl;
   cout<<"Input array"<<endl;
   displayArray(heap_arr,n);

   heapSort(heap_arr, n);

   cout << endl;
   cout << "Sorted array"<<endl;
   displayArray(heap_arr, n);
}
