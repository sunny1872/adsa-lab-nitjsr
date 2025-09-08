#include <stdio.h>
#include<stdlib.h>

struct btree{
    int val ;
    struct btree* left ;
    struct btree* right ;
};

typedef struct btree bt ;

bt* createnode(int v){
    bt* node = malloc(sizeof(bt)) ;
    *node = (bt){v , NULL , NULL} ;
    return node ;
}

int main()
{
    int n ; scanf("%d",&n) ;
    bt* a[n] ;
    bt* b[n] ;
    for(int i = 0 , x ; i < n ; i ++){
        scanf("%d",&x) ;
        a[i] = createnode(x) ;
        if(i > 0){
            bt* root = a[(i - 1) / 2] ;
            if(i&1) root -> left = a[i] ;
            else root -> right = a[i] ;
        }
    }
    int index = -1 ;
    b[++index] = a[0] ;
    while(index > -1){
        bt* root = b[index--] ;
        printf("%d,",root -> val) ;
        if(root -> right != NULL) b[++index] = root -> right ;
        if(root -> left != NULL) b[++index] = root -> left ;
    }
    return 0;
}
