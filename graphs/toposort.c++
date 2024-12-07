#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
#include<queue>
#include<map>
using namespace std;

class Graph{
    public:
    unordered_map<int,list<int>> adjList;


    void addEdge(int u, int v, int dir){

        if(dir==1){
            adjList[u].push_back(v);
        }else{
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }

    void printadjList(){
        for(auto it:adjList){
            cout<<it.first<<":{ ";
            for(auto i:it.second){
                cout<<i<<",";
            }
            cout<<"}"<<endl;
        }
    }

    void topoSortDfs(int src,map<int,bool> &vis,stack<int>& st){
        vis[src]=true;

        for(auto nbr:adjList[src]){
            if(!vis[nbr]){
                topoSortDfs(nbr,vis,st);
            }

        }
        st.push(src);

    }

    void topoSortBfs(int n){

        unordered_map<int,int> indegree;

        for(auto it:adjList){
            for(auto i:it.second){
                indegree[i]++;
            }
        }

        queue<int> q;

        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }


        while(!q.empty()){
            int frontNode=q.front();
            q.pop();
            cout<<frontNode<<",";

            for(auto it:adjList[frontNode]){
                indegree[it]--;

                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
    }


};

int main(){
Graph g;
g.addEdge(0,1,1);
g.addEdge(1,2,1);
g.addEdge(2,3,1);
g.addEdge(3,4,1);
g.addEdge(3,5,1);
g.addEdge(4,6,1);
g.addEdge(5,6,1);
g.addEdge(6,7,1);

g.printadjList();

// map<int,bool> vis;
// stack <int> st;
// g.topoSortDfs(0,vis,st);

// while(!st.empty()){
//     cout<<st.top()<<" ";
//     st.pop();
// }

g.topoSortBfs(8);

}