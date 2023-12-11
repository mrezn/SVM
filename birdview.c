#include <stdio.h>
#include <opencv2/core/core_c.h>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/imgcodecs/imgcodecs_c.h>
#include <math.h> 
// #define TOTAL_H 480
// #define TOTAL_W 640

// const int xl = 100; // Replace with the actual value
// const int xr = 200; // Replace with the actual value
// const int yt = 100; // Replace with the actual value
// const int yb = 200; // Replace with the actual value

void FI(IplImage* inputImage, IplImage* outputImage, int yt, int yb, int xr,int xl, int HEIGHT,int WIDTH){
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < xl; j++) {
            CvScalar pixel = cvGet2D(inputImage, i,j);
            cvSet2D(outputImage, i,j, pixel);
        }
    }
}


void FII(IplImage* inputImage, IplImage* outputImage, int yt, int yb, int xr,int xl, int HEIGHT,int WIDTH) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = xr; j < WIDTH; j++) {
            CvScalar pixel = cvGet2D(inputImage, i,j);
            cvSet2D(outputImage, i,j-xr, pixel);
        }
    }

}

void FM(IplImage* inputImage, IplImage* outputImage, int yt, int yb, int xr,int xl, int HEIGHT,int WIDTH) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = xl; j < xr; j++) {
            CvScalar pixel = cvGet2D(inputImage, i,j);
            cvSet2D(outputImage,i, j-xl, pixel);
        }
    }

}

void BIII(IplImage* inputImage, IplImage* outputImage, int yt, int yb, int xr,int xl, int HEIGHT,int WIDTH) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < xl; j++) {
            CvScalar pixel = cvGet2D(inputImage, i,j);
            cvSet2D(outputImage, i,j, pixel);
        }
    }

}

void BIV(IplImage* inputImage, IplImage* outputImage, int yt, int yb, int xr,int xl, int HEIGHT,int WIDTH) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = xr; j < WIDTH; j++) {
            CvScalar pixel = cvGet2D(inputImage, i,j);
            cvSet2D(outputImage,i,j-xr, pixel);
        }
    }

}

void BM(IplImage* inputImage, IplImage* outputImage, int yt, int yb, int xr,int xl, int HEIGHT,int WIDTH) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = xl; j < xr; j++) {
            CvScalar pixel = cvGet2D(inputImage, i,j);
            cvSet2D(outputImage,i,j-xl, pixel);
        }
    }

}

void LI(IplImage* inputImage, IplImage* outputImage, int yt, int yb, int xr,int xl, int HEIGHT,int WIDTH) {
    for (int i = 0; i < yt; i++) {
        for (int j = 0; j < WIDTH; j++) {
            CvScalar pixel = cvGet2D(inputImage, i,j);
            cvSet2D(outputImage, i,j, pixel);
        }
    }

}

void LIII(IplImage* inputImage, IplImage* outputImage, int yt, int yb, int xr,int xl, int HEIGHT,int WIDTH) {
    for (int i = yb; i <HEIGHT ; i++) {
        for (int j = 0; j < WIDTH ; j++) {
            CvScalar pixel = cvGet2D(inputImage, i,j);
            cvSet2D(outputImage,i-yb,j, pixel);
        }
    }

}
void LM(IplImage* inputImage, IplImage* outputImage, int yt, int yb, int xr,int xl, int HEIGHT,int WIDTH) {
    for (int i = yt; i < yb; i++) {
        for (int j = 0; j <WIDTH ; j++) {
            CvScalar pixel = cvGet2D(inputImage,i,j);
            cvSet2D(outputImage,i-yt,j, pixel);
        }
    }

}
void RII(IplImage* inputImage, IplImage* outputImage, int yt, int yb, int xr,int xl, int HEIGHT,int WIDTH) {
    for (int i = 0; i <yt ; i++) {
        for (int j = 0; j < WIDTH ; j++) {
            CvScalar pixel = cvGet2D(inputImage,i,j);
            cvSet2D(outputImage, i,j, pixel);
        }
    }

}
void RIV(IplImage* inputImage, IplImage* outputImage, int yt, int yb, int xr,int xl, int HEIGHT,int WIDTH) {
    for (int i = yb; i < HEIGHT; i++) {
        for (int j =0 ; j <WIDTH ; j++) {
            CvScalar pixel = cvGet2D(inputImage, i,j);
            cvSet2D(outputImage,i-yb,j, pixel);
        }
    }

}

void RM(IplImage* inputImage, IplImage* outputImage, int yt, int yb, int xr,int xl, int HEIGHT,int WIDTH) {
    for (int i = yt; i <yb ; i++) {
        for (int j = 0; j <WIDTH ; j++) {
            CvScalar pixel = cvGet2D(inputImage, i,j);
            cvSet2D(outputImage,i-yt,j, pixel);
        }
    }

}
///////////////image///////////////////////
void FL(IplImage* inputImage, IplImage* outputImage, int yt, int yb, int xr,int xl, int HEIGHT,int WIDTH) {
    for (int i = 0; i < yt; i++) {
        for (int j = 0; j < xl; j++) {
            CvScalar pixel = cvGet2D(inputImage, i,j);
            cvSet2D(outputImage,i,j, pixel);
        }
    }

}


void F(IplImage* inputImage, IplImage* outputImage, int yt, int yb, int xr,int xl, int HEIGHT,int WIDTH) {
    for (int i = 0; i < yt; i++) {
        for (int j = xl; j < xr; j++) {
            CvScalar pixel = cvGet2D(inputImage, i,j-xl);
            cvSet2D(outputImage, i,j, pixel);
        }
    }

}

