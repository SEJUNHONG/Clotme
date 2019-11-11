#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LEN		256
#define PI		3.141592653897

double* MemAlloc_d(int length)
{
	double* Y = 0;
	Y = (double*)malloc(sizeof(double)*length);
	return Y;
}

unsigned char* MemAlloc(int length)
{
	unsigned char* X=0;
	X = (unsigned char*)malloc(sizeof(unsigned char)*length);
	return X;
}


void FDCT_1D(unsigned char* img_in1, double* img_x, unsigned char* img_out, int size)
{
	int i = 0, j = 0, m = 0, n = 0, k = 0;
	for (n = 0; n < 32; n++){
		for (m = 0; m < 32; m++){
			for (j = 0; j < 8; j++){
				for(k=0; k<8; k++){
					double temp = 0.0;
					double ntemp = 0.0;
					double a = 0.0;
					if (k == 0){
						a = 1.0 / sqrt(8);}
					else{
						a = 1.0 / 2.0;}
					for (i = 0; i < 8; i++){
						temp += (double) img_in1[LEN*(8 * n + j) + (8 * m + i)] * cos((2 * i + 1)*PI*k / 16.0);}
					ntemp = a*temp;
					img_x[LEN*(8 * n + j) + (8 * m + k)] = ntemp;}}

			for (int k = 0; k < 8; k++){
				for (int j =k+ 1; j < 8; j++){
					double temp;
					temp = img_x[LEN*(8 * n + j) + (8 * m + k)];
					img_x[LEN*(8 * n + j) + (8 * m + k)] = img_x[LEN*(8 * n + k) + (8 * m + j)];
					img_x[LEN*(8 * n + k) + (8 * m + j)] = temp;}}
			
			for (k = 0; k < 8; k++){
				for (i = 0; i < 8; i++) {
					double temp = 0.0;
					double ntemp = 0.0;
					double a = 0.0;
					if (i == 0) {
						a = 1.0 / sqrt(8);}
					else {
						a = 1.0 / 2.0;}
					for (j = 0; j < 8; j++) {
						temp += (double)img_x[LEN*(8 * n + k) + (8 * m + j)] * cos((2 * j + 1)*PI*i / 16.0);}
					ntemp = a * temp;
					if (ntemp < 0)
						ntemp = 0;
					else if (ntemp > 255)
						ntemp = 255;
					img_out[LEN*(8 * n + k) + (8 * m + i)] = (unsigned char)floor(ntemp + 0.5);}}}}
}

void FDCT1_1D(unsigned char* img_in1, double*img_x1, double* img_out1, int size)
{
	int i = 0, j = 0, m = 0, n = 0, k = 0;
	for (n = 0; n < 32; n++)
	{
		for (m = 0; m < 32; m++)
		{
			for (j = 0; j < 8; j++)
			{
				for (k = 0; k < 8; k++)
				{
					double temp = 0.0;
					double ntemp = 0.0;
					double a = 0.0;
					if (k == 0)
					{
						a = 1.0 / sqrt(8);
					}
					else
					{
						a = 1.0 / 2.0;
					}
					for (i = 0; i < 8; i++)
					{
						temp += (double)img_in1[LEN*(8 * n + j) + (8 * m + i)] * cos((2 * i + 1)*PI*k / 16.0);
					}
					ntemp = a * temp;
					img_x1[LEN*(8 * n + j) + (8 * m + k)] = ntemp;
				}
			}

			for (int k = 0; k < 8; k++)
			{
				for (int j = k + 1; j < 8; j++)
				{
					double temp;
					temp = img_x1[LEN*(8 * n + j) + (8 * m + k)];
					img_x1[LEN*(8 * n + j) + (8 * m + k)] = img_x1[LEN*(8 * n + k) + (8 * m + j)];
					img_x1[LEN*(8 * n + k) + (8 * m + j)] = temp;
				}
			}

			for (k = 0; k < 8; k++)
			{
				for (i = 0; i < 8; i++)
				{
					double temp = 0.0;
					double a = 0.0;
					if (i == 0)
					{
						a = 1.0 / sqrt(8);
					}
					else
					{
						a = 1.0 / 2.0;
					}
					for (j = 0; j < 8; j++)
					{
						temp += (double)img_x1[LEN*(8 * n + k) + (8 * m + j)] * cos((2 * j + 1)*PI*i / 16.0);
					}
					img_out1[LEN*(8 * n + k) + (8 * m + i)] = (double) a* temp;
				}
			}
		}
	}
}

