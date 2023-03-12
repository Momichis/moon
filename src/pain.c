#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#include <util.h>
#include <disp.h>

//msg.h

extern pthread_mutex_t mutex;


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

void anal(char *buff,text_struct *tt){
	tt->len = strlen(buff);
	tt->words = 1;
	int i;
	
	for(i=0;i<tt->len;i++){
		if(buff[i] == ' ' && i>1){
			++tt->words;
		}
	}
	tt->wpos = (int *)malloc(sizeof(int) * (tt->words + 2));
		if(tt->wpos == NULL){
			printf("Error allocating memory.");
			exit(1);
		}
	
	int j=1;
	
	tt->wpos[0] = 0;
	tt->wpos[tt->words] = tt->len;

	for(i=0;i<tt->len;i++){
		if(buff[i] == ' ' && i>1){
			tt->wpos[j] = i;
			j++;
		}
	}
}

void DrawMessageBox(message_box m){

	Mix_Chunk *sound = Mix_LoadWAV(m.sq_snd[0]);
	//printing square
	int i,j=0;
	
	if(m.sq_snd_en[0]){
		sound = Mix_LoadWAV(m.sq_snd[0]);
		Mix_PlayChannel(0, sound, 0);

	}
		
		for(i=m.y;i<m.Y;i++){
			for(j=m.x;j<m.X;j++){
				if(((i==m.y) || i==(m.Y-1)) && ((j==m.x) || j==(m.X-1))){
				   pthread_mutex_lock(&mutex);
					gotoxy(i,j);
					printf("+");				
				   pthread_mutex_unlock(&mutex);	
				}
				else if((i==m.y) || i==(m.Y-1)){
					pthread_mutex_lock(&mutex);
					gotoxy(i,j);
					printf("-");
					pthread_mutex_unlock(&mutex);
				}
				else if((j==m.x) || j==(m.X-1)){
					pthread_mutex_lock(&mutex);
					gotoxy(i,j);
					printf("|");
					pthread_mutex_unlock(&mutex);
				}
				else{
					pthread_mutex_lock(&mutex);
					gotoxy(i,j);
					printf(" ");
					pthread_mutex_unlock(&mutex);
				}
				
			}

//			if(m.sq_snd_en[0]) Mix_PlayChannel(0, sound, 0);
			if(m.bs_en) Sleep(m.bs);
		}
			
			if(m.sq_snd_en[1]){
				sound = Mix_LoadWAV(m.sq_snd[1]);
				Mix_PlayChannel(0, sound, 0);
				Sleep(400);
			}
			
//printing title

	if(m.t_snd_en){
		 sound = Mix_LoadWAV(m.t_snd);
	}

	text_struct title;
	anal(m.title,&title);

	if(title.len > m.X - m.x){
		if(m.t_alineation == 0){
			for(i=title.words;i>0;i--){
				if(title.wpos[i] < (m.X-m.x)-2){
					j=title.wpos[i];
					i=-1;
				}
			}
			

			for(i=0;i<j;i++){
				
				pthread_mutex_lock(&mutex);	
				gotoxy(m.y+1,i+(m.x+((m.X-m.x)/2)-j/2));
				printf("%c",m.title[i]);
				if(m.t_snd_en) Mix_PlayChannel(0, sound, 0);
				pthread_mutex_unlock(&mutex);
				
				if(m.title_spell_en && m.title[i] == ' '){
					Sleep(m.title_spell_range[0] + (rand() % m.title_spell_range[1]));
				}

				if(m.ts_en) Sleep(m.ts);
			}

			for(i=j;i<title.len;i++){

				pthread_mutex_lock(&mutex);	
				gotoxy(m.y+2,(i-j)+(m.x+((m.X-m.x)/2)-(title.len - j)/2));
				printf("%c",m.title[i]);
				if(m.t_snd_en) Mix_PlayChannel(0, sound, 0);
				pthread_mutex_unlock(&mutex);	

				if(m.title_spell_en && m.title[i] == ' '){
					Sleep(m.title_spell_range[0] + (rand() % m.title_spell_range[1]));
				}

				if(m.ts_en) Sleep(m.ts);
			
			}
		}
		
		else if(m.t_alineation == 1){
			for(i=title.words;i>0;i--){
				if(title.wpos[i] < (m.X-m.x)-2){
					j=title.wpos[i];
					i=-1;
				}
			}
			for(i=0;i<j;i++){
				
				pthread_mutex_lock(&mutex);		
				gotoxy(m.y+1,m.x+2);
				printf("%c",m.title[i]);
				if(m.t_snd_en) Mix_PlayChannel(0, sound, 0);
				pthread_mutex_unlock(&mutex);	

				if(m.title_spell_en && m.title[i] == ' '){
					Sleep(m.title_spell_range[0] + (rand() % m.title_spell_range[1]));
				}


				if(m.ts_en) Sleep(m.ts);
			}


			int pene = 0;

			for(i=j;i<title.len;i++){
				if(!(m.title[i]==' ' && i==j)){
					pthread_mutex_lock(&mutex);						
					gotoxy(m.y+2,pene+(m.x+2));
					printf("%c",m.title[i]);
					if(m.t_snd_en) Mix_PlayChannel(0, sound, 0);
					pthread_mutex_unlock(&mutex);						
					++pene;
				}
				
					if(m.title_spell_en && m.title[i] == ' '){
						Sleep(m.title_spell_range[0] + (rand() % m.title_spell_range[1]));
					}

					if(m.ts_en) Sleep(m.ts);
			}
		
		}
		else if(m.t_alineation == 2){
			for(i=title.words;i>0;i--){
				if(title.wpos[i] < (m.X-m.x)-2){
					j=title.wpos[i];
					i=-1;
				}
			}
			for(i=0;i<j;i++){
				pthread_mutex_lock(&mutex);						
				gotoxy(m.y+1,i+((m.X-2)-j));
				printf("%c",m.title[i]);
				if(m.t_snd_en) Mix_PlayChannel(0, sound, 0);
				pthread_mutex_unlock(&mutex);						

				if(m.title_spell_en && m.title[i] == ' '){
					Sleep(m.title_spell_range[0] + (rand() % m.title_spell_range[1]));
				}

				if(m.ts_en) Sleep(m.ts);
			}

			for(i=j;i<title.len;i++){
				pthread_mutex_lock(&mutex);										
				gotoxy(m.y+2,(i-j)+((m.X-2)-(title.len-j))); //
				printf("%c",m.title[i]);
				if(m.t_snd_en) Mix_PlayChannel(0, sound, 0);
				pthread_mutex_unlock(&mutex);						

				if(m.title_spell_en && m.title[i] == ' '){
					Sleep(m.title_spell_range[0] + (rand() % m.title_spell_range[1]));
				}

				if(m.ts_en) Sleep(m.ts);
			}
		}
		if(m.line_space >= 2)
			m.line_space++;
	}else{
		if(m.t_alineation == 0){
				if(m.ts_en){
				
//					iamsostupid(m.title,m.ts); //-___-
					for(int i=0;i<strlen(m.title);i++){
						pthread_mutex_lock(&mutex);						
						gotoxy(m.y+1,(m.x+((m.X-m.x)/2)-title.len/2) + i);
						printf("%c",m.title[i]);
						if(m.t_snd_en) Mix_PlayChannel(0, sound, 0);
						pthread_mutex_unlock(&mutex);						
						
						if(m.title_spell_en && m.title[i] == ' '){
							Sleep(m.title_spell_range[0] + (rand() % m.title_spell_range[1]));
						}
						
						Sleep(m.ts);
					}//
					
				}
				else{
					pthread_mutex_lock(&mutex);						
					printf("%s",m.title);
					pthread_mutex_unlock(&mutex);						
					}
		}
		else if(m.t_alineation == 1){
				if(m.ts_en){
//					iamsostupidxy(m.title,m.y+1,m.X-title.len-2,m.ts);
					
					for(int i=0;i<strlen(m.title);i++){
						pthread_mutex_lock(&mutex);						
						gotoxy(m.y+1,(m.X-title.len-2) + i);
						printf("%c",m.title[i]);
						if(m.t_snd_en) Mix_PlayChannel(0, sound, 0);
						pthread_mutex_unlock(&mutex);						
						
						if(m.title_spell_en && m.title[i] == ' '){
							Sleep(m.title_spell_range[0] + (rand() % m.title_spell_range[1]));
						}
						
						Sleep(m.ts);
					}//


				}
	
				else{
					pthread_mutex_lock(&mutex);						
					gotoxy(m.y+1,m.X-title.len-2);
					printf("%s",m.title);
					if(m.t_snd_en) Mix_PlayChannel(0, sound, 0);
					pthread_mutex_unlock(&mutex);
					}						
		}
		else if(m.t_alineation == 2){
				if(m.ts_en){
//					iamsostupidxy(m.title,m.y+1,m.x+2,m.ts);

					for(int i=0;i<strlen(m.title);i++){//
						pthread_mutex_lock(&mutex);						
						gotoxy(m.y+1,(m.x+2) + i);
						printf("%c",m.title[i]);
						if(m.t_snd_en) Mix_PlayChannel(0, sound, 0);
						pthread_mutex_unlock(&mutex);						
						
						if(m.title_spell_en && m.title[i] == ' '){
							Sleep(m.title_spell_range[0] + (rand() % m.title_spell_range[1]));
						}
						
						Sleep(m.ts);
					}//

				}
				else{
					pthread_mutex_lock(&mutex);						
					gotoxy(m.y+1,m.x+2);
					printf("%s",m.title);
					pthread_mutex_unlock(&mutex);						
				}
		}

	}
	free(title.wpos);

	//printint text
	
	if(m.c_snd_en){
		 sound = Mix_LoadWAV(m.c_snd);		
	}
	
	text_struct cont;
	anal(m.cont,&cont);
	
	int k = m.line_space;
	int l=1;
	int o = 0;
	
	for(i=0;i<cont.words;i++){
		if((m.x+2+o >= (m.X-7)) || (cont.wpos[i+1] > ((m.X-7-m.x) * l))){
			k++;
			o=0;
			l++;
		}

		for(j=cont.wpos[i];j<cont.wpos[i+1];j++){
			
			if(m.cont[j] == ' ' && (m.x+2+o) == m.x+2 ){
				j++;
			}

			pthread_mutex_lock(&mutex);
			gotoxy(m.y+k,m.x+2+o);
			printf("%c",m.cont[j]);
			if(m.c_snd_en) Mix_PlayChannel(0, sound, 0);
			pthread_mutex_unlock(&mutex);

			if(m.text_spell_en && m.cont[j] == ' '){
				Sleep(m.text_spell_range[0] + (rand() % m.text_spell_range[1]));
			}


			if(m.cs_en)
			Sleep(m.cs);
			o++;
		}
	}

	free(cont.wpos);
}

