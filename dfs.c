#include<stdio.h>
  int visited[6]={0,0,0,0,0,0};
    int A[6][6]={{0,1,1,0,0,0},
                 {1,0,0,1,1,0},
                 {1,0,0,0,1,0},
                 {0,1,0,0,1,1},
                 {0,1,1,1,0,1},
                 {0,0,0,1,1,0}};

void dfs(int i){
    int j;
    printf("%d",i);
    visited[i]=1;
    for(j=0;j<6;j++){
        if(A[i][j]== 1 &&!visited[j]){ //* !visited[j]  means  visited[j]==0 
            dfs(j);
        }
    }
}
int main(){
  dfs(0);
  return 0;
}