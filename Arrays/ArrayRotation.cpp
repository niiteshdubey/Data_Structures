//this program illustrates how to rotate an array by d positions
//i.e., if given array is: {1,2,3,4,5,6,7} and d=3 then,
//rotated array will be: {4,5,6,7,1,2,3}
#include <iostream>
using namespace std;
//helper function for finding gcd of two numbers
int GCD(int a,int b){
    if(b==0)
    return a;
    return GCD(b,a%b);
}
//helper function to print array elements
void printArray(int arr[],int n){
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
    cout<<'\n';
}
//helper function to reverse an array
void reverse(int arr[],int start,int end){  //here start and end are starting and ending points of array
    int t;
    while(start<end){
        t=arr[start];
        arr[start]=arr[end];
        arr[end]=t;
        start++;
        end--;
    }
}
//Methon 1: by using temp array for storing d elements
/*
void Rotate(int arr[],int n,int d){
    int temp[d];
    int i;
    for(i=0;i<d;i++)
    temp[i]=arr[i];
    for(i=0;i<n-d;i++)
    arr[i]=arr[i+d];
    int j=0;
    while(i<n){
        arr[i]=temp[j];
        i++;
        j++;
    }
}
*/
//Another approach for this problem can be juggling method which is implemented below
//method 2: Juggling approach
/*
void Rotate(int arr[],int n,int d){
    //if d>=n
    d=d%n;
    int gcd=GCD(d,n);
    for(int i=0;i<gcd;i++){
        int t=arr[i];
        int j=i;
        while(true){
            int k=j+d;
            if(k>=n)
            k=k-n;
            if(k==i)
            break;
            arr[j]=arr[k];
            j=k;
        }
        arr[j]=t;
    }
}
*/
//The third important method is reversal method
//method 3: Using reversal method
void Rotate(int arr[],int d,int n){
    reverse(arr,0,d-1);
    reverse(arr,d,n-1);
    reverse(arr,0,n-1);
}
int main(){
    int arr[]={1,2,3,4,5,6,7,8,9};
    int d=3;
    int n=sizeof(arr)/sizeof(arr[0]);
    printArray(arr,n);
    Rotate(arr,d,n);
    cout<<"array after rotation:\n";
    printArray(arr,n);
    return 0;
}

