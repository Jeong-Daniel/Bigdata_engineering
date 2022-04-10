#include<iostream>
using namespace std;
int maps[12][12];
int visited[12]={0};
int num;
void init(){
    for (int i = 0; i < 12; i++)
        for (int j = 0; j < 12; j++)
            maps[i][j] = 0;
}
void dfs(int v)
{
    cout<<v<<endl;
    visited[v] = 0;
    for(int i = 0; i <= num; i++)
    {
        if(maps[v][i] && visited[i]) 
            dfs(i);
    }
}
int main(void)
{
    int v1,v2;
    init();
    int temp;
    cin>> temp;
    cin>> num;
    for(int i=0;i<num;i++)
    {
        cin>>v1>>v2;
        maps[v1][v2] = maps[v2][v1] = 1;
        visited[v1] = visited[v2] = 1;
    }
    int start;
    cin>>start;
    dfs(start);
    return 0;
}

