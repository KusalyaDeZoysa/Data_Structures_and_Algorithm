# include <iostream>
#include <cstdlib>
using namespace std;

int part(int arr[], int startindex, int endindex){
    int pivot = arr[endindex];
    int i= startindex-1;

    for(int j=startindex; j<endindex; j++){
        if (arr[j]<pivot){
            i++;
            int temp= arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    i++;
    int temp=arr[i];
    arr[i]=pivot;
    arr[endindex]=temp;

    return i;
}

void quicksort(int arr[], int startindex, int endindex){

    if (endindex<= startindex){
        return;
    }
    int pivot= part(arr, startindex, endindex);

    quicksort(arr, startindex, pivot-1);
    quicksort(arr, pivot+1, endindex);

}

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
      arr[i]=rand()%500;

    quicksort(arr,0,n-1);

    for (int m=0; m<n; m++){
        cout << arr[m] << " ";
    }
}


