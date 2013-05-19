#include <stdio.h>

char A[4][8];

int count(char k) {
    int ret = 0;
    for (int i = 0; i < 4 ;i++) 
        for (int j = 0; j < 4; j++)
            if (A[i][j] == k) ret++;
    return ret;
}

bool win(char k) {
    for (int i = 0; i < 4; i++) {
        bool flag = true;
        for (int j = 0; j < 4 ; j++) 
            if (A[i][j] !=k && A[i][j] != 'T') flag = false;
        if (flag) return true;
    }
    
    for (int i = 0; i < 4; i++) {
        bool flag = true;
        for (int j = 0; j < 4 ; j++) 
            if (A[j][i] !=k && A[j][i] != 'T') flag = false;
        if (flag) return true;
    }
    
    bool flag = true;
    for (int i = 0; i < 4 ; i++) 
        if (A[i][i] !=k && A[i][i] != 'T') flag = false;
    if (flag) return true;

    flag = true;
    for (int i = 0; i < 4 ; i++) 
        if (A[i][3 - i] !=k && A[i][3 - i] != 'T') flag = false;
    if (flag) return true;
    return false;
} 

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1 ; t <= T ;t ++) {
       for (int i = 0; i < 4; i++) {
          scanf("%s", A[i]);
       }
       
       printf("Case #%d: ", t);

       if (win('X'))printf("X won\n");
       else if (win('O')) printf("O won\n");
       else if (count('.') > 0) printf("Game has not completed\n");
       else printf("Draw\n"); 
    }
}
