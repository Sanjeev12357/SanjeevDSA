#include<iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<limits.h>

using namespace std;


class Graph{

    public:
    unordered_map<char,list<pair<char,int>>> adjList;

    void addEdge(char u, char v, int wt , int direction){
        if(direction==1){
            adjList[u].push_back({v,wt});

        }else {
            adjList[u].push_back({v,wt});
            adjList[v].push_back({u,wt});
        }
    }


    void printAdjList(){
        for(auto it:adjList){
            cout<<it.first<<" ";
            for(auto i:it.second){
                cout<<"{"<<i.first<<","<<i.second<<"}";
            }
            cout<<endl;
        }
    }

    void bellmanFord(int n,char src){

        vector<int> dist(n,INT_MAX);

        dist[src-'A']=0;

        for(int i=0;i<n-1;i++){
            for(auto a:adjList){
                for(auto b:a.second){
                    char u=a.first;
                    char v=b.first;
                    int wt=b.second;

                    if(dist[u-'A']!=INT_MAX && wt+dist[u-'A'] < dist[v-'A']){
                        dist[v-'A']=dist[u-'A']+wt;

                    }
                }
            }
        }
        bool hasCycle=false;
        for(auto a:adjList){
                for(auto b:a.second){
                    char u=a.first;
                    char v=b.first;
                    int wt=b.second;

                    if(dist[u-'A']!=INT_MAX && wt+dist[u-'A'] < dist[v-'A']){
                        hasCycle=true;
                        break;
                        dist[v-'A']=dist[u-'A']+wt;
                        
                    }
                }
            }
            if(hasCycle==true){
                cout<<"negative wt cycle is present";
            }else{
                for(auto i:dist){
                    cout<<i<<" ";
                }
            }




    }

};


int main(){

    Graph g;
    g.addEdge('A','B',-1,1);
    g.addEdge('B','E',2,1);
    g.addEdge('E','D',-3,1);
    g.addEdge('D','C',5,1);
    g.addEdge('A','C',4,1);
    g.addEdge('B','C',3,1);
    g.addEdge('B','D',2,1);
    g.addEdge('D','B',1,1);

    //g.printAdjList();
    g.bellmanFord(5,'A');

    
}