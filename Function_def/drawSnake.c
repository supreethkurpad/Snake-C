void drawSnake(int l, int b, char p[l][b], int snakePos[][2], int len){ 
    int head = 1;
    for(int i = 0; i<l; i++){
        for(int j = 0; j<b; j++){
            for(int n = 0; n<len; n++){
                if(i==snakePos[n][0] && j==snakePos[n][1]){
                    if(head){
                        p[i][j] = '@';
                        head = 0;
                    }
                    else
                    p[i][j] = '*';
                }
            }
        }
    }
}
