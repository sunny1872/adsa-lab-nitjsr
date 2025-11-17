/* graham.c - read n then n points (x y) ints; prints hull points in CCW */
#include <stdio.h>
#include <stdlib.h>

typedef long long ll;
typedef struct{ ll x,y; } P;
P *a;
int n;

ll cross(const P *o,const P *a,const P *b){ return (a->x - o->x)*(b->y - o->y) - (a->y - o->y)*(b->x - o->x); }

int cmp(const void *A,const void *B){
    P *p=(P*)A,*q=(P*)B;
    if(p->x!=q->x) return p->x < q->x ? -1:1;
    return p->y < q->y ? -1: (p->y>q->y);
}

int main(){
    if(scanf("%d",&n)!=1) return 0;
    a = malloc(n * sizeof(P));
    for(int i=0;i<n;i++) scanf("%lld %lld",&a[i].x,&a[i].y);
    if(n<3){ for(int i=0;i<n;i++) printf("%lld %lld\n", a[i].x, a[i].y); return 0; }
    qsort(a,n,sizeof(P),cmp);
    P *h = malloc((2*n) * sizeof(P));
    int k=0;
    for(int i=0;i<n;i++){
        while(k>=2 && cross(&h[k-2], &h[k-1], &a[i]) <= 0) k--;
        h[k++]=a[i];
    }
    for(int i=n-2, t=k+1;i>=0;i--){
        while(k>=t && cross(&h[k-2], &h[k-1], &a[i]) <= 0) k--;
        h[k++]=a[i];
    }
    // k-1 is number of distinct hull points, prints CCW starting from leftmost
    for(int i=0;i<k-1;i++) printf("%lld %lld\n", h[i].x, h[i].y);
    free(a); free(h);
    return 0;
}
