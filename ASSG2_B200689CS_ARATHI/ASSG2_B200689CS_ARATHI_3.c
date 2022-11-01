#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int i,j=0,len1,len2,temp,k=0,m=0,count,present=0;
    char string1[1000],string2[1000];
    scanf("%s",string1);
    scanf("%s",string2);
    len1=strlen(string1);
    len2=strlen(string2);
    int*new_arr=(int*)malloc(len1*sizeof(int));
    for(i=0;i<len1;i++)
    {	
		j=0;
	    if(string1[i]==string2[j])
	    {
		   temp=i+1;count=1;j++;
		   for(;j<len2;j++)
             {   
				 if(string1[temp]==string2[j])
				 {
					 temp++;
					 count++;
				 }
			 }
		   if(count==len2)
		   {
			   for(k=i;k<i+len2;k++,m++)
                  new_arr[m]=k;
		 	}
		}
	}
	for(i=0;i<len1;i++)
	{
		present = 0;
		for(j=0;j<m;j++)
		{
			if(i == new_arr[j])
				present=1;
		}
		if(present==0)
			printf("%c",string1[i]);
	}

	return 0;
}

              
