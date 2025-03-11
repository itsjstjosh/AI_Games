#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/utils/logger.hpp" // utils::logging::LOG_LEVEL_WARNING
#include <iostream>
#include <string>

// g++ 06_capture_show_video_grab_image.cpp -lopencv_core -lopencv_highgui -lopencv_videoio -lopencv_imgcodecs

int main(int argc, const char *argv[])
{
  cv::Mat frame;
  double fps = 30;
  const char win_name[] = "Live Video...";

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

  int i{0}; // a simple counter to save multiple images
  while (1) {
    vid_in >> frame;
    cv::imshow(win_name, frame);
    int code = cv::waitKey(1000/fps); // how long to wait for a key (msecs)
    if      (code == 27) // escape. See http://www.asciitable.com/
      break;
    else if (code == 32) // space.  ""
      //      cv::imwrite("../out.png", frame);
      cv::imwrite(std::string("../out") + std::to_string(i++) + ".png", frame);
  }

  vid_in.release();
  return 0;
}

