#include <stdio.h>
#include <string.h>
#include <opencv2/core/core_c.h>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/imgcodecs/imgcodecs_c.h>
#include <opencv2/imgcodecs/imgcodecs_c.h>
#include <math.h> 
#include "fisheye_camera.c"
#include "birdview.c"


void resizeImage(IplImage* inputImage,IplImage* outputImage, CvSize newSize) {
    cvResize(inputImage, outputImage, CV_INTER_AREA);
}

void pre_process(const char* weight_path_txt_0,const char* weight_path_txt_1,const char* weight_path_txt_2,const char* weight_path_txt_3, const char* masks_path_txt_0,
 const char* masks_path_txt_1, const char* masks_path_txt_2, const char* masks_path_txt_3,IplImage* GMatImage,
IplImage* MMatImage, CvMat* masks[4], CvMatND* weights[4],const char* project_matrix_path_front,const char* project_matrix_path_back ,
const char* project_matrix_path_left ,const char* project_matrix_path_right, const char* project_shape_path_front,
 const char* project_shape_path_back, const char* project_shape_path_left, const char* project_shape_path_right, double project_matrix_front[3][3], 
 double project_matrix_back[3][3], double project_matrix_left[3][3], double project_matrix_right[3][3], double project_shape_front[2],double project_shape_back[2],
 double project_shape_left[2],double project_shape_right[2]){

    load_weights_and_masks( weight_path_txt_0,weight_path_txt_1,weight_path_txt_2,weight_path_txt_3,   masks_path_txt_0,   masks_path_txt_1,   masks_path_txt_2,   masks_path_txt_3,GMatImage, MMatImage, masks,  weights);
    printf("5556566");
    load_camera_params(  project_matrix_path_front ,  project_shape_path_front, project_matrix_front, project_shape_front);
    load_camera_params(  project_matrix_path_back ,  project_shape_path_back, project_matrix_back, project_shape_back);
    load_camera_params(  project_matrix_path_left ,  project_shape_path_left, project_matrix_left, project_shape_left);
    load_camera_params(  project_matrix_path_right ,  project_shape_path_right, project_matrix_right, project_shape_right);
}

