/**********************************************************
 Statement - Print All ASCII Values
 Programmer - Vineet Choudhary
 Written For - http://developerinsider.in
 **********************************************************/

#include<stdio.h>

int main()
{
    int i = 0;
    
    for (i = 0; i < 256; i++)
    {
        printf("%d -> %c \n",i, i);
    }
    
    return 0;
}