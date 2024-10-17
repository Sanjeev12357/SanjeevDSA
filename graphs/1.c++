 #include<iostream>
    #include<unordered_map>
    #include<list>
    #include<queue>
 using namespace std;


    template<typename T>

  class Graph{
    public:
        unordered_map<T,list<T>> adjList;
        void addEdge(T u,T v,bool direction ){
            // direction->0->undirected
            // direction->1->directed
            if(direction == 1){
                // u se v ki taraf ek edge hai
                // u->v
                adjList[u].push_back(v);

            }else{
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }
            printAdjList();
        }
        void printAdjList(){
            for(auto i:adjList){
                cout<<i.first<<"->";
                for(auto entry:i.second){
                    cout<<entry<<",";
                } 
                cout<<endl;
            }
        }
        void bfsTraversal(T src){
            //adjlist already data memenber have
             unordered_map<T,bool>vis;

             queue<T>q;
             //initial state
             q.push(src);
             vis[src]=true;

             while(!q.empty()){
                T frontNode=q.front();
                cout<<frontNode<<" ";
                q.pop();

                for(auto nbr:adjList[frontNode]){
                    if(!vis[nbr]){
                        q.push(nbr);
                        vis[nbr]=true;
                    }
             }
            }
        }


        void dfs(T src,unordered_map<T,bool> &vis){ 
            vis[src]=true;
            cout<<src<<" ";

            for(auto nbr:adjList[src]){
            
                if(!vis[nbr]){
                    dfs(nbr,vis);
                }
            }
        }
  };

  int main(){
        Graph<int> g;
        g.addEdge(0,1,1);
        g.addEdge(0,4,1);
        g.addEdge(1,2,1);
        g.addEdge(2,3,1);

        g.bfsTraversal(0);
        unordered_map<int,bool>vis;
        g.dfs(0,vis);
        cout<<"hello";  
  }