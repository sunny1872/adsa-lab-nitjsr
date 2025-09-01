#include<stdio.h>

void heapify(int *b , int index , int n){
    if(index >= n) return ;
    int min_index = index ;
    if(b[min_index] > b[2*index + 1]) min_index = 2*index + 1 ;
    if(b[min_index] > b[2*index + 2]) min_index = 2*index + 2 ;
    if(min_index != index){
        swap(b + index , b + min_index) ;
        heapify(b , min_index , n) ;
    }
}

void heap_sort(int *a , int n){
    int b[n] ;
    for(int i = 0 ; i < n ; i ++) b[i] = *(a + i) ;
    for(int i = n / 2 - 1 ; i >= 0 ; i --) heapify(b , i , n) ;
    printf("After heap_sort : ") ;
    for(int i = 0 ; i < n ; i ++) printf("%d,",b[i]) ;
    printf("\n") ;
    for(int i = n - 1 ; i >= 0 ; i --){
        printf("%d,",b[0]) ;
        b[0] = b[i] ;
        heapify(b , 0 , i) ;
    }
}

int main(){
    int n ; scanf("%d",&n) ; int a[n] ;
    for(int i = 0 ; i < n ; i ++) scanf("%d" , a + i) ;
    heap_sort(a , n) ;
    return 0 ;
}
