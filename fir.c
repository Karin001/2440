#include<stdio.h>
#define A 1000000
#define B 600000
#define C 400000
#define D 200000
#define E 100000
int lirun(int price)
{
    float sum = 0;
    if(price>A)
    {
        sum = sum + (price-A)*0.01;
        price = A;
    }
    else if(price>B)
    {
        sum = sum + (price-B)*0.015;
        price =B;
    }
    else if(price>C)
    {
        sum = sum + (price-C)*0.03;
        price = C;
    }
     else if(price>D)
    {
        sum = sum + (price-D)*0.05;
        price = D;
    }
    else if(price>E)
    {
        sum = sum + (price-E)*0.075;
        price = E;
    }
     else
    {
        sum = sum + price*0.1;
    
    }
    return sum;
}
int main(void)
{
    int price;
    scanf("%d",&price);
    printf("%d",(int)lirun(price));
}