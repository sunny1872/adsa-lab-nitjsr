/* bmh.c - Boyer-Moore-Horspool: print indices of matches */
#include <stdio.h>
#include <string.h>

void bmh(const char *t,const char *p){
    int n=strlen(t), m=strlen(p);
    if(m>n) return;
    int shift[256]; for(int i=0;i<256;i++) shift[i]=m;
    for(int i=0;i<m-1;i++) shift[(unsigned char)p[i]] = m-1-i;
    int i=0;
    while(i<=n-m){
        int j=m-1;
        while(j>=0 && p[j]==t[i+j]) j--;
        if(j<0){ printf("%d\n", i); i+=shift[(unsigned char)t[i+m-1]]; }
        else i += shift[(unsigned char)t[i+m-1]];
    }
}

int main(){
    static char T[2000001], P[2000001];
    if(scanf("%s %s", T, P)!=2) return 0;
    bmh(T,P);
    return 0;
}
