#pragma once
#include <stdio.h>
#include <string.h>
#include <opencv2/core/core_c.h>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/imgcodecs/imgcodecs_c.h>

void load_weights_and_masks(IplImage* GMatImage, IplImage* MMatImage, CvMat* masks[4], CvMatND* weights[4]);


void  project_action(IplImage* image, double project_matrix[3][3], double project_shape[2],IplImage* result) ;

void load_camera_params(const char* project_matrix_pat , const char* project_shape_path,double project_matrix[3][3],double project_shape[2]) ;
void flip(const char* camera_name, IplImage* image, IplImage* result);
