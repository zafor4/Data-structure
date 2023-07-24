#include<stdio.h>
typedef struct student
{
int id;
int mark;
char fav_character;
char name[34];
} std;
int main(){
    std s1,s2;
    s1.id=56;
    printf("%d\n",s1.id);
    int* a,b;
    int c=10;
    a=&c;
    // b=&c;
    typedef int* pointers;
    pointers x,y;
    int d=20;
    x=&c;
    y=&d;
    return 0;
}