int main(){
    const char* front_path="./images/front.jpg";
    const char* back_path="./images/back.jpg";
    const char* left_path="./images/left.jpg";
    const char* right_path="./images/right.jpg";
    const char* weights_image="./weights.jpg"; 
    const char* masks_image="./masks.jpg";
    const char* car_path="./images/car.jpg";

    const char* weight_path_txt_0="./yaml/weights_0.txt";
    const char* weight_path_txt_1="./yaml/weights_1.txt";
    const char* weight_path_txt_2="./yaml/weights_2.txt";
    const char* weight_path_txt_3="./yaml/weights_3.txt";

    const char* masks_path_txt_0="./yaml/masks_1.txt";
    const char* masks_path_txt_1="./yaml/masks_2.txt";
    const char* masks_path_txt_2="./yaml/masks_3.txt";
    const char* masks_path_txt_3="./yaml/masks_4.txt";

    IplImage* front = cvLoadImage(front_path,CV_LOAD_IMAGE_UNCHANGED);
    IplImage* back = cvLoadImage(back_path,CV_LOAD_IMAGE_UNCHANGED);
    IplImage* left = cvLoadImage(left_path,CV_LOAD_IMAGE_UNCHANGED);
    IplImage* right = cvLoadImage(right_path,CV_LOAD_IMAGE_UNCHANGED);
    IplImage* car_image = cvLoadImage(car_path,CV_LOAD_IMAGE_UNCHANGED);

    IplImage* GMatImage = cvLoadImage(weights_image, CV_LOAD_IMAGE_UNCHANGED);
    IplImage* MMatImage = cvLoadImage(masks_image, CV_LOAD_IMAGE_UNCHANGED);
    
    const char* project_matrix_path_front="./yaml/front.txt";
    const char* project_matrix_path_back="./yaml/back.txt";
    const char* project_matrix_path_left="./yaml/left.txt";
    const char* project_matrix_path_right="./yaml/right.txt";

    const char* project_shape_path_front="./yaml/front_2.txt";
    const char* project_shape_path_back="./yaml/back_2.txt";
    const char* project_shape_path_left="./yaml/left_2.txt";
    const char* project_shape_path_right="./yaml/right_2.txt";
    
    const char* camera_name_front="front";
    const char* camera_name_back="back";
    const char* camera_name_left="left";
    const char* camera_name_right="right";

    double project_matrix_front[3][3];
    double project_matrix_back[3][3];
    double project_matrix_left[3][3];
    double project_matrix_right[3][3];

    double project_shape_front[2];
    double project_shape_back[2];
    double project_shape_left[2];
    double project_shape_right[2];

    double total_h=1130;
    double total_w=910;
    double yt=510;
    double yb=620;
    double xr=530;
    double xl=380;

    CvMat* masks[4];
    CvMatND* weights[4];
    CvSize newSize = cvSize(640, 480);

    IplImage* image = cvCreateImage(cvSize( total_w,total_h), IPL_DEPTH_8U, 3);

    // IplImage* front_resized = cvCreateImage(newSize, front->depth, front->nChannels);
    // IplImage* back_resized = cvCreateImage(newSize, back->depth, back->nChannels);
    // IplImage* left_resized = cvCreateImage(newSize, left->depth, left->nChannels);
    // IplImage* right_resized = cvCreateImage(newSize, right->depth, right->nChannels);
    IplImage* front_resized = cvCreateImage(cvSize(640, 480), front->depth, front->nChannels);
    IplImage* back_resized = cvCreateImage(cvSize(640, 480), back->depth, back->nChannels);
    IplImage* left_resized = cvCreateImage(cvSize(640, 480), left->depth, left->nChannels);
    IplImage* right_resized = cvCreateImage(cvSize(640, 480), right->depth, right->nChannels);

    resizeImage( front, front_resized,newSize);
    resizeImage( back, back_resized,  newSize);
    resizeImage( left, left_resized,  newSize);
    resizeImage( right, right_resized,  newSize);
    
    cvReleaseImage(&front);
    cvReleaseImage(&back);
    cvReleaseImage(&left);
    cvReleaseImage(&right);

    // load_weights_and_masks( weight_path_txt_0,weight_path_txt_1,weight_path_txt_2,weight_path_txt_3,GMatImage, MMatImage, masks,  weights);
    pre_process( weight_path_txt_0, weight_path_txt_1, weight_path_txt_2, weight_path_txt_3, masks_path_txt_0,
   masks_path_txt_1,  masks_path_txt_2,  masks_path_txt_3, GMatImage, MMatImage, masks,  weights, project_matrix_path_front,  project_matrix_path_back ,  
     project_matrix_path_left ,  project_matrix_path_right, project_shape_path_front,   project_shape_path_back,   
     project_shape_path_left,   project_shape_path_right, project_matrix_front,  project_matrix_back,  project_matrix_left ,  
     project_matrix_right, project_shape_front , project_shape_back, project_shape_left, project_shape_right);

    cvReleaseImage(&GMatImage);
    cvReleaseImage(&MMatImage);

    // load_camera_params(  project_matrix_path_front ,  project_shape_path_front, project_matrix_front, project_shape_front);
    // load_camera_params(  project_matrix_path_back ,  project_shape_path_back, project_matrix_back, project_shape_back);
    // load_camera_params(  project_matrix_path_left ,  project_shape_path_left, project_matrix_left, project_shape_left);
    // load_camera_params(  project_matrix_path_right ,  project_shape_path_right, project_matrix_right, project_shape_right);

    printf("\nfront_resized_projected %d,%d\n",cvSize((int)project_shape_front[0], (int)project_shape_front[1]).height,cvSize((int)project_shape_front[0], (int)project_shape_front[1]).width);
    printf("back_resized_projected %d,%d\n",cvSize((int)project_shape_back[0], (int)project_shape_back[1]).height,cvSize((int)project_shape_back[0], (int)project_shape_back[1]).width);
    printf("left_resized_projected %d,%d\n",cvSize((int)project_shape_left[0], (int)project_shape_left[1]).height,cvSize((int)project_shape_left[0], (int)project_shape_left[1]).width);
    printf("right_resized_projected %d,%d\n",cvSize((int)project_shape_right[0], (int)project_shape_right[1]).height,cvSize((int)project_shape_right[0], (int)project_shape_right[1]).width);


    IplImage* front_resized_projected = cvCreateImage(cvSize(910,510), IPL_DEPTH_8U, front_resized->nChannels);
    IplImage* back_resized_projected = cvCreateImage(cvSize(910,510), IPL_DEPTH_8U, back_resized->nChannels);
    IplImage* left_resized_projected = cvCreateImage(cvSize(1130,380), IPL_DEPTH_8U, left_resized->nChannels);
    IplImage* right_resized_projected = cvCreateImage(cvSize(1130,380), IPL_DEPTH_8U, right_resized->nChannels);

    // IplImage* front_resized_projected = cvCreateImage(cvSize((int)project_shape_front[0], (int)project_shape_front[1]), IPL_DEPTH_8U, front_resized->nChannels);
    // IplImage* back_resized_projected = cvCreateImage(cvSize((int)project_shape_back[0], (int)project_shape_back[1]), IPL_DEPTH_8U, back_resized->nChannels);
    // IplImage* left_resized_projected = cvCreateImage(cvSize((int)project_shape_left[0], (int)project_shape_left[1]), IPL_DEPTH_8U, left_resized->nChannels);
    // IplImage* right_resized_projected = cvCreateImage(cvSize((int)project_shape_right[0], (int)project_shape_right[1]), IPL_DEPTH_8U, right_resized->nChannels);

    project_action( front_resized,  project_matrix_front,  project_shape_front, front_resized_projected);
    project_action( back_resized,  project_matrix_back,  project_shape_back, back_resized_projected);
    project_action( left_resized,  project_matrix_left,  project_shape_left, left_resized_projected);
    project_action( right_resized,  project_matrix_right,  project_shape_right, right_resized_projected);

    cvReleaseImage(&front_resized);
    cvReleaseImage(&back_resized);
    cvReleaseImage(&left_resized);
    cvReleaseImage(&right_resized);
    
    printf("front_resized_flip %d,%d\n",cvGetSize(front_resized_projected).height,cvGetSize(front_resized_projected).width);
    printf("back_resized_flip %d,%d\n",cvGetSize(back_resized_projected).height,cvGetSize(back_resized_projected).width);
    printf("left_resized_flip %d,%d\n",left_resized_projected->height,left_resized_projected->width);
    printf("right_resized_flip %d,%d\n",right_resized_projected->height,right_resized_projected->width);


    IplImage* front_resized_flip = cvCreateImage(cvSize(910,510), IPL_DEPTH_8U, front_resized_projected->nChannels);
    IplImage* back_resized_flip = cvCreateImage(cvSize(910,510), IPL_DEPTH_8U, back_resized_projected->nChannels);
    IplImage* left_resized_flip = cvCreateImage(cvSize(380,1130),IPL_DEPTH_8U, left_resized_projected->nChannels);
    IplImage* right_resized_flip = cvCreateImage(cvSize(380,1130 ),IPL_DEPTH_8U ,right_resized_projected->nChannels);

    // IplImage* front_resized_flip = cvCreateImage(cvGetSize(front_resized_projected), IPL_DEPTH_8U, front_resized_projected->nChannels);
    // IplImage* back_resized_flip = cvCreateImage(cvGetSize(back_resized_projected), IPL_DEPTH_8U, back_resized_projected->nChannels);
    // IplImage* left_resized_flip = cvCreateImage(cvSize(left_resized_projected->height,left_resized_projected->width ),IPL_DEPTH_8U, left_resized_projected->nChannels);
    // IplImage* right_resized_flip = cvCreateImage(cvSize(right_resized_projected->height,right_resized_projected->width ),IPL_DEPTH_8U ,right_resized_projected->nChannels);

    flip( camera_name_front,  front_resized_projected, front_resized_flip);
    flip( camera_name_back,  back_resized_projected, back_resized_flip);
    flip( camera_name_left,  left_resized_projected, left_resized_flip);
    flip( camera_name_right,  right_resized_projected, right_resized_flip);

    cvReleaseImage(&front_resized_projected);
    cvReleaseImage(&back_resized_projected);
    cvReleaseImage(&left_resized_projected);
    cvReleaseImage(&right_resized_projected);

    printf("front_new %d,%d\n",cvGetSize(front_resized_flip).height,cvGetSize(front_resized_flip).width);
    printf("back_new %d,%d\n",cvGetSize(back_resized_flip).height,cvGetSize(back_resized_flip).width);
    printf("left_new %d,%d\n",cvGetSize(left_resized_flip).height,cvGetSize(left_resized_flip).width);
    printf("right_new %d,%d\n",cvGetSize(right_resized_flip).height,cvGetSize(right_resized_flip).width);

    IplImage* front_new = cvCreateImage(cvSize(910,510), IPL_DEPTH_8U, 3);
    IplImage* back_new = cvCreateImage(cvSize(910,510), IPL_DEPTH_8U, 3);
    IplImage* left_new = cvCreateImage(cvSize(380,1130), IPL_DEPTH_8U, 3);
    IplImage* right_new = cvCreateImage(cvSize(380,1130), IPL_DEPTH_8U, 3);

    // IplImage* front_new = cvCreateImage(cvGetSize(front_resized_flip), IPL_DEPTH_8U, 3);
    // IplImage* back_new = cvCreateImage(cvGetSize(back_resized_flip), IPL_DEPTH_8U, 3);
    // IplImage* left_new = cvCreateImage(cvGetSize(left_resized_flip), IPL_DEPTH_8U, 3);
    // IplImage* right_new = cvCreateImage(cvGetSize(right_resized_flip), IPL_DEPTH_8U, 3);

    make_luminance_balance( front_resized_flip, back_resized_flip, left_resized_flip, right_resized_flip ,  masks, front_new, back_new, left_new, right_new, yt, yb, xr, xl);

    cvReleaseImage(&front_resized_flip);
    cvReleaseImage(&back_resized_flip);
    cvReleaseImage(&left_resized_flip);
    cvReleaseImage(&right_resized_flip);

    stitch_all_parts( front_new, back_new, left_new, right_new, image,  weights, yt, yb, xr, xl);
    // printf("000\n");

    cvReleaseImage(&front_new);
    cvReleaseImage(&back_new);
    cvReleaseImage(&left_new);
    cvReleaseImage(&right_new);
    // printf("0010\n");


    CvSize car_newSize = cvSize(xr - xl, yb - yt);

    printf("car_image_resized %d,%d\n",car_newSize.height,car_newSize.width);

    IplImage* car_image_resized = cvCreateImage(cvSize(150,110), car_image->depth, car_image->nChannels);
// 
    // IplImage* car_image_resized = cvCreateImage(car_newSize, car_image->depth, car_image->nChannels);

    resizeImage( car_image, car_image_resized,car_newSize);

    copy_car_image(image, car_image_resized, yt, yb, xr, xl);
    cvReleaseImage(&car_image);
    cvReleaseImage(&car_image_resized);
    cvSaveImage("imagefinal.jpg", image, 0);

    cvNamedWindow("svm", CV_WINDOW_AUTOSIZE);
    cvShowImage("Image", image);
    cvWaitKey(0);
    cvReleaseImage(&image);

    return 0;
}