void IDCT_1D(double* img_out1, double*img_x2, unsigned char* img_outf, int size)
{
	int k = 0, i = 0, j=0, m = 0, n = 0;
	for (n = 0; n < 32; n++){
		for (m = 0; m < 32; m++){
			for (k = 0; k < 8; k++){
				for (j = 0; j < 8; j++){
					double temp = 0.0;
					for (i = 0; i < 8; i++){
						double a = 0.0;
						if (i == 0){
							a = 1 / sqrt(2);}
						else{
							a = 1.0;}
						temp += (double)a * img_out1[LEN*(8 * n + k) + (8 * m + i)] * cos((2 * j + 1)*PI*i / 16.0);}
				img_x2[LEN*(8 * n + k) + (8 * m + j)] = 0.5*temp;}}

			for (int k = 0; k < 8; k++){
				for (int j = k+1; j < 8; j++){
					double temp;
					temp = img_x2[LEN*(8 * n + k) + (8 * m + j)];
					img_x2[LEN*(8 * n + k) + (8 * m + j)] = img_x2[LEN*(8 * n + j) + (8 * m + k)];
					img_x2[LEN*(8 * n + j) + (8 * m + k)] = temp;}}

			for (j = 0; j < 8; j++){
				for (i = 0; i < 8; i++){
					double temp = 0.0;
					double ntemp = 0.0;
					for (k = 0; k < 8; k++){
						double a = 0.0;
						if (k == 0){
							a = 1 / sqrt(2);}
						else{
							a = 1.0;}
						temp += (double) a * img_x2[LEN*(8 * n + j) + (8 * m + k)] * cos((2 * i + 1)*PI*k / 16.0);}
					ntemp = 0.5*temp;
					if (ntemp < 0)
						ntemp = 0;
					else if (ntemp > 255)
						ntemp = 255;
				img_outf[LEN*(8 * n + j) + (8 * m + i)] = (unsigned char)floor(ntemp + 0.5);}}}}
}

void FDCT_2D(unsigned char* img_in, unsigned char* img_out2, int size)
{
	int i = 0, j = 0, m = 0, n = 0, x=0, y=0;
	for (n = 0; n < 32; n++){
		for (m = 0; m < 32; m++){
			for (y = 0; y < 8; y++){
				for (x = 0; x < 8; x++){
					double temp = 0.0;
					double ntemp = 0.0;
					for (j = 0; j < 8; j++){
						for (i = 0; i < 8; i++){
							temp += (double) img_in[LEN*(8 * n + j) + (8 * m + i)] * cos((2 * i + 1)*PI*x / (2*8))*cos((2 * j + 1)*PI*y / (2*8));}}
					double ax = 0.0, ay=0.0;
					if (x == 0){
						ax = 1/sqrt(2);}
					else{
						ax = 1.0;}
					if (y == 0){
						ay = 1 / sqrt(2);}
					else{
						ay=1.0;}
					ntemp = (ax*ay / 4.0)*temp;
					if (ntemp < 0)
						ntemp = 0;
					else if (ntemp > 255)
						ntemp = 255;
					img_out2[LEN*(8 * n + y) + (8 * m + x)] =  ntemp;}}}}
}

void FDCT2_2D(unsigned char* img_in, double* img_out3, int size)
{
	int i = 0, j = 0, m = 0, n = 0, x = 0, y = 0;
	for (n = 0; n < (32); n++)
	{
		for (m = 0; m < (32); m++)
		{
			for (y = 0; y < 8; y++)
			{
				for (x = 0; x < 8; x++)
				{
					double temp = 0.0;
					for (j = 0; j < 8; j++)
					{
						for (i = 0; i < 8; i++)
						{
							temp += (double)img_in[LEN*(8 * n + j) + (8 * m + i)] * cos((2 * i + 1)*PI*x / (2*8))*cos((2 * j + 1)*PI*y / (2*8));
						}

					}
					double ax = 0.0, ay = 0.0;
					if (x == 0)
					{
						ax = 1.0 / sqrt(2);
					}
					else
					{
						ax = 1.0;
					}

					if (y == 0)
					{
						ay = 1.0 / sqrt(2);
					}
					else
					{
						ay = 1.0;
					}
					img_out3[LEN*(8 * n + y) + (8 * m + x)] = (double)(ax*ay / 4.0)*temp;
				}
			}
		}
	}
}

