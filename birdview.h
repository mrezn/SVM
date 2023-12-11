#pragma once
#include <stdio.h>
#include <opencv2/core/core_c.h>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/imgcodecs/imgcodecs_c.h>

void stitch_all_parts(IplImage* front,IplImage* back,IplImage* left,IplImage* right,IplImage* image, CvMatND* weights[4],int yt,int yb,int xr,int xl) ;

void copy_car_image(IplImage* image, IplImage* car_image,int yt,int yb,int xr,int xl) ;

void make_luminance_balance(IplImage* front,IplImage* back,IplImage* left,IplImage* right , CvMat** masks,IplImage* front_new,IplImage* back_new,IplImage* left_new,IplImage* right_new,int yt,int yb,int xr,int xl);