void FR(IplImage* inputImage, IplImage* outputImage, int yt, int yb, int xr,int xl, int HEIGHT,int WIDTH) {
    for (int i = 0; i < yt; i++) {
        for (int j = xr; j < WIDTH; j++) {
            CvScalar pixel = cvGet2D(inputImage, i,j-xr);
            cvSet2D(outputImage, i,j, pixel);
        }
    }

}

void BL(IplImage* inputImage, IplImage* outputImage, int yt, int yb, int xr,int xl, int HEIGHT,int WIDTH) {
    for (int i = yb; i < HEIGHT; i++) {
        for (int j = 0; j < xl; j++) {
            CvScalar pixel = cvGet2D(inputImage, i-yb,j);
            cvSet2D(outputImage,i,j, pixel);
        }
    }

}
void B(IplImage* inputImage, IplImage* outputImage, int yt, int yb, int xr,int xl, int HEIGHT,int WIDTH) {
    for (int i = yb; i < HEIGHT; i++) {
        for (int j = xl; j < xr; j++) {
            CvScalar pixel = cvGet2D(inputImage,i-yb,j-xl);
            cvSet2D(outputImage,i,j, pixel);
        }
    }

}
void BR(IplImage* inputImage, IplImage* outputImage, int yt, int yb, int xr,int xl, int HEIGHT,int WIDTH){
    for (int i = yb; i < HEIGHT; i++) {
        for (int j = xr; j < WIDTH; j++) {
            CvScalar pixel = cvGet2D(inputImage, i-yb, j-xr);
            cvSet2D(outputImage, i,j, pixel);
        }
    }

}
void L(IplImage* inputImage, IplImage* outputImage, int yt, int yb, int xr,int xl, int HEIGHT,int WIDTH) {
    for (int i = yt; i < yb; i++) {
        for (int j = 0; j < xl; j++) {
            CvScalar pixel = cvGet2D(inputImage, i-yt,j);
            cvSet2D(outputImage, i,j, pixel);
        }
    }

}
void R(IplImage* inputImage, IplImage* outputImage, int yt, int yb, int xr,int xl, int HEIGHT,int WIDTH) {
    for (int i = yt ; i < yb; i++) {
        for (int j =xr ; j < WIDTH; j++) {
            CvScalar pixel = cvGet2D(inputImage, i-yt,j-xr);
            cvSet2D(outputImage,i,j, pixel);
        }
    }

}
void C(IplImage* inputImage, IplImage* outputImage, int yt, int yb, int xr,int xl, int HEIGHT,int WIDTH) {
    for (int i = yt; i < yb; i++) {
        for (int j = xl; j < xr; j++) {
            CvScalar pixel = cvGet2D(inputImage, i-yt,j-xl);
            cvSet2D(outputImage, i,j, pixel);
        }
    }
}


void merge(IplImage* imA, IplImage* imB, int k, CvMatND* weights[4],IplImage* result) {
    // Create a new IplImage to store the merged result
    // IplImage* result = cvCreateImage(cvGetSize(imA), IPL_DEPTH_8U, 3);

    // Extract weight matrix for the given index k
    CvMatND* G = weights[k];
    if(k==2){
        printf("imA->height:%d,imA->width:%d\n",imA->height,imA->width);
        float r111 = cvGetReal3D(weights[0], 123, 267, 0); // Red component
        float g111 = cvGetReal3D(weights[0], 123, 267, 1); // Green component
        float b111 = cvGetReal3D(weights[0], 123, 267, 2);
        printf("r111:%f,g111:%f,b111:%f\n",r111,g111,b111);

    }
    // Iterate through the pixels and perform the weighted merge operation
    for (int y = 0; y < imA->height; y++) {
        for (int x = 0; x < imA->width; x++) {
            // Extract pixel values from imA and imB
            CvScalar pixelA = cvGet2D(imA, y, x);
            CvScalar pixelB = cvGet2D(imB, y, x);

            // Extract weight value for the current pixel
            // double weight = cvmGet(G, y, x);
            float r = cvGetReal3D(G, y, x, 0); // Red component
            float g = cvGetReal3D(G, y, x, 1); // Green component
            float b = cvGetReal3D(G, y, x, 2);

            // Compute weighted merge operation
            CvScalar mergedPixel;
            mergedPixel.val[0] = pixelA.val[0] *  r + pixelB.val[0] * (1 -  r);
            mergedPixel.val[1] = pixelA.val[1] * g + pixelB.val[1] * (1 - g);
            mergedPixel.val[2] = pixelA.val[2] * b + pixelB.val[2] * (1 - b);

            // Set the merged pixel to the result image
            cvSet2D(result, y, x, mergedPixel);
        }
    }
}

void stitch_parts(IplImage* im1, IplImage* im2) {
    cvCopy(im2, im1, NULL);
    // return im1;
}



