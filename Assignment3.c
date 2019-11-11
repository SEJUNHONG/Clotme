#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH	512
#define HEIGHT	512

typedef unsigned char BYTE;

unsigned char** MemAlloc_2D(int width, int height);
void MemFree_2D(unsigned char**arr, int height);
void DownSampling(unsigned char** img_in, unsigned char** img_out, int width, int height);

int main(void)
{
	FILE *fp_in1 = 0, *fp_in2 = 0, *fp_out1 = 0, *fp_out2 = 0;
	BYTE **img_in1 = 0, **img_in2 = 0, **img_out1 = 0, **img_out2 = 0;
	int i = 0;

	fp_in1 = fopen("Lena(512x512).raw", "rb");
	fp_in2 = fopen("[Gaussian_5x5]Lena(512x512).raw", "rb");

	img_in1 = MemAlloc_2D(WIDTH, HEIGHT);
	img_in2 = MemAlloc_2D(WIDTH, HEIGHT);
	img_out1 = MemAlloc_2D(WIDTH, HEIGHT);
	img_out2 = MemAlloc_2D(WIDTH, HEIGHT);

	for (i = 0; i < HEIGHT; i++)
	{
		fread(img_in1[i], sizeof(BYTE), WIDTH, fp_in1);
		fread(img_in2[i], sizeof(BYTE), WIDTH, fp_in2);
	}


	DownSampling(img_in1, img_out1, WIDTH, HEIGHT);
	fp_out1 = fopen("[DownSampling]Lena(512x512).raw", "wb");

	DownSampling(img_in2, img_out2, WIDTH, HEIGHT);
	fp_out2 = fopen("[DownSampling][Gaussian_5x5]Lena(512x512).raw", "wb");

	for (i = 0; i < (HEIGHT/2); i++)
	{
		fwrite(img_out1[i], sizeof(BYTE), (WIDTH / 2), fp_out1);
		fwrite(img_out2[i], sizeof(BYTE), (WIDTH / 2), fp_out2);
	}

	MemFree_2D(img_in1, HEIGHT);
	MemFree_2D(img_in2, HEIGHT);
	MemFree_2D(img_out1, HEIGHT);
	MemFree_2D(img_out2, HEIGHT);
	fclose(fp_in1);
	fclose(fp_in2);
	fclose(fp_out1);
	fclose(fp_out2);

	return 0;
}

void DownSampling(unsigned char** img_in, unsigned char** img_out, int width, int height)
{
	int i, j;

	for (i = 0; i < 256; i++)
	{
		for (j = 0; j < 256; j++)
		{
			// img_out[256*j + i] = img_in[512*(2 * j) + (2 * i)];
			img_out[j][i] = img_in[2 * j][2 * i];
		}
	}
}

unsigned char** MemAlloc_2D(int width, int height)
{
	unsigned char** MemA;
	MemA = (unsigned char**)malloc(sizeof(unsigned char*)*height);
	for (int i = 0; i < height; i++)
	{
		MemA[i] = (unsigned char*)malloc(sizeof(unsigned char*)*width);
	}
	return MemA;
}

void MemFree_2D(unsigned char** arr, int height)
{
	for (int i = 0; i < height; i++)
		free(arr[i]);
	free(arr);
}