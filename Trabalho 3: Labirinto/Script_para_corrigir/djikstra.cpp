#include <bits/stdc++.h>
#define pii pair<int,int>
#define ff first
#define ss second
#define endl '\n'
#define vi vector<int>
#define INF 1e9
using namespace std;

int n,m;
int di[] = {1,-1,0,0}, dj[] = {0,0,1,-1};

int verifica(int i, int j){
    return i >= 0 && j >=0 && i < n && j < m;
}

int djikstra(vector<vi>& arr){
    vector<vi> mark(n, vi(m,0)), dist(n, vi(m, INF));
    
    priority_queue< pair<int,pii> , vector< pair<int,pii> >> fila;
    
    dist[0][1] = 0;
    fila.push({0,{0,1}});
    //peso 0, vertice 0
    
    while(!fila.empty()){
        pii u = fila.top().ss;
        fila.pop();
        
        int i = u.ff, j = u.ss;
        
        if(mark[i][j]) continue;
        mark[i][j] = 1;
        
        for(int p = 0; p < 4; p++){
            int iAt = i + di[p], jAt = j + dj[p];
            
            if(verifica(iAt,jAt)){
                
                if(dist[i][j] + arr[iAt][jAt] < dist[iAt][jAt]){
                    dist[iAt][jAt] = dist[i][j] + arr[iAt][jAt];
                    fila.push({ -dist[iAt][jAt], {iAt,jAt} });
                }
            }   
        }
    }
    return dist[n-1][m-2];
}

int main(){
    FILE* in = fopen("in","r");
    FILE* out = fopen("dj","w");
    char re;
    char a = '1', b = '0';
    fscanf(in,"%d %d",&n,&m);
    fscanf(in,"%c",&re);
    vector<vector<int>> arr(n, vector<int>(m));
    for(int i = 0; i < n; i++){
        
        for(int j = 0; j < m; j++){
            fscanf(in,"%c",&re);
            if(re == '#') arr[i][j] = INF;
            else arr[i][j] = 1;
        }
        fscanf(in,"%c",&re); // '\n'
    }
    int ans = djikstra(arr);
    if(ans < INF) fwrite(&a,1,1,out);
    else fwrite(&b,1,1,out);
    fclose(in); fclose(out);
}