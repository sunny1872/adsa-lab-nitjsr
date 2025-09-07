#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
void push(int st1[],int *top,int x)
    {
    st1[++(*top)]=x;
}
void pop(int st1[],int st2[],int *top)
    {
    int top_2=-1,c;
    while(*top>=0)
        st2[++top_2]=st1[(*top)--];
    top_2--;
    while(top_2>=0)
        st1[++(*top)]=st2[top_2--];
}
int main() {
    int st1[100000],st2[100000],top=-1,q,x,ch;
    scanf("%d",&q);
    while(q--)
        {
        scanf("%d",&ch);
        switch(ch)
            {
            case 1:
            scanf("%d",&x);
            push(st1,&top,x);
            break;
            case 2:
            pop(st1,st2,&top);
            break;
            case 3:
            printf("%d\n",st1[0]);
            break;
        }
    }
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    return 0;
}
