#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    int n,e;
    if(scanf("%d %d",&n,&e)!=2) return 0;
    int cap = 2*e;
    int *head = malloc(n * sizeof(int));
    int *to = malloc(cap * sizeof(int));
    int *nxt = malloc(cap * sizeof(int));
    memset(head,-1,n*sizeof(int));
    int idx=0;
    for(int i=0;i<e;i++){
        int u,v; scanf("%d %d",&u,&v);
        /* assume 0-based; if 1-based do u--,v--; */
        to[idx]=v; nxt[idx]=head[u]; head[u]=idx++;
        to[idx]=u; nxt[idx]=head[v]; head[v]=idx++;
    }

    int *color = malloc(n * sizeof(int));
    for(int i=0;i<n;i++) color[i] = -1;
    int *q = malloc(n * sizeof(int));

    for(int s=0;s<n;s++){
        if(color[s]!=-1) continue;
        int front=0, rear=0;
        color[s]=0; q[rear++]=s;
        while(front<rear){
            int u=q[front++];
            for(int ei=head[u]; ei!=-1; ei=nxt[ei]){
                int v=to[ei];
                if(color[v]==-1){ color[v]=1-color[u]; q[rear++]=v; }
                else if(color[v]==color[u]){ printf("NO\n"); return 0; }
            }
        }
    }
    printf("YES\n");
    return 0;
}
