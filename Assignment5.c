#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"

#define WIDTH	256
#define HEIGHT	256

int main(void)
{
	FILE* fp_in = 0, *fp_out3 = 0, *fp_out1 = 0, *fp_out2 = 0;
	unsigned char* img_in_R = 0, *img_in_G = 0, *img_in_B = 0;
	unsigned char *img_out1_R = 0, *img_out1_G = 0, *img_out1_B = 0;
	unsigned char *img_out2_R = 0, *img_out2_G = 0, *img_out2_B = 0;
	unsigned char *img_out3_R = 0, *img_out3_G = 0, *img_out3_B = 0;

	fp_in = fopen("Lena_(256x256).RGB", "rb");
	fp_out1 = fopen("[UpSampling_Copy]Lena(512x512).RGB", "wb");
	fp_out2 = fopen("[UpSampling_Average]Lena(512x512).RGB", "wb");
	fp_out3 = fopen("[UpSampling_Interpolation]Lena(512x512).RGB", "wb");
	img_in_R = MemAlloc(WIDTH * HEIGHT);
	img_in_G = MemAlloc(WIDTH * HEIGHT);
	img_in_B = MemAlloc(WIDTH * HEIGHT);
	img_out1_R = MemAlloc((WIDTH * 2) * (HEIGHT * 2));
	img_out1_G = MemAlloc((WIDTH * 2) * (HEIGHT * 2));
	img_out1_B = MemAlloc((WIDTH * 2) * (HEIGHT * 2));
	img_out2_R = MemAlloc((WIDTH * 2) * (HEIGHT * 2));
	img_out2_G = MemAlloc((WIDTH * 2) * (HEIGHT * 2));
	img_out2_B = MemAlloc((WIDTH * 2) * (HEIGHT * 2));
	img_out3_R = MemAlloc((WIDTH * 2) * (HEIGHT * 2));
	img_out3_G = MemAlloc((WIDTH * 2) * (HEIGHT * 2));
	img_out3_B = MemAlloc((WIDTH * 2) * (HEIGHT * 2));

	unsigned char R_read, G_read, B_read;
	R_read = fread(img_in_R, sizeof(unsigned char), WIDTH*HEIGHT, fp_in);
	G_read = fread(img_in_G, sizeof(unsigned char), WIDTH*HEIGHT, fp_in);
	B_read = fread(img_in_B, sizeof(unsigned char), WIDTH*HEIGHT, fp_in);

	UpSampling_Copy(img_in_R, img_out1_R, WIDTH*HEIGHT);
	UpSampling_Copy(img_in_G, img_out1_G, WIDTH*HEIGHT);
	UpSampling_Copy(img_in_B, img_out1_B, WIDTH*HEIGHT);
	
	fwrite(img_out1_R, sizeof(unsigned char), (WIDTH * 2)*(HEIGHT * 2), fp_out1);
	fwrite(img_out1_G, sizeof(unsigned char), (WIDTH * 2)*(HEIGHT * 2), fp_out1);
	fwrite(img_out1_B, sizeof(unsigned char), (WIDTH * 2)*(HEIGHT * 2), fp_out1);
	
	UpSampling_Average(img_in_R, img_out2_R, WIDTH*HEIGHT);
	UpSampling_Average(img_in_G, img_out2_G, WIDTH*HEIGHT);
	UpSampling_Average(img_in_B, img_out2_B, WIDTH*HEIGHT);
	
	fwrite(img_out2_R, sizeof(unsigned char), (WIDTH * 2)*(HEIGHT * 2), fp_out2);
	fwrite(img_out2_G, sizeof(unsigned char), (WIDTH * 2)*(HEIGHT * 2), fp_out2);
	fwrite(img_out2_B, sizeof(unsigned char), (WIDTH * 2)*(HEIGHT * 2), fp_out2);

	UpSampling_Interpolation(img_in_R, img_out3_R, WIDTH * HEIGHT);
	UpSampling_Interpolation(img_in_G, img_out3_G, WIDTH * HEIGHT);
	UpSampling_Interpolation(img_in_B, img_out3_B, WIDTH * HEIGHT);

	fwrite(img_out3_R, sizeof(unsigned char), (WIDTH * 2) * (HEIGHT * 2), fp_out3);
	fwrite(img_out3_G, sizeof(unsigned char), (WIDTH * 2) * (HEIGHT * 2), fp_out3);
	fwrite(img_out3_B, sizeof(unsigned char), (WIDTH * 2) * (HEIGHT * 2), fp_out3);

	GetPSNR(img_out3_R, img_out3_G, img_out3_B, img_out1_R, img_out1_G, img_out1_B);
	GetPSNR(img_out3_R, img_out3_G, img_out3_B, img_out2_R, img_out2_G, img_out2_B);

	free(img_in_R);
	free(img_in_G);
	free(img_in_B);
	free(img_out1_R);
	free(img_out1_G);
	free(img_out1_B);
	free(img_out2_R);
	free(img_out2_G);
	free(img_out2_B);
	free(img_out3_R);
	free(img_out3_G);
	free(img_out3_B);

	fclose(fp_in);
	fclose(fp_out1);
	fclose(fp_out2);
	fclose(fp_out3);

	return 0;
}