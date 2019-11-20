#include <iostream>
#include <cstring>
#include <stack>
using namespace std;

#define MAX 205
#define INF 0x3f3f3f3f
struct MGraph
{
    int edges[MAX][MAX];
    int n,e;
}G;

int path[MAX][MAX];
int A[MAX][MAX];
void init() {
    memset(G.edges, INF, sizeof(G.edges));
    memset(A, -1, sizeof(A));
    for(int i = 1; i < MAX; i++){ 
        G.edges[i][i] = 0;
    } 
}
void insert(int u, int v, int w) {
    G.edges[u][v] = w;
}

void Floyd(MGraph G, int path[][MAX]){  
    int i, j, k;
    //int A[MAX][MAX];
   
    for(i = 1; i <= G.n; i++){
        for(j = 1; j <= G.n; j++){
            A[i][j] = G.edges[i][j];
            path[i][j] = -1;
        }
    } 
  
    for(k = 1; k <= G.n; k++){ 
        for(i = 1; i <= G.n; i++){ 
            for(j = 1; j <= G.n; j++){ 
                if(A[i][j] > A[i][k] + A[k][j]){ 
                    A[i][j] = A[i][k] + A[k][j];  
                    path[i][j] = k;  
                }
            }
        }
    } 
}


int main() {
    int n, m;//n个点，m条边
    int a, x, y, w;
    int T;
    int max;
    int i,j;
    cin >> T;
    while(T--)
    {
         max =-99999999;
        init();
         cin >> n >> m;
         G.e = m;
         G.n = n;
        for(int i = 0; i < m; i++){
            cin >> x >> y >> w;
            insert(x, y, w);
        }
        Floyd(G, path);
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
            if(A[i][j]>max&&A[i][j]!=INF) max=A[i][j];
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++)
              if(max==A[i][j]) cout << i << ' ' << j <<endl;


    }
    return 0;
}
