#include<stdio.h>
#include<stdlib.h>


typedef struct queue{
    struct queue* next ;
    int val , index ;
} ;

void swap(int *a , int *b){
    int temp = (*a) ^ (*b) ;
    *b = temp ^ ((*a) = (temp ^ (*a))) ;
}



int main(){
    int n ; scanf("%d",&n) ;
    int a[n] , b[n] ; for(int i = 0 ; i < n ; i ++) scanf("%d",a + i) ;
    for(int i = 0 ; i < n ; i ++) b[i] = *(a + i) ;
    struct queue* first[2][10] = {{NULL},{NULL}};
    struct queue* last[2][10] = {{NULL},{NULL}} ;
    for(int j = 0 ; j < n ; j ++){
        struct queue* temp = malloc(sizeof(struct queue)) ;
        temp -> next = NULL , temp -> val = b[j] , temp -> index = j ;
        int r = temp -> val % 10 ;
        struct queue* head = last[0][r] ;
        if(head == NULL) first[0][r] = temp , last[0][r] = temp ;
        else last[0][r] -> next = temp , last[0][r] = temp ;
        temp -> val = (temp -> val) / 10 ;
    }
    for(int i = 1 , k = 0 ; i < 10 ; i ++ , k ^= 1){
        for(int j = 0 , r , c = 0 ; j < 10 ; j ++ , c = 0){
            while(first[k][j] != NULL){
                r = first[k][j] -> val % 10 ;
                first[k][j] -> val = (first[k][j] -> val) / 10 ;
                if(last[k^1][r] == NULL) first[k^1][r] = first[k][j] , last[k^1][r] = first[k][j] ;
                else last[k^1][r] -> next = first[k][j] , last[k^1][r] = first[k][j] ;
                first[k][j] = first[k][j] -> next , last[k^1][r] -> next = NULL , c ++ ;
            }
            last[k][j] = NULL ;
        }
    }
    for(int i = 0 ; i < 10 ; i ++){
        struct queue* head = first[1][i] ;
        while(head != NULL) printf("%d,",a[head -> index]) , head = head -> next ;
    }
    return 0 ;
} 
