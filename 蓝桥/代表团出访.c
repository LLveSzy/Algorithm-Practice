#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	int d = 0;

    //a：可取最大个数的限定
    //k: 当前考虑位置
    //n: 目标名额
    //s: 已经决定的代表团成员 
    void fk(int*a,int num1, int k, int n, char *s,int num2)
    {
        if (k == num1){
            if (n == 0){
               printf("%s\n",s);
            	d++;	
			}            
            return;
        }
        char *s2 = malloc(sizeof(char)*num2);
        strcpy(s2, s);
		int i = 0; 
        for(i = 0; i <= a[k]; i++)
        {
            fk(a, num1, k + 1, n - i, s2, num2);
            
            char x=k + 'A';
            char arr[10] = { 0 };
            arr[0] = x;
            strcat(s2, arr);            
            num2++;
        }
    }

    void main()
    {
        int a[] = { 4, 2, 2, 1, 1, 3 };

        fk(a,6, 0, 5, "",0);
        printf("%d",d);
    }

