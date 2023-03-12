#ifndef LOSING__H
#define LOSING__H

int iamsostupid(char *buff,int spd);
int iamsostupidxy(char *buff,int y,int x,int spd);
int iamsostupidclean(int y,int x, int re,char fill,int spd);
int iamsostupidclean_arr(int y, int x, int v, int h,int re,char array[v][h], int spd);
void PrintInsideSquarexy(int v, int h, int x, int y, char array[v][h]);
void FocusInsideSquarexy(int v, int h, int y, int x, int Y, int X, int yy, int xx, char array[v][h]);
void DrawSquare(int y, int x, int Y, int X,int spd_en,int speed);
void Print(int v, int h, char array[v][h]);
void Fill(int v, int h, char array[v][h],char c);
void PrintInsideSquare(int v, int h, char map[v][h]);
void Copy(int v, int h, char source[v][h],char dest[v][h]);
void Focus(int v, int h, int V, int H, int y, int x,char array[v][h]);
void CopyLocation(int v, int h, int V, int H, int y, int x,char source[v][h], char dest[V][H]);
void FocusInsideSquare(int v, int h, int V, int H, int y, int x,char array[v][h]);
void puttext(int v, int h,char array[v][h], int y, int x,char *text);
void ffocus(int v, int h, int V, int H, int y, int x,char array[v][h]);
void pprint(int v, int h, char map[v][h]);

#endif
