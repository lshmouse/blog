#include <stdio.h>
#include <string.h>
#include <math.h>

int x, y, k;
char grid[32][32];
bool flag[32][32];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dfs(int x1, int y1, char color) {
  if (x1 < 0 || x1 >= x) return 0;
  if (y1 < 0 || y1 >= y) return 0;
  
  if (grid[x1][y1] != color) return 0;
  if (flag[x1][y1]) return 0;

  flag[x1][y1] = true;

  int ret = 1;

  for (int i= 0; i < 4; i++) {
    int x2 = x1 + dx[i];
    int y2 = y1 + dy[i];
    ret += dfs(x2, y2, color);
  }
  return ret;
}

/* Head ends here */
void nextMove(int x, int y, int color){
  for (int i = 0; i < x; i++)
    for (int j = 0; j < y; j++) flag[i][j] = false;
  
  int maxScore = -1;
  int x1 = -1, y1 = -1;

  for (int i = 0; i < x; i ++)
    for (int j = 0; j < y; j++) if(grid[i][j] != '-' && flag[i][j] == false){
      int score = dfs(i, j, grid[i][j]);
      if (score > maxScore) {
        maxScore = score;
        x1 = i;
        y1 = j;
      }
    }
  if (maxScore > 1) 
    printf("%d %d\n", x1, y1);
}

/* Tail starts here */
int main() {
    scanf("%d %d %d", &x, &y, &k);
    for( int i=0; i<x; i++) {
        scanf("%s", grid[i]);
        
    }
    nextMove( x, y, k);
    return 0;
}
