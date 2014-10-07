// ---------------------------------------------------------------
// TME motorway dataset pre-processing
// ---------------------------------------------------------------
// To run,
// $ g++ preprocess.cpp -o filename -I/usr/local/include/opencv2 -L/usr/local/lib -lm -lopencv_core -lopencv_highgui -lopencv_imgproc
// $ ./filename 1 left  (or right)
// ---------------------------------------------------------------
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int main(int argc, char** argv) {

   int i;
   int numImg = atoi(argv[1]);
   string cam = argv[2];
   string filename;

   // define matrix variables
   Mat img, img_rgb, img_flip;

   for (i=0; i<numImg; i++) {

      // set filename and read image
      if (cam == string("left"))       filename = format("lena%04i-L.png", i+1);
      else if (cam == string("right")) filename = format("lena%04i-R.png", i+1);
      else                             return 1;
      img = imread(filename, 1); // as is(-1), grayscale(0), color(1)

      // convert color
      cvtColor(img, img_rgb, CV_RGB2GRAY, 0); //BayerGB2BGR, 0);

      // flip image
      flip(img_rgb, img_flip, 0); // x-axis(0), y-axis(1), both(-1)

      // display img
      imshow("img", img_flip);

      // save img
      imwrite(filename, img_flip);
   }

  // wait
  waitKey(0);
  return 0;
}
