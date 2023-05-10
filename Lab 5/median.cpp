#include <iostream>
#include <iomanip>
using namespace std;

float median(int arr[], int n){
    float median=0.0;
    if (n==1){
        median=arr[0]/1.0;
    }
    else if(n%2==0){
        int j=(n)/2;
        int m=(n+2)/2;
        median= (arr[j-1]+arr[m-1])/2.0;
    } else{
        int j= n/2;
        median= arr[j]/1.0;
    }
return median;
}

void insertionSort(int arr[], int n){
    int i, key, j;
    for (i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

}

int main(){
    int k;
    int m;
    cout << "Enter the no of inputs: ";
    cin >> k;
    int arr[k];
    cout << "Enter the array as space separated list: ";
    for (int i=0; i<k; i++){
            cin>>m;
        arr[i]=m;
    }

    for (int i=0; i<k; i++){
        insertionSort(arr,i+1);
        cout << "[";
        for (int m=0; m<=i; m++){
            cout <<arr[m] << ",";
        }
        cout << "]" << "        ";
        float t = median(arr, i+1);
        cout <<fixed << setprecision(1);
        cout << t << endl;
    }
return 0;

}
