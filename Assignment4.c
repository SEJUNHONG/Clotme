#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#include "header.h"
#define LEN	256
#define PI 3.1415926535897

int main(void)
{
	time_t start1, start2, end1, end2;
	double result1, result2;
	int i, j;
	int sum = 0;
	int len = 0;
	FILE*fp_in = 0, *fp_in1=0, *fp_out = 0, *fp_outf = 0, *fp_out2 = 0, *fp_out2f = 0, *fp_out3 = 0, *fp_out2L4 = 0, *fp_out2H36=0;
	unsigned char *img_in = 0, *img_in1=0, *img_out = 0, *img_outf = 0, *img_out2 = 0, *img_out2f = 0;
	unsigned char *img_out2L4f = 0,  *img_out2H36f=0;
	double *img_x=0, *img_x1=0, *img_x2=0, *img_out3 = 0, *img_out2L4 = 0, *img_out2H36=0, *img_out1=0;

	fp_in = fopen("Lena(256x256).raw", "rb");
	fp_in1 = fopen("Lena(256x256).raw", "rb");
	fp_out = fopen("[1D_FDCT]Lena(256x256).raw", "wb");
	fp_outf = fopen("[1D_IDCT]Lena(256x256).raw", "wb");
	fp_out2 = fopen("[2D_FDCT]Lena(256x256).raw", "wb");
	fp_out2f = fopen("[2D_IDCT]Lena(256x256).raw", "wb");
	fp_out2L4 = fopen("[2D_FDCT_LOW4]Lena(256x256).raw", "wb");
	fp_out2H36 = fopen("[2D_FDCT_HIGH36]Lena(256x256).raw", "wb");


	img_x = MemAlloc_d(LEN*LEN);
	img_x1 = MemAlloc_d(LEN*LEN);
	img_x2 = MemAlloc_d(LEN*LEN);
	img_in = MemAlloc(LEN*LEN);
	img_in1 = MemAlloc(LEN*LEN);
	img_out = MemAlloc(LEN*LEN);
	img_out1 = MemAlloc_d(LEN*LEN);
	img_outf = MemAlloc(LEN*LEN);
	img_out2 = MemAlloc(LEN*LEN);
	img_out2f = MemAlloc(LEN*LEN);
	img_out3 = MemAlloc_d(LEN*LEN);
	img_out2L4 = MemAlloc_d(LEN*LEN);
	img_out2L4f = MemAlloc(LEN*LEN);
	img_out2H36 = MemAlloc_d(LEN*LEN);
	img_out2H36f = MemAlloc(LEN*LEN);


	unsigned char in2_read;
	in2_read = fread(img_in, sizeof(unsigned char), LEN*LEN, fp_in);
	FDCT_2D(img_in, img_out2, LEN*LEN);
	FDCT2_2D(img_in, img_out3, LEN*LEN);
	
	fwrite(img_out2, sizeof(unsigned char), LEN*LEN, fp_out2);
	
	IDCT_2D(img_out3, img_out2f, LEN*LEN);
	
	fwrite(img_out2f, sizeof(unsigned char), LEN*LEN, fp_out2f);
	
	FDCT2L4_2D(img_in, img_out2L4, LEN*LEN);
	IDCT_2D(img_out2L4, img_out2L4f, LEN*LEN);
	fwrite(img_out2L4f, sizeof(unsigned char), LEN*LEN, fp_out2L4);
	
	FDCT2H36_2D(img_in, img_out2H36, LEN*LEN);
	IDCT_2D(img_out2H36, img_out2H36f, LEN*LEN);
	fwrite(img_out2H36f, sizeof(unsigned char), LEN*LEN, fp_out2H36);
	
	
	unsigned char in1_read;
	in1_read = fread(img_in1, sizeof(unsigned char), LEN*LEN, fp_in1);
	FDCT_1D(img_in1, img_x, img_out, LEN*LEN);
	FDCT1_1D(img_in1, img_x1, img_out1, LEN*LEN);
	
	
	fwrite(img_out, sizeof(unsigned char), LEN*LEN, fp_out);
	
	IDCT_1D(img_out1, img_x2, img_outf, LEN*LEN);
	
	fwrite(img_outf, sizeof(unsigned char), LEN*LEN, fp_outf);
	
	

	free(img_x);
	free(img_x1);
	free(img_x2);
	free(img_in);
	free(img_in1);
	free(img_out);
	free(img_out1);
	free(img_outf);
	free(img_out2);
	free(img_out2f);
	free(img_out3);
	free(img_out2L4);
	free(img_out2L4f);
	free(img_out2H36);
	free(img_out2H36f);

	fclose(fp_in);
	fclose(fp_in1);
	fclose(fp_out);
	fclose(fp_outf);
	fclose(fp_out2);
	fclose(fp_out2f);
	fclose(fp_out2L4);
	fclose(fp_out2H36);

	return 0;
}