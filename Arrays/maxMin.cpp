#include<bits/stdc++.h>
using namespace std;

// METHOD 1: SIMPLE LINEAR SEARCH
// In this method, the total number of comparisons is 1 + 2(n-2) in the worst case 
// and 1 + n – 2 in the best case. 
// In this implementation, the worst case occurs when elements are sorted in descending order
// and the best case occurs when elements are sorted in ascending order.
// TIME COMPLEXITY = O(N), SPACE COMPLEXITY = O(1)
pair<int,int>max_min1(int arr[],int n){
    pair<int,int>p; //first will represent min and second will represent max element
    if(n==1){
        p.first=arr[0];
        p.second=arr[0];
        return p;
    }
    if(n==2){
        if(arr[0]<arr[1]){
            p.first=arr[0];
            p.second=arr[1];
        }
        else{
            p.first=arr[1];
            p.second=arr[0];
        }
        return p;
    }
    p.first=arr[0];
    p.second=arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]<p.first)
        p.first=arr[i];
        if(arr[i]>p.second)
        p.second=arr[i];
    }
    return p;
}

// METHOD 2: COMPARE IN PAIRS
// If n is odd then initialize min and max as first element. 
// If n is even then initialize min and max as minimum and maximum of the first two elements respectively. 
// For rest of the elements, pick them in pairs and compare their 
// maximum and minimum with max and min respectively.
// If n is odd:    3*(n-1)/2  
// If n is even:   1 Initial comparison for initializing min and max, 
//                 and 3(n-2)/2 comparisons for rest of the elements  
//                 =  1 + 3*(n-2)/2 = 3n/2 -2
// TIME COMPLEXITY = O(n), SPACE COMPLEXITY = O(1)
pair<int,int> max_min2(int arr[],int n){
    pair<int,int>p;
    int i;
    if(n==1){
        p.first=arr[0];
        p.second=arr[1];
        return p;
    }
    if(n%2==0){
        if(arr[0]<arr[1]){
            p.first=arr[0];
            p.second=arr[1];
        }
        else{
            p.first=arr[1];
            p.second=arr[0];
        }
        i=2;
    }
    else{
        p.first=p.second=arr[0];
        i=1;
    }
    while(i<n-1){
        if(arr[i]<arr[i+1]){
            if(p.first>arr[i])
            p.first=arr[i];
            if(p.second<arr[i+1])
            p.second=arr[i+1];
        }
        else{
            if(p.second<arr[i])
            p.second=arr[i];
            if(p.first>arr[i+1])
            p.first=arr[i+1];
        }
        i+=2;
    }
    return p;
}

// METHOD 3: TOURNAMENT METHOD
// Divide the array into two parts 
// and compare the maximums and minimums of the two parts 
// to get the maximum and the minimum of the whole array.
pair<int,int>max_min3(int arr[],int low,int high){
    pair<int,int>mm,mml,mmr;
    int mid;
    // if there is only one element then return the max and min as the only element
    if(low==high){
        mm.first=arr[low];
        mm.second=arr[low];
        return mm;
    }
    //if there are only two elements then return the max and min element among the only two elements
    else if(low+1==high){
        if(arr[low]<arr[high]){
            mm.first=arr[low];
            mm.second=arr[high];
        }
        else{
            mm.first=arr[high];
            mm.second=arr[low];
        }
        return mm;
    }
    // if there are more than two elements then recur on two halves of the array
    else{
        mid=(low+high)/2;   //get the mid point of the array
        mml=max_min3(arr,low,mid);  //recur to the left part of the array
        mmr=max_min3(arr,mid+1,high);   //recur to the right part of the array
        //compare minimums of two parts
        if(mml.first<mmr.first)
            mm.first=mml.first;
        else
            mm.first=mmr.first;
        if(mml.second>mmr.second)
            mm.second=mml.second;
        else
            mm.second=mmr.second;
    }
    return mm;
}
int main(){
    // AMONG THESE THREE METHODS THE 2ND METHOD IS CONSIDERED TO BE THE BEST
    pair<int,int> maxmin;
    int arr[]={1,2,3,4,5,6,7,8,9,10};
    maxmin = max_min3(arr,0,9);
    cout<<maxmin.first<<" is the minimum element of the array"<<endl;
    cout<<maxmin.second<<" is the maximum element of the array"<<endl;
    return 0;
}