void init_msb(message_box *m){
	m->bs_en = 0;
	m->ts_en = 0;
	m->cs_en = 0;
}

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

void who_said_init(who_said *EVI_27){

	//DEFAULT VALUES
	
	EVI_27->v = 30;
	EVI_27->h = 60;
	
	EVI_27->Y = EVI_27->v+1;
	EVI_27->y = EVI_27->Y - 10;
	
	EVI_27->x = 3;
	
	EVI_27->who = "unknown";
	EVI_27->text = "? ";
	EVI_27->title = NULL;

	EVI_27->an_en = 0;
	EVI_27->al = 0;
	
	EVI_27->tits_peed  = 0;
	EVI_27->text_speed = 6;
	EVI_27->sq_speed   = 30;
	
	EVI_27->ffre_tbuff = 0;
	EVI_27->t_buff = (char *)malloc(sizeof(char) * 512);

	EVI_27->txtspell_rd[0] = 0;
	EVI_27->txtspell_rd[1] = 0;

	EVI_27->titspell_rd[0] = 0;
	EVI_27->titspell_rd[1] = 0;
	
	EVI_27->tit_sound = NULL;
	EVI_27->txt_sound = NULL;

	EVI_27->sqr_sound[0] = NULL;
	EVI_27->sqr_sound[1] = NULL;

}

