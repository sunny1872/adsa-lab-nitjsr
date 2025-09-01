#include <stdio.h>

void selection_sort(int *a , int n){
    int b[n] ; for(int i = 0 ; i < n ; i ++) b[i] = *(a + i) ;
    for(int i = 0 ; i < n ; i ++){
        for(int j = i ; j < n ; j ++){
            if(b[j] < b[i]) swap(b + j , b + i) ;
        }
    }
    printf("After selection_sort : ") ;
    for(int i = 0 ; i < n ; i ++) printf("%d,",b[i]) ;
    printf("\n") ;
}

int main(){
    int n ; scanf("%d",&n) ; int a[n] ;
    for(int i = 0 ; i < n ; i ++) scanf("%d" , a + i) ;
    selection_sort(a , n) ;
}
