#include<stdio.h>

void shell_sort(int *a , int n){
    int b[n] ;
    for(int i = 0 ; i < n ; i ++) b[i] = *(a + i) ;
    for(int gap = n / 2 ; gap >= 1 ; gap >>= 1){
        for(int i = gap ; i < n ; i += gap){
            int j = i - gap , temp = b[i] ;
            while(j>=0 && b[j] > temp) b[j + gap] = b[j] , j -= gap ;
            b[j + gap] = temp ;
        }
    }
    printf("After shell_sort : ") ;
    for(int i = 0 ; i < n ; i ++) printf("%d,",b[i]) ;
    printf("\n") ;
}

int main(){
    int n ; scanf("%d",&n) ; int a[n] ;
    for(int i = 0 ; i < n ; i ++) scanf("%d" , a + i) ;
    shell_sort(a , n) ;
    return 0 ;
}