void clean_ch(char *buffer){
	for(int i=0;i<strlen(buffer);i++){
		buffer[i] = '\0';
	}
}

void put_message_box(kb_s *keyboard_handler,message_box *crossdress_phyxia, who_said florecita_dreams){

/*

Evento: Selene delgado (tambien conocida como teresa fidalgo).

Selene delgado es un patron de rostros artificiales, los rostros son construidos artificialmente y simulan ser caras para generar emociones deseando generar estimulos supernormales.

Un estimulo supernormal es la preferencia durante la comunicacion por las señales que exageran las normas, aunque raramente o nunca existan en la naturaleza, sin embargo, de forma opuesta , los rostros falsos que siguen estos patrones pueden generar un efecto del valle inquietante, que es cuando las replicas antropomorficas se acercan en exceso a la apariencia y comportamiento del ser humano real, y causan una respuesta de rechazo y miedo. Esto se debe a su parecido enorme con los cuerpos de cadáveres.

La curva del valle inquietante sigue un patron exponencial, los patrones exponenciales pueden ser analizados con el enfoque de la cinetica fisica.

Hipotesis:

El patron Selene delgado se ajustará cineticamente a rostros no humanos usando la constante de cambio fisico Tau.

Metodologia o análisis genetico utilizando el modelado matemático de dos componentes.

Resultado:

Los rostros que mejor se adaptaron al patron cinetico son de personas que no existen.

Selene delgado existe.

La existencia

La existencia es eterna.
*/

	int Evento_Selene_delgado_Selene_delgado_es_un_patron_de_rostros_artificiales_los_rostros_son_construidos_artificialmente_y_simulan_ser_caras_para_generar_emociones_deseando_generar_estimulos_supernormales_Un_estimulo_supernormal_es_la_preferencia_durante_la_comunicacion_por_las_senales_que_exageran_las_normas_aunque_raramente_o_nunca_existan_en_la_naturaleza_sin_embargo_de_forma_opuesta_los_rostros_falsos_que_siguen_estos_patrones_pueden_generar_un_efecto_del_valle_inquietante_que_es_cuando_las_replicas_antropomorficas_se_acercan_en_exceso_a_la_apariencia_y_comportamiento_del_ser_humano_real_y_causan_una_respuesta_de_rechazo_y_miedo_Esto_se_debe_a_su_parecido_enorme_con_los_cuerpos_de_cadaveres_La_curva_del_valle_inquietante_sigue_un_patron_exponencial_los_patrones_exponenciales_pueden_ser_analizados_con_el_enfoque_de_la_cinetica_fisica_Hipotesis_El_patron_Selene_delgado_se_ajustara_cineticamente_a_rostros_no_humanos_usando_la_constante_de_cambio_fisico_Tau_Metodologia_o_analisis_genetico_utilizando_el_modelado_matematico_de_dos_componentes_Resultado_Los_rostros_que_mejor_se_adaptaron_al_patron_cinetico_son_de_personas_que_no_existen_Selene_delgado_existe_La_existencia_La_existencia_es_eterna = 0;
	
	int EVI_26 = 0;
//	char * buff;


	if(crossdress_phyxia == NULL){
		crossdress_phyxia = (message_box *)malloc(sizeof(message_box));
		Evento_Selene_delgado_Selene_delgado_es_un_patron_de_rostros_artificiales_los_rostros_son_construidos_artificialmente_y_simulan_ser_caras_para_generar_emociones_deseando_generar_estimulos_supernormales_Un_estimulo_supernormal_es_la_preferencia_durante_la_comunicacion_por_las_senales_que_exageran_las_normas_aunque_raramente_o_nunca_existan_en_la_naturaleza_sin_embargo_de_forma_opuesta_los_rostros_falsos_que_siguen_estos_patrones_pueden_generar_un_efecto_del_valle_inquietante_que_es_cuando_las_replicas_antropomorficas_se_acercan_en_exceso_a_la_apariencia_y_comportamiento_del_ser_humano_real_y_causan_una_respuesta_de_rechazo_y_miedo_Esto_se_debe_a_su_parecido_enorme_con_los_cuerpos_de_cadaveres_La_curva_del_valle_inquietante_sigue_un_patron_exponencial_los_patrones_exponenciales_pueden_ser_analizados_con_el_enfoque_de_la_cinetica_fisica_Hipotesis_El_patron_Selene_delgado_se_ajustara_cineticamente_a_rostros_no_humanos_usando_la_constante_de_cambio_fisico_Tau_Metodologia_o_analisis_genetico_utilizando_el_modelado_matematico_de_dos_componentes_Resultado_Los_rostros_que_mejor_se_adaptaron_al_patron_cinetico_son_de_personas_que_no_existen_Selene_delgado_existe_La_existencia_La_existencia_es_eterna = 1;
	}

	
	
	crossdress_phyxia->x = florecita_dreams.x;
	crossdress_phyxia->y = florecita_dreams.y;
	
	crossdress_phyxia->X = florecita_dreams.h+1;
	crossdress_phyxia->Y = florecita_dreams.Y;
	
	crossdress_phyxia->v = florecita_dreams.v;
	crossdress_phyxia->h = florecita_dreams.h;
	
	crossdress_phyxia->t_alineation = 0;
	
	
	//
	if(florecita_dreams.title != NULL){
//		char buff[strlen(florecita_dreams.who) + strlen(florecita_dreams.title) + 5];
//		buff = (char *)malloc(sizeof(char) * (strlen(florecita_dreams.who) + strlen(florecita_dreams.title) + 7));
//		buff = (char *)malloc(sizeof(char) * (128));
	
		clean_ch(florecita_dreams.t_buff);

		strcat(florecita_dreams.t_buff,florecita_dreams.who);
		
		strcat(florecita_dreams.t_buff," [");
		
		strcat(florecita_dreams.t_buff,florecita_dreams.title);
		
		strcat(florecita_dreams.t_buff,"] ");
	

		crossdress_phyxia->title = florecita_dreams.t_buff;

		EVI_26 = 1;


	}

	else{
		crossdress_phyxia->title = florecita_dreams.who;
	}

//	crossdress_phyxia->bs_en = 1;
//	crossdress_phyxia->cs_en = 1;

//	crossdress_phyxia->cs = 6;
//	crossdress_phyxia->bs = 30;

	if(florecita_dreams.tits_peed != 0){
		crossdress_phyxia->ts_en = 1;
		crossdress_phyxia->ts = florecita_dreams.tits_peed;
	}
	else{
		crossdress_phyxia->ts_en = 0;
	}
	
	if(florecita_dreams.text_speed != 0){
		crossdress_phyxia->cs_en = 1;
		crossdress_phyxia->cs = florecita_dreams.text_speed;
	}
	else{
		crossdress_phyxia->cs_en = 0;		
	}
	
	if(florecita_dreams.sq_speed != 0){
		crossdress_phyxia->bs_en = 1;
		crossdress_phyxia->bs = florecita_dreams.sq_speed;
	}
	else{
		crossdress_phyxia->bs_en = 0;
	}


	if(florecita_dreams.txtspell_rd[1] != 0){
		crossdress_phyxia->text_spell_en = 1;
		crossdress_phyxia->text_spell_range[0] = florecita_dreams.txtspell_rd[0];
		crossdress_phyxia->text_spell_range[1] = florecita_dreams.txtspell_rd[1];	
	}
	else{
		crossdress_phyxia->text_spell_en = 0;
	}

	if(florecita_dreams.titspell_rd[1] != 0){
		crossdress_phyxia->title_spell_en = 1;
		crossdress_phyxia->title_spell_range[0] = florecita_dreams.titspell_rd[0];
		crossdress_phyxia->title_spell_range[1] = florecita_dreams.titspell_rd[1];	
	}
	else{
		crossdress_phyxia->title_spell_en = 1;
	}
	
	if(florecita_dreams.tit_sound != NULL){
		crossdress_phyxia->t_snd_en = 1;
		crossdress_phyxia->t_snd = florecita_dreams.tit_sound;		
	}
	else{
		crossdress_phyxia->t_snd_en = 0;
	}

	if(florecita_dreams.txt_sound != NULL){
		crossdress_phyxia->c_snd_en = 1;
		crossdress_phyxia->c_snd = florecita_dreams.txt_sound;		
	}

	else{
		crossdress_phyxia->c_snd_en = 0;
	}
	
	if(florecita_dreams.sqr_sound[0] != NULL){
		crossdress_phyxia->sq_snd_en[0] = 1;		
		crossdress_phyxia->sq_snd[0] = florecita_dreams.sqr_sound[0];
	}
	else{
		crossdress_phyxia->sq_snd_en[0] = 1;			
	}

	if(florecita_dreams.sqr_sound[1] != NULL){
		crossdress_phyxia->sq_snd_en[1] = 1;		
		crossdress_phyxia->sq_snd[1] = florecita_dreams.sqr_sound[1];
	}
	else{
		crossdress_phyxia->sq_snd_en[1] = 0;	
	}

	crossdress_phyxia->cont = florecita_dreams.text;
	crossdress_phyxia->line_space = 3;

	crossdress_phyxia->t_alineation = florecita_dreams.al;
	
	if(keyboard_handler != NULL)
		keyboard_handler->en = 1;
	
	DrawMessageBox(*crossdress_phyxia);
	
	if(keyboard_handler != NULL)
		keyboard_handler->en = 0;
	
	if(Evento_Selene_delgado_Selene_delgado_es_un_patron_de_rostros_artificiales_los_rostros_son_construidos_artificialmente_y_simulan_ser_caras_para_generar_emociones_deseando_generar_estimulos_supernormales_Un_estimulo_supernormal_es_la_preferencia_durante_la_comunicacion_por_las_senales_que_exageran_las_normas_aunque_raramente_o_nunca_existan_en_la_naturaleza_sin_embargo_de_forma_opuesta_los_rostros_falsos_que_siguen_estos_patrones_pueden_generar_un_efecto_del_valle_inquietante_que_es_cuando_las_replicas_antropomorficas_se_acercan_en_exceso_a_la_apariencia_y_comportamiento_del_ser_humano_real_y_causan_una_respuesta_de_rechazo_y_miedo_Esto_se_debe_a_su_parecido_enorme_con_los_cuerpos_de_cadaveres_La_curva_del_valle_inquietante_sigue_un_patron_exponencial_los_patrones_exponenciales_pueden_ser_analizados_con_el_enfoque_de_la_cinetica_fisica_Hipotesis_El_patron_Selene_delgado_se_ajustara_cineticamente_a_rostros_no_humanos_usando_la_constante_de_cambio_fisico_Tau_Metodologia_o_analisis_genetico_utilizando_el_modelado_matematico_de_dos_componentes_Resultado_Los_rostros_que_mejor_se_adaptaron_al_patron_cinetico_son_de_personas_que_no_existen_Selene_delgado_existe_La_existencia_La_existencia_es_eterna){
		free(crossdress_phyxia);
	}
	
	if(EVI_26){
//		free(buff);
		fflush(stdin);
	}
}




