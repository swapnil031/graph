//checking whether a route is there between two vertices
#include<iostream>
#include<vector>
#include<list>
#include<unordered_set>
using namespace std;
vector<list<int>> graph;
unordered_set<int>visited;
int v;


void add_egde(int src,int dest,bool bidirec=true){
    //bidrected graph=true
    //unidirectred graph=false

    graph[src].push_back(dest);//create an edge from source to destination
    if(bidirec){
        graph[dest].push_back(src);
    }
}

bool dfs(int curr,int end){
    if(curr==end) return true;
    visited.insert(curr); //mark visited
    for(auto neighbour:graph[curr]){
        if(not visited.count(neighbour)){
            bool result=dfs(neighbour,end);
            if(result) return true;
        }
    }
    return false;
}

bool anypath(int src,int dest){
    return dfs(src,dest);
}
void display(){
    int i;
    for(i=0;i<graph.size();i++){
        cout<<i<<"->";
        for(auto el:graph[i]){
            cout<<el<<",";
        }
        cout<<endl;
    }
}
int main(){
    cout<<"enter the no of vertices : ";
    cin>>v;
    graph.resize(v,list<int>());
    cout<<"enter the no of edges : ";
    int e;
    cin >>e;
    while(e--){
        int c,d;
        cin>>c>>d;
        add_egde(c,d);
    }
    int x,y;
    cin>>x>>y;
    cout<<anypath(x,y);
    //display();
}