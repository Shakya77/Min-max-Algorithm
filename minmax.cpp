//Min Max Problem 
#include <iostream>
using namespace std;

struct mm{
    int min;
    int max;
};

struct mm minMax(int a[], int low ,int high){
    struct mm min_max;
    if(low == high){  //a[] containes only one element
        min_max.min = a[low];
        min_max.max = a[low];
        return min_max;
    }else if( high - low == 1){  //a[] contains two elements
        if(a[low] < a[high]){
            min_max.min = a[low];
            min_max.max = a[high];
        }else{
            min_max.min = a[high];
            min_max.max = a[low];
        }
        return min_max;
    }else{ //a[] contains more than two elements    
        int mid = (low + high)/2;
        struct mm left = minMax(a,low,mid);
        struct mm right = minMax(a,mid+1,high);
        // find overall minimun element
        if(left.min < right.min){
            min_max.min = left.min;
        }else{
            min_max.min = right.min;
        }
        // find overall maximun element
        if(left.max > right.max){
            min_max.max = left.max;
        }else{
            min_max.max = right.max;
        }
        return min_max;
    }
}

int main()
{   
    // input array
    int n;
    int size;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    struct mm min_max = minMax(arr,0,n-1);
    cout << "Minimun Element in the array is: " << min_max.min << endl;
    cout << "Maximun Element in the array is: " << min_max.max << endl;
    return 0;
}