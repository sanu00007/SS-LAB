#include<stdio.h>
#include<string.h>
void main()
{
 FILE *f1,*f2,*f3,*f4;
 int locctr,startadr,o;
 char mnemonic[20],label[20],op[20],opcode[20];
 f1=fopen("sourcecode.txt","r");
 f3=fopen("symtab.txt","w");
 f4=fopen("inter.txt","w");
 fscanf(f1,"%s%s%X",label,mnemonic,&startadr);
 if(strcmp(mnemonic,"START")==0)
 {
 locctr=startadr;
 fprintf(f4,"\t%s\t%s\t%X\n",label,mnemonic,startadr);
 }
 else
 {
 locctr=0X0;
 }
 fscanf(f1,"%s%s%s",label,mnemonic,op);
 while(!feof(f1))
 {
 //fscanf(f1,"%s",op);
 fprintf(f4,"\n%X\t%s\t%s\t%s\n",locctr,label,mnemonic,op);
 if(strcmp(label,"-")!=0)
 {
 fprintf(f3,"\n%X\t%s\n",locctr,label);
 }
 f2=fopen("optab.txt","r");
 fscanf(f2,"%s%X",opcode,&o); //o=hexadecimal value
 while(!feof(f2))
 {
 if(strcmp(mnemonic,opcode)==0)
 {
 locctr=locctr+3;
 break;
 }
 fscanf(f2,"%s%X",opcode,&o);
 }
 fclose(f2);
 if(strcmp(mnemonic,"WORD")==0)
 {
 locctr=locctr+3;
 }
 else if(strcmp(mnemonic,"RESW")==0)
 {
 startadr=atoi(op);
 locctr=locctr+(3*startadr);
 }
 else if(strcmp(mnemonic,"BYTE")==0)
 {
 if(op[0]=='X')
 {
 locctr=locctr+1;
 }
 else
 {
 int len=strlen(op);
locctr=locctr+len;
 }
 }
 else if(strcmp(mnemonic,"RESB")==0)
 {
 startadr=atoi(op);
 locctr=locctr+startadr;
 }
 fscanf(f1,"%s%s%s",label,mnemonic,op);
 }
 fclose(f1);
 fclose(f3);
} 
