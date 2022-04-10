#include<stdio.h>
#include<string.h>

int main(){
	FILE *fp = fopen("file.tl","r");
	char c ;
	char string[10000];
	char *point;
	int i =0 ;





	 while( 1 ){
 	 	c =  fgetc(fp);
 	printf("%c\n",c);
 	if(c == EOF) break;
 	else{
 	  if(c == 'C' && fgetc(fp)=='H' && fgetc(fp)=='E'&& fgetc(fp)=='P'&& fgetc(fp)=='P'&& fgetc(fp)=='U'&& fgetc(fp)==' '&& fgetc(fp)=='"'){
 		 
 	char d = fgetc(fp);
 	while(d != '"' ){
 	 	  	string[i] = d;
 	 		d = fgetc(fp);
 		printf("%c",d);
 	 	  	i++;
 		  	
 	  }
 		  
 	 	  printf("%s",string);
 		 
 		  	
 	 	  }	
 		
 		
 	 	}
		
	
	 }
	

}
