    #include<stdio.h>  
    #include<math.h>  
    int map[3][6];  
    int flag[15];  
    int sum=0;  
    int flag1=0;  
    int check()  
    {  
        int i,j;  
        for(i=0;i<2;i++)  
            for(j=0;j<5;j++)  
        {  
        if((map[i][j]>map[i][j+1]) || (map[i][j]>map[i+1][j]))  
            return 0;  
        }  
        return 1;  
    }  
    void dfs(int count)  
    {  
        int i,j;  
        if (count==10)  
        {  
            if(check())  
            {  
                for(i=0;i<2;i++)  
                {  
                for(j=0;j<5;j++)  
                printf("%d ",map[i][j]);  
            printf("\n");  
                }  
                printf("\n");  
            sum++;  
            }  
            return;  
        }  
        {  
            for(i=1;i<=10;i++)  
            {  
                if(!flag[i])  
                {  
                    flag[i]=1;  
                    map[count/5][count%5]=i;  
                    dfs(count+1);  
                    flag[i]=0;  
                }  
            }  
        }  
    }  
    int main ()  
    {  
        int i;  
        map[0][5]=map[1][5]=100;  
        for(i=0;i<5;i++)  
            map[2][i]=100;  
      
        dfs(0);  
        printf("%d\n",sum);  
        return 0;  
    }  
