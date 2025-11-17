/* kmp.c - print indices of matches (0-based) */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void kmp(const char *t,const char *p){
    int n=strlen(t), m=strlen(p);
    if(m>n) return;
    int *lps = malloc(m * sizeof(int));
    lps[0]=0; for(int i=1,len=0;i<m;){
        if(p[i]==p[len]) lps[i++]=++len;
        else if(len) len=lps[len-1];
        else lps[i++]=0;
    }
    for(int i=0,j=0;i<n;){
        if(t[i]==p[j]){ i++; j++; if(j==m){ printf("%d\n", i-j); j=lps[j-1]; } }
        else if(j) j=lps[j-1];
        else i++;
    }
    free(lps);
}

int main(){
    static char T[2000001], P[2000001];
    if(scanf("%s %s", T, P)!=2) return 0;
    kmp(T,P);
    return 0;
}
