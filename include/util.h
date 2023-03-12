#ifndef __UTIL_H
#define __UTIL_H
#include <SDL2/SDL_mixer.h>

#define clear() gotoxy(0,0)


typedef struct{
	char key;
	int en;
	int tkill;
	int en_kp;
	char kp;
	int en_hit;
}kb_s;

char *input_letters(int quant, char buff[quant]);
void *RD_KB(void *arg);
int CalcFileMD5(char *file_name, char *md5_sum);
void tau();
int kbhit(void);
int _kbhit(void);
char getch(void);
int Sleep(long msec);
void gotoxy(int y,int x);
void ShowConsoleCursor(int showFlag);

void bg_sound(char *filename);
void init_sdl_mixer();

#endif