void stitch_all_parts(IplImage* front,IplImage* back,IplImage* left,IplImage* right,IplImage* image, CvMatND* weights[4],int yt,int yb,int xr,int xl) {
    // IplImage* front = cvLoadImage(front_path,CV_LOAD_IMAGE_UNCHANGED);
    // IplImage* back = cvLoadImage(back_path,CV_LOAD_IMAGE_UNCHANGED);
    // IplImage* left = cvLoadImage(left_path,CV_LOAD_IMAGE_UNCHANGED);
    // IplImage* right = cvLoadImage(right_path,CV_LOAD_IMAGE_UNCHANGED);
 
    // int yt = 100;
    // int yb = 900;
    // int xr = 150;
    // int xl = 150;



    // IplImage* FM_img = cvCreateImage(cvSize( xr-xl,front->height), IPL_DEPTH_8U, front->nChannels);
    // IplImage* BM_img = cvCreateImage(cvSize( xr-xl,back->height), IPL_DEPTH_8U, back->nChannels);
    // IplImage* LM_img = cvCreateImage(cvSize(left->width,yb - yt ), IPL_DEPTH_8U, left->nChannels);
    // IplImage* RM_img = cvCreateImage(cvSize(right->width,yb - yt ), IPL_DEPTH_8U, right->nChannels);
    // IplImage* FI_img = cvCreateImage(cvSize(xl,front->height ), IPL_DEPTH_8U, front->nChannels);
    // IplImage* LI_img = cvCreateImage(cvSize( left->width,yt ), IPL_DEPTH_8U, left->nChannels);
    // IplImage* FII_img = cvCreateImage(cvSize(front->width - xr,front->height), IPL_DEPTH_8U, front->nChannels);
    // IplImage* RII_img = cvCreateImage(cvSize(right->width,yt ), IPL_DEPTH_8U, right->nChannels);
    // IplImage* BIII_img = cvCreateImage(cvSize(xl,back->height), IPL_DEPTH_8U, back->nChannels);
    // IplImage* LIII_img = cvCreateImage(cvSize(left->width ,left->height - yb), IPL_DEPTH_8U, left->nChannels);
    // IplImage* RIV_img = cvCreateImage(cvSize(right->width,right->height - yb), IPL_DEPTH_8U, right->nChannels);
    // IplImage* BIV_img = cvCreateImage(cvSize(back->width - xr,back->height), IPL_DEPTH_8U, back->nChannels);

    IplImage* FM_img = cvCreateImage(cvSize( xr-xl,510), IPL_DEPTH_8U, front->nChannels);
    IplImage* BM_img = cvCreateImage(cvSize( xr-xl,510), IPL_DEPTH_8U, back->nChannels);
    IplImage* LM_img = cvCreateImage(cvSize(380,yb - yt ), IPL_DEPTH_8U, left->nChannels);
    IplImage* RM_img = cvCreateImage(cvSize(380,yb - yt ), IPL_DEPTH_8U, right->nChannels);
    IplImage* FI_img = cvCreateImage(cvSize(xl,510 ), IPL_DEPTH_8U, front->nChannels);
    IplImage* LI_img = cvCreateImage(cvSize( 380,yt ), IPL_DEPTH_8U, left->nChannels);
    IplImage* FII_img = cvCreateImage(cvSize(910 - xr,510), IPL_DEPTH_8U, front->nChannels);
    IplImage* RII_img = cvCreateImage(cvSize(380,yt ), IPL_DEPTH_8U, right->nChannels);
    IplImage* BIII_img = cvCreateImage(cvSize(xl,510), IPL_DEPTH_8U, back->nChannels);
    IplImage* LIII_img = cvCreateImage(cvSize(380 ,1130- yb), IPL_DEPTH_8U, left->nChannels);
    IplImage* RIV_img = cvCreateImage(cvSize(380,1130 - yb), IPL_DEPTH_8U, right->nChannels);
    IplImage* BIV_img = cvCreateImage(cvSize(910 - xr,510), IPL_DEPTH_8U, back->nChannels);

    // IplImage* F_img = cvCreateImage(cvSize(yt, xr-xl), IPL_DEPTH_8U, image->nChannels);
    // IplImage* B_img = cvCreateImage(cvSize(image->width-yb,xr- xl), IPL_DEPTH_8U, image->nChannels);
    // IplImage* L_img = cvCreateImage(cvSize(yb-yt, xl), IPL_DEPTH_8U, image->nChannels);
    // IplImage* R_img = cvCreateImage(cvSize(yb-yt, image->height - xr), IPL_DEPTH_8U, image->nChannels);
    // IplImage* FL_img = cvCreateImage(cvSize(yt, xl), IPL_DEPTH_8U, image->nChannels);
    // IplImage* FR_img = cvCreateImage(cvSize(yt, image->height - xr), IPL_DEPTH_8U, image->nChannels);
    // IplImage* BL_img = cvCreateImage(cvSize( image->width-yb, xl), IPL_DEPTH_8U, image->nChannels);
    // IplImage* BR_img = cvCreateImage(cvSize( image->width-yb, image->height - xr), IPL_DEPTH_8U, image->nChannels);

    // printf("xr:%d\n,  xl:%d\n,   front->height:%d\n,front->width :%d\n",xr,  xl,   front->height,front->width);

    FM(front, FM_img,   yt,   yb,   xr,  xl,   front->height,  front->width);
    // printf("xr:%d\n,  xl:%d\n,   back->height:%d\n,back->width :%d\n",xr,  xl,   back->height,back->width);

    BM(back, BM_img,  yt,   yb,   xr,  xl,   back->height,  back->width);
    LM(left, LM_img,  yt,   yb,   xr,  xl,   left->height,  left->width);

    RM(right, RM_img,  yt,   yb,   xr,  xl,   right->height,  right->width);
    FI(front, FI_img,  yt,   yb,   xr,  xl,   front->height,  front->width);
    LI(left, LI_img,  yt,   yb,   xr,  xl,   left->height,  left->width);

    FII(front, FII_img,  yt,   yb,   xr,  xl,   front->height,  front->width);
    RII(right, RII_img,  yt,   yb,   xr,  xl,   right->height,  right->width);
    BIII(back, BIII_img,  yt,   yb,   xr,  xl,  back->height, back->width);
    LIII(left, LIII_img,  yt,  yb,  xr, xl,  left->height, left->width);
    
    // cvSaveImage("back88888888.jpg", back, 0);
    // cvSaveImage("left88888888.jpg", left, 0);

    RIV(right, RIV_img,  yt,  yb,  xr, xl,  right->height, right->width);
    BIV(back, BIV_img,  yt,  yb, xr,  xl, back->height, back->width);

    // F(image, F_img,   yt,   yb,   xr,  xl,   image->height,   image->width);
    // B(image, B_img,   yt,   yb,   xr,  xl,   image->height,   image->width);
    // L(image, L_img,   yt,   yb,   xr,  xl,   image->height,   image->width);
    // R(image, R_img,   yt,   yb,   xr,  xl,   image->height,   image->width);
    // FL(image, FL_img,   yt,   yb,   xr,  xl,   image->height,   image->width);
    // FR(image, FR_img,   yt,   yb,   xr,  xl,   image->height,   image->width);
    // BL(image, BL_img,   yt,   yb,   xr,  xl,   image->height,   image->width);
    // BR(image, BR_img,   yt,   yb,   xr,  xl,   image->height,   image->width);


    // IplImage* merge_FI_LI =  cvCreateImage(cvGetSize(FI_img), IPL_DEPTH_8U, 3);
    // IplImage* merge_FII_RII =  cvCreateImage(cvGetSize(FII_img), IPL_DEPTH_8U, 3);
    // IplImage* merge_BIII_LIII =  cvCreateImage(cvGetSize(BIII_img), IPL_DEPTH_8U, 3);
    // IplImage* merge_BIV_RIV =  cvCreateImage(cvGetSize(BIV_img), IPL_DEPTH_8U, 3);

    IplImage* merge_FI_LI =  cvCreateImage(cvSize(xl,510), IPL_DEPTH_8U, 3);
    IplImage* merge_FII_RII =  cvCreateImage(cvSize(910 - xr,510), IPL_DEPTH_8U, 3);
    IplImage* merge_BIII_LIII =  cvCreateImage(cvSize(xl,510), IPL_DEPTH_8U, 3);
    IplImage* merge_BIV_RIV =  cvCreateImage(cvSize(910 - xr,510), IPL_DEPTH_8U, 3);

    merge(FI_img, LI_img, 0,  weights, merge_FI_LI );
    merge(FII_img, RII_img, 1,  weights, merge_FII_RII );
    merge(BIII_img, LIII_img, 2,  weights, merge_BIII_LIII );
    merge(BIV_img, RIV_img, 3,  weights, merge_BIV_RIV );

    // cvSaveImage("LIII_img88888888.jpg", LIII_img, 0);
    // cvSaveImage("BIII_img88888888.jpg", BIII_img, 0);

    F( FM_img,image,  yt,  yb,  xr, xl, image->height ,image->width);
    B( BM_img,image,  yt,  yb,  xr, xl, image->height ,image->width);

    L( LM_img,image,  yt,  yb,  xr, xl, image->height ,image->width);

    R( RM_img,image,  yt,  yb,  xr, xl,  image->height ,image->width);

    FL( merge_FI_LI,image,  yt,  yb,  xr, xl,  image->height ,image->width);
    FR( merge_FII_RII,image,  yt,  yb,  xr, xl,  image->height ,image->width);
    // cvSaveImage("image88888888.jpg", image, 0);
    // cvSaveImage("merge_BIII_LIII88888888.jpg", merge_BIII_LIII, 0);

    BL( merge_BIII_LIII,image,  yt,  yb,  xr, xl,  image->height ,image->width);

    BR( merge_BIV_RIV,image,  yt,  yb,  xr, xl, image->height ,image->width);

    cvReleaseImage(&FM_img);
    cvReleaseImage(&BM_img);
    cvReleaseImage(&LM_img);
    cvReleaseImage(&RM_img);
    cvReleaseImage(&FI_img);
    cvReleaseImage(&LI_img);
    cvReleaseImage(&FII_img);
    cvReleaseImage(&RII_img);
    cvReleaseImage(&BIII_img);
    cvReleaseImage(&LIII_img);
    cvReleaseImage(&RIV_img);
    cvReleaseImage(&BIV_img);
    cvReleaseImage(&merge_FI_LI);
    cvReleaseImage(&merge_FII_RII);
    cvReleaseImage(&merge_BIII_LIII);
    cvReleaseImage(&merge_BIV_RIV);
    // stitch_parts(F_img, FM_img);
    // stitch_parts(B_img, BM_img);
    // stitch_parts(L_img, LM_img);
    // stitch_parts(R_img, RM_img);
    // stitch_parts(FL_img, merge_FI_LI);
    // stitch_parts(FR_img, merge_FII_RII);
    // stitch_parts(BL_img, merge_BIII_LIII);
    // stitch_parts(BR_img, merge_BIV_RIV);
    // return BR_img,BL_img,FR_img
}

