#ifndef PAIN__H
#define PAIN__H

#include <util.h>

typedef struct{
	int x;
	int y;
	int Y;
	int X;
	int v;
	int h;
	char *title;
	char *cont;
	int t_alineation;
	int line_space;
	int ts;
	int cs;
	int ts_en;
	int cs_en;
	int bs_en;
	int bs;
	int title_spell_en;
	int text_spell_en;
	int text_spell_range[2];
	int title_spell_range[2];
	int t_snd_en;
	int sq_snd_en[2];
	int c_snd_en;
	char *t_snd;
	char *c_snd;
	char *sq_snd[2];
}message_box;

typedef struct{
	int words;
	int len;
	int* wpos;
}text_struct;


typedef struct{
	char *who;
	char *text;
	char *title;
	int v;
	int h;
	int y;
	int x;
	int Y;
	int an_en;
	int al;
	
	int tits_peed;
	int text_speed;
	int sq_speed;
	
	char *t_buff;
	int ffre_tbuff;
	
	int txtspell_rd[2];
	int titspell_rd[2];
	
	char *tit_sound;
	char *txt_sound;
	
	char *sqr_sound[2];
}who_said;


void anal(char *buff,text_struct *tt);
void DrawMessageBox(message_box m);
void init_msb(message_box *m);
void who_said_init(who_said *EVI_27);
void put_message_box(kb_s *keyboard_handler,message_box *crossdress_phyxia, who_said florecita_dreams);

#endif
