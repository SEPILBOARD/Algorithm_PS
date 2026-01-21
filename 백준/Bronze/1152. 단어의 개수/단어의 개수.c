#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

char arr[1000001] = { 0, };

int main() {

    size_t end;
    int a = 0;

    gets(arr);

    end = strlen(arr);

    for (int i = 0; i < end; i++) {
        if (arr[i] == ' ') {
            a++;
        }
    } 
    a++;

    if (arr[0] == ' ') {
        a--;
    }
    if (arr[end - 1] == ' ') {
        a--;
    }
    printf("%d", a);

    return 0;
}