#include<stdio.h>
#include<stdlib.h>

int main()
{
    FILE *fp;
    fp = fopen("numbers.txt", "w");
    int a;
    char ch = 'y';
    while(ch == 'y')
    {
        printf("Enter the number\n");     
        scanf("%d", &a);
        fprintf(fp, "%d ", a);
        printf("Do you want to continue?");
        fflush(stdin);
        scanf("%c", &ch);    //doesn't work at all
    }
    fclose(fp);
    return 0;
}
