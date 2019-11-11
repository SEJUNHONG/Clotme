#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE*src = 0;
	FILE*des = 0;

	unsigned char*Y = (unsigned char*)malloc(sizeof(unsigned char) * 960 * 540);
	unsigned char*U = (unsigned char*)malloc(sizeof(unsigned char) * 480 * 270);
	unsigned char*V = (unsigned char*)malloc(sizeof(unsigned char) * 480 * 270);

	src = fopen("BasketballDrive_960x540_YUV420.yuv", "rb");
	des = fopen("BasketballDrive_960x540_YUV444.yuv", "wb");

	while (1)
	{
		int yread, uread, vread;
		yread = fread(Y, sizeof(unsigned char), 960 * 540, src);
		uread = fread(U, sizeof(unsigned char), 480 * 270, src);
		vread = fread(V, sizeof(unsigned char), 480 * 270, src);

		if (yread == 960 * 540 || uread == 480 * 270 || vread == 480 * 270)
		{
			fwrite(Y, sizeof(unsigned char), 960 * 540, src);
			fwrite(U, sizeof(unsigned char), 960 * 540, src);
			fwrite(V, sizeof(unsigned char), 960 * 540, src);
		}
		else
			break;
	}

	fclose(src);
	fclose(des);
	free(Y);
	free(U);
	free(V);

	return 0;
}