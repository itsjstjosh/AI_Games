#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"

#include <iostream>

using namespace cv;
using namespace std;

int _brightness = 100;
int _contrast = 100;

Mat image;

/* brightness/contrast callback function */
void updateBrightnessContrast( int, void* )
{
    int histSize = 255;
    int brightness = _brightness - 100;
    int contrast = _contrast - 100;

    double a, b;
    if( contrast > 0 )
    {
       double delta = 127.*contrast/100;
       a = 255./(255. - delta*2);
       b = a*(brightness - delta);
    }
    else
    {
      double delta = -128.*contrast/100;
      a = (256.-delta*2)/255.;
      b = a*brightness + delta;
    }

    Mat dst, hist;

    image.convertTo(dst, CV_8U, a, b);

    imshow("image", dst);

    calcHist(&dst, 1, 0, Mat(), hist, 1, &histSize, 0);
    Mat histImage = Mat::ones(200, 320, CV_8U)*255;

    normalize(hist, hist, 0, histImage.rows, CV_MINMAX, CV_32F);

    histImage = Scalar::all(255);
    int binW = cvRound((double)histImage.cols/histSize);

    for( int i = 0; i < histSize; i++ )
       rectangle( histImage, Point(i*binW, histImage.rows),
                  Point((i+1)*binW, histImage.rows - cvRound(hist.at<float>(i))),
                  Scalar::all(0), -1, 8, 0 );
       imshow("histogram", histImage);
   }

const char* keys =
   {
            "{1| |fruits.jpg|input image file}"
   };

int main( int argc, const char** argv )
   {
     CommandLineParser parser(argc, argv, keys);
            string inputImage = parser.get<string>("1");

            // Read the source image.
            image = imread( inputImage, 0 );

        namedWindow("image", 0);
        namedWindow("histogram", 0);

        createTrackbar("brightness", "image", &_brightness, 200, updateBrightnessContrast);
        createTrackbar("contrast", "image", &_contrast, 200, updateBrightnessContrast);

        updateBrightnessContrast(0, 0);
        waitKey();

    return 0;
    }
