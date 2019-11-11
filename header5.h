#pragma once

unsigned char* MemAlloc(int length);
void UpSampling_Copy(unsigned char* img_in, unsigned char* img_out1, int size);
void UpSampling_Average(unsigned char* img_in, unsigned char* img_out2, int size);
void UpSampling_Interpolation(unsigned char* img_in, unsigned char* img_out3, int size);

void GetPSNR(unsigned char* img_out3_R, unsigned char* img_out3_G, unsigned char* img_out3_B, unsigned char* img_out_R, unsigned char* img_out_G, unsigned char* img_out_B);