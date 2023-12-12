#include<stdio.h>
#include<string.h>
#include <stdlib.h>

void main(){

  FILE *f1,*f2,*f3,*f4;
  char lab[10],mnu[10],op[10],opcode[10];
  int locctr,startaddr,o;
  f1=fopen("sourcecode.txt","r");
  
  f3=fopen("symtab.txt","w");
  f4=fopen("inter.txt","w");
  
  fscanf(f1,"%s%s%x",lab,mnu,&startaddr);
 
  if(strcmp(mnu,"START")==0){
  locctr=startaddr;
  fprintf(f4,"\t%s\t%s\t%x\n",lab,mnu,startaddr);
  
  }
  else{
  locctr=0X0;
  
  }
  
  fscanf(f1,"%s%s%s",lab,mnu,op);
  while(!feof(f1)){
  fprintf(f4,"%X\t%s\t%s\t%s\n",locctr,lab,mnu,op);
  
  if(strcmp(lab,"-")!=0){
  fprintf(f3,"%x\t%s\n",locctr,lab);
  
  }
  
  f2=fopen("optab.txt","r");
  fscanf(f2,"%s%x",opcode,&o);
  while(!feof(f2)){
      if(strcmp(mnu,opcode)==0){
      locctr+=3;
      break;
      }
  
  fscanf(f2,"%s%x",opcode,&o);
  }
  fclose(f2);
  
  if(strcmp(mnu,"WORD")==0){
    locctr+=3;
  }
  else if(strcmp(mnu,"RESW")==0){
    int add= 3*atoi(op);
    locctr+=add;
  }
   else if(strcmp(mnu,"RESB")==0){
    int add= atoi(op);
    locctr+=add;
  }
  
  else if(strcmp(mnu,"BYTE")==0){
    
   if(op[0]=='X'){
   locctr+=1;
   }
  else{
  int len=strlen(op);
  locctr+=len;
  }
  
  
  }
  
  
  
  
  
  
  
  fscanf(f1,"%s%s%s",lab,mnu,op);
  
  
  
  
  
  
  }
  








}
