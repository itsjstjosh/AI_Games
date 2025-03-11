#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

#include "opencv2/imgproc/imgproc.hpp"



// g++ 01_show_colour.cpp -lopencv_core -lopencv_highgui
	
int G_redness = 255;
  
void on_trackbar_slide(int pos, void*)
{
    G_redness = pos;
}




int main(int argc, const char *argv[])
{
double fps = 30;

  cv::Mat frame(480, 640, CV_8UC3, cv::Scalar(255,255,G_redness)); // RED: n.b. BGR colour
  const char win_name[] = "Simple Colour...";

  cv::namedWindow(win_name);
  cv::createTrackbar("", win_name, &G_redness, 255 , on_trackbar_slide);
 // cv::waitKey(0);

  while (true) 
  {
      frame = cv::Scalar(0, 255, G_redness);
      cv::circle(frame, cv::Point(frame.cols/2, frame.rows/2 ), 255 - G_redness, G_redness, cv::FILLED);
      imshow(win_name, frame);
      if (cv::waitKey(1000.0 / fps) >= 0) // how long to wait for a key (milliseconds)
        break;
  
  
  }

  return 0;
}

