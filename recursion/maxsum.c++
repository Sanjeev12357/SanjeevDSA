#include<iostream>
#include<vector>

using namespace std;


//max sum of no adjacent arrays
int  solve(vector<int> arr,int n,int i){
    if(i>=arr.size()){
        return 0;
    }

    int inc=arr[i]+solve(arr,n-1,i+2);
    int exc=0+solve(arr,n-1,i+1);

    return max(inc,exc);

}
int main(){
    vector<int> arr={1,2,3,4,5,6};
    int n=arr.size();
    int i=0;
    int ans=solve(arr,n,i);
    cout<<ans;

    
}