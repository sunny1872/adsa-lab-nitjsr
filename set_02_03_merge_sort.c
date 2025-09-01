#include<stdio.h>

void merge_sort(int *a , int n){
    int b[n] , c[n] ;
    for(int i = 0 ; i < n ; i ++) b[i] = *(a + i) ;
    for(int len = 1 ; len < n ; len <<= 1){
        for(int j = 0 ; j < n ; j += 2*len){
            int l = j , r = j + len , l_c = 0 , r_c = 0 , k = 0 ;
            while(l < n && r < n && l_c < len && r_c < len){
                if(b[r] < b[l]) c[k ++] = b[r ++] , r_c ++ ;
                else c[k ++] = b[l ++] , l_c ++ ;
            }
            while(l < n && l_c < len) c[k ++] = b[l ++] , l_c ++ ;
            while(r < n && r_c < len) c[k ++] = b[r ++] , r_c ++ ;
            k = j ; 
            int m = 0 ;
            while(k < n && m < 2*len) b[k ++] = c[m ++] ;
        }
    }
    printf("After merge_sort : ") ;
    for(int i = 0 ; i < n ; i ++) printf("%d,",b[i]) ;
    printf("\n") ;
}
int main(){
    int n ; scanf("%d",&n) ; int a[n] ;
    for(int i = 0 ; i < n ; i ++) scanf("%d" , a + i) ; 
    merge_sort(a , n) ;
    return 0 ;
}
