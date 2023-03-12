#ifndef __FLORECITA

#define __FLORECITA	

#define   FREE 0
#define   ASS  1

#define __ODSY 1
#define __ODSX 2


typedef struct{
	int x;
	int y;
	int prev_x;
	int prev_y;
	int n;
	char C;
	char c;
	int spd;
}lo_que_le_paso_al_nino_en_el_infierno;

typedef struct{
	lo_que_le_paso_al_nino_en_el_infierno *main;
	lo_que_le_paso_al_nino_en_el_infierno attr;

	int rx;
	int rX;
	int ry;
	int rY;
	int mode;

	int mode2speed;
	int mode2_x_en;
	int mode2_y_en;

	int mode2_rx;
	int mode2_ry;

	int mode2_rX;
	int mode2_rY;

	int mode2_x_inc;
	int mode2_y_inc;

	int mode1_speed;

	int onion;
	int v;
	int h;

	char **mapp;
}adrenocromo_s;


void * m_c(void *arg);
void carta_de_la_virgen(adrenocromo_s *recuerdos_maternales, char el_perro_que_viajo_al_limbo[recuerdos_maternales->v][recuerdos_maternales->h],int tributo_a_florecita_dreams);
void * unicornio_rosa_invisible(void *arg);
void * magic_madness_and_sadness(void *arg);
void testing_npc();



#endif
