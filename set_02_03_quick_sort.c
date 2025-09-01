#include<stdio.h>

void swap(int *a , int *b){
    int temp = *a ;
    *a = *b ;
    *b = temp ;
}

void quick_sort_op(int *b , int l , int r){
    if(l < r){
        int pivot = l ;
        int i = l , j = r ;
        while(i <= j){
            while(b[i] <= b[pivot]) i ++ ;
            while(b[j] > b[pivot]) j -- ;
            if(i < j) swap(b + i , b + j) , i ++ , j -- ;
        }
        //printf("%d %d\n",i,j) ;
        if(l < j) swap(b + l , b + j) ;
        quick_sort_op(b , l , j - 1) ;
        quick_sort_op(b , j + 1 , r) ;
    }
}

void quick_sort(int *a , int n){
    int b[n] ;
    for(int i = 0 ; i < n ; i ++) b[i] = *(a + i) ;
    quick_sort_op(b , 0 , n - 1) ;
    printf("After quick_sort : ") ;
    for(int i = 0 ; i < n ; i ++) printf("%d,",b[i]) ;
    printf("\n") ;
}

int main(){
    int n ; scanf("%d",&n) ; int a[n] ;
    for(int i = 0 ; i < n ; i ++) scanf("%d" , a + i) ;
    quick_sort(a , n) ;
    return 0 ;
}
