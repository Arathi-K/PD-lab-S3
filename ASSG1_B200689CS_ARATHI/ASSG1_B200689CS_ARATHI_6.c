#include<stdio.h>

int gcd(int n1,int n2)
{
    if(n2==0)
        return n1;
    else if(n1>n2)
        return gcd(n2,n1%n2);
    else if(n2>n1)
        return gcd(n1,n2%n1);
    else if(n1==n2)
        return n1;
    return 0;
}

int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    if(a<0)
       a=a*-1;
    if (b<0)
        b=b*-1;
    printf("%d",gcd(a,b));
    
    return 0;
}
