#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void main()
{
	FILE *fin,*fsym,*fopt,*flen;
	fin=fopen("intermediate.txt","r");
 	fsym=fopen("symtab.txt","r");
 	fopt=fopen("optab.txt","r");
 	flen=fopen("length.txt","r");
	char la[20],mne[20],op[20],otp[20],sym[20],opval[3],symval[10];
	int sa,len,oplen;
	fscanf(fin,"%X%s%s%X",&sa,la,mne,&sa);
 	if(strcmp(mne,"START")==0)
	{
		printf("%X\t%s\t%s\t%X\n",sa,la,mne,sa);
	}

	fscanf(fin,"%X%s%s%s",&sa,la,mne,op);
	int addr=sa;
	printf("%X\t%s\t%s\t%s",sa,la,mne,op);
	while(strcmp(mne,"END")!=0)
	{
		fscanf(fopt,"%s%s",otp,opval);
  		while(!feof(fopt))
  		{
   			if(strcmp(mne,otp)==0)
    		{
      			fscanf(fsym,"%s%s",sym,symval);
        		while(!feof(fsym))
         		{
          			if(strcmp(op,sym)==0)
           			{
                 		printf("\t%s%s\n",opval,symval);
           			}
          			fscanf(fsym,"%s%s",sym,symval);
         		}
    		}
  		fscanf(fopt,"%s%s",otp,opval);
  		}
 		fseek(fopt,SEEK_SET,0);
 		fseek(fsym,SEEK_SET,0);
 		if(strcmp(mne,"WORD")==0)
		printf("\t00000%s\n",op);
 
 		if(strcmp(mne,"BYTE")==0)
 		{
  			for(int i=0;i<strlen(op);i++)
   			{
     			printf("%X",op[i]);
   			}
     		printf("\n");
 		}
		fscanf(fin,"%X%s%s%s",&sa,la,mne,op);
		printf("\n%X\t%s\t%s\t%s",sa,la,mne,op);
	}

	fclose(fin);
	fclose(fopt);
	fclose(fsym);

	fin=fopen("intermediate.txt","r");
 	fsym=fopen("symtab.txt","r");
 	fopt=fopen("optab.txt","r");

	printf("\nOBJECT PROGRAM\n");	
	fscanf(fin,"%X%s%s%X",&sa,la,mne,&sa);
 	if(strcmp(mne,"START")==0)
	{
  		fscanf(flen,"%X%X",&len,&oplen);
	}
	printf("H^%s^00%X^0000%X\nT^00%X^%X^",la,sa,len,sa,oplen);
	fscanf(fin,"%X%s%s%s",&sa,la,mne,op);
 	addr=sa;
	while(strcmp(mne,"END")!=0)
	{
		fscanf(fopt,"%s%s",otp,opval);
  		while(!feof(fopt))
  		{
   			if(strcmp(mne,otp)==0)
    		{
      			fscanf(fsym,"%s%s",sym,symval);
        		while(!feof(fsym))
         		{
          			if(strcmp(op,sym)==0)
           			{
             			printf("%s%s^",opval,symval);
           			}
          			fscanf(fsym,"%s%s",sym,symval);
         		}
    		}
  		fscanf(fopt,"%s%s",otp,opval);
  		}
 	fseek(fopt,SEEK_SET,0);
	fseek(fsym,SEEK_SET,0);
 	if(strcmp(mne,"WORD")==0)
  		printf("00000%s^",op);
 	if(strcmp(mne,"BYTE")==0)
 	{
  		for(int i=0;i<strlen(op);i++)
   		{
     		printf("%X",op[i]);
   		}
     		printf("\n");
 	}
		fscanf(fin,"%X%s%s%s",&sa,la,mne,op);
	}
	printf("\nE^00%X\n",addr);
	fclose(fin);
	fclose(fopt);
	fclose(fsym);
	fclose(flen);
}
