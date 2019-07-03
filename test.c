#include<stdio.h>
struct students{
    char number[10];
    char name[10];
    unsigned char rerult[3];
};
unsigned char shuliang;
struct students data[100];
void input(unsigned char n){
    unsigned char k;
    for(k=0; k<n; k++){
        scanf(
            "%s %s %d %d %d",
            (data[k].number),
            (data[k].name),
            &(data[k].rerult[0]),
            &(data[k].rerult[1]),
            &(data[k].rerult[2])
            );
    };

   
}
void print(unsigned char n){
    unsigned char k;
    for(k=0; k<n; k++){
        printf( 
            "%s,%s,%d,%d,%d\2n",
            (data[k].number),
            (data[k].name),
            (data[k].rerult[0]),
            (data[k].rerult[1]),
            (data[k].rerult[2])
            );
    };
}
int main(void){

    scanf("%d",&shuliang);
    input(shuliang);
    print(shuliang);
    return 0;
}