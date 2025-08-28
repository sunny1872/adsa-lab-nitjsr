#include<stdio.h>
int main(){
    int row , coloumn ;
    scanf("%d %d",&row,&coloumn) ;
    int a[row][coloumn];
    for(int i = 0 ; i < row ; i ++){
        for(int j = 0 ; j < coloumn ; j ++) a[i][j] = 0 ;
    }
    for(int i = 0 ; i < row ; i ++){
        for(int j = 0 ; j < coloumn ; j ++) scanf("%d",(*(a + i) + j)) ;
    }
    for(int i = 0 ; i < row ; i ++){
        for(int j = 0 ; j < coloumn ; j ++) printf("%d,",a[i][j]) ;
        printf("\n") ;
    }
    return 0;
}
