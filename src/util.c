#ifdef __WIN32

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <ctype.h>
 
void gotoxy(int y, int x){	
	HANDLE pussy = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cock;
	cock.X = x;
	cock.Y = y;
	SetConsoleCursorPosition(pussy,cock);	
}

void ShowConsoleCursor(int showFlag){
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    GetConsoleCursorInfo(handle, &cci);
    cci.bVisible = showFlag;
    SetConsoleCursorInfo(handle, &cci);
}

#else

#include <stdio.h>
#include <termios.h>
#include <errno.h>
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <moon.h>
#include <ctype.h>

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

//////////////////

static struct termios old, new;

void initTermios(int echo) 
{
  tcgetattr(0, &old); 
  new = old; 
//  new.c_lflag &= ~ICANON;
  new.c_lflag &= (~ICANON & ~ECHO);
tcsetattr(STDIN_FILENO,TCSANOW,&new);
}

void resetTermios(void) 
{
	tcsetattr(STDIN_FILENO,TCSANOW,&old);
}

char getch_(int echo) 
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

void changemode(int dir)
{
  static struct termios oldt, newt;
 
  if ( dir == 1 )
  {
    tcgetattr( STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newt);
  }
  else
    tcsetattr( STDIN_FILENO, TCSANOW, &oldt);
}
 
int kbhit (void) 
{
  struct timeval tv;
  fd_set rdfs;
 
  tv.tv_sec = 0;
  tv.tv_usec = 0;
 
  FD_ZERO(&rdfs);
  FD_SET (STDIN_FILENO, &rdfs);
 
  select(STDIN_FILENO+1, &rdfs, NULL, NULL, &tv);

  return FD_ISSET(STDIN_FILENO, &rdfs);
}

int _kbhit(void)
{
//  struct termios oldt, newt;
  int ch;
  int oldf;
 				setbuf(stdin,NULL);
  tcgetattr(STDIN_FILENO, &old);
  new = old;
  new.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &new);
  oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
 
  ch = getchar();
 
  tcsetattr(STDIN_FILENO, TCSANOW, &old);
  fcntl(STDIN_FILENO, F_SETFL, oldf);
 
  if(ch != EOF)
  {
    ungetc(ch, stdin);
    return 1;
  }
 
  return 0;
}

char getch(void) 
{
  return getch_(0);
}

char getche(void) 
{
  return getch_(1);
}

int Sleep(long msec)
{
    struct timespec ts;
    int res;

    ts.tv_sec = msec / 1000;
    ts.tv_nsec = (msec % 1000) * 1000000;
	fflush(stdout);

    do {
        res = nanosleep(&ts, &ts);
    } while (res && errno == EINTR);

    return res;
}

void gotoxy(int y,int x)
{
    printf( "\033[%d;%df",y+1,x);
}

void ShowConsoleCursor(int showFlag){
	if(showFlag == 0){
	printf("\e[?25l");
	}
	if(showFlag == 1){
	printf("\e[?25h");
	}	
}

#endif




#define STR_VALUE(val) #val
#define STR(name) STR_VALUE(name)

#define PATH_LEN 256
#define MD5_LEN 32

int CalcFileMD5(char *file_name, char *md5_sum)
{
    #define MD5SUM_CMD_FMT "md5sum %." STR(PATH_LEN) "s 2>/dev/null"
    char cmd[PATH_LEN + sizeof (MD5SUM_CMD_FMT)];
    sprintf(cmd, MD5SUM_CMD_FMT, file_name);
    #undef MD5SUM_CMD_FMT

    FILE *p = popen(cmd, "r");
    if (p == NULL) return 0;

    int i, ch;
    for (i = 0; i < MD5_LEN && isxdigit(ch = fgetc(p)); i++) {
        *md5_sum++ = ch;
    }

    *md5_sum = '\0';
    pclose(p);
    return i == MD5_LEN;
}



char *input_letters(int quant, char buff[quant]){
	int i=0;
	char key;
	while(i<quant){
		key=getch();
		if(((key >= 97 && key <= 122) || (key >= 65 && key <= 90) || key == ' ') && i != quant-1){
			printf("%c",key);
			buff[i] = key;
			i++;
		}
		if(key == '\n'){
			buff[i+1] = '\0';
			return buff;
		}
		if(key == 127 && i>0){
			printf("\b \b");
			i--;
		}
	}
	return 0;
}

typedef struct{
	char key;
	int en;
	int tkill;
	int en_kp;
	char kp;
	int en_hit;
}kb_s;

void *RD_KB(void *arg){
	kb_s *kb = (kb_s*)arg;
	while(kb->tkill){
		while(kb->en){
			if(kb->key == kb->kp && kb->en_kp){
				kb->en=0;
			}
			if(_kbhit() && kb->en_hit)
			kb->key = getch();
		}
	}
	return 0;
}

void tau(){

	char *buff = (char *)malloc(sizeof(char) * 512);
	
	
	CalcFileMD5("coco.jpg", buff);
	
	char ccc[] = "099f5bbe4b9bd4c74969a23dc663e498";
	
	if((strcmp(ccc,buff))){
			int* p = NULL; 
			*p = 10;
			exit(-1);
	}
	else{
		free(buff);
	}
}

void init_sdl_mixer(){
	SDL_Init(SDL_INIT_AUDIO);
	Mix_Init(MIX_INIT_OGG);
	
	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1){
		printf("Mix_OpenAudio: %s\n", Mix_GetError());
		exit(1);
	}
}

void bg_sound(char *filename){
	Mix_Music *music = Mix_LoadMUS(filename);
	Mix_PlayMusic(music, -1);
}
