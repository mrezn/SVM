#include <stdio.h>
#include <string.h>
#include <opencv2/core/core_c.h>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/imgproc/imgproc_c.h>
#include <opencv2/imgcodecs/imgcodecs_c.h>
#include <math.h> 
void load_weights_and_masks(const char* file_path_0,const char* file_path_1,const char* file_path_2,const char* file_path_3,const char* file_path_0_1,const char* file_path_1_1,const char* file_path_2_1,const char* file_path_3_1, IplImage* GMatImage, IplImage* MMatImage, CvMat* masks[4], CvMatND* weights[4]) {

    
    int h=GMatImage->height;
    int w= GMatImage->width;
    float data[h][w][3];
    float mask_data[h][w]; 
    // printf("000\n");
    // printf("%d\n",h);
    // printf("%d\n",w);

    for (int k = 0; k < 4; k++) {
        int sizes[3] = {GMatImage->height, GMatImage->width, 3};
        weights[k] = cvCreateMatND(3, sizes, CV_32FC1);
        masks[k] = cvCreateMat(h, w, CV_32FC1);//masks[k] = cvCreateMatND(3, sizes, CV_32FC1);//cvCreateMat(MMatImage->height, MMatImage->width, CV_32FC1);

        if(k==0){
            FILE *file_0 = fopen(file_path_0, "r"); // Open the file in read mode
                if (file_0 == NULL) {
                    printf("file_path_0 Error opening the file.\n");
                    // return 0;
                }
                for (int i = 0; i < h; i++) {
                    for (int j = 0; j < w; j++) {
                            #pragma GCC diagnostic ignored "-Wunused-result"
                            fscanf(file_0, "%f,%f,%f", &data[i][j][0],&data[i][j][1],&data[i][j][2]); // Read integers from the file
                            #pragma GCC diagnostic ignored "-Wunused-result"

                    }
                }
                fclose(file_0);

                 FILE *file_0_1 = fopen(file_path_0_1, "r"); // Open the file in read mode
                if (file_0_1 == NULL) {
                    printf("file_path_0 Error opening the file.\n");
                    // return 0;
                }
                for (int i = 0; i < h; i++) {
                    // for (int j = 0; j < w; j++) {
                            #pragma GCC diagnostic ignored "-Wunused-result"
                            fscanf(file_0_1, "%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f", &mask_data[i][0],&mask_data[i][1],&mask_data[i][2],&mask_data[i][3],&mask_data[i][4],&mask_data[i][5],&mask_data[i][6],&mask_data[i][7],&mask_data[i][8],&mask_data[i][9],&mask_data[i][10],&mask_data[i][11],&mask_data[i][12],&mask_data[i][13],&mask_data[i][14],&mask_data[i][15],&mask_data[i][16],&mask_data[i][17],&mask_data[i][18],&mask_data[i][19],&mask_data[i][20],&mask_data[i][21],&mask_data[i][22],&mask_data[i][23],&mask_data[i][24],&mask_data[i][25],&mask_data[i][26],&mask_data[i][27],&mask_data[i][28],&mask_data[i][29],&mask_data[i][30],&mask_data[i][31],&mask_data[i][32],&mask_data[i][33],&mask_data[i][34],&mask_data[i][35],&mask_data[i][36],&mask_data[i][37],&mask_data[i][38],&mask_data[i][39],&mask_data[i][40],&mask_data[i][41],&mask_data[i][42],&mask_data[i][43],&mask_data[i][44],&mask_data[i][45],&mask_data[i][46],&mask_data[i][47],&mask_data[i][48],&mask_data[i][49],&mask_data[i][50],&mask_data[i][51],&mask_data[i][52],&mask_data[i][53],&mask_data[i][54],&mask_data[i][55],&mask_data[i][56],&mask_data[i][57],&mask_data[i][58],&mask_data[i][59],&mask_data[i][60],&mask_data[i][61],&mask_data[i][62],&mask_data[i][63],&mask_data[i][64],&mask_data[i][65],&mask_data[i][66],&mask_data[i][67],&mask_data[i][68],&mask_data[i][69],&mask_data[i][70],&mask_data[i][71],&mask_data[i][72],&mask_data[i][73],&mask_data[i][74],&mask_data[i][75],&mask_data[i][76],&mask_data[i][77],&mask_data[i][78],&mask_data[i][79],&mask_data[i][80],&mask_data[i][81],&mask_data[i][82],&mask_data[i][83],&mask_data[i][84],&mask_data[i][85],&mask_data[i][86],&mask_data[i][87],&mask_data[i][88],&mask_data[i][89],&mask_data[i][90],&mask_data[i][91],&mask_data[i][92],&mask_data[i][93],&mask_data[i][94],&mask_data[i][95],&mask_data[i][96],&mask_data[i][97],&mask_data[i][98],&mask_data[i][99],&mask_data[i][100],&mask_data[i][101],&mask_data[i][102],&mask_data[i][103],&mask_data[i][104],&mask_data[i][105],&mask_data[i][106],&mask_data[i][107],&mask_data[i][108],&mask_data[i][109],&mask_data[i][110],&mask_data[i][111],&mask_data[i][112],&mask_data[i][113],&mask_data[i][114],&mask_data[i][115],&mask_data[i][116],&mask_data[i][117],&mask_data[i][118],&mask_data[i][119],&mask_data[i][120],&mask_data[i][121],&mask_data[i][122],&mask_data[i][123],&mask_data[i][124],&mask_data[i][125],&mask_data[i][126],&mask_data[i][127],&mask_data[i][128],&mask_data[i][129],&mask_data[i][130],&mask_data[i][131],&mask_data[i][132],&mask_data[i][133],&mask_data[i][134],&mask_data[i][135],&mask_data[i][136],&mask_data[i][137],&mask_data[i][138],&mask_data[i][139],&mask_data[i][140],&mask_data[i][141],&mask_data[i][142],&mask_data[i][143],&mask_data[i][144],&mask_data[i][145],&mask_data[i][146],&mask_data[i][147],&mask_data[i][148],&mask_data[i][149],&mask_data[i][150],&mask_data[i][151],&mask_data[i][152],&mask_data[i][153],&mask_data[i][154],&mask_data[i][155],&mask_data[i][156],&mask_data[i][157],&mask_data[i][158],&mask_data[i][159],&mask_data[i][160],&mask_data[i][161],&mask_data[i][162],&mask_data[i][163],&mask_data[i][164],&mask_data[i][165],&mask_data[i][166],&mask_data[i][167],&mask_data[i][168],&mask_data[i][169],&mask_data[i][170],&mask_data[i][171],&mask_data[i][172],&mask_data[i][173],&mask_data[i][174],&mask_data[i][175],&mask_data[i][176],&mask_data[i][177],&mask_data[i][178],&mask_data[i][179],&mask_data[i][180],&mask_data[i][181],&mask_data[i][182],&mask_data[i][183],&mask_data[i][184],&mask_data[i][185],&mask_data[i][186],&mask_data[i][187],&mask_data[i][188],&mask_data[i][189],&mask_data[i][190],&mask_data[i][191],&mask_data[i][192],&mask_data[i][193],&mask_data[i][194],&mask_data[i][195],&mask_data[i][196],&mask_data[i][197],&mask_data[i][198],&mask_data[i][199],&mask_data[i][200],&mask_data[i][201],&mask_data[i][202],&mask_data[i][203],&mask_data[i][204],&mask_data[i][205],&mask_data[i][206],&mask_data[i][207],&mask_data[i][208],&mask_data[i][209],&mask_data[i][210],&mask_data[i][211],&mask_data[i][212],&mask_data[i][213],&mask_data[i][214],&mask_data[i][215],&mask_data[i][216],&mask_data[i][217],&mask_data[i][218],&mask_data[i][219],&mask_data[i][220],&mask_data[i][221],&mask_data[i][222],&mask_data[i][223],&mask_data[i][224],&mask_data[i][225],&mask_data[i][226],&mask_data[i][227],&mask_data[i][228],&mask_data[i][229],&mask_data[i][230],&mask_data[i][231],&mask_data[i][232],&mask_data[i][233],&mask_data[i][234],&mask_data[i][235],&mask_data[i][236],&mask_data[i][237],&mask_data[i][238],&mask_data[i][239],&mask_data[i][240],&mask_data[i][241],&mask_data[i][242],&mask_data[i][243],&mask_data[i][244],&mask_data[i][245],&mask_data[i][246],&mask_data[i][247],&mask_data[i][248],&mask_data[i][249],&mask_data[i][250],&mask_data[i][251],&mask_data[i][252],&mask_data[i][253],&mask_data[i][254],&mask_data[i][255],&mask_data[i][256],&mask_data[i][257],&mask_data[i][258],&mask_data[i][259],&mask_data[i][260],&mask_data[i][261],&mask_data[i][262],&mask_data[i][263],&mask_data[i][264],&mask_data[i][265],&mask_data[i][266],&mask_data[i][267],&mask_data[i][268],&mask_data[i][269],&mask_data[i][270],&mask_data[i][271],&mask_data[i][272],&mask_data[i][273],&mask_data[i][274],&mask_data[i][275],&mask_data[i][276],&mask_data[i][277],&mask_data[i][278],&mask_data[i][279],&mask_data[i][280],&mask_data[i][281],&mask_data[i][282],&mask_data[i][283],&mask_data[i][284],&mask_data[i][285],&mask_data[i][286],&mask_data[i][287],&mask_data[i][288],&mask_data[i][289],&mask_data[i][290],&mask_data[i][291],&mask_data[i][292],&mask_data[i][293],&mask_data[i][294],&mask_data[i][295],&mask_data[i][296],&mask_data[i][297],&mask_data[i][298],&mask_data[i][299],&mask_data[i][300],&mask_data[i][301],&mask_data[i][302],&mask_data[i][303],&mask_data[i][304],&mask_data[i][305],&mask_data[i][306],&mask_data[i][307],&mask_data[i][308],&mask_data[i][309],&mask_data[i][310],&mask_data[i][311],&mask_data[i][312],&mask_data[i][313],&mask_data[i][314],&mask_data[i][315],&mask_data[i][316],&mask_data[i][317],&mask_data[i][318],&mask_data[i][319],&mask_data[i][320],&mask_data[i][321],&mask_data[i][322],&mask_data[i][323],&mask_data[i][324],&mask_data[i][325],&mask_data[i][326],&mask_data[i][327],&mask_data[i][328],&mask_data[i][329],&mask_data[i][330],&mask_data[i][331],&mask_data[i][332],&mask_data[i][333],&mask_data[i][334],&mask_data[i][335],&mask_data[i][336],&mask_data[i][337],&mask_data[i][338],&mask_data[i][339],&mask_data[i][340],&mask_data[i][341],&mask_data[i][342],&mask_data[i][343],&mask_data[i][344],&mask_data[i][345],&mask_data[i][346],&mask_data[i][347],&mask_data[i][348],&mask_data[i][349],&mask_data[i][350],&mask_data[i][351],&mask_data[i][352],&mask_data[i][353],&mask_data[i][354],&mask_data[i][355],&mask_data[i][356],&mask_data[i][357],&mask_data[i][358],&mask_data[i][359],&mask_data[i][360],&mask_data[i][361],&mask_data[i][362],&mask_data[i][363],&mask_data[i][364],&mask_data[i][365],&mask_data[i][366],&mask_data[i][367],&mask_data[i][368],&mask_data[i][369],&mask_data[i][370],&mask_data[i][371],&mask_data[i][372],&mask_data[i][373],&mask_data[i][374],&mask_data[i][375],&mask_data[i][376],&mask_data[i][377],&mask_data[i][378],&mask_data[i][379]); // Read integers from the file
                            #pragma GCC diagnostic ignored "-Wunused-result"

                    // }
                }
                fclose(file_0_1);
                
        }
                                            

        else if (k==1){

            FILE *file_1 = fopen(file_path_1, "r"); // Open the file in read mode

                if (file_1 == NULL) {
                    printf("file_path_1 Error opening the file.\n");
                    // return 0;
                }
                for (int i = 0; i < h; i++) {
                    for (int j = 0; j < w; j++) {
                            #pragma GCC diagnostic ignored "-Wunused-result"
                            fscanf(file_1, "%f,%f,%f", &data[i][j][0],&data[i][j][1],&data[i][j][2]); // Read integers from the file
                            #pragma GCC diagnostic ignored "-Wunused-result"

                    }
                }

                fclose(file_1);

                
                 FILE *file_1_1 = fopen(file_path_1_1, "r"); // Open the file in read mode
                if (file_1_1 == NULL) {
                    printf("file_path_0 Error opening the file.\n");
                    // return 0;
                }
                for (int i = 0; i < h; i++) {
                    // for (int j = 0; j < w; j++) {
                            #pragma GCC diagnostic ignored "-Wunused-result"
                            fscanf(file_1_1,"%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f",&mask_data[i][0],&mask_data[i][1],&mask_data[i][2],&mask_data[i][3],&mask_data[i][4],&mask_data[i][5],&mask_data[i][6],&mask_data[i][7],&mask_data[i][8],&mask_data[i][9],&mask_data[i][10],&mask_data[i][11],&mask_data[i][12],&mask_data[i][13],&mask_data[i][14],&mask_data[i][15],&mask_data[i][16],&mask_data[i][17],&mask_data[i][18],&mask_data[i][19],&mask_data[i][20],&mask_data[i][21],&mask_data[i][22],&mask_data[i][23],&mask_data[i][24],&mask_data[i][25],&mask_data[i][26],&mask_data[i][27],&mask_data[i][28],&mask_data[i][29],&mask_data[i][30],&mask_data[i][31],&mask_data[i][32],&mask_data[i][33],&mask_data[i][34],&mask_data[i][35],&mask_data[i][36],&mask_data[i][37],&mask_data[i][38],&mask_data[i][39],&mask_data[i][40],&mask_data[i][41],&mask_data[i][42],&mask_data[i][43],&mask_data[i][44],&mask_data[i][45],&mask_data[i][46],&mask_data[i][47],&mask_data[i][48],&mask_data[i][49],&mask_data[i][50],&mask_data[i][51],&mask_data[i][52],&mask_data[i][53],&mask_data[i][54],&mask_data[i][55],&mask_data[i][56],&mask_data[i][57],&mask_data[i][58],&mask_data[i][59],&mask_data[i][60],&mask_data[i][61],&mask_data[i][62],&mask_data[i][63],&mask_data[i][64],&mask_data[i][65],&mask_data[i][66],&mask_data[i][67],&mask_data[i][68],&mask_data[i][69],&mask_data[i][70],&mask_data[i][71],&mask_data[i][72],&mask_data[i][73],&mask_data[i][74],&mask_data[i][75],&mask_data[i][76],&mask_data[i][77],&mask_data[i][78],&mask_data[i][79],&mask_data[i][80],&mask_data[i][81],&mask_data[i][82],&mask_data[i][83],&mask_data[i][84],&mask_data[i][85],&mask_data[i][86],&mask_data[i][87],&mask_data[i][88],&mask_data[i][89],&mask_data[i][90],&mask_data[i][91],&mask_data[i][92],&mask_data[i][93],&mask_data[i][94],&mask_data[i][95],&mask_data[i][96],&mask_data[i][97],&mask_data[i][98],&mask_data[i][99],&mask_data[i][100],&mask_data[i][101],&mask_data[i][102],&mask_data[i][103],&mask_data[i][104],&mask_data[i][105],&mask_data[i][106],&mask_data[i][107],&mask_data[i][108],&mask_data[i][109],&mask_data[i][110],&mask_data[i][111],&mask_data[i][112],&mask_data[i][113],&mask_data[i][114],&mask_data[i][115],&mask_data[i][116],&mask_data[i][117],&mask_data[i][118],&mask_data[i][119],&mask_data[i][120],&mask_data[i][121],&mask_data[i][122],&mask_data[i][123],&mask_data[i][124],&mask_data[i][125],&mask_data[i][126],&mask_data[i][127],&mask_data[i][128],&mask_data[i][129],&mask_data[i][130],&mask_data[i][131],&mask_data[i][132],&mask_data[i][133],&mask_data[i][134],&mask_data[i][135],&mask_data[i][136],&mask_data[i][137],&mask_data[i][138],&mask_data[i][139],&mask_data[i][140],&mask_data[i][141],&mask_data[i][142],&mask_data[i][143],&mask_data[i][144],&mask_data[i][145],&mask_data[i][146],&mask_data[i][147],&mask_data[i][148],&mask_data[i][149],&mask_data[i][150],&mask_data[i][151],&mask_data[i][152],&mask_data[i][153],&mask_data[i][154],&mask_data[i][155],&mask_data[i][156],&mask_data[i][157],&mask_data[i][158],&mask_data[i][159],&mask_data[i][160],&mask_data[i][161],&mask_data[i][162],&mask_data[i][163],&mask_data[i][164],&mask_data[i][165],&mask_data[i][166],&mask_data[i][167],&mask_data[i][168],&mask_data[i][169],&mask_data[i][170],&mask_data[i][171],&mask_data[i][172],&mask_data[i][173],&mask_data[i][174],&mask_data[i][175],&mask_data[i][176],&mask_data[i][177],&mask_data[i][178],&mask_data[i][179],&mask_data[i][180],&mask_data[i][181],&mask_data[i][182],&mask_data[i][183],&mask_data[i][184],&mask_data[i][185],&mask_data[i][186],&mask_data[i][187],&mask_data[i][188],&mask_data[i][189],&mask_data[i][190],&mask_data[i][191],&mask_data[i][192],&mask_data[i][193],&mask_data[i][194],&mask_data[i][195],&mask_data[i][196],&mask_data[i][197],&mask_data[i][198],&mask_data[i][199],&mask_data[i][200],&mask_data[i][201],&mask_data[i][202],&mask_data[i][203],&mask_data[i][204],&mask_data[i][205],&mask_data[i][206],&mask_data[i][207],&mask_data[i][208],&mask_data[i][209],&mask_data[i][210],&mask_data[i][211],&mask_data[i][212],&mask_data[i][213],&mask_data[i][214],&mask_data[i][215],&mask_data[i][216],&mask_data[i][217],&mask_data[i][218],&mask_data[i][219],&mask_data[i][220],&mask_data[i][221],&mask_data[i][222],&mask_data[i][223],&mask_data[i][224],&mask_data[i][225],&mask_data[i][226],&mask_data[i][227],&mask_data[i][228],&mask_data[i][229],&mask_data[i][230],&mask_data[i][231],&mask_data[i][232],&mask_data[i][233],&mask_data[i][234],&mask_data[i][235],&mask_data[i][236],&mask_data[i][237],&mask_data[i][238],&mask_data[i][239],&mask_data[i][240],&mask_data[i][241],&mask_data[i][242],&mask_data[i][243],&mask_data[i][244],&mask_data[i][245],&mask_data[i][246],&mask_data[i][247],&mask_data[i][248],&mask_data[i][249],&mask_data[i][250],&mask_data[i][251],&mask_data[i][252],&mask_data[i][253],&mask_data[i][254],&mask_data[i][255],&mask_data[i][256],&mask_data[i][257],&mask_data[i][258],&mask_data[i][259],&mask_data[i][260],&mask_data[i][261],&mask_data[i][262],&mask_data[i][263],&mask_data[i][264],&mask_data[i][265],&mask_data[i][266],&mask_data[i][267],&mask_data[i][268],&mask_data[i][269],&mask_data[i][270],&mask_data[i][271],&mask_data[i][272],&mask_data[i][273],&mask_data[i][274],&mask_data[i][275],&mask_data[i][276],&mask_data[i][277],&mask_data[i][278],&mask_data[i][279],&mask_data[i][280],&mask_data[i][281],&mask_data[i][282],&mask_data[i][283],&mask_data[i][284],&mask_data[i][285],&mask_data[i][286],&mask_data[i][287],&mask_data[i][288],&mask_data[i][289],&mask_data[i][290],&mask_data[i][291],&mask_data[i][292],&mask_data[i][293],&mask_data[i][294],&mask_data[i][295],&mask_data[i][296],&mask_data[i][297],&mask_data[i][298],&mask_data[i][299],&mask_data[i][300],&mask_data[i][301],&mask_data[i][302],&mask_data[i][303],&mask_data[i][304],&mask_data[i][305],&mask_data[i][306],&mask_data[i][307],&mask_data[i][308],&mask_data[i][309],&mask_data[i][310],&mask_data[i][311],&mask_data[i][312],&mask_data[i][313],&mask_data[i][314],&mask_data[i][315],&mask_data[i][316],&mask_data[i][317],&mask_data[i][318],&mask_data[i][319],&mask_data[i][320],&mask_data[i][321],&mask_data[i][322],&mask_data[i][323],&mask_data[i][324],&mask_data[i][325],&mask_data[i][326],&mask_data[i][327],&mask_data[i][328],&mask_data[i][329],&mask_data[i][330],&mask_data[i][331],&mask_data[i][332],&mask_data[i][333],&mask_data[i][334],&mask_data[i][335],&mask_data[i][336],&mask_data[i][337],&mask_data[i][338],&mask_data[i][339],&mask_data[i][340],&mask_data[i][341],&mask_data[i][342],&mask_data[i][343],&mask_data[i][344],&mask_data[i][345],&mask_data[i][346],&mask_data[i][347],&mask_data[i][348],&mask_data[i][349],&mask_data[i][350],&mask_data[i][351],&mask_data[i][352],&mask_data[i][353],&mask_data[i][354],&mask_data[i][355],&mask_data[i][356],&mask_data[i][357],&mask_data[i][358],&mask_data[i][359],&mask_data[i][360],&mask_data[i][361],&mask_data[i][362],&mask_data[i][363],&mask_data[i][364],&mask_data[i][365],&mask_data[i][366],&mask_data[i][367],&mask_data[i][368],&mask_data[i][369],&mask_data[i][370],&mask_data[i][371],&mask_data[i][372],&mask_data[i][373],&mask_data[i][374],&mask_data[i][375],&mask_data[i][376],&mask_data[i][377],&mask_data[i][378],&mask_data[i][379]); // Read integers from the file
                            #pragma GCC diagnostic ignored "-Wunused-result"

                    // }
                }
                fclose(file_1_1);

        }

        else if (k==2){
            FILE *file_2 = fopen(file_path_2, "r"); // Open the file in read mode

                if (file_2 == NULL) {
                    printf("file_path_2 Error opening the file.\n");
                    // return 0;
                }

                for (int i = 0; i < h; i++) {
                    for (int j = 0; j < w; j++) {
                            #pragma GCC diagnostic ignored "-Wunused-result"
                            fscanf(file_2,"%f,%f,%f", &data[i][j][0],&data[i][j][1],&data[i][j][2]); // Read integers from the file
                            #pragma GCC diagnostic ignored "-Wunused-result"
                    }
                }
                fclose(file_2);
                FILE *file_2_1 = fopen(file_path_2_1, "r"); // Open the file in read mode
                if (file_2_1 == NULL) {
                    printf("file_path_0 Error opening the file.\n");
                    // return 0;
                }
                for (int i = 0; i < h; i++) {
                    // for (int j = 0; j < w; j++) {
                            #pragma GCC diagnostic ignored "-Wunused-result"
                            fscanf(file_2_1,"%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f", &mask_data[i][0],&mask_data[i][1],&mask_data[i][2],&mask_data[i][3],&mask_data[i][4],&mask_data[i][5],&mask_data[i][6],&mask_data[i][7],&mask_data[i][8],&mask_data[i][9],&mask_data[i][10],&mask_data[i][11],&mask_data[i][12],&mask_data[i][13],&mask_data[i][14],&mask_data[i][15],&mask_data[i][16],&mask_data[i][17],&mask_data[i][18],&mask_data[i][19],&mask_data[i][20],&mask_data[i][21],&mask_data[i][22],&mask_data[i][23],&mask_data[i][24],&mask_data[i][25],&mask_data[i][26],&mask_data[i][27],&mask_data[i][28],&mask_data[i][29],&mask_data[i][30],&mask_data[i][31],&mask_data[i][32],&mask_data[i][33],&mask_data[i][34],&mask_data[i][35],&mask_data[i][36],&mask_data[i][37],&mask_data[i][38],&mask_data[i][39],&mask_data[i][40],&mask_data[i][41],&mask_data[i][42],&mask_data[i][43],&mask_data[i][44],&mask_data[i][45],&mask_data[i][46],&mask_data[i][47],&mask_data[i][48],&mask_data[i][49],&mask_data[i][50],&mask_data[i][51],&mask_data[i][52],&mask_data[i][53],&mask_data[i][54],&mask_data[i][55],&mask_data[i][56],&mask_data[i][57],&mask_data[i][58],&mask_data[i][59],&mask_data[i][60],&mask_data[i][61],&mask_data[i][62],&mask_data[i][63],&mask_data[i][64],&mask_data[i][65],&mask_data[i][66],&mask_data[i][67],&mask_data[i][68],&mask_data[i][69],&mask_data[i][70],&mask_data[i][71],&mask_data[i][72],&mask_data[i][73],&mask_data[i][74],&mask_data[i][75],&mask_data[i][76],&mask_data[i][77],&mask_data[i][78],&mask_data[i][79],&mask_data[i][80],&mask_data[i][81],&mask_data[i][82],&mask_data[i][83],&mask_data[i][84],&mask_data[i][85],&mask_data[i][86],&mask_data[i][87],&mask_data[i][88],&mask_data[i][89],&mask_data[i][90],&mask_data[i][91],&mask_data[i][92],&mask_data[i][93],&mask_data[i][94],&mask_data[i][95],&mask_data[i][96],&mask_data[i][97],&mask_data[i][98],&mask_data[i][99],&mask_data[i][100],&mask_data[i][101],&mask_data[i][102],&mask_data[i][103],&mask_data[i][104],&mask_data[i][105],&mask_data[i][106],&mask_data[i][107],&mask_data[i][108],&mask_data[i][109],&mask_data[i][110],&mask_data[i][111],&mask_data[i][112],&mask_data[i][113],&mask_data[i][114],&mask_data[i][115],&mask_data[i][116],&mask_data[i][117],&mask_data[i][118],&mask_data[i][119],&mask_data[i][120],&mask_data[i][121],&mask_data[i][122],&mask_data[i][123],&mask_data[i][124],&mask_data[i][125],&mask_data[i][126],&mask_data[i][127],&mask_data[i][128],&mask_data[i][129],&mask_data[i][130],&mask_data[i][131],&mask_data[i][132],&mask_data[i][133],&mask_data[i][134],&mask_data[i][135],&mask_data[i][136],&mask_data[i][137],&mask_data[i][138],&mask_data[i][139],&mask_data[i][140],&mask_data[i][141],&mask_data[i][142],&mask_data[i][143],&mask_data[i][144],&mask_data[i][145],&mask_data[i][146],&mask_data[i][147],&mask_data[i][148],&mask_data[i][149],&mask_data[i][150],&mask_data[i][151],&mask_data[i][152],&mask_data[i][153],&mask_data[i][154],&mask_data[i][155],&mask_data[i][156],&mask_data[i][157],&mask_data[i][158],&mask_data[i][159],&mask_data[i][160],&mask_data[i][161],&mask_data[i][162],&mask_data[i][163],&mask_data[i][164],&mask_data[i][165],&mask_data[i][166],&mask_data[i][167],&mask_data[i][168],&mask_data[i][169],&mask_data[i][170],&mask_data[i][171],&mask_data[i][172],&mask_data[i][173],&mask_data[i][174],&mask_data[i][175],&mask_data[i][176],&mask_data[i][177],&mask_data[i][178],&mask_data[i][179],&mask_data[i][180],&mask_data[i][181],&mask_data[i][182],&mask_data[i][183],&mask_data[i][184],&mask_data[i][185],&mask_data[i][186],&mask_data[i][187],&mask_data[i][188],&mask_data[i][189],&mask_data[i][190],&mask_data[i][191],&mask_data[i][192],&mask_data[i][193],&mask_data[i][194],&mask_data[i][195],&mask_data[i][196],&mask_data[i][197],&mask_data[i][198],&mask_data[i][199],&mask_data[i][200],&mask_data[i][201],&mask_data[i][202],&mask_data[i][203],&mask_data[i][204],&mask_data[i][205],&mask_data[i][206],&mask_data[i][207],&mask_data[i][208],&mask_data[i][209],&mask_data[i][210],&mask_data[i][211],&mask_data[i][212],&mask_data[i][213],&mask_data[i][214],&mask_data[i][215],&mask_data[i][216],&mask_data[i][217],&mask_data[i][218],&mask_data[i][219],&mask_data[i][220],&mask_data[i][221],&mask_data[i][222],&mask_data[i][223],&mask_data[i][224],&mask_data[i][225],&mask_data[i][226],&mask_data[i][227],&mask_data[i][228],&mask_data[i][229],&mask_data[i][230],&mask_data[i][231],&mask_data[i][232],&mask_data[i][233],&mask_data[i][234],&mask_data[i][235],&mask_data[i][236],&mask_data[i][237],&mask_data[i][238],&mask_data[i][239],&mask_data[i][240],&mask_data[i][241],&mask_data[i][242],&mask_data[i][243],&mask_data[i][244],&mask_data[i][245],&mask_data[i][246],&mask_data[i][247],&mask_data[i][248],&mask_data[i][249],&mask_data[i][250],&mask_data[i][251],&mask_data[i][252],&mask_data[i][253],&mask_data[i][254],&mask_data[i][255],&mask_data[i][256],&mask_data[i][257],&mask_data[i][258],&mask_data[i][259],&mask_data[i][260],&mask_data[i][261],&mask_data[i][262],&mask_data[i][263],&mask_data[i][264],&mask_data[i][265],&mask_data[i][266],&mask_data[i][267],&mask_data[i][268],&mask_data[i][269],&mask_data[i][270],&mask_data[i][271],&mask_data[i][272],&mask_data[i][273],&mask_data[i][274],&mask_data[i][275],&mask_data[i][276],&mask_data[i][277],&mask_data[i][278],&mask_data[i][279],&mask_data[i][280],&mask_data[i][281],&mask_data[i][282],&mask_data[i][283],&mask_data[i][284],&mask_data[i][285],&mask_data[i][286],&mask_data[i][287],&mask_data[i][288],&mask_data[i][289],&mask_data[i][290],&mask_data[i][291],&mask_data[i][292],&mask_data[i][293],&mask_data[i][294],&mask_data[i][295],&mask_data[i][296],&mask_data[i][297],&mask_data[i][298],&mask_data[i][299],&mask_data[i][300],&mask_data[i][301],&mask_data[i][302],&mask_data[i][303],&mask_data[i][304],&mask_data[i][305],&mask_data[i][306],&mask_data[i][307],&mask_data[i][308],&mask_data[i][309],&mask_data[i][310],&mask_data[i][311],&mask_data[i][312],&mask_data[i][313],&mask_data[i][314],&mask_data[i][315],&mask_data[i][316],&mask_data[i][317],&mask_data[i][318],&mask_data[i][319],&mask_data[i][320],&mask_data[i][321],&mask_data[i][322],&mask_data[i][323],&mask_data[i][324],&mask_data[i][325],&mask_data[i][326],&mask_data[i][327],&mask_data[i][328],&mask_data[i][329],&mask_data[i][330],&mask_data[i][331],&mask_data[i][332],&mask_data[i][333],&mask_data[i][334],&mask_data[i][335],&mask_data[i][336],&mask_data[i][337],&mask_data[i][338],&mask_data[i][339],&mask_data[i][340],&mask_data[i][341],&mask_data[i][342],&mask_data[i][343],&mask_data[i][344],&mask_data[i][345],&mask_data[i][346],&mask_data[i][347],&mask_data[i][348],&mask_data[i][349],&mask_data[i][350],&mask_data[i][351],&mask_data[i][352],&mask_data[i][353],&mask_data[i][354],&mask_data[i][355],&mask_data[i][356],&mask_data[i][357],&mask_data[i][358],&mask_data[i][359],&mask_data[i][360],&mask_data[i][361],&mask_data[i][362],&mask_data[i][363],&mask_data[i][364],&mask_data[i][365],&mask_data[i][366],&mask_data[i][367],&mask_data[i][368],&mask_data[i][369],&mask_data[i][370],&mask_data[i][371],&mask_data[i][372],&mask_data[i][373],&mask_data[i][374],&mask_data[i][375],&mask_data[i][376],&mask_data[i][377],&mask_data[i][378],&mask_data[i][379]); // Read integers from the file
                            #pragma GCC diagnostic ignored "-Wunused-result"

                    // }
                }
                fclose(file_2_1);
        }
        else {
            FILE *file_3 = fopen(file_path_3, "r"); // Open the file in read mode

                if (file_3 == NULL) {
                    printf("file_path_3 Error opening the file.\n");
                    // return 0;
                }
                // Read data from the file
                for (int i = 0; i < h; i++) {
                    for (int j = 0; j < w; j++) {
                            #pragma GCC diagnostic ignored "-Wunused-result"
                            fscanf(file_3, "%f,%f,%f", &data[i][j][0],&data[i][j][1],&data[i][j][2]); // Read integers from the file
                            #pragma GCC diagnostic ignored "-Wunused-result"
                    }
                }
                fclose(file_3);
                FILE *file_3_1 = fopen(file_path_3_1, "r"); // Open the file in read mode
                if (file_3_1 == NULL) {
                    printf("file_path_0 Error opening the file.\n");
                    // return 0;
                }
                for (int i = 0; i < h; i++) {
                    // for (int j = 0; j < w; j++) {
                            #pragma GCC diagnostic ignored "-Wunused-result"
                            fscanf(file_3_1,"%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f,%f",&mask_data[i][0],&mask_data[i][1],&mask_data[i][2],&mask_data[i][3],&mask_data[i][4],&mask_data[i][5],&mask_data[i][6],&mask_data[i][7],&mask_data[i][8],&mask_data[i][9],&mask_data[i][10],&mask_data[i][11],&mask_data[i][12],&mask_data[i][13],&mask_data[i][14],&mask_data[i][15],&mask_data[i][16],&mask_data[i][17],&mask_data[i][18],&mask_data[i][19],&mask_data[i][20],&mask_data[i][21],&mask_data[i][22],&mask_data[i][23],&mask_data[i][24],&mask_data[i][25],&mask_data[i][26],&mask_data[i][27],&mask_data[i][28],&mask_data[i][29],&mask_data[i][30],&mask_data[i][31],&mask_data[i][32],&mask_data[i][33],&mask_data[i][34],&mask_data[i][35],&mask_data[i][36],&mask_data[i][37],&mask_data[i][38],&mask_data[i][39],&mask_data[i][40],&mask_data[i][41],&mask_data[i][42],&mask_data[i][43],&mask_data[i][44],&mask_data[i][45],&mask_data[i][46],&mask_data[i][47],&mask_data[i][48],&mask_data[i][49],&mask_data[i][50],&mask_data[i][51],&mask_data[i][52],&mask_data[i][53],&mask_data[i][54],&mask_data[i][55],&mask_data[i][56],&mask_data[i][57],&mask_data[i][58],&mask_data[i][59],&mask_data[i][60],&mask_data[i][61],&mask_data[i][62],&mask_data[i][63],&mask_data[i][64],&mask_data[i][65],&mask_data[i][66],&mask_data[i][67],&mask_data[i][68],&mask_data[i][69],&mask_data[i][70],&mask_data[i][71],&mask_data[i][72],&mask_data[i][73],&mask_data[i][74],&mask_data[i][75],&mask_data[i][76],&mask_data[i][77],&mask_data[i][78],&mask_data[i][79],&mask_data[i][80],&mask_data[i][81],&mask_data[i][82],&mask_data[i][83],&mask_data[i][84],&mask_data[i][85],&mask_data[i][86],&mask_data[i][87],&mask_data[i][88],&mask_data[i][89],&mask_data[i][90],&mask_data[i][91],&mask_data[i][92],&mask_data[i][93],&mask_data[i][94],&mask_data[i][95],&mask_data[i][96],&mask_data[i][97],&mask_data[i][98],&mask_data[i][99],&mask_data[i][100],&mask_data[i][101],&mask_data[i][102],&mask_data[i][103],&mask_data[i][104],&mask_data[i][105],&mask_data[i][106],&mask_data[i][107],&mask_data[i][108],&mask_data[i][109],&mask_data[i][110],&mask_data[i][111],&mask_data[i][112],&mask_data[i][113],&mask_data[i][114],&mask_data[i][115],&mask_data[i][116],&mask_data[i][117],&mask_data[i][118],&mask_data[i][119],&mask_data[i][120],&mask_data[i][121],&mask_data[i][122],&mask_data[i][123],&mask_data[i][124],&mask_data[i][125],&mask_data[i][126],&mask_data[i][127],&mask_data[i][128],&mask_data[i][129],&mask_data[i][130],&mask_data[i][131],&mask_data[i][132],&mask_data[i][133],&mask_data[i][134],&mask_data[i][135],&mask_data[i][136],&mask_data[i][137],&mask_data[i][138],&mask_data[i][139],&mask_data[i][140],&mask_data[i][141],&mask_data[i][142],&mask_data[i][143],&mask_data[i][144],&mask_data[i][145],&mask_data[i][146],&mask_data[i][147],&mask_data[i][148],&mask_data[i][149],&mask_data[i][150],&mask_data[i][151],&mask_data[i][152],&mask_data[i][153],&mask_data[i][154],&mask_data[i][155],&mask_data[i][156],&mask_data[i][157],&mask_data[i][158],&mask_data[i][159],&mask_data[i][160],&mask_data[i][161],&mask_data[i][162],&mask_data[i][163],&mask_data[i][164],&mask_data[i][165],&mask_data[i][166],&mask_data[i][167],&mask_data[i][168],&mask_data[i][169],&mask_data[i][170],&mask_data[i][171],&mask_data[i][172],&mask_data[i][173],&mask_data[i][174],&mask_data[i][175],&mask_data[i][176],&mask_data[i][177],&mask_data[i][178],&mask_data[i][179],&mask_data[i][180],&mask_data[i][181],&mask_data[i][182],&mask_data[i][183],&mask_data[i][184],&mask_data[i][185],&mask_data[i][186],&mask_data[i][187],&mask_data[i][188],&mask_data[i][189],&mask_data[i][190],&mask_data[i][191],&mask_data[i][192],&mask_data[i][193],&mask_data[i][194],&mask_data[i][195],&mask_data[i][196],&mask_data[i][197],&mask_data[i][198],&mask_data[i][199],&mask_data[i][200],&mask_data[i][201],&mask_data[i][202],&mask_data[i][203],&mask_data[i][204],&mask_data[i][205],&mask_data[i][206],&mask_data[i][207],&mask_data[i][208],&mask_data[i][209],&mask_data[i][210],&mask_data[i][211],&mask_data[i][212],&mask_data[i][213],&mask_data[i][214],&mask_data[i][215],&mask_data[i][216],&mask_data[i][217],&mask_data[i][218],&mask_data[i][219],&mask_data[i][220],&mask_data[i][221],&mask_data[i][222],&mask_data[i][223],&mask_data[i][224],&mask_data[i][225],&mask_data[i][226],&mask_data[i][227],&mask_data[i][228],&mask_data[i][229],&mask_data[i][230],&mask_data[i][231],&mask_data[i][232],&mask_data[i][233],&mask_data[i][234],&mask_data[i][235],&mask_data[i][236],&mask_data[i][237],&mask_data[i][238],&mask_data[i][239],&mask_data[i][240],&mask_data[i][241],&mask_data[i][242],&mask_data[i][243],&mask_data[i][244],&mask_data[i][245],&mask_data[i][246],&mask_data[i][247],&mask_data[i][248],&mask_data[i][249],&mask_data[i][250],&mask_data[i][251],&mask_data[i][252],&mask_data[i][253],&mask_data[i][254],&mask_data[i][255],&mask_data[i][256],&mask_data[i][257],&mask_data[i][258],&mask_data[i][259],&mask_data[i][260],&mask_data[i][261],&mask_data[i][262],&mask_data[i][263],&mask_data[i][264],&mask_data[i][265],&mask_data[i][266],&mask_data[i][267],&mask_data[i][268],&mask_data[i][269],&mask_data[i][270],&mask_data[i][271],&mask_data[i][272],&mask_data[i][273],&mask_data[i][274],&mask_data[i][275],&mask_data[i][276],&mask_data[i][277],&mask_data[i][278],&mask_data[i][279],&mask_data[i][280],&mask_data[i][281],&mask_data[i][282],&mask_data[i][283],&mask_data[i][284],&mask_data[i][285],&mask_data[i][286],&mask_data[i][287],&mask_data[i][288],&mask_data[i][289],&mask_data[i][290],&mask_data[i][291],&mask_data[i][292],&mask_data[i][293],&mask_data[i][294],&mask_data[i][295],&mask_data[i][296],&mask_data[i][297],&mask_data[i][298],&mask_data[i][299],&mask_data[i][300],&mask_data[i][301],&mask_data[i][302],&mask_data[i][303],&mask_data[i][304],&mask_data[i][305],&mask_data[i][306],&mask_data[i][307],&mask_data[i][308],&mask_data[i][309],&mask_data[i][310],&mask_data[i][311],&mask_data[i][312],&mask_data[i][313],&mask_data[i][314],&mask_data[i][315],&mask_data[i][316],&mask_data[i][317],&mask_data[i][318],&mask_data[i][319],&mask_data[i][320],&mask_data[i][321],&mask_data[i][322],&mask_data[i][323],&mask_data[i][324],&mask_data[i][325],&mask_data[i][326],&mask_data[i][327],&mask_data[i][328],&mask_data[i][329],&mask_data[i][330],&mask_data[i][331],&mask_data[i][332],&mask_data[i][333],&mask_data[i][334],&mask_data[i][335],&mask_data[i][336],&mask_data[i][337],&mask_data[i][338],&mask_data[i][339],&mask_data[i][340],&mask_data[i][341],&mask_data[i][342],&mask_data[i][343],&mask_data[i][344],&mask_data[i][345],&mask_data[i][346],&mask_data[i][347],&mask_data[i][348],&mask_data[i][349],&mask_data[i][350],&mask_data[i][351],&mask_data[i][352],&mask_data[i][353],&mask_data[i][354],&mask_data[i][355],&mask_data[i][356],&mask_data[i][357],&mask_data[i][358],&mask_data[i][359],&mask_data[i][360],&mask_data[i][361],&mask_data[i][362],&mask_data[i][363],&mask_data[i][364],&mask_data[i][365],&mask_data[i][366],&mask_data[i][367],&mask_data[i][368],&mask_data[i][369],&mask_data[i][370],&mask_data[i][371],&mask_data[i][372],&mask_data[i][373],&mask_data[i][374],&mask_data[i][375],&mask_data[i][376],&mask_data[i][377],&mask_data[i][378],&mask_data[i][379]); // Read integers from the file
                            #pragma GCC diagnostic ignored "-Wunused-result"

                    // }
                }
                fclose(file_3_1);
        }

        for (int i = 0; i < GMatImage->height; i++) {
            for (int j = 0; j < GMatImage->width; j++) {
                CvScalar pixelGMat = cvGet2D(GMatImage, i, j);
                CvScalar pixelMMat = cvGet2D(MMatImage, i, j);

                // Extract RGBA values
                float r =data[i][j][0]; //pixelGMat.val[0] / 255.0;
                float g =data[i][j][1]; //pixelGMat.val[1] / 255.0;
                float b =data[i][j][2];//pixelGMat.val[2] / 255.0;

                cvSetReal3D(weights[k], i, j, 0, r);  // Set red component
                cvSetReal3D(weights[k], i, j, 1, g);  // Set green component
                cvSetReal3D(weights[k], i, j, 2, b); 

                CvScalar pixelMMat_final;
                pixelMMat_final.val[0]=0;
                double pixelMMat_temp=pixelMMat.val[0]/255;
                if ( pixelMMat_temp > 0.1 ){
                    pixelMMat_final.val[0]=1;
                }
                // CvScalar scalarValue = cvScalar(pixelMMat_final.val[0], 0, 0, 0);
                // cvSetReal3D(masks[k], i, j,mask_data[i][j]);
                cvSetReal2D(masks[k], i, j, mask_data[i][j]);
                // cvSet2D(masks[k], i, j, mask_data[i][j]);
                // printf("000\n");
                // printf("%d\n",i);
                // printf("%d\n",j);
                // printf("%d\n",h);
                // printf("%d\n",w);
    

            }
        }
        // printf("111000\n");

    }

    // Release the loaded images when done

}


