
    IplImage* front_resized = cvCreateImage(cvSize(640, 480), front->depth, front->nChannels);
    IplImage* back_resized = cvCreateImage(cvSize(640, 480), back->depth, back->nChannels);
    IplImage* left_resized = cvCreateImage(cvSize(640, 480), left->depth, left->nChannels);
    IplImage* right_resized = cvCreateImage(cvSize(640, 480), right->depth, right->nChannels);


    IplImage* front_resized_projected = cvCreateImage(cvSize(910,510), IPL_DEPTH_8U, front_resized->nChannels);
    IplImage* back_resized_projected = cvCreateImage(cvSize(910,510), IPL_DEPTH_8U, back_resized->nChannels);
    IplImage* left_resized_projected = cvCreateImage(cvSize(1130,380), IPL_DEPTH_8U, left_resized->nChannels);
    IplImage* right_resized_projected = cvCreateImage(cvSize(1130,380), IPL_DEPTH_8U, right_resized->nChannels);

    IplImage* front_resized_flip = cvCreateImage(cvSize(910,510), IPL_DEPTH_8U, front_resized_projected->nChannels);
    IplImage* back_resized_flip = cvCreateImage(cvSize(910,510), IPL_DEPTH_8U, back_resized_projected->nChannels);
    IplImage* left_resized_flip = cvCreateImage(cvSize(380,1130),IPL_DEPTH_8U, left_resized_projected->nChannels);
    IplImage* right_resized_flip = cvCreateImage(cvSize(380,1130 ),IPL_DEPTH_8U ,right_resized_projected->nChannels);


    IplImage* front_new = cvCreateImage(cvSize(910,510), IPL_DEPTH_8U, 3);
    IplImage* back_new = cvCreateImage(cvSize(910,510), IPL_DEPTH_8U, 3);
    IplImage* left_new = cvCreateImage(cvSize(380,1130), IPL_DEPTH_8U, 3);
    IplImage* right_new = cvCreateImage(cvSize(380,1130), IPL_DEPTH_8U, 3);


    IplImage* car_image_resized = cvCreateImage(cvSize(150,110), car_image->depth, car_image->nChannels);


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

    IplImage* merge_FI_LI =  cvCreateImage(cvSize(xl,510), IPL_DEPTH_8U, 3);
    IplImage* merge_FII_RII =  cvCreateImage(cvSize(910 - xr,510), IPL_DEPTH_8U, 3);
    IplImage* merge_BIII_LIII =  cvCreateImage(cvSize(xl,510), IPL_DEPTH_8U, 3);
    IplImage* merge_BIV_RIV =  cvCreateImage(cvSize(910 - xr,510), IPL_DEPTH_8U, 3);