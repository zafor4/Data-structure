#include<stdio.h>
struct student
{
    int age;
    int mark;
};

int main(){
    struct student s1,s2,s3;
    s1.age=20;
    s2.age=21;
    s3.age=22;
    s1.mark=33;
    s2.mark=34;
    s3.mark=35;
    printf("s1 age: %d",s1.age);
    return 0;
}