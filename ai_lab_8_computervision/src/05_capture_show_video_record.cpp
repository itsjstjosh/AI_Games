#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/utils/logger.hpp" // utils::logging::LOG_LEVEL_WARNING
#include <iostream>
#include"opencv2/imgproc/imgproc.hpp "


// g++ 05_capture_show_video_record.cpp -lopencv_core -lopencv_highgui -lopencv_videoio

int main(int argc, const char *argv[])
{
  cv::Mat frame;
  double fps = 30;
  const char win_name[] = "Live Video...";
  const char file_out[] = "../recorded.avi";

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


  double width  = vid_in.get(cv::CAP_PROP_FRAME_WIDTH);
  double height = vid_in.get(cv::CAP_PROP_FRAME_HEIGHT);
  cv::Size_<double> sz(width,height);
  //cv::GaussianBlur(, dst, ksize, sigma);

  // MJPG codec is supported natively by OpenCV
  const int codec = cv::VideoWriter::fourcc('M', 'J', 'P', 'G');
  cv::VideoWriter vid_out(file_out, codec, fps, sz);
  if (!vid_out.isOpened()) {
    std::cerr << "error: File "<< file_out << " could not be opened.\n";
    return -1;
  }

  cv::namedWindow(win_name);
  while (1) {
    vid_in  >> frame;
    vid_out << frame;
    imshow(win_name, frame);
    if (cv::waitKey(1000/fps) >= 0) // how long to wait for a key (milliseconds)
      break;
  }

  vid_in.release();
  return 0;
}

