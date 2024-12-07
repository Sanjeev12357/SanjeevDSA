#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
#include<queue>
#include<map>
#include<algorithm>
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

    void shortestPathBFS(int src,int dest){

        unordered_map<int, int> parent;
        unordered_map<int, bool> vis;
        queue<int> q;
        q.push(src);
        vis[src]=true;
        parent[src]=-1;

        while(!q.empty()){
            int frontNode=q.front();
            q.pop();

            for(auto nbr:adjList[frontNode]){
                if(!vis[nbr]){
                    q.push(nbr);
                    vis[nbr]=true;
                    parent[nbr]=frontNode;
                }
            }
        }
        vector<int> ans;
        while(dest!=-1){
            ans.push_back(dest);
            dest=parent[dest];
        }

        reverse(ans.begin(),ans.end());

        for(auto i:ans){
            cout<<i<<" ";
        }
    }



};

int main(){
Graph g;
g.addEdge(0,5,0);
g.addEdge(5,4,0);
g.addEdge(4,3,0);
g.addEdge(0,6,0);
g.addEdge(6,3,0);
g.addEdge(0,1 ,0);
g.addEdge(1,2,0);
g.addEdge(2,3,0);

g.printadjList();


g.shortestPathBFS(0,3);


}