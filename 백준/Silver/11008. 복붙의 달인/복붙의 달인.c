#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>


int main()
{
	char arr[10001];
	char brr[101];
	int n,count=0;
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%s %s", arr, brr);
        
        int ans = 0;
		for(int j = 0; j < strlen(arr); j++){
            // printf("%d\n", j);
			if(arr[j] == brr[0]){
				for(int k = 0; k < strlen(brr); k++){
                    if(j+k >= strlen(arr)){
                        break;
                    }
					if(arr[j+k] != brr[k]){
						break;
					}
					else{
						count++;	
					}
				}

                ans += count/strlen(brr);
                j += count -1;
                count = 0;
			}
		}
		printf("%d\n", strlen(arr) - strlen(brr) * ans + ans);
		ans = 0;
	}
	return 0;
}