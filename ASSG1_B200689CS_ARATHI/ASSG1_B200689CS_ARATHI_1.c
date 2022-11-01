#include <stdio.h>
#include <math.h>

int main()
{
    int n, dec=0, i=0;

    scanf("%d",&n);
    while(n>0)
    {
        dec = dec + ((n%10) * pow(8,i));
        n = n/10;
        i++;
    }
    printf("%d",dec);

    return 0;
}