void copy_car_image(IplImage* image, IplImage* car_image,int yt,int yb,int xr,int xl) {
    

    C(car_image, image,  yt,  yb, xr, xl, image->height ,image->width);
    // cvCopy(im2, im1, NULL);
}

void splitChannels(IplImage* front, IplImage* Fb, IplImage* Fg, IplImage* Fr) {
    // Splitting the channels of the input image
    CvSize size = cvGetSize(front);
    cvSetImageROI(front, cvRect(0, 0, size.width, size.height));

    cvSplit(front, Fb, Fg, Fr, NULL);
}

double calculateLuminance(CvMat* masks[4], IplImage* im1, IplImage* im2, int n) {
    CvMat* m2;
    m2= masks[n];  // Assuming you are using the second mask (index 1) for calculations

    double sum1 = 0, sum2 = 0;

    // Calculate the weighted sum of im1 and im2 using the mask m2
    for (int i = 0; i < m2->rows; i++) {
        for (int j = 0; j < m2->cols; j++) {
            double maskValue = cvGet2D(m2, i, j).val[0];
            double im1Value = cvGet2D(im1, i, j).val[0];
            double im2Value = cvGet2D(im2, i, j).val[0];

            sum1 += im1Value * maskValue;
            sum2 += im2Value * maskValue;
        }
    }

    if (sum2 != 0) {
        return sum1 / sum2;
    } else {
        // Handle the case where sum2 is 0 to avoid division by zero
        return 0.0;
    }
}
double cal0(double a1, double b1, double c1, double d1) {
    double t1 = pow(a1 * b1 * c1 * d1, 0.25);
    return t1;

}
double cal1(double a1, double d1, double t1) {
    double x = t1 / sqrt(d1 / a1);

    if (x >= 1) {
        x = x * exp((1 - x) * 0.5);
    } else {
        x = x * exp((1 - x) * 0.8);
    }

    return x;
}

