#define _CRT_SECURE_WO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define WIDTH	256
#define HEIGHT	256

unsigned char* MemAlloc(int length)
{
	unsigned char* X = 0;
	X = (unsigned char*)malloc(sizeof(unsigned char)*length);
	return X;
}

void UpSampling_Copy(unsigned char* img_in, unsigned char* img_out1, int size)
{
	int i, j;
	for (i = 0; i < WIDTH; i++)
	{
		for (j = 0; j < HEIGHT; j++)
		{
			img_out1[(WIDTH * 2)*(2 * i) + (2 * j)] = img_in[WIDTH*i + j];
			img_out1[(WIDTH * 2)*(2 * i) + (2 * j + 1)] = img_in[WIDTH*i + j];
			img_out1[(WIDTH * 2)*(2 * i + 1) + (2 * j)] = img_in[WIDTH*i + j];
			img_out1[(WIDTH * 2)*(2 * i + 1) + (2 * j + 1)] = img_in[WIDTH*i + j];
		}
	}
}

void UpSampling_Average(unsigned char* img_in, unsigned char* img_out2, int size)
{
	unsigned char* img_in_pad2=0;
	img_in_pad2 = MemAlloc((WIDTH + 1)*(HEIGHT + 1));
	int i, j;

	for (i = 0; i < WIDTH; i++)
	{
		for (j = 0; j < HEIGHT; j++)
		{
			img_in_pad2[WIDTH*i + j] = img_in[WIDTH*i + j];
		}
	}

	for (i = 0; i < HEIGHT; i++)
	{
		for (j = WIDTH; j < WIDTH+1; j++)
		{
			img_in_pad2[WIDTH*i + (j+1)] = img_in[WIDTH*i + (WIDTH-1)];
		}
	}

	for (j = 1; j < WIDTH; j++)
	{
		for (i = HEIGHT; i < HEIGHT + 1; i++)
		{
			img_in_pad2[WIDTH*(i+1) + j] = img_in[WIDTH*(HEIGHT - 1) + j];
		}
	}

	for (i = HEIGHT; i < HEIGHT+1; i++)
	{
		for (j = WIDTH; j < WIDTH+1; j++)
		{
			img_in_pad2[WIDTH*(i+1) + (j+1)] = img_in[WIDTH*HEIGHT];
		}
	}

	for (int i = 0; i < WIDTH+1; i++)
	{
		for (int j = 0; j < HEIGHT+1; j++)
		{
			img_out2[(WIDTH * 2 + 1)*(2 * i) + (2 * j)] = img_in_pad2[(WIDTH + 1)*i + j];
		}
	}

	for (i = 0; i < WIDTH+1; i++)
	{
		for (j = 0; j < HEIGHT; j++)
		{
			img_out2[(WIDTH * 2 + 1) * (2 * i) + (2 * j+1)] = (img_out2[(WIDTH * 2 + 1) * (2 * i) + (2 * j)] + img_out2[(WIDTH * 2 + 1) * (2 * i) + (2 * j+2)]) / 2;
		}
	}

	for (i = 0; i < WIDTH; i++)
	{
		for (j = 0; j < HEIGHT+1; j++)
		{
			img_out2[(WIDTH * 2 + 1) * (2 * i+1) + (2 * j)] = (img_out2[(WIDTH * 2 + 1) * (2 * i) + (2 * j)] + img_out2[(WIDTH * 2 + 1) * (2 * i+2) + (2 * j)]) / 2;
		}
	}

	for (i = 0; i < WIDTH; i++)
	{
		for (j = 0; j < HEIGHT; j++)
		{
			img_out2[(WIDTH * 2 + 1) * (2 * i+1) + (2 * j+1)] = (img_out2[(WIDTH * 2 + 1) * (2 * i + 1) + (2 * j)] + img_out2[(WIDTH * 2 + 1) * (2 * i + 1) + (2 * j+2)]) / 2;
		}
	}
	free(img_in_pad2);
}

