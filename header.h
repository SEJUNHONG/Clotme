#pragma once


double* MemAlloc_d(int length);
unsigned char* MemAlloc(int length);
void FDCT_1D(unsigned char* img_in1, double* img_x, unsigned char* img_out, int size);
void FDCT1_1D(unsigned char* img_in1, double* img_x1, double* img_out1, int size);
void IDCT_1D(double* img_out1, double*img_x2, unsigned char* img_outf, int size);
void FDCT_2D(unsigned char* img_in, unsigned char* img_out2, int size);
void FDCT2_2D(unsigned char* img_in, double* img_out3, int size);
void IDCT_2D(double* img_out3, unsigned char* img_out2f, int size);
void FDCT2L4_2D(unsigned char* img_in, double* img_out2L4, int size);
void FDCT2H36_2D(unsigned char* img_in, double* img_out2H36, int size);
