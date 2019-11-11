#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define w	1280
#define h	720

double MAX(double a, double b, double c)
{
	if (a > b)
	{
		if (a > c)
			return a;
		else
			return c;
	}
	else
	{
		if (b > c)
			return b;
		else
			return c;
	}
}

void Read_Frame()
{

}

int *Mem_A(size)
{
	int *arr = 0;

	arr = (int*)malloc(sizeof(int)*size);

	return arr;
}

double *Mem_B(size)
{
	double *arr = 0;

	arr = (double*)malloc(sizeof(double)*size);

	return arr;
}

unsigned char *Mem_C(size)
{
	unsigned char *arr = 0;

	arr = (unsigned char*)malloc(sizeof(unsigned char)*size);

	return arr;
}

int main(void)
{
	FILE*src = 0;
	FILE*des = 0;

	unsigned char *Y = Mem_C(w*h);
	unsigned char *U = Mem_C((w/2)*(h/2));
	unsigned char *V = Mem_C((w/2)*(h/2));

	unsigned char *NU = Mem_C(w*h);
	unsigned char *NV = Mem_C(w*h);

	unsigned char *R = Mem_C(w*h);
	unsigned char *G = Mem_C(w*h);
	unsigned char *B = Mem_C(w*h);

	int *H = Mem_A(w*h);
	double *S = Mem_B(w*h);
	double *VV = Mem_B(w*h);

	unsigned char *max = Mem_C(w*h);

	double *C = Mem_B(w*h);
	double *X = Mem_B(w*h);
	double *m = Mem_B(w*h);

	int hue ;
	double sat ;

	//unsigned char*max=(unsigned char*)malloc(sizeof(unsigned char*))

	src = fopen("RGB_heartshaker_1280x720.rgb", "rb");
	des = fopen("Sepia_heartshaker_1280x720_YUV420.yuv", "wb");

	printf("H값을 입력하세요(0~360): ");
	scanf("%d", &hue);
	printf("S값을 입력하세요(0~1): ");
	scanf("%lf", &sat);

	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			H[w*j + i] = hue;
			S[w*j + i] = sat;
		}
	}

	

	while (1)
	{
		int rread, gread, bread;
		rread = fread(R, sizeof(unsigned char), w * h, src);
		gread = fread(G, sizeof(unsigned char), w * h, src);
		bread = fread(B, sizeof(unsigned char), w * h, src);

		int i, j, k, l;
		
		for (i = 0; i < w; i++)
		{
			for (j = 0; j < h; j++)
			{
				VV[w*j + i] = MAX(R[w*j + i]/255.0, G[w*j + i]/255.0, B[w*j + i]/255.0);
			}
		}
		
		for (i = 0; i < w; i++)
		{
			for (j = 0; j < h; j++)
			{
				C[w*j + i] = (VV[w*j + i]) * S[w*j + i];
				X[w*j + i] = C[w*j + i] * (1.0 - abs(fmod(H[w*j + i] / 60.0, 2) -1.0));
				m[w*j + i] = (VV[w*j + i]) - C[w*j + i];


				if (H[w*j + i] >= 0 && H[w*j + i] < 60)
				{
					R[w*j + i] = (C[w*j + i] + m[w*j + i]) * 255;
					G[w*j + i] = (X[w*j + i] + m[w*j + i]) * 255;
					B[w*j + i] = m[w*j + i] * 255;
				}
				else if (H[w*j + i] >= 60 && H[w*j + i] < 120)
				{
					R[w*j + i] = (X[w*j + i] + m[w*j + i]) * 255;
					G[w*j + i] = (C[w*j + i] + m[w*j + i]) * 255;
					B[w*j + i] = m[w*j + i] * 255;
				}
				else if (H[w*j + i] >= 120 && H[w*j + i] < 180)
				{
					R[w*j + i] = m[w*j + i] * 255;
					G[w*j + i] = (C[w*j + i] + m[w*j + i]) * 255;
					B[w*j + i] = (X[w*j + i] + m[w*j + i]) * 255;
				}
				else if (H[w*j + i] >= 180 && H[w*j + i] < 240)
				{
					R[w*j + i] = m[w*j + i] * 255;
					G[w*j + i] = (X[w*j + i] + m[w*j + i]) * 255;
					B[w*j + i] = (C[w*j + i] + m[w*j + i]) * 255;
				}
				else if (H[w*j + i] >= 240 && H[w*j + i] < 300)
				{
					R[w*j + i] = (X[w*j + i] + m[w*j + i]) * 255;
					G[w*j + i] = m[w*j + i] * 255;
					B[w*j + i] = (C[w*j + i] + m[w*j + i]) * 255;
				}
				else if (H[w*j + i] >= 300 && H[w*j + i] < 360)
				{
					R[w*j + i] = (C[w*j + i] + m[w*j + i]) * 255;
					G[w*j + i] = m[w*j + i] * 255;
					B[w*j + i] = (X[w*j + i] + m[w*j + i]) * 255;
				}
			}
		}

		for (i = 0; i < w; i++)
		{
			for (j = 0; j < h; j++)
			{
				Y[w*j + i] = 0.257*R[w*j + i] + 0.504*G[w*j + i] + 0.098*B[w*j + i] + 16;
				NU[w*j + i] = -0.148*R[w*j + i] - 0.291*G[w*j + i] + 0.439*B[w*j + i] + 128;
				NV[w*j + i] = 0.439*R[w*j + i] - 0.368*G[w*j + i] - 0.071*B[w*j + i] + 128;
			}
		}

		for (k = 0; k < (w / 2); k++)
		{
			for (l = 0; l < (h / 2); l++)
			{
				U[(w / 2)*l + k] = NU[w *(2 * l) + (2 * k)];
			}
		}
		
		for (k = 0; k < (w / 2); k++)
		{
			for (l = 0; l < (h / 2); l++)
			{
				V[(w / 2)*l + k] = NV[w *(2 * l) + (2 * k)];
			}
		}


		if (rread == w * h || gread == w * h || bread == w * h)
		{
			fwrite(Y, sizeof(unsigned char), w * h, des);
			fwrite(U, sizeof(unsigned char), (w/2) * (h/2), des);
			fwrite(V, sizeof(unsigned char), (w/2) * (h/2), des);
		}
		else
			break;
	}

	fclose(src);
	fclose(des);
	free(Y);
	free(U);
	free(V);
	free(NU);
	free(NV);
	free(R);
	free(G);
	free(B);
	free(H);
	free(S);
	free(VV);
	free(max);
	free(C);
	free(X);
	free(m);

	return 0;
}