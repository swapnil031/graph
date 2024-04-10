#include<iostream>
#include<vector>
#include<list>
using namespace std;
vector<list<int>> graph;
int v;
void add_egde(int src,int dest,bool bidirec=true){
    //bidrected graph=true
    //unidirectred graph=false

    graph[src].push_back(dest);//create an edge from source to destination
    if(bidirec){
        graph[dest].push_back(src);
    }
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
    display();
}