#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int ans = 0;
char str[1000001];

int main()
{
	// fgets(str, sizeof(str), stdin);
	gets(str);

    size_t n = strlen(str);
    int wasblank = 1;

    for(int i = 0; i<n; i++){
        if(str[i] == ' '){
            wasblank = 1;
        }
        else{
            if(wasblank){
                ans++;
            }
            wasblank = 0;
        }
    }
    printf("%d", ans);
	return 0;
}