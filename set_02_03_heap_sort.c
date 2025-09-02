void swap(int *a , int *b){
    int temp = (*a) ^ (*b) ;
    *b = temp ^ ((*a) = (temp ^ (*a))) ;
}

void heapify(int *b , int index , int n){
    if(index >= n) return ;
    int min_index = index , l = 2*index + 1 , r = 2*index + 2 ;
    if(l < n && b[min_index] > b[l]) min_index = l ;
    if(r < n && b[min_index] > b[r]) min_index = r ;
    if(min_index != index){
        swap(b + min_index , b + index) ;
        heapify(b , min_index , n) ;
    }
}

void heap_sort(int *a , int n){
    int b[n] ;
    for(int i = 0 ; i < n ; i ++) b[i] = *(a + i) ;
    for(int i = n / 2 - 1 ; i >= 0 ; i --){
        heapify(b , i , n) ;
        for(int i = 0 ; i < n ; i ++) printf("%d,",b[i]) ;
        printf("\n") ;
    }
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
    int n ; scanf("%d",&n) ;
    int a[n] ; for(int i = 0 ; i < n ; i ++) scanf("%d",a + i) ;
    heap_sort(a , n) ;
    return 0 ;
}
