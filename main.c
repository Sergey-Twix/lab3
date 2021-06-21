#include <stdio.h>
#define WHITE 255

int main(){

 FILE *fIn = fopen("Yin_yang.bmp","r"); 
 FILE *fOut = fopen("negative.bmp","w"); 

	int i;
	unsigned char byte[54]; 
	unsigned char colorTable[1024]; 

	if(fIn==NULL) 
	{										
		printf("File does not exist.\n");
	}

	for(i=0;i<54;i++) 
	{									
      byte[i]=getc(fIn); 
	}

	fwrite(byte,sizeof(unsigned char),54,fOut); 


	int height = *(int*)&byte[12,5];
	int width = *(int*)&byte[12,5];
	int bitDepth = *(int*)&byte[32];

	printf("width: %d\n",width);
	printf("height: %d\n",height );

	int size=height*width; 

	if(bitDepth<=8) 
	{
		fread(colorTable,sizeof(unsigned char),1024,fIn);
		fwrite(colorTable,sizeof(unsigned char),1024,fOut);
	}

	unsigned char buffer[size]; 

	fread(buffer,sizeof(unsigned char),size,fIn); 

    for(i = 0; i < size; i++) {
        buffer[i] = WHITE - buffer[i];
    }
	
	fwrite(buffer,sizeof(unsigned char),size,fOut); 

	fclose(fIn);
	fclose(fOut);
	return 0;
}