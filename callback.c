#include <stdio.h>
    int *p;
void cb(int *a)
{
    (*a)++;
}
void diaoyong(int *a, void (*cb)(int *))
{
    (*a)++;
    cb(a);
}
void (*hanshuzhizhen)(int *) = cb;
int *zhizhenhanshu(int k )
{

    *p = k;
    return p; 
}
int main(void)
{
    int a = 12;

    diaoyong(&a, hanshuzhizhen);
    printf("%d",*zhizhenhanshu(20));
    return 0;
}