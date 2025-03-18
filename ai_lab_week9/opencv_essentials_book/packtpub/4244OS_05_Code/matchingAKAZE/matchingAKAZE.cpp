#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/highgui.hpp"

using namespace cv;
using namespace std;

int main(int argc, char *argv[])
{
  Mat img_orig = imread(argc > 1 ? argv[1] : "../blox.png",      IMREAD_GRAYSCALE);
  Mat img_cam  = imread(argc > 2 ? argv[2] : "../blox_crop.png", IMREAD_GRAYSCALE);

  if (!img_orig.data || !img_cam.data)
  {
    cerr << " Failed to load images." << endl;
    return -1;
  }

  // Step 1: Detect the keypoints using AKAZE Detector
  Ptr<Feature2D> f2d = AKAZE::create();
  vector<KeyPoint> keypoints1, keypoints2;

  f2d->detect(img_orig, keypoints1);
  f2d->detect(img_cam,  keypoints2);

  // Step 2: Compute descriptors using AKAZE Extractor
  Mat descriptors1, descriptors2;

  f2d->compute(img_orig, keypoints1, descriptors1);
  f2d->compute(img_cam,  keypoints2, descriptors2);

  // Step 3: Match descriptors using a BruteForce-Hamming Matcher
  BFMatcher matcher;
  vector<vector<DMatch>> matches;
  vector<DMatch> good_matches;

  matcher.knnMatch(descriptors1, descriptors2, matches, 2);

  // Step 4: Filter results using ratio-test
  float ratioT = 0.6;
  for (int i = 0; i < (int) matches.size(); i++)
  {
    if((matches[i][0].distance < ratioT*(matches[i][1].distance)) && ((int) matches[i].size()<=2 && (int) matches[i].size()>0))
    {
      good_matches.push_back(matches[i][0]);
    }
  }

  // Draw the results
  Mat img_result_matches;
  drawMatches(img_orig, keypoints1, img_cam, keypoints2, good_matches, img_result_matches);
  imshow("Matching AKAZE Descriptors", img_result_matches);

  waitKey(0);
  return 0;
}
