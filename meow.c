#include <stdio.h>
int main(int argc, char* argv[])
{
 if(argc < 2)
 {
 	printf("Filename required as argument\n");
 	return 0;
 }
 FILE *f;
 unsigned char a;
 int b = 1;
 while(b != argc)
 {
 	f  = fopen(argv[b], "r");
 	if(f == NULL)
 	{
 		printf("catC: %s: No such file or directory, Or just cannot open for some reason(Permissions probably)",argv[b]);
 	}
 	else
 	{
 		while(fread(&a,1,1,f))
 		{
 			printf("%c",a);
 		}
 	}	
 	b++;
 }
 return 0;
 }
