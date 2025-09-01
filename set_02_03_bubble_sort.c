#include <stdio.h>

void swap(int *a , int *b){
    int temp = *a ;
    *a = *b ;
    *b = temp ;
}
void bubble_sort(int *a , int n){
    int b[n] ;
    for(int i = 0 ; i < n ; i ++) b[i] = *(a + i) ;
    for(int i = 0 ; i < n ; i ++){
        for(int j = 1 ; j < n - i ; j ++) if(b[j] < b[j - 1]) swap(b + j , b + j - 1) ;
    }
    printf("After bubble_sort : ") ;
    for(int i = 0 ; i < n ; i ++) printf("%d," , b[i]) ;
    printf("\n") ;
}

int main(){
    int n ; scanf("%d",&n) ; int a[n] ;
    for(int i = 0 ; i < n ; i ++) scanf("%d" , a + i) ;
    bubble_sort(a , n) ;
}
