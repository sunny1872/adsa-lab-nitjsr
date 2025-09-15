/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include<stdlib.h>

struct list{
    int node , weight ;
    struct list* link ;
};

struct heap_node{
    int node , weight ;
} ;

typedef struct heap_node pair ;
typedef struct list lt ;

void heapify_up(int index , pair* heap){
    if(index > 0){
        int p_index = (index - 1) / 2 ;
        if(heap[p_index].weight > heap[index].weight){
            pair temp = heap[index] ;
            heap[index] = heap[p_index] ;
            heap[p_index] = temp ;
            heapify(p_index , heap) ;
        }
    }
}

void heapify_down(int index , int n , pair* heap){
    if(index <= n){
        int left = 2*index + 1 ;
        int right = 2*index + 2 ;
        if(left<=n and )
    }
    
}


int main()
{
    int no_of_nodes ; scanf("%d",&no_of_nodes) ;
    lt* adj[no_of_nodes] ;
    for(int i = 0 ; i < no_of_nodes ; i ++) adj[i] = NULL ;
    int no_of_edges ; scanf("%d",&no_of_edges) ;
    for(int i = 0 , u , v , w ; i < no_of_edges ; i ++){
        scanf("%d %d %d",&u,&v,&w) ;
        lt* p1 = {v , w , NULL} ;
        lt* p2 = {u , w , NULL} ;
        lt* root = adj[u] ;
        if(root == NULL) adj[u] = p1 ;
        else{
            while(root -> link != NULL) root = root -> link ;
            root -> link = p1 ;
        }
        lt* root = adj[v] ;
        if(root == NULL) adj[v] = p2 ;
        else{
            while(root -> link != NULL) root = root -> link ;
            root -> link = p2 ;
        }
    }
    int ans[no_of_nodes] ;
    for(int i = 0 ; i < no_of_nodes ; i ++) ans[i] = INT_MAX ;
    pair heap[no_of_nodes] ;
    int index = -1 ;
    heap[++index] = (pair){0 , 0} ;
    while(index > -1){
        pair p = heap[0] ;
        lt* root = adj[p.node] ;
        heap[0] = heap[index --] ;
        heapify_down(0 , index , heap) ;
        while(root != NULL){
            int new_weight = p.weight + root -> weight ;
            if(ans[p -> node] > new_weight){
                heap[++index] = (pair){p->node , new_weight} ;
                heapify_up(index , heap) ;
            }
        }
    }
    
    return 0;
}
