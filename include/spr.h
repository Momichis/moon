#ifndef LONELINESS__H
#define LONELINESS__H

typedef struct{
	int x;
	int y;
	int n;
	int speed;
	char C;
	char c;
}m_cstruct;

typedef struct{
	int x;
	int y;
	int h;
	int v;
	char ***sprites;
	int sp_quant;
	int speed;
	int a_en;
}obj_sprite;

void *m_cfunction(void *arg);
void *animate_object(void *arg);
void free_spr(int y, int x,char ***spr);

char ***srmomichi_d(void);
char ***mooni_d(void);

#define srmomichi_sprcount 3
#define srmomichi_v 7
#define srmomichi_h 3
#endif
