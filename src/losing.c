#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

#include <util.h>

//disp.h

extern pthread_mutex_t mutex;

int iamsostupid(char *buff,int spd){
	int i;
	for(i=0;i<strlen(buff);i++){
		pthread_mutex_lock(&mutex);
		printf("%c",buff[i]);
		Sleep(spd);
		pthread_mutex_unlock(&mutex);
	}
	return i;
}

int iamsostupidxy(char *buff,int y,int x,int spd){
	int i;
	for(i=0;i<strlen(buff);i++){
		pthread_mutex_lock(&mutex);
		gotoxy(y,x);
		printf("%c",buff[i]);
		x++;
		pthread_mutex_unlock(&mutex);
		Sleep(spd);
	}
	return i;
}

int iamsostupidclean(int y,int x, int re,char fill,int spd){
	int i;
	for(i=0;i<re;i++){
		pthread_mutex_lock(&mutex);
		gotoxy(y,x);
		printf("%c",fill);
		x++;
		pthread_mutex_unlock(&mutex);
		Sleep(spd);
	}
	return i;
}

int iamsostupidclean_arr(int y, int x, int v, int h,int re,char array[v][h], int spd){
	int i;
	for(i=0;i<re;i++){
		pthread_mutex_lock(&mutex);
		gotoxy(y,x);
		printf("%c",array[y][x+1]);
		//pending

		x++;
		pthread_mutex_unlock(&mutex);
		Sleep(spd);
	}
	return i;
}

void PrintInsideSquarexy(int v, int h, int x, int y, char array[v][h]){
	
	int i,j;
	
	for(i=y-1;i<v+y+1;i++){
		for(j=x-1;j<x+h+1;j++){
			
			if((i==y-1 || i==(v+y)) && (j==x-1 || j==(h+x))){
				gotoxy(i,j);
				printf("+");	
			}

			else if(i==y-1 || i==(v+y)){
				gotoxy(i,j);
				printf("-");
			}
			
			else if(j==x-1 || j==(h+x)){
				gotoxy(i,j);
				printf("|");
			}
			
			else{
				gotoxy(i,j);
				printf("%c",array[i-y][j-x]);
			//	printf(" ");
			
			}
		}
	}
}

void FocusInsideSquarexy(int v, int h, int y, int x, int Y, int X, int yy, int xx, char array[v][h]){
	int i,j;

	for(i=y-1;i<Y+y+1;i++){
		for(j=x-1;j<x+X+1;j++){
			
			if((i==y-1 || i==(Y+y)) && (j==x-1 || j==(X+x))){
				gotoxy(i,j);
				printf("+");	
			}

			else if(i==y-1 || i==(Y+y)){
				gotoxy(i,j);
				printf("-");
			}
			
			else if(j==x-1 || j==(X+x)){
				gotoxy(i,j);
				printf("|");
			}
			
			else{
				gotoxy(i,j);
				printf("%c",array[i-y+yy][j-x+xx]);
			}
		}
	}
}

void DrawSquare(int y, int x, int Y, int X,int spd_en,int speed){
		int i,j;
		for(i=y;i<Y;i++){
			for(j=x;j<X;j++){
				if(((i==y) || i==(Y-1)) && ((j==x) || j==(X-1))){
					gotoxy(i,j);
					printf("+");					
				}
				else if((i==y) || i==(Y-1)){
					gotoxy(i,j);
					printf("-");
				}
				else if((j==x) || j==(X-1)){
					gotoxy(i,j);
					printf("|");
				}
				else{
					gotoxy(i,j);
					printf(" ");
				}
			}
			if(spd_en)
				Sleep(speed);
		}
}

void Print(int v, int h, char array[v][h]){
	int i,j;
	for(i=0;i<v;i++){
		for(j=0;j<h;j++){
			printf("%c",array[v][h]);
		}	printf("\n");
	}
}

void Fill(int v, int h, char array[v][h],char c){
	int i,j;
	for(i=0;i<v;i++){
		for(j=0;j<h;j++){
			array[i][j] = c;
		}
	}
}

void PrintInsideSquare(int v, int h, char map[v][h]){
int i,j;
	for(i=-1;i<v+1;i++){
		for(j=-1;j<h+1;j++){
			
			if((i==-1 || i==v) && (j==-1 || j==h)){
				gotoxy(i+1,j+2);
				printf("+");
			}
			else if(i==-1 || i==v){
			gotoxy(i+1,j+2);
				printf("-");
			}
			else if(j==-1 || j==h){
			gotoxy(i+1,j+2);
				printf("|");
			}
			else{
			gotoxy(i+1,j+2);
			printf("%c",map[i][j]);
			}
		}
	}
}

void Copy(int v, int h, char source[v][h],char dest[v][h])
{
	int i,j;
	for(i=0;i<v;i++){
		for(j=0;j<h;j++){
			dest[i][j] = source[i][j];
		}
	}
}

void Focus(int v, int h, int V, int H, int y, int x,char array[v][h]){
	if(H>h || V>v){
		printf("LocateArray: Output size too big.");
		exit(-1);
	}
	
	int i,j;
	for(i=y;i<V+y;i++){
		for(j=x;j<H+x;j++){
			printf("%c",array[i][j]);
		}	printf("\n");
	}
}

void CopyLocation(int v, int h, int V, int H, int y, int x,char source[v][h], char dest[V][H])
								{
  int i,j;
	for(i=y;i<y+V;i++){
	 	for(j=x;j<x+H;j++){
	 	  dest[i-y][j-x] = source[i][j];
		}
	 }
}

void FocusInsideSquare(int v, int h, int V, int H, int y, int x,char array[v][h]){
		
	if(H>h || V>v){
		printf("LocateArray: Output size too big.");
		exit(-1);
	}

	int i,j;
	for(i=y-1;i<V+y+1;i++){
		for(j=x-1;j<x+H+1;j++){
			
			if((i==y-1 || i==y+V) && (j==x-1 || j==H+x)){
				gotoxy(i-y+1,j-x+2);
				printf("+");
			}
			else if(i==y-1 || i==y+V){
			gotoxy(i-y+1,j-x+2);
				printf("-");
			}
			else if(j==x-1 || j==H+x){
			gotoxy(i-y+1,j-x+2);
				printf("|");
			}
			else{
			gotoxy(i-y+1,j-x+2);
			printf("%c",array[i][j]);
			}
		}
	}
}

void puttext(int v, int h,char array[v][h], int y, int x,char *text){
		int i,j=0;
		for(i=x;i<strlen(text)+x;i++){
			array[y][i]=text[j];
			j++;
		}
}

void ffocus(int v, int h, int V, int H, int y, int x,char array[v][h]){
	FocusInsideSquare(v,h,V,H,y,x,array);
}

void pprint(int v, int h, char map[v][h]){
	PrintInsideSquare(v,h,map);
}


