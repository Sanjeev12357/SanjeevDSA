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
        
        
         bool checkcyclepresent(int src){
            queue<int>q;
            unordered_map<int, bool>visited;
            unordered_map<int,int> parent;
            q.push(src);
            visited[src]=true;
            parent[src]=-1;

            while(!q.empty()){
                int frontNode=q.front();
                q.pop();

                for(auto nbr:adjList[frontNode]){
                    if(visited[nbr]!=true){
                        visited[nbr]=true;
                        q.push(nbr);
                        parent[nbr]=frontNode;
                    }
                    if(visited[nbr]==true && frontNode!=parent[nbr]){
                        return true;
                    }
                }
            }
            return false;

            }
  };

 

  int main(){
        Graph<int> g;
        g.addEdge(0,1,1);
        g.addEdge(0,4,1);
        g.addEdge(1,2,1);
        g.addEdge(2,3,1);
      //  g.addEdge(3,4,1);

        g.bfsTraversal(0);
        bool check=g.checkcyclepresent(0);

        if(check){
            cout<<"cycle is present";
        }else{
            cout<<"cycle is not present";
        }
        unordered_map<int,bool>vis;
        g.dfs(0,vis);
        cout<<"hello";  
  }


bool checkCyclePresent(int src, unordered_map<int, vector<int>>& adjList) {
    queue<int> q;
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    
    q.push(src);
    visited[src] = true;
    parent[src] = -1;

    while (!q.empty()) {
        int frontNode = q.front();
        q.pop();

        // Traverse neighbors of the current node
        for (auto nbr : adjList[frontNode]) {
            if (!visited[nbr]) {
                visited[nbr] = true;
                q.push(nbr);
                parent[nbr] = frontNode;
            } 
            // If neighbor is visited and not parent, there's a cycle
            else if (nbr != parent[frontNode]) {
                return true;
            }
        }
    }
    return false;
}

// Wrapper for disconnected graph handling
bool isCycleInGraph(unordered_map<int, vector<int>>& adjList) {
    unordered_map<int, bool> visited;

    for (auto& node : adjList) {
        int src = node.first;
        if (!visited[src]) {
            if (checkCyclePresent(src, adjList)) {
                return true;
            }
        }
    }
    return false;
}
