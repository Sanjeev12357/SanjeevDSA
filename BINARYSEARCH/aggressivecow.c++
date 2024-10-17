#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
 

bool isPossible(vector<int> & stalls,int n, int k , int sol){
    int c=1;

    //pehli cow ko first index pr rkh diya 
    int pos=stalls[0];


    // abh dekho ko min atleast sol distance pr rkh skte hai ki nhi
    for(int i=1;i<n;i++){
        if(stalls[i]-pos>=sol){
            c++;
            pos=stalls[i];
        }
        if(c==k) return true;
    }
    return false;
}

int main(){
    int n=5;
    int k=3;
    vector<int>stalls={1,2,8,4,9};
    sort(stalls.begin(),stalls.end());

    int s=0;
    int end=stalls[n-1]-stalls[0];
    int ans=-1;

    while(s<=end){
        int mid=(s+end)>>1;
        if(isPossible(stalls,n,k,mid)){
            ans=mid;
            //agr to mid par solution hai to ho skta hai isse zyada space pr bhi cows ko place kr skte hai to age badho
            s=mid+1;
        }else{
            end=mid-1;
        }
    }
    cout<<ans<<endl;
}

 