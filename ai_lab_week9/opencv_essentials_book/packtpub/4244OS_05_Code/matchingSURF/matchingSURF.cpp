#include <iostream>
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/xfeatures2d.hpp"

using namespace std;
using namespace cv;

int main( int argc, char** argv )
{
  Mat img_orig     = imread(argc > 1 ? argv[1] : "../lena.png",      IMREAD_GRAYSCALE);
  Mat img_fragment = imread(argc > 2 ? argv[2] : "../lena_crop_180.png", IMREAD_GRAYSCALE);

  if (img_orig.empty() || img_fragment.empty())
  {
    cerr << " Failed to load images." << endl;
    return -1;
  }

  //Step 1: Detect keypoints using SURF Detector
  vector<KeyPoint> keypoints1, keypoints2;
  using cv::xfeatures2d::SIFT;
  Ptr<Feature2D> f2d = SIFT::create();

  f2d->detect(img_orig,     keypoints1);
  f2d->detect(img_fragment, keypoints2);

  //Step 2: Compute descriptors using SURF Extractor
  Mat descriptors1, descriptors2;

  f2d->compute(img_orig,     keypoints1, descriptors1);
  f2d->compute(img_fragment, keypoints2, descriptors2);

  //Step 3: Match descriptors using a FlannBased Matcher
  FlannBasedMatcher matcher;
  vector<DMatch> matches12;
  vector<DMatch> matches21;
  vector<DMatch> good_matches;

  matcher.match(descriptors1, descriptors2, matches12);
  matcher.match(descriptors2, descriptors1, matches21);

  //Step 4: Filter results using cross-checking
  for( size_t i = 0; i < matches12.size(); i++ )
  {
    DMatch forward  = matches12[i];
    DMatch backward = matches21[forward.trainIdx];
    if (backward.trainIdx == forward.queryIdx)
      good_matches.push_back(forward);
  }

  //Draw the results
  Mat img_result_matches;
  drawMatches(img_orig, keypoints1, img_fragment, keypoints2,
              good_matches, img_result_matches);
  imshow("Matching SURF Descriptors", img_result_matches);

  waitKey(0);

  return 0;
}