void cal2(double x1, IplImage* im1,IplImage* result) {
    // IplImage* result = cvCreateImage(cvGetSize(im1), IPL_DEPTH_8U, 1);
    cvScale(im1, result, 1.5 * x1, 0);
    cvThreshold(result, result, 255, 0, CV_THRESH_TRUNC);
    // return result;
}

void cal3(IplImage* Fb, IplImage* Fg, IplImage* Fr,IplImage* img) {
    // Create an empty 3-channel image with the same size as Fb, Fg, and Fr
    // IplImage* img = cvCreateImage(cvGetSize(Fb), IPL_DEPTH_8U, 3);
    
    // Merge the three channels into a single image
    cvMerge(Fb, Fg, Fr, NULL, img);
    
    // return img;
}

void make_luminance_balance(IplImage* front,IplImage* back,IplImage* left,IplImage* right , CvMat* masks[4],IplImage* front_new,IplImage* back_new,IplImage* left_new,IplImage* right_new,int yt,int yb,int xr,int xl){

    // int yt = 100;
    // int yb = 900;
    // int xr = 150;
    // int xl = 150;



    // IplImage* Fb = cvCreateImage(cvSize(front->width, front->height), IPL_DEPTH_8U, 1);
    // IplImage* Fg = cvCreateImage(cvSize(front->width, front->height), IPL_DEPTH_8U, 1);
    // IplImage* Fr = cvCreateImage(cvSize(front->width, front->height), IPL_DEPTH_8U, 1);

    // IplImage* Bb = cvCreateImage(cvSize(back->width, back->height), IPL_DEPTH_8U, 1);
    // IplImage* Bg = cvCreateImage(cvSize(back->width, back->height), IPL_DEPTH_8U, 1);
    // IplImage* Br = cvCreateImage(cvSize(back->width, back->height), IPL_DEPTH_8U, 1);

    // IplImage* Lb = cvCreateImage(cvSize(left->width, left->height), IPL_DEPTH_8U, 1);
    // IplImage* Lg = cvCreateImage(cvSize(left->width, left->height), IPL_DEPTH_8U, 1);
    // IplImage* Lr = cvCreateImage(cvSize(left->width, left->height), IPL_DEPTH_8U, 1);

    // IplImage* Rb = cvCreateImage(cvSize(right->width, right->height), IPL_DEPTH_8U, 1);
    // IplImage* Rg = cvCreateImage(cvSize(right->width, right->height), IPL_DEPTH_8U, 1);
    // IplImage* Rr = cvCreateImage(cvSize(right->width, right->height), IPL_DEPTH_8U, 1);


    IplImage* Fb = cvCreateImage(cvSize(910,510), IPL_DEPTH_8U, 1);
    IplImage* Fg = cvCreateImage(cvSize(910,510), IPL_DEPTH_8U, 1);
    IplImage* Fr = cvCreateImage(cvSize(910,510), IPL_DEPTH_8U, 1);

    IplImage* Bb = cvCreateImage(cvSize(910,510), IPL_DEPTH_8U, 1);
    IplImage* Bg = cvCreateImage(cvSize(910,510), IPL_DEPTH_8U, 1);
    IplImage* Br = cvCreateImage(cvSize(910,510), IPL_DEPTH_8U, 1);

    IplImage* Lb = cvCreateImage(cvSize(380,1130), IPL_DEPTH_8U, 1);
    IplImage* Lg = cvCreateImage(cvSize(380,1130), IPL_DEPTH_8U, 1);
    IplImage* Lr = cvCreateImage(cvSize(380,1130), IPL_DEPTH_8U, 1);

    IplImage* Rb = cvCreateImage(cvSize(380,1130), IPL_DEPTH_8U, 1);
    IplImage* Rg = cvCreateImage(cvSize(380,1130), IPL_DEPTH_8U, 1);
    IplImage* Rr = cvCreateImage(cvSize(380,1130), IPL_DEPTH_8U, 1);


    splitChannels(front, Fb,  Fg, Fr);
    splitChannels(back, Bb,  Bg, Br);
    splitChannels(left, Lb,  Lg, Lr);
    splitChannels(right, Rb,  Rg, Rr);

    // IplImage* RII_img_Rb = cvCreateImage(cvSize( right->width,yt), IPL_DEPTH_8U, 1);
    // IplImage* RII_img_Rg = cvCreateImage(cvSize( right->width,yt), IPL_DEPTH_8U, 1);
    // IplImage* RII_img_Rr = cvCreateImage(cvSize( right->width,yt), IPL_DEPTH_8U, 1);

    // IplImage* FII_img_Fb = cvCreateImage(cvSize(front->width-xr,front->height ), IPL_DEPTH_8U, 1);
    // IplImage* FII_img_Fg = cvCreateImage(cvSize(front->width-xr,front->height ), IPL_DEPTH_8U, 1);
    // IplImage* FII_img_Fr = cvCreateImage(cvSize(front->width-xr,front->height ), IPL_DEPTH_8U, 1);

    // IplImage* BIV_img_Bb = cvCreateImage(cvSize(back->width-xr,back->height ), IPL_DEPTH_8U, 1);
    // IplImage* BIV_img_Bg = cvCreateImage(cvSize(back->width-xr,back->height ), IPL_DEPTH_8U, 1);
    // IplImage* BIV_img_Br = cvCreateImage(cvSize(back->width-xr,back->height ), IPL_DEPTH_8U, 1);

    // IplImage* RIV_img_Rb = cvCreateImage(cvSize(right->width,right->height-yb ), IPL_DEPTH_8U, 1);
    // IplImage* RIV_img_Rg = cvCreateImage(cvSize(right->width,right->height-yb ), IPL_DEPTH_8U, 1);
    // IplImage* RIV_img_Rr = cvCreateImage(cvSize(right->width,right->height-yb ), IPL_DEPTH_8U, 1);

    // IplImage* LIII_img_Lb = cvCreateImage(cvSize(left->width,left->height-yb ), IPL_DEPTH_8U, 1);
    // IplImage* LIII_img_Lg = cvCreateImage(cvSize(left->width,left->height-yb ), IPL_DEPTH_8U, 1);
    // IplImage* LIII_img_Lr = cvCreateImage(cvSize(left->width,left->height-yb ), IPL_DEPTH_8U, 1);

    // IplImage* BIII_img_Bb = cvCreateImage(cvSize(xl,back->height ), IPL_DEPTH_8U, 1);
    // IplImage* BIII_img_Bg = cvCreateImage(cvSize(xl,back->height ), IPL_DEPTH_8U, 1);
    // IplImage* BIII_img_Br = cvCreateImage(cvSize(xl,back->height ), IPL_DEPTH_8U, 1);

    // IplImage* FI_img_Fb = cvCreateImage(cvSize(xl,front->height ), IPL_DEPTH_8U, 1);
    // IplImage* FI_img_Fg = cvCreateImage(cvSize(xl,front->height ), IPL_DEPTH_8U, 1);
    // IplImage* FI_img_Fr = cvCreateImage(cvSize(xl,front->height ), IPL_DEPTH_8U, 1);

    // IplImage* LI_img_Lb = cvCreateImage(cvSize(left->width,yt ), IPL_DEPTH_8U, 1);
    // IplImage* LI_img_Lg = cvCreateImage(cvSize(left->width,yt ), IPL_DEPTH_8U, 1);
    // IplImage* LI_img_Lr = cvCreateImage(cvSize(left->width,yt ), IPL_DEPTH_8U, 1);

    IplImage* RII_img_Rb = cvCreateImage(cvSize( 380,yt), IPL_DEPTH_8U, 1);
    IplImage* RII_img_Rg = cvCreateImage(cvSize( 380,yt), IPL_DEPTH_8U, 1);
    IplImage* RII_img_Rr = cvCreateImage(cvSize( 380,yt), IPL_DEPTH_8U, 1);

    IplImage* FII_img_Fb = cvCreateImage(cvSize(910-xr,510 ), IPL_DEPTH_8U, 1);
    IplImage* FII_img_Fg = cvCreateImage(cvSize(910-xr,510 ), IPL_DEPTH_8U, 1);
    IplImage* FII_img_Fr = cvCreateImage(cvSize(910-xr,510 ), IPL_DEPTH_8U, 1);

    IplImage* BIV_img_Bb = cvCreateImage(cvSize(910-xr,510), IPL_DEPTH_8U, 1);
    IplImage* BIV_img_Bg = cvCreateImage(cvSize(910-xr,510), IPL_DEPTH_8U, 1);
    IplImage* BIV_img_Br = cvCreateImage(cvSize(910-xr,510), IPL_DEPTH_8U, 1);

    IplImage* RIV_img_Rb = cvCreateImage(cvSize(380,1130-yb ), IPL_DEPTH_8U, 1);
    IplImage* RIV_img_Rg = cvCreateImage(cvSize(380,1130-yb ), IPL_DEPTH_8U, 1);
    IplImage* RIV_img_Rr = cvCreateImage(cvSize(380,1130-yb ), IPL_DEPTH_8U, 1);

    IplImage* LIII_img_Lb = cvCreateImage(cvSize(380,1130-yb ), IPL_DEPTH_8U, 1);
    IplImage* LIII_img_Lg = cvCreateImage(cvSize(380,1130-yb ), IPL_DEPTH_8U, 1);
    IplImage* LIII_img_Lr = cvCreateImage(cvSize(380,1130-yb ), IPL_DEPTH_8U, 1);

    IplImage* BIII_img_Bb = cvCreateImage(cvSize(xl,510), IPL_DEPTH_8U, 1);
    IplImage* BIII_img_Bg = cvCreateImage(cvSize(xl,510), IPL_DEPTH_8U, 1);
    IplImage* BIII_img_Br = cvCreateImage(cvSize(xl,510), IPL_DEPTH_8U, 1);

    IplImage* FI_img_Fb = cvCreateImage(cvSize(xl,510 ), IPL_DEPTH_8U, 1);
    IplImage* FI_img_Fg = cvCreateImage(cvSize(xl,510 ), IPL_DEPTH_8U, 1);
    IplImage* FI_img_Fr = cvCreateImage(cvSize(xl,510 ), IPL_DEPTH_8U, 1);

    IplImage* LI_img_Lb = cvCreateImage(cvSize(380,yt ), IPL_DEPTH_8U, 1);
    IplImage* LI_img_Lg = cvCreateImage(cvSize(380,yt ), IPL_DEPTH_8U, 1);
    IplImage* LI_img_Lr = cvCreateImage(cvSize(380,yt ), IPL_DEPTH_8U, 1);



    RII(Rb, RII_img_Rb,   yt,   yb,   xr,  xl,   right->height,  right->width);
    RII(Rg, RII_img_Rg,   yt,   yb,   xr,  xl,   right->height,  right->width);
    RII(Rr, RII_img_Rr,   yt,   yb,   xr,  xl,   right->height,  right->width);

    FII(Fb, FII_img_Fb,   yt,   yb,   xr,  xl,   front->height,  front->width);
    FII(Fg, FII_img_Fg,   yt,   yb,   xr,  xl,   front->height,  front->width);
    FII(Fr, FII_img_Fr,   yt,   yb,   xr,  xl,   front->height,  front->width);

    BIV(Bb, BIV_img_Bb,   yt,   yb,   xr,  xl,   back->height,  back->width);
    BIV(Bg, BIV_img_Bg,   yt,   yb,   xr,  xl,   back->height,  back->width);
    BIV(Br, BIV_img_Br,   yt,   yb,   xr,  xl,   back->height,  back->width);

    RIV(Rb, RIV_img_Rb,   yt,   yb,   xr,  xl,   right->height,  right->width);
    RIV(Rg, RIV_img_Rg,   yt,   yb,   xr,  xl,   right->height,  right->width);
    RIV(Rr, RIV_img_Rr,   yt,   yb,   xr,  xl,   right->height,  right->width);

    LIII(Lb, LIII_img_Lb ,   yt,   yb,   xr,  xl,   left->height,  left->width);
    LIII(Lg, LIII_img_Lg ,   yt,   yb,   xr,  xl,   left->height,  left->width);
    LIII(Lr, LIII_img_Lr ,   yt,   yb,   xr,  xl,   left->height,  left->width);

    BIII(Bb, BIII_img_Bb,   yt,   yb,   xr,  xl,   back->height,  back->width);
    BIII(Bg, BIII_img_Bg,   yt,   yb,   xr,  xl,   back->height,  back->width);
    BIII(Br, BIII_img_Br,   yt,   yb,   xr,  xl,   back->height,  back->width);

    FI(Fb, FI_img_Fb,   yt,   yb,   xr,  xl,   front->height,  front->width);
    FI(Fb, FI_img_Fg,   yt,   yb,   xr,  xl,   front->height,  front->width);
    FI(Fb, FI_img_Fr,   yt,   yb,   xr,  xl,   front->height,  front->width);

    LI(Lb, LI_img_Lb,   yt,   yb,   xr,  xl,   left->height,  left->width);
    LI(Lg, LI_img_Lg,   yt,   yb,   xr,  xl,   left->height,  left->width);
    LI(Lr, LI_img_Lr,   yt,   yb,   xr,  xl,   left->height,  left->width);

    double a1=calculateLuminance( masks,  RII_img_Rb,  FII_img_Fb, 1);
    double a2=calculateLuminance( masks,  RII_img_Rg,  FII_img_Fg, 1);
    double a3=calculateLuminance( masks,  RII_img_Rr,  FII_img_Fr, 1);

    double b1=calculateLuminance( masks,  BIV_img_Bb,  RIV_img_Rb, 3);
    double b2=calculateLuminance( masks,  BIV_img_Bg,  RIV_img_Rg, 3);
    double b3=calculateLuminance( masks,  BIV_img_Br,  RIV_img_Rr, 3);

    double c1=calculateLuminance( masks,  LIII_img_Lb,  BIII_img_Bb, 2);
    double c2=calculateLuminance( masks,  LIII_img_Lg,  BIII_img_Bg, 2);
    double c3=calculateLuminance( masks,  LIII_img_Lr,  BIII_img_Br, 2);

    double d1=calculateLuminance( masks,  FI_img_Fb,  LI_img_Lb, 0);
    double d2=calculateLuminance( masks,  FI_img_Fg,  LI_img_Lg, 0);
    double d3=calculateLuminance( masks,  FI_img_Fr,  LI_img_Lr, 0);

    double t1 = cal0( a1,  b1,  c1,  d1);
    double t2 = cal0( a2,  b2,  c2,  d2);
    double t3 = cal0( a3,  b3,  c3,  d2);
    
    double x1 =  cal1( a1,  d1,  t1);
    double x2 =  cal1( a2,  d2,  t2);
    double x3 =  cal1( a3,  d3,  t3);

    double y1 =  cal1( c1,  b1,  t1);
    double y2 =  cal1( c2,  b2,  t2);
    double y3 =  cal1( c3,  b3,  t3);

    double z1 =  cal1( d1,  c1,  t1);
    double z2 =  cal1( d2,  c2,  t2);
    double z3 =  cal1( d3,  c3,  t3);

    double w1 =  cal1( b1,  a1,  t1);
    double w2 =  cal1( b2,  a2,  t2);
    double w3 =  cal1( b3,  a3,  t3);
    

    // IplImage* Fb_im = cvCreateImage(cvGetSize(Fb), IPL_DEPTH_8U, 1);
    // IplImage* Fg_im = cvCreateImage(cvGetSize(Fg), IPL_DEPTH_8U, 1);
    // IplImage* Fr_im = cvCreateImage(cvGetSize(Fr), IPL_DEPTH_8U, 1);

    // IplImage* Bb_im = cvCreateImage(cvGetSize(Bb), IPL_DEPTH_8U, 1);
    // IplImage* Bg_im = cvCreateImage(cvGetSize(Bg), IPL_DEPTH_8U, 1);
    // IplImage* Br_im = cvCreateImage(cvGetSize(Br), IPL_DEPTH_8U, 1);

    // IplImage* Lb_im = cvCreateImage(cvGetSize(Lb), IPL_DEPTH_8U, 1);
    // IplImage* Lg_im = cvCreateImage(cvGetSize(Lg), IPL_DEPTH_8U, 1);
    // IplImage* Lr_im = cvCreateImage(cvGetSize(Lr), IPL_DEPTH_8U, 1);

    // IplImage* Rb_im = cvCreateImage(cvGetSize(Rb), IPL_DEPTH_8U, 1);
    // IplImage* Rg_im = cvCreateImage(cvGetSize(Rg), IPL_DEPTH_8U, 1);
    // IplImage* Rr_im = cvCreateImage(cvGetSize(Rr), IPL_DEPTH_8U, 1);

    IplImage* Fb_im = cvCreateImage(cvSize(910,510), IPL_DEPTH_8U, 1);
    IplImage* Fg_im = cvCreateImage(cvSize(910,510), IPL_DEPTH_8U, 1);
    IplImage* Fr_im = cvCreateImage(cvSize(910,510), IPL_DEPTH_8U, 1);

    IplImage* Bb_im = cvCreateImage(cvSize(910,510), IPL_DEPTH_8U, 1);
    IplImage* Bg_im = cvCreateImage(cvSize(910,510), IPL_DEPTH_8U, 1);
    IplImage* Br_im = cvCreateImage(cvSize(910,510), IPL_DEPTH_8U, 1);

    IplImage* Lb_im = cvCreateImage(cvSize(380,1130), IPL_DEPTH_8U, 1);
    IplImage* Lg_im = cvCreateImage(cvSize(380,1130), IPL_DEPTH_8U, 1);
    IplImage* Lr_im = cvCreateImage(cvSize(380,1130), IPL_DEPTH_8U, 1);

    IplImage* Rb_im = cvCreateImage(cvSize(380,1130), IPL_DEPTH_8U, 1);
    IplImage* Rg_im = cvCreateImage(cvSize(380,1130), IPL_DEPTH_8U, 1);
    IplImage* Rr_im = cvCreateImage(cvSize(380,1130), IPL_DEPTH_8U, 1);


    cal2( x1, Fb,Fb_im);
    cal2( x2, Fg,Fg_im);
    cal2( x3, Fr,Fr_im);

    cal2( y1, Bb,Bb_im);
    cal2( y2, Bg,Bg_im);
    cal2( y3, Br,Br_im);

    cal2( z1, Lb,Lb_im);
    cal2( z2, Lg,Lg_im);
    cal2( z3, Lr,Lr_im);

    cal2( w1, Rb,Rb_im);
    cal2( w2, Rg,Rg_im);
    cal2( w3, Rr,Rr_im);
    
    // IplImage* front_new = cvCreateImage(cvGetSize(Fb_im), IPL_DEPTH_8U, 3);
    // IplImage* back_new = cvCreateImage(cvGetSize(Bb_im), IPL_DEPTH_8U, 3);
    // IplImage* left_new = cvCreateImage(cvGetSize(Lb_im), IPL_DEPTH_8U, 3);
    // IplImage* right_new = cvCreateImage(cvGetSize(Rb_im), IPL_DEPTH_8U, 3);

    cal3(Fb_im,  Fg_im,  Fr_im,front_new);
    cal3(Bb_im,  Bg_im,  Br_im,back_new);
    cal3(Lb_im,  Lg_im,  Lr_im,left_new);
    cal3(Rb_im,  Rg_im,  Rr_im,right_new);

    cvReleaseImage(&Fb_im);
    cvReleaseImage(&Fg_im);
    cvReleaseImage(&Fr_im);
    cvReleaseImage(&Bb_im);
    cvReleaseImage(&Br_im);
    cvReleaseImage(&Bg_im);
    cvReleaseImage(&Lb_im);
    cvReleaseImage(&Lg_im);
    cvReleaseImage(&Lr_im);
    cvReleaseImage(&Rb_im);
    cvReleaseImage(&Rg_im);
    cvReleaseImage(&Rr_im);
    cvReleaseImage(&RII_img_Rb);
    cvReleaseImage(&RII_img_Rg);
    cvReleaseImage(&RII_img_Rr);
    cvReleaseImage(&FII_img_Fb);
    cvReleaseImage(&FII_img_Fg);
    cvReleaseImage(&FII_img_Fr);
    cvReleaseImage(&BIV_img_Bb);
    cvReleaseImage(&BIV_img_Bg);
    cvReleaseImage(&BIV_img_Br);
    cvReleaseImage(&RIV_img_Rb);
    cvReleaseImage(&RIV_img_Rg);
    cvReleaseImage(&RIV_img_Rr);
    cvReleaseImage(&LIII_img_Lb);
    cvReleaseImage(&LIII_img_Lg);
    cvReleaseImage(&LIII_img_Lr);
    cvReleaseImage(&BIII_img_Bb);
    cvReleaseImage(&BIII_img_Bg);
    cvReleaseImage(&FI_img_Fb);
    cvReleaseImage(&FI_img_Fg);
    cvReleaseImage(&FI_img_Fr);
    cvReleaseImage(&LI_img_Lb);
    cvReleaseImage(&LI_img_Lg);
    cvReleaseImage(&LI_img_Lr);
    cvReleaseImage(&Fb);
    cvReleaseImage(&Fg);
    cvReleaseImage(&Fr);
    cvReleaseImage(&Bb);
    cvReleaseImage(&Bg);
    cvReleaseImage(&Br);
    cvReleaseImage(&Lb);
    cvReleaseImage(&Lg);
    cvReleaseImage(&Lr);
    cvReleaseImage(&Rb);
    cvReleaseImage(&Rg);
    cvReleaseImage(&Rr);

}
