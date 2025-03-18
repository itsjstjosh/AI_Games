#include "opencv2/video/tracking.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/videoio/videoio.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

// g++ simple_fback.cpp -lopencv_core -lopencv_highgui -lopencv_videoio -lopencv_video -lopencv_imgproc

int main(int argc, char** argv)
{
  cv::VideoCapture vid(0);
  if (!vid.isOpened()) {
    std::cerr << "error: Camera 0 could not be opened for capture.\n";
    return -1;
  }

  cv::Mat  flow, frame;
  cv::UMat gray, prevgray, uflow; // Change to cv::Mat if you see OpenCL errors
  const char win_name[] = "simple_fback";
  cv::namedWindow(win_name);

  for (;;)
  {
    vid >> frame;
    cvtColor(frame, gray, cv::COLOR_BGR2GRAY);

    if (!prevgray.empty())
    {
      calcOpticalFlowFarneback(prevgray, gray, uflow, 0.5, 3, 15, 3, 5, 1.2, 0);
      uflow.copyTo(flow);

      cv::Point2f total{};
      const int step = 16;
      float num_samples = 0;
      for (int y = 0; y < flow.rows; y += step) {
        for (int x = 0; x < flow.cols; x += step) {
          total += flow.at<cv::Point2f>(y,x);
          num_samples++;
        }
      }

      cv::Point2f v = total / num_samples;
      std::cout << v << '\n';

      cv::imshow(win_name, frame);
    }

    if (cv::waitKeyEx(30) >= 0)
      break;

    std::swap(prevgray, gray);
  }

  return 0;
}
