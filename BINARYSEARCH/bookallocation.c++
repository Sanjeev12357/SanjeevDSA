#include<iostream>
#include<bits/stdc++.h>
using namespace std;


bool isPossiblesol(int arr[], int n, int m , int sol){
    int pageSum=0;
    int c=1;
    for(int i=0;i<n;i++){
        if(arr[i]>sol){
            return false;

        }
        if(pageSum+arr[i]>sol){
            c++;
            pageSum=arr[i];
            if(c>m){
                return false;
            }
        }else{
            pageSum+=arr[i];
        }
    }
    return true;
}
int main(){
    int arr[]={10,10,10,10};
    int n=4;
    int m=2;
    int start=0;
    int end=accumulate(arr,arr+n,0);
    int ans=-1;
    if(m>n){
        return -1;
    }


    while(start<=end){
        int mid=(start+end)/2;
        if(isPossiblesol(arr,n,m,mid)){
            ans=mid;
            end=mid-1;

        }else{
            start=mid+1;
        }
    }

    cout<<ans<<endl;

}