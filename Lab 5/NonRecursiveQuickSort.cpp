#include <iostream>
#include <cstdlib>
#include <stack>
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

void quicksort(int arr[], int startindex, int endindex) {
    stack<int> stk;

    stk.push(startindex);
    stk.push(endindex);

    while (!stk.empty()) {
        endindex = stk.top();
        stk.pop();
        startindex = stk.top();
        stk.pop();

        int pivot = part(arr, startindex, endindex);

        if (pivot - 1 > startindex) {
            stk.push(startindex);
            stk.push(pivot - 1);
        }

        if (pivot + 1 < endindex) {
            stk.push(pivot + 1);
            stk.push(endindex);
        }
    }
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




