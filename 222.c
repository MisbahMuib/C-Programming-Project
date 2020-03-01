#include<stdio.h>

int main()
{
    int array[1000],i=0,j=0,total;
    int result,result1;
    double result2;

    while(scanf("%d",&array[i]) != EOF)
    {
        i++;
        j++;
    }

    if(j%2==1)
    {
        total=j/2;
       printf("%d",array[total]);
    }
else{


    result=j/2;
    result1=(array[result]+array[result-1]);

    result2=(double)result1/2;

    printf("%lf\n",result2);

    }










    return 0;
}

