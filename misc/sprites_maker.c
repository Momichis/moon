#include <stdio.h>
#include <stdlib.h>

int main(int argc,char *argv[]){
	if(argc != 4){
		printf("Bad Usage.\n");
		printf("%s [file to open] [destination C file] [array name]\n",argv[0]);
		exit(-1);
	}
	FILE *fd = fopen(argv[1],"r");
		if(fd == NULL){
			printf("Error opening \"%s\"",argv[1]);
			exit(-1);
		}
	fseek(fd,0L,SEEK_END);
	int filesize = ftell(fd);
	fseek(fd,0L,SEEK_SET);
	
	char *buffer = (char *)malloc(sizeof(char) *filesize);
		if(buffer == NULL){
			printf("Error\n");
			exit(-1);
		}
	fread(buffer,sizeof(char),filesize,fd);
	fclose(fd);
	
	int i;
	int j;
	int k;
	
	int spr_count = 0;

	for(i=0;i<filesize;i++){
		if(buffer[i] == 'C' && buffer[i+1] == 'P' && buffer[i+2] == '\n'){
			spr_count++;
		}
	}
	
	int *spr_ends = (int *)malloc(sizeof(int) * spr_count);
	int *spr_starts = (int *)malloc(sizeof(int) * spr_count);
	
	j=0;
	
	for(i=0;i<filesize;i++){
		if(buffer[i] == 'C' && buffer[i+1] == 'P' && buffer[i+2] == '\n'){
			spr_ends[j] = i;
			j++;
		}
	}
	
	spr_starts[0] = 0;

	j=1;
	for(i=0;i<filesize;i++){
		if(buffer[i] == 'C' && buffer[i+1] == 'P' && buffer[i+2] == '\n'){
			if(j<spr_count){
			spr_starts[j] = i+3;
			j++;
			}
		}
	}
	
	int spr_lines_count = 0;

	for(i=spr_starts[0];i<spr_ends[0];i++){
		if(buffer[i] == '\n'){
			spr_lines_count++;
		}
	}
	
	int spr_cols_count = 0;
	
	for(i=spr_starts[0];i<spr_ends[0];i++){
		if(buffer[i] == '\n'){
			break;
		}
		else{
			spr_cols_count++;
		}
	}

	fflush(fd);
	fd = fopen(argv[2],"a");
		if(fd == NULL){
			printf("Error opening \"%s\"",argv[2]);
			exit(-1);
		}

//	fprintf(fd,"char %s[%d][%d][%d] = {\n",argv[3],spr_count,spr_lines_count,spr_cols_count);

//	fprintf(fd,"#include <stdlib.h>\n\n");
	fprintf(fd,"char ***%s_d(void){\n",argv[3]);
	fprintf(fd,"\tchar ***%s = (char ***)malloc(sizeof(char **) * %d);\n",argv[3],spr_count);
	fprintf(fd,"\tint i,j;\n");
	fprintf(fd,"\tfor(i=0;i<%d;i++){\n",spr_count);
	fprintf(fd,"\t\t%s[i] = (char **)malloc(sizeof(char *) * %d);\n",argv[3],spr_lines_count);
	fprintf(fd,"\t\tfor(j=0;j<%d;j++){\n",spr_lines_count);
	fprintf(fd,"\t\t\t%s[i][j] = (char *)malloc(sizeof(char) * %d);\n",argv[3],spr_cols_count);
	fprintf(fd,"\t\t}\n");
	fprintf(fd,"\t}\n\n");

	k=0;
	for(i=0;i<spr_count;i++){ k=0;
	fprintf(fd,"\t%s[%d][%d] = \"",argv[3],i,k);
	k++;
		for(j=spr_starts[i];j<spr_ends[i];j++){
			if(buffer[j] != '\n'){
				if(buffer[j] == '\\'){
					fprintf(fd,"\\");
				}
				
				fprintf(fd,"%c",buffer[j]);
			}			
			else{
				if(j!=spr_ends[i]-1){
					fprintf(fd,"\";\n\t%s[%d][%d] = \"",argv[3],i,k);
					k++;
				}
				else{
					fprintf(fd,"\";\n");
				}
			}
		}fprintf(fd,"\n");
	}
	fprintf(fd,"\n  return %s;\n",argv[3]);
	fprintf(fd,"}\n\n");
	
	
		/*
	
	fprintf(fd,"void %s_freee(char ***%s){\n",argv[3],argv[3]);
	fprintf(fd,"\tint i,j;\n");
	fprintf(fd,"\tfor(i=0;i<%d;i++){\n",spr_count);
	fprintf(fd,"\t\tfor(j=0;j<%d;j++){\n",spr_lines_count);
	
	fprintf(fd,"\t\t\tfree(%s[i][j]);\n",argv[3]);
	
	fprintf(fd,"\t\t}\n");
	fprintf(fd,"\t}\n");
	
	fprintf(fd,"\tfree(%s)",argv[3]);
	
		*/
	fclose(fd);
	free(buffer);
	return 0;
}
