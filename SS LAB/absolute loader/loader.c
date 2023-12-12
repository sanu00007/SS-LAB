# include <stdio.h>
# include <string.h>
void main()
{
char object[10];
int start,length,address;
FILE *fp1,*fp2;
fp1=fopen("object.txt","r");
fp2=fopen("output.txt","w");
fscanf(fp1,"%s",object);
while(strcmp(object,"E")!=0)
{
if(strcmp(object,"H")==0)
{
fscanf(fp1,"%x%x%s",&start,&length,object);
}
else if(strcmp(object,"T")==0)
{
fscanf(fp1,"%x%s",&address,object);
fprintf(fp2,"%x\t%c%c\n",address,object[0],object[1]);
fprintf(fp2,"%x\t%c%c\n",(address+1),object[2],object[3]);
fprintf(fp2,"%x\t%c%c\n",(address+2),object[4],object[5]);
address+=3;
fscanf(fp1,"%s",object);
}
else
{
fprintf(fp2,"%x\t%c%c\n",address,object[0],object[1]);
fprintf(fp2,"%x\t%c%c\n",(address+1),object[2],object[3]);
fprintf(fp2,"%x\t%c%c\n",(address+2),object[4],object[5]);
address+=3;
fscanf(fp1,"%s",object);
}
}
fclose(fp1);
fclose(fp2);
printf("FINISHED");
}

