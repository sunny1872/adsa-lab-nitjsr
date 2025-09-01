#include <stdio.h>

void insertion_sort(int *a , int n){
    int b[n] ;
    for(int i = 0 ; i < n ; i ++) b[i] = *(a + i) ;
    for(int i = 1 ; i < n ; i ++){
        int temp = b[i] , j = i - 1 ;
        while(j >= 0 && b[j] > temp) b[j + 1] = b[j] , j -- ;
        b[j + 1] = temp ;
    }
    printf("After insertion_sort : ") ;
    for(int i = 0 ; i < n ; i ++) printf("%d,",b[i]) ;
    printf("\n") ;
}

int main(){
    int n ; scanf("%d",&n) ; int a[n] ;
    for(int i = 0 ; i < n ; i ++) scanf("%d" , a + i) ;
    insertion_sort(a , n) ;
}
