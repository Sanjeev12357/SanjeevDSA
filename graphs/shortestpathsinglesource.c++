#include<iostream>
#include<unordered_map>
#include<list>
#include<stack>
#include<vector>
#include<limits.h>
#include<set>
using namespace std;


class Graph{
    public:
    unordered_map<int,list<pair<int,int>>>adjList;


    void addEdge(int u,int v, int wt, int direction){
        if(direction==1){
            adjList[u].push_back({v,wt});
        }else{
            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,wt});
        }
    }

    void printList(){
        for(auto it:adjList){
            cout<<it.first<<": {";
            for(auto i:it.second){
                cout<<"("<<i.first<<","<<i.second<<"), ";
            }
            cout<<"}"<<endl;
        }
    }

    void topoOrder(int src,stack<int> &st,unordered_map<int,int>&  vis){
        vis[src]=true;

        for(auto nbr:adjList[src]){
            if(!vis[nbr.first]){
                vis[nbr.first]=true;
                topoOrder(nbr.first,st,vis);
            }
        }
        st.push(src);

    }

    void topoSortDfs(stack<int> topoOrder,int n){
        vector<int> dist(n,INT_MAX);

        int src=topoOrder.top();
        topoOrder.pop();
        dist[src]=0;

        for(auto nbrPair:adjList[src]){
            int nbrNode=nbrPair.first;
            int nbrWt=nbrPair.second;
            if(dist[src]+nbrWt <dist[nbrNode]){
                dist[nbrNode]=dist[src]+nbrWt;
            }
        }

        while(!topoOrder.empty()){
            int src=topoOrder.top();
            topoOrder.pop();
            for(auto nbrPair:adjList[src]){
            int nbrNode=nbrPair.first;
            int nbrWt=nbrPair.second;
            if(dist[src]+nbrWt <dist[nbrNode]){
                dist[nbrNode]=dist[src]+nbrWt;
            }
        }
        }

        for(auto i:dist){
            cout<<i<<" ";
        }
    }

    void dijkstraShortestDistance(int n, int src,int dest){
        // create a distance array;
        vector<int> dist(n+1,INT_MAX);
        // create an set because it will store the node with mininmun distance above
        // make the set a pair with distof node and node  
        set<pair<int,int>> st;
        // insert the distance of the source
        st.insert({0,src});
        // update in the distance array also;

        dist[src]=0;

        // distance update for all the nbr nodes;

        while(!st.empty()){
            // calculate the top elemeent ;;
            auto topElement= st.begin();
            pair<int,int> topPair=*topElement;
            int topDist=topPair.first;
            int topNode=topPair.second;

            st.erase(st.begin());
            for(auto nbrPair:adjList[topNode]){
                int nbrDist=nbrPair.second;
                int nbrNode=nbrPair.first;

                if(topDist + nbrDist < dist[nbrNode]){
                    // found a shorter distance update the entry in the set 
                    auto previousEntry=st.find({dist[nbrNode],nbrNode});
                    if(previousEntry!=st.end()){
                        st.erase(previousEntry);
                    }

                    // update the dist array also
                    dist[nbrNode]=topDist+nbrDist;
                    // insert hthe updated distance of the nbr node in the set
                    st.insert({dist[nbrNode],nbrNode});
                }
            }
        }

        cout<<"distance from src to dest"<<src<<" "<<dest<<" "<<dist[dest]<<endl;
    }


};


int main(){
    Graph g;
    // g.addEdge(0,1,5,1);
    // g.addEdge(0,2,3,1);
    // g.addEdge(2,1,2,1);
    // g.addEdge(1,3,3,1);
    // g.addEdge(2,3,5,1);
    // g.addEdge(2,4,6,1);
    // g.addEdge(4,3,1,1);

    // g.printList();
    // stack<int> topoStack;
    // unordered_map<int,int>vis;
    // g.topoOrder(0,topoStack,vis);


    // // while(!topoStack.empty()){
    // //     cout<<topoStack.top()<<" ";
    // //     topoStack.pop();
    // // }
    // cout<<endl;
    // g.topoSortDfs(topoStack,5);

    g.addEdge(1,6,14,0);
    g.addEdge(1,3,9,0);
    g.addEdge(1,2,7,0);
    g.addEdge(2,3,10,0);
    g.addEdge(2,4,15,0);
    g.addEdge(3,4,11,0);
    g.addEdge(6,3,2,0);
    g.addEdge(6,5,9,0);
    g.addEdge(5,4,6,0);
    //g.addEdge(1,6,14,1);

    g.dijkstraShortestDistance(6,6,4);
}