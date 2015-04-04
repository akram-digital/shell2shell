/*
Shell2Shell v 0.1
Created By Akram Abed-Eslem Chaima 
email : digitalakram@gmail.com
Under GPL
*/
#include<stdio.h>
#include<stdlib.h> 
int main(int argc,char *argv[])
{
FILE *fp;
int t=2;
int n=argc;
char fcode[1024];
char tcode[1024]="\0";
char compile[1024];
char clean[1024];
char swapargv[1024];
printf("\n   Shell2shell v 0.1 By Akram Abed-Eslem Chaima\n ");
printf("   under : GPL \n");
printf("------------------------------------------------\n\n");
if(argc<2)
{
printf("Usage: shell2shell -f base_command arg1... -t your_command  \n\n");
exit(1);
}
if(strcmp(argv[1],"-f")!=strcmp(argv[n-2],"-t")!=0)
{
printf("Usage: shell2shell -f base_command arg1... -t your_command  \n\n");
exit(1);
}
else
{
snprintf(fcode,sizeof(fcode),"%s.c",argv[n-1]);
fp=fopen(fcode,"a");
while(t<=n-3)
{
snprintf(swapargv,sizeof(swapargv)," %s",argv[t]);
strcat(tcode,swapargv);
t++;
}

fprintf(fp,"\n #include<stdio.h>\n #include<stdlib.h> \n int main() \n {\n system(\"%s\"); \n }",tcode);
fclose(fp);
printf("   *Compiling ....\n");
snprintf(compile,sizeof(compile),"gcc %s -o %s",fcode,argv[n-1]);
system(compile);
printf("   *Cleaning ....\n"); 
snprintf(clean,sizeof(clean),"mv %s /usr/bin/ && rm %s",argv[n-1],fcode);
system(clean);
printf("   *Command [ %s ] is Created  \n",argv[n-1]);
printf("\n         Done !\n\n");
}
return 0;
}
