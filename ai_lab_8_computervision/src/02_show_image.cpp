#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"

// g++ 02_show_image.cpp -lopencv_core -lopencv_highgui -lopencv_imgcodecs

int main(int argc, const char *argv[])
{
  cv::Mat frame = cv::imread("../../baboon.jpg");//, cv::IMREAD_UNCHANGED);
  const char win_name[] = "Simple Baboon...";

  cv::namedWindow(win_name);
  cv::imshow(win_name, frame);

  while (1) {
    int code = cv::waitKey(10); // how long to wait for a key (10 milliseconds)
    if (code == 27) // escape. See http://www.asciitable.com/
        break;
  }

  return 0;
}