void IDCT_2D(double* img_out3, unsigned char* img_out2f, int size)
{
	int i = 0, j = 0, m = 0, n = 0, x = 0, y = 0;
	for (n = 0; n < (32); n++){
		for (m = 0; m < 32; m++){
			for (j = 0; j < 8; j++){
				for (i = 0; i < 8; i++){
					double temp = 0.0;
					double ntemp = 0.0;
					for (y = 0; y < 8; y++){
						for (x = 0; x <8 ; x++){
							double ax = 0.0, ay=0.0;
							if (x == 0){
								ax = 1 / sqrt(2);}
							else{
								ax = 1.0;}
							if (y == 0){
								ay = 1 / sqrt(2);}
							else{
								ay = 1.0;}
							temp += (double)(ax*ay / 4.0)*img_out3[LEN*(8 * n + y) + (8 * m + x)] * cos((2 * i + 1)*PI*x / (2*8))*cos((2 * j + 1)*PI*y / (2*8));
							if (temp < 0)
								temp = 0;
							else if (temp > 255)
								temp = 255;
						}
						img_out2f[LEN*(8 * n + j) + (8 * m + i)] = temp;
					}
				}
			}
		}
	}
}

void FDCT2L4_2D(unsigned char* img_in, double* img_out2L4, int size)
{
	int num;
	printf("n°ª ÀÔ·Â (n=2, 4, 6): ");
	scanf("%d", &num);
	int i = 0, j = 0, m = 0, n = 0, x = 0, y = 0;
	for (n = 0; n < 32; n++)
	{
		for (m = 0; m < 32; m++)
		{
			for (y = 0; y < 8; y++)
			{
				for (x = 0; x < 8; x++)
				{
					double temp = 0.0;
					double ntemp = 0.0;
					for (j = 0; j < 8; j++)
					{
						for (i = 0; i < 8; i++)
						{
							temp += (double)img_in[LEN*(8 * n + j) + (8 * m + i)] * cos((2 * i + 1)*PI*x / 16.0)*cos((2 * j + 1)*PI*y / 16.0);
						}

					}
					double ax = 0.0, ay = 0.0;
					if (x == 0)
					{
						ax = 1.0 / sqrt(2);
					}
					else
					{
						ax = 1.0;
					}

					if (y == 0)
					{
						ay = 1.0 / sqrt(2);
					}
					else
					{
						ay = 1.0;
					}
					ntemp = (double)(ax*ay / 4.0)*temp;

					if (x >= num)
						ntemp = 0;
					else if (y >= num)
						ntemp = 0;

					img_out2L4[LEN*(8 * n + y) + (8 * m + x)] = ntemp;
				}
			}
		}
	}
}

void FDCT2H36_2D(unsigned char* img_in, double* img_out2H36, int size)
{
	int i = 0, j = 0, m = 0, n = 0, x = 0, y = 0;
	for (n = 0; n < 32; n++)
	{
		for (m = 0; m < 32; m++)
		{
			for (y = 0; y < 8; y++)
			{
				for (x = 0; x < 8; x++)
				{
					double temp = 0.0;
					double ntemp = 0.0;
					for (j = 0; j < 8; j++)
					{
						for (i = 0; i < 8; i++)
						{
							temp += (double)img_in[LEN*(8 * n + j) + (8 * m + i)] * cos((2 * i + 1)*PI*x / 16.0)*cos((2 * j + 1)*PI*y / 16.0);
						}

					}
					double ax = 0.0, ay = 0.0;
					if (x == 0)
					{
						ax = 1.0 / sqrt(2);
					}
					else
					{
						ax = 1.0;
					}

					if (y == 0)
					{
						ay = 1.0 / sqrt(2);
					}
					else
					{
						ay = 1.0;
					}
					ntemp = (double)(ax*ay / 4.0)*temp;

					if (x < 2)
						ntemp = 0;
					else if (y < 2)
						ntemp = 0;

					img_out2H36[LEN*(8 * n + y) + (8 * m + x)] = ntemp;
				}
			}
		}
	}
}