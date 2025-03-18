#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/features2d.hpp"
#include <iostream>

// g++ FASTDetector.cpp -lopencv_core -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs -lopencv_imgproc -lopencv_features2d

using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
  //Load original image and convert to gray scale
  Mat in_img = imread("../blox.png");
  cvtColor(in_img, in_img, COLOR_BGR2GRAY);

  //Create keypoint vectors
  vector<KeyPoint> keypoints1,keypoints2;
  //FAST detector with threshold value of 80 and 100
  Ptr<FastFeatureDetector> detector1 = FastFeatureDetector::create(80);
  Ptr<FastFeatureDetector> detector2 = FastFeatureDetector::create(100);

  //Compute keypoints in in_img with detector1 and detector2
  detector1->detect(in_img, keypoints1); // opencv3
  detector2->detect(in_img, keypoints2); // opencv3

  Mat out_img1, out_img2;
  //Draw keypoints1 and keypoints2
  drawKeypoints(in_img,keypoints1,out_img1);
  drawKeypoints(in_img,keypoints2,out_img2);

  //Show keypoints detected by detector1 and detector2
  imshow("out_img1", out_img1);
  imshow("out_img2", out_img2);
  waitKey(0);

  return 0;
}










