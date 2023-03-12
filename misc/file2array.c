/* 
 * Convert a file into a C array!
 * The file lines must have same size
 * 
 * */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
	
	if(argc != 4){
		printf("Bad Usage.\n");
		printf("%s [file to open] [destination C file] [array name]\n",argv[0]);
			exit(-1);
		}
	
	FILE * FD = fopen(argv[1],"a");
		if(FD == NULL){
			printf("Error opening file.\n");
				exit(-1);
			}
	fseek(FD,0L,SEEK_END);
		size_t len = (size_t)ftell(FD);
	fclose(FD);
	
	char *buffer = (char *)malloc(sizeof(char) * len);
		if(buffer == NULL){
			printf("Error allocating memory.\n");
				exit(-1);
		}
	
	int fd;
	fd = open(argv[1],O_RDONLY);
	
	  if(fd == -1){
			printf("Error opening file.");
				exit(-1);
	  }
	  read(fd,buffer,len);	
		//printf("%s",buffer);

	close(fd);

	/////
	int lines=0;
	int cols;
	int *linesize;
	
	int i;
	for(i=0;i<len;i++){
		if(buffer[i] == '\n'){
				lines++;
			}
	}lines++;
	linesize = (int *)malloc(sizeof(int) * len);
		if(linesize == NULL){
				printf("Error allocating memory.\n");
					exit(-1);
			}
	for(i=0;i<lines;i++){
			linesize[i] = 0;
		}
		
	int j=0;
	for(i=0;i<len;i++){
			if(buffer[i] == '\n'){
					j++;
				}
			else{
					linesize[j]++;
				}
		}
	bool samesz = true;
	for(i=0;i<lines-3;i++){
			if(linesize[i] != linesize[i+1]){
					samesz = false;
					i=lines+1;
					printf("Error?:\nlinesize[%d] = %d != linesize[%d] = %d\n",i,linesize[i],i+1,linesize[i+1]);
				}
				else{
					printf("line %d size: %d\n",i,linesize[i]);
				}
		}
	
	if(!samesz){
			printf("Error. Invalid file.\n");
					printf("Error in line %d\n",i);
					free(linesize);
					free(buffer);
					exit(-1);
		}
	
	cols = linesize[0];
		free(linesize);

		FILE * fw = fopen(argv[2],"w");
			if(fw == NULL){
					//printf("Error creating file: %s\n",argv[2]);
						free(buffer);
						exit(-1);
				}
	
		fprintf(fw,"char %s[%d][%d] = {\n",argv[3],lines,cols+1);

	int k=0;
	for(i=0;i<lines;i++){ fprintf(fw,"  {");
		for(j=0;j<=cols;j++){
			if(buffer[k]!='\n'){
				if(j == cols-1){
				fprintf(fw,"%d",buffer[k]);

					}
				else{
				fprintf(fw,"%d,",buffer[k]);
				}
			}
			k++;
					
			}

			fprintf(fw,",'\\0'},\n");
		
		}fprintf(fw,"};\n");
	

	printf("Done. %s written! | %d lines, %d cols.\n",argv[2],
													lines-3,cols+1);
													
	fclose(fw);	
	free(buffer);
  return 0;
}
