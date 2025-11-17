/* rabin_karp.c - print 0-based start indices of matches */
#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define BASE 256
#define MOD 1000000007

void rabin_karp(const char *t, const char *p){
    int n=strlen(t), m=strlen(p);
    if(m>n) return;
    int64_t ph=0, th=0, power=1;
    for(int i=0;i<m;i++){ ph=(ph*BASE + (unsigned char)p[i])%MOD; th=(th*BASE + (unsigned char)t[i])%MOD; if(i) power=(power*BASE)%MOD; }
    for(int i=0;i+ m <= n;i++){
        if(ph==th){
            if(strncmp(t+i,p,m)==0) printf("%d\n", i);
        }
        if(i+ m < n){
            th = (th - (unsigned char)t[i]*power)%MOD;
            if(th<0) th+=MOD;
            th = (th*BASE + (unsigned char)t[i+m])%MOD;
        }
    }
}

int main(){
    static char T[2000001], P[2000001];
    if(scanf("%s %s", T, P)!=2) return 0;
    rabin_karp(T,P);
    return 0;
}
