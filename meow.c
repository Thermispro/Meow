#include <stdio.h>
#include <string.h>
void printFunction(unsigned int whatArgv, unsigned int whatFlag, char* argvv[]);
void inputBuffer(unsigned int whatFlag);
int flag = 0;
int main(int argc, char* argv[])
{
 /* if(argc < 2)
 {
 	printf("Filename required as argument\n");
 	return 0;
 }*/
 int b = 1,c = 1;
 unsigned int ArgInd = 0, specArgInd = 0,ArgToPass = 0;
 if(argc > 1)
 {
 while(b != argc)
 {
 	if(argv[b][0] == '-')
 	{
 		c = 1;
 		flag++;
 		ArgInd |= (1 << b);
 		while(c < strlen(argv[b]))
 		{
 			switch(argv[b][c])
 			{
 				case 'n':
 				{
 					specArgInd |= (1 << 0);
 					break;
 				}
 				case 'E':
 				{
 					specArgInd |= (1 << 1);
 					break;
 				}
 			}
 			c++;
 		}
 	}
 	else
 	{
 		ArgToPass |= (1 << b);
 	}
 	b++;
 }
 }
 if(!ArgToPass)
 {
 	inputBuffer(specArgInd);
 }
 printFunction(ArgToPass, specArgInd, argv);		
 return 0;
 }
void printFunction(unsigned int whatArgv, unsigned int whatFlag, char* argvv[])
{
	 FILE *f;
	int b = 0,c = 0,n = 0,Eflag = 0;
	unsigned char a;
	while(whatArgv)
	{
		if(whatArgv & 1)
		{			
			f  = fopen(argvv[c], "rb");
 			if(f == NULL)
 			{
 				printf("catC: %s: No such file or directory, Or just cannot open for some reason(Permissions probably)",argvv[c]);
 			}
 			else
 			{
 				if(!flag)
 				{
 					while(fread(&a,1,1,f))
 					{
 						printf("%c",a);
 					}
 				}
 				else
 				{
 					while(whatFlag)
 					{
 						if(whatFlag & 1 && b == 0)
 						{
							n = 2;
 							printf("     1  ");
 						}
 						else if(whatFlag & 1 && b == 1)
 						{
							Eflag = 1;
 						}
 						 whatFlag = whatFlag >> 1;
 						 b++;
 					}
 					while(fread(&a,1,1,f))
 					{
 						if(Eflag && a == '\n')
 						{
 							printf("$");
 						}	 					
 						printf("%c",a);
 						if(n && a == '\n' )
 						{
 							printf("     %d  ",n);
 							n++;
 						}	
 					}
 				}
 			}
 		}
 		c++;
 		whatArgv = whatArgv >> 1;
 	}
 }
 void inputBuffer(unsigned int whatFlag)
 {
 	char inputBuff[1024];
 	int n = 0,b = 0,Eflag = 0, cspnTempVar = 0;
 	if(!flag)
 	{
 		while(1)
 		{
  		   if (fgets(inputBuff, 1024, stdin) == NULL)
  		   {
           		break;
           }
 			printf("%s",inputBuff);
 		}
 	}
 				else
 				{
 					while(whatFlag)
 					{
 						if(whatFlag & 1 && b == 0)
 						{
							n = 2;
 						}
 						else if(whatFlag & 1 && b == 1)
 						{
							Eflag = 1;
 						}
 						 whatFlag = whatFlag >> 1;
 						 b++;
 					}
 					while(1)
 					{
 			if (fgets(inputBuff, 1024, stdin) == NULL)
 			{
           		break;
           }
 						if(Eflag)
 						{
 							cspnTempVar = strcspn(inputBuff,"\n" );
 							inputBuff[cspnTempVar] = '$';
 							inputBuff[cspnTempVar + 1] = '\n';	
 							inputBuff[cspnTempVar + 2] = '\0';
 						}	
 						if(n)
 						{
 							printf("     %d  ",n - 1);
 							n++;
 						}
 						printf("%s",inputBuff);	
 					}
 				}
 }
 		
 		 				
 		










