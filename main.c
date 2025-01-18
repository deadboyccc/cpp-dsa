#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <stdlib.h>
#include <ctype.h>
struct Rectangle
{
    int x;
    int y;
};
typedef union registers
{
    int i;
    float f;
    char c;
    char str[20];
} registers;
char *return_ptr(char *ptr, size_t n)
{
    // to lower
    for (int i = 0; i < n; i++)
    {
        ptr[i] = tolower(ptr[i]);
    }

    return ptr;
}
void print_array(char *ptr)
{
    printf("%c", *ptr);
    // int i = 0;
    // while(ptr[i]!= '\0'){
    //     printf("%c", ptr[i]);
    //     i++;
    // }
    // printf("\n"); c++ => c => Rust
}
int main(int argc, char const *argv[])
{

    // double temp = 2.223;
    // printf("%12.2lf ", temp);
    // registers a;
    // strcpy(a.str,"hello world!");
    // printf("%s \n", a.str);
    // int *ptr = (int *)malloc(sizeof(int));
    // *ptr = 10;
    // printf("%d \n", *ptr);
    // printf("%p \n", ptr);
    // char *chtr = (char *)malloc(sizeof(char));
    // // relocate to have 3 size of int
    // ptr = realloc(ptr, 20 * sizeof(int));
    // for (int i = 0; i < 20; i++)
    // {
    //     *(ptr + i) = i + 1;
    // }
    // // print all array values in ptr pointer
    // for (int i = 0; i < 20; i++)
    // {
    //     printf("%d \n", *(ptr + i));
    // }
    // printf("%p \n", ptr);
    // free(ptr);
    // free(chtr);

    // char b[] = "hello!";
    // char l[1000];
    // printf("%d ", sizeof(a));
    // printf("%d ", sizeof(b));
    // printf("%d ", sizeof(l));
    // printf("%s", a);
    // char *t = (char *)malloc(sizeof(3));
    // t[0] = 'a';
    // t[1] = 'b';
    // t[2] = '\0';
    // printf("%s \n", t);
    // printf("%p \n", t);
    // char c[100];
    // *c=*(return_ptr(a,5));
    // print_array(c);
    // printf("%s \n",c);

    // free(t);

    // printf("%p \n", t);
    // t = NULL;
    // printf("%s \n", t);

    // 00000000 00000000 00000000 00000000
    // 00000000 00000000 00000000 00000001 ==1
    // 00000000 00000000 00000000 00000010 ==2
    // 00000000 00000000 00000000 00000011 ==2
    //? CJ sam3 b vim ? i'm using it :3
    // no mouse just keyboard
    typedef struct Rectangle
    {
        int a;
        int b;
    } Rectangle;

    typedef enum
    {
        RED,
        GREEN,
        BLUE
    } RGBcolors;
    RGBcolors test = BLUE;
    Rectangle test2 = {10, 20};
    printf("%d \n", test2.a);
    printf("%d \n", test2.b);
    printf("%d \n", test);
    RGBcolors test4 = GREEN;
    printf("%d \n", test4);
    return 0;
}
