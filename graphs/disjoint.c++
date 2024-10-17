#include<iostream>
#include<vector>
using namespace std;

class disjointSet{
    vector<int> rank,parent,size;
    public:
        disjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            size.resize(n+1,1);

            for(int i=0;i<=n;i++){
                parent[i]=i;
            }
        }

        int findUPar(int node){
            if(node == parent[node]){
                return node;
            }
            return parent[node]= findUPar(parent[node]);
        }

        void unionByrank(int u,int v){
            int ulp_u=findUPar(u);
            int ulp_v=findUPar(v);  
            if(rank[ulp_u]<rank[ulp_v]){
                parent[ulp_u]=ulp_v;
            }else if(rank[ulp_u]>rank[ulp_v]){
                parent[ulp_v]=ulp_u;
            }else{
                parent[ulp_v]=ulp_u;
                rank[ulp_u]++;
            }
        }

        void unionBysize(int u,int v){
            int ulp_u=findUPar(u);
            int ulp_v=findUPar(v);  
            if(size[ulp_u]<size[ulp_v]){
                parent[ulp_u]=ulp_v;
                size[ulp_v]+=size[ulp_u];
            }else{
                parent[ulp_v]=ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
        }
        
       
};
int main(){
    disjointSet ds(7);
    ds.unionByrank(1,2);
    ds.unionByrank(2,3);
    ds.unionByrank(4,5);
    ds.unionByrank(6,7);
    ds.unionByrank(5,6);
    if(ds.findUPar(7)==ds.findUPar(3)){
        cout<<"Same component"<<endl;
    }else{
        cout<<"Different component"<<endl;
    }
    ds.unionByrank(3,7);
    if(ds.findUPar(7)==ds.findUPar(3)){
        cout<<"Same component"<<endl;
    }else{
        cout<<"Different component"<<endl;
    }
    return 0;
}