#include<iostream>
#include<vector>
using namespace std;


void printsubarray(vector<int> &nums,int start,int end)
{
    if(end==nums.size()){
        return;
    }
    for(int i=start;i<=end;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    printsubarray(nums,start,end+1);
}

void printsubarr(vector<int> nums){
    for(int start=0;start<nums.size();start++){
        int end=start;
        printsubarray(nums,start,end);
    }
}





int main(){
    vector<int> nums{1,2,3,4,5};
    printsubarr(nums);

}