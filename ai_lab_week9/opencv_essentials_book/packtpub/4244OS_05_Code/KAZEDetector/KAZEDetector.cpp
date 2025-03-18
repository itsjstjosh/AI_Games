#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/features2d.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
  //Load original image and convert to gray scale
  Mat in_img = imread("../blox.png");
  cvtColor( in_img, in_img, COLOR_BGR2GRAY);

  //Create a keypoint vectors
  vector<KeyPoint> keypoints1,keypoints2;

  //Create KAZE and AKAZE detectors
  Ptr<KAZE>  detector1 =  KAZE::create(true,true);
  Ptr<AKAZE> detector2 = AKAZE::create(cv::AKAZE::DESCRIPTOR_KAZE_UPRIGHT,0,3);

  //Compute keypoints in in_img with detector1 and detector2
  detector1->detect(in_img, keypoints1);
  detector2->detect(in_img, keypoints2,cv::Mat());

  Mat out_img1, out_img2;
  //Draw keypoints1 and keypoints2
  const auto draw_flag = DrawMatchesFlags::DRAW_RICH_KEYPOINTS;
  drawKeypoints(in_img,keypoints1,out_img1,Scalar::all(-1), draw_flag);
  drawKeypoints(in_img,keypoints2,out_img2,Scalar::all(-1), draw_flag);

  //Show result of detector1 and detector2
  imshow("out_img1", out_img1);
  imshow("out_img2", out_img2);
  waitKey(0);

  return 0;
}


