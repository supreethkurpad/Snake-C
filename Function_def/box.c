#include<stdio.h>
//Included Display Function just if required for any purpose.

void boxInit(int n, char p[n][n]){
    for(int i = 0; i<n; i++){    
        for(int j = 0; j<n; j++){
            if(j==n-1 || j==0)
                p[i][j] = '0';
            else
            {
                p[i][j] = ' ';
            }  
            if(i == 0 || i==n-1)
                p[i][j] = '0'; 
        }        
    }
}
void displayBox(int n, char p[n][n]){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            printf("%c",p[i][j]);
        }
        printf("\n");
    }
}

