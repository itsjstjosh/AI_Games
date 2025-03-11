#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/utils/logger.hpp" // utils::logging::LOG_LEVEL_WARNING
#include <iostream>

// g++ 03_capture_show_image.cpp -lopencv_core -lopencv_highgui -lopencv_videoio

int main(int argc, const char *argv[])
{
  cv::Mat frame;
  double fps = 30;
  const char win_name[] = "Press a key...";

  cv::utils::logging::setLogLevel(cv::utils::logging::LOG_LEVEL_SILENT);

  std::cout << "Wait 60 secs. for camera access to be obtained..." << std::endl;
  cv::VideoCapture vid_in(0);   // argument is the camera id

  if (vid_in.isOpened())
  {
    std::cout << "Camera capture obtained." << std::endl;
  }
  else
  {
    std::cerr << "error: Camera 0 could not be opened for capture.\n";
    return -1;
  }

  cv::namedWindow(win_name);
  while (true)
  {
    vid_in >> frame;
    if (cv::waitKey(1000/fps) >= 0) // how long to wait for a key (milliseconds)
      break;
  }

  imshow(win_name, frame);
  cv::waitKey(0);

  vid_in.release();
  return 0;
}