void UpSampling_Interpolation(unsigned char* img_in, unsigned char* img_out3, int size)
{
	int InterpolFilter[8] = { -1, 4, -11, 40, 40, -11, 4, -1 };
	int sum = 64;
	float temp;
	unsigned char* img_in_pad3 = 0, *img_out_pad3 = 0;
	img_in_pad3  = MemAlloc((WIDTH + 7) * (HEIGHT + 7));
	
	img_out_pad3 = MemAlloc(100);
	//img_out_pad3 = MemAlloc((WIDTH + 7) * 2 * (HEIGHT + 7) * 2);
	int i, j, k;

	for (i = 0; i < HEIGHT; i++)  // COPY OK
	{
		for (j = 0; j < WIDTH; j++)
		{
			img_in_pad3[(WIDTH+7) * (i + 3) + (j + 3)] = img_in[WIDTH * i + j];
		}
	}

	for (i = 0; i < 3; i++) //위 패딩
	{
		for (j = 0; j < WIDTH; j++)
		{
			img_in_pad3[(WIDTH + 7) * i + (j + 3)] = img_in[WIDTH * 0 + j];
		}
	}

	for (i = HEIGHT+3; i < HEIGHT+7; i++)  // 아래 패딩
	{
		for (j = 0; j < WIDTH; j++)
		{
			img_in_pad3[(WIDTH + 7) * i + j+3 ] = img_in[WIDTH * (HEIGHT - 1) + j];
		}
	}

	for (i = 0; i < HEIGHT; i++)  // 왼쪽 패딩
	{
		for (j = 0; j < 3; j++)
		{
			img_in_pad3[(WIDTH+7)*(i+3)+j] = img_in[WIDTH * i + 0];
		}
	}

	for (i = 0; i < HEIGHT; i++) // 오른쪽 패딩
	{
		for (j = WIDTH+3; j < WIDTH+7; j++)
		{
			img_in_pad3[(WIDTH + 7) * (i+3) + j] = img_in[WIDTH * i + WIDTH-1];
		}
	}

	for (i = 0; i < 3; i++)  // 북서 패딩
	{
		for (j = 0; j < 3; j++)
		{
			img_in_pad3[(WIDTH + 7) * i + j] = img_in[0];
		}
	}

	for (i = 0; i < 3; i++)  // 북동 패딩
	{
		for (j = 3+WIDTH; j < WIDTH+7; j++)
		{
			img_in_pad3[(WIDTH + 7) * i + j] = img_in[255];
		}
	}

	for (i = 3+HEIGHT; i < HEIGHT+7; i++)  // 남서 패딩
	{
		for (j = 0; j < 3; j++)
		{
			img_in_pad3[(WIDTH + 7) * i + j] = img_in[WIDTH*(HEIGHT-1)];
		}
	}

	for (i = HEIGHT+3; i < HEIGHT+7; i++)  // 남동 패딩
	{
		for (j = WIDTH+3; j < WIDTH+7; j++)
		{
			img_in_pad3[(WIDTH + 7) * i + j] = img_in[WIDTH * HEIGHT-1];
		}
	}

	for (i = 0; i < HEIGHT+7; i++)
	{
		for (j = 0; j < WIDTH+7; j++)
		{
			img_out_pad3[(WIDTH + 7) * 2 * (2 * i) + (2 * j)] = img_in_pad3[(WIDTH + 7) * i + j];
		}
	}

	for (i = 0; i < HEIGHT+7; i++)
	{
		for (j = 0; j < WIDTH; j++)
		{
			temp = 0;
			for (k = 0; k < 8; k++)
			{ 
				temp += InterpolFilter[k] * img_out_pad3[(WIDTH + 7) * 2 * (2 * i) + (2 * j) + (2 * k)];
			}
			img_out_pad3[(WIDTH + 7) * 2 * (2 * i) + 6 + (2 * j + 1)] = (temp / sum);
		}
	}

	for (i = 0; i < HEIGHT; i++)
	{
		for (j = 0; j < 2*WIDTH; j++)
		{
			temp = 0;
			for (k = 0; k < 8; k++)
			{
				temp += InterpolFilter[k] * img_out_pad3[(WIDTH + 7) * 2 * (2 * i + 2 * k) + 6+j];
			}
			img_out_pad3[(WIDTH + 7) * 2 * (6 + (2 * i + 1)) + 6+j] = (temp / sum);
		}
	}

	for (i = 0; i < HEIGHT*2; i++)
	{
		for (j = 0; j < WIDTH*2; j++)
		{
			img_out3[(WIDTH * 2) * i + j] = img_out_pad3[(WIDTH + 7) * 2 * (6 + i) + (6 + j)];
		}
	}

	free(img_in_pad3);
	free(img_out_pad3);
}

void GetPSNR(unsigned char* img_out3_R, unsigned char* img_out3_G, unsigned char* img_out3_B, unsigned char* img_out_R, unsigned char* img_out_G, unsigned char* img_out_B)
{
	int i, j;
	double RPSNR = 0.0, GPSNR=0.0, BPSNR=0.0;
	double RMSE=0.0, GMSE=0.0, BMSE=0.0;
	double TPSNR=0.0;
	for (i = 0; i < 512; i++)
	{
		for (j = 0; j < 512; j++)
		{
			RMSE += pow((double)img_out3_R[512 * i + j] - (double)img_out_R[512 * i + j], 2);
			GMSE += pow((double)img_out3_G[512 * i + j] - (double)img_out_G[512 * i + j], 2);
			BMSE += pow((double)img_out3_B[512 * i + j] - (double)img_out_B[512 * i + j], 2);
		}
	}
	RMSE = RMSE / (512.0 * 512.0);
	GMSE = GMSE / (512.0 * 512.0);
	BMSE = BMSE / (512.0 * 512.0);
	RPSNR = 10.0 * log10((255.0 * 255.0) / RMSE);
	GPSNR = 10.0 * log10((255.0 * 255.0) / GMSE);
	BPSNR = 10.0 * log10((255.0 * 255.0) / BMSE);
	TPSNR = (RPSNR + GPSNR + BPSNR) / 3.0;

	printf("PSNR : %f dB입니다. \n\n", TPSNR);
}