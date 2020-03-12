//Function Definitions
void boxInit(int l,int b, char p[l][b]){
    for(int i = 0; i<l; i++){    
        for(int j = 0; j<b; j++){
            if(j==b-1 || j==0)
                p[i][j] = 'o';
            else
            {
                p[i][j] = ' ';
            }  
            if(i == 0 || i==l-1)
                p[i][j] = 'o'; 
        }        
    }
}
void displayBox(int l,int b, char p[l][b]){
    for(int i = 0; i<l; i++){
        for(int j = 0; j<b; j++){
            printf("%c",p[i][j]);
        }
        printf("\n");
    }
}

////main function if required for debugging
//void main(){
//	char p[50][100];
//	boxInit(50,100,p);
//	displayBox(50,100,p);
//}