void  project_action(IplImage* image, double project_matrix[3][3], double project_shape[2],IplImage* result) {
    // IplImage* result = cvCreateImage(cvSize((int)project_shape[0], (int)project_shape[1]), IPL_DEPTH_8U, image->nChannels);

    CvMat* warp_matrix = cvCreateMat(3, 3, CV_32FC1);
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            CV_MAT_ELEM(*warp_matrix, float, i, j) = (float)project_matrix[i][j];
        }
    }

    cvWarpPerspective(image, result, warp_matrix, CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS, cvScalarAll(0));


    // Release resources
    cvReleaseMat(&warp_matrix);
    // return result ;
}

void load_camera_params(const char* project_matrix_path , const char* project_shape_path,double project_matrix[3][3],double project_shape[2]) {
    FILE *file;
    char line[256]; 
    FILE *file_2;
    char line_2[256]; 

    file = fopen(project_matrix_path, "r");
    if (file == NULL) {
        printf("Error: Unable to open the file.\n");
    }
    for (int i = 0; i < 3; i++) {
        #pragma GCC diagnostic ignored "-Wunused-result"
        fgets(line, sizeof(line), file);
        #pragma GCC diagnostic ignored "-Wunused-result"

        sscanf(line, "%lf,%lf,%lf,", &project_matrix[i][0], &project_matrix[i][1], &project_matrix[i][2]);
    }
    fclose(file);

    file_2 = fopen(project_shape_path, "r");
    if (file_2 == NULL) {
        printf("Error: Unable to open the file.\n");
    }
    #pragma GCC diagnostic ignored "-Wunused-result"
    fgets(line_2, sizeof(line), file);
    #pragma GCC diagnostic warning "-Wunused-result"

    sscanf(line_2, "%lf,%lf,", &project_shape[0], &project_shape[1]);

    fclose(file_2);

}
void flip(const char* camera_name, IplImage* image, IplImage* result) {
    // IplImage* result = cvCreateImage(cvGetSize(image), image->depth, image->nChannels);

    if (strcmp(camera_name, "front") == 0) {
        cvCopy(image, result, NULL);
    } else if (strcmp(camera_name, "back") == 0) {
        cvFlip(image, result, -1); // Flip both horizontally and vertically
    } else if (strcmp(camera_name, "left") == 0) {
        cvTranspose(image, result);
        cvFlip(result, result, 0); // Flip vertically

    } else {

        cvTranspose(image, result);
        cvFlip(result, result, 1);

    }

}
