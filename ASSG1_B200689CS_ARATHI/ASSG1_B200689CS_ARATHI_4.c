#include <stdio.h>

int *CONVERT(int n)
{
    static int b[16],i;
    for(i=15;i>=0;i--)
    {
        b[i] = n%2;
        n = n/2;
    }
    for(i=0;i<16;i++)
        printf("%d",b[i]);
    printf("\n");

    return b;
}

int circularLeft(int *b, int k)
{
    int i, temp, x=0,bin[15];
    for(i=0;i<16;i++)
        bin[i] = b[i];

    temp = bin[0];
    while(x<k)
    {
        for(i=0;i<15;i++)
            bin[i] = bin[i+1];
        bin[i+1] = temp;
        x++;
    }

    for(i=0;i<16;i++)
        printf("%d",bin[i]);

    printf("\n");
    return 0;
}

int circularRight(int *b, int k)
{
    int i, temp, x, bin[15];
    for(i=0;i<16;i++)
        bin[i] = b[i];

    for(i=0;i<k;i++)
    {    
        x=15;
        temp = bin[15];
        while(x>0)
        {
            bin[x]=bin[x-1];
            x--;
        }
        bin[0]=temp;
    }
    for(i=0;i<16;i++)
        printf("%d",bin[i]);

    return 0;
}

int main()
{
    int n, k, *bin;

    scanf("%d %d",&n,&k);
    bin = CONVERT(n);
    circularLeft(bin, k);
    circularRight(bin, k);

    return 0;
}

