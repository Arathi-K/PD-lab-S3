#include <stdio.h>
#include <string.h>

int main()
{
    int len;
    char sentence[1000];

    scanf("%[^\n]%*c", sentence);
    len = strlen(sentence);

    for(int i=0;i<len;i++)
    {
        if(sentence[i] >= 'A' && sentence[i] <= 'Z')
            sentence[i] += 32;
        else if(sentence[i] >= 'a' && sentence[i] <= 'z')
            sentence[i] -= 32;
    }
    printf("%s",sentence);

    return 0;
}

