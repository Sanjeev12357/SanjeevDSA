#include<iostream>
#include<unordered_map>
#include<list>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

class Graph{
    public :
    unordered_map<int,list<int>> adjList;
    void addEdge(int u,int v,bool direction){
        if(direction==1){
            adjList[u].push_back(v);
        }else{
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }

    }
    void printAdjist(){
        for(auto i:adjList){
            cout<<i.first<<"->";
            for(auto entry:i.second){
                cout<<entry<<",";
            }
            cout<<endl;
        }   
    }

    void topoSortDfs(int src, map<int,bool> & visited, stack<int> & st){
        visited[src]=true;


        for(auto nbr:adjList[src]){
            if(!visited[nbr]){
                topoSortDfs(nbr,visited,st);
            }
        }
        st.push(src);;
    }

    void topSortBFS(){
        queue<int> q;
        map<int,int> indegre;

        for(auto i :adjList){
            for(auto  nbr:i.second){
                indegre[nbr]++;
            }
        }
        


        

        // for(auto i: indegre){
        //     cout<<i.first <<"->"<<i.second<<endl;
        // }


    }

    void shortesPathBFS(int src, int dest){
        queue<int> q;
        map<int,int> parent;
        map<int,bool> visited;

        //intial state  
        q.push(src);
        visited[src]=true;
        parent[src]=-1;

        while(!q.empty()){
            int frontNode=q.front();
            q.pop();

            for(auto nbr: adjList[frontNode]){
                if(!visited[nbr]){
                    q.push(nbr);
                    visited[nbr]=true;
                    parent[nbr]=frontNode;
                }
            }
        }

        // parent array tyar hogya ab path print karna hai

        vector<int> ans;
        while(dest!=-1){
            ans.push_back(dest);
            dest=parent[dest];
        }

        reverse(ans.begin(),ans.end());
        //printing the shorted path

        for(auto i:ans){
            cout<<i<<" ";
        }
         
    }
};
int main(){
    Graph g;
    g.addEdge(0,1,1);
    g.addEdge(1,2,1);
    g.addEdge(2,3,1);
    g.addEdge(3,4,1); 
     

   // g.printAdjist();
    g.topSortBFS();
 g.shortesPathBFS(0,3);

    // int n=5;
    // map<int,bool>visited;
    // stack<int>st;
    // for(int node=0;node<n;node++){
    //     if(!visited[node]){
    //         g.topoSortDfs(node,visited,st);
    //     }
    // }
    // while(!st.empty()){
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }
    return 0;
}