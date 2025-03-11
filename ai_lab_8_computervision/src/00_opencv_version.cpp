#include "opencv2/opencv.hpp"

// Although the above include mentions opencv2, this is actually OpenCV 4

int main(int argc, char *argv[])
{
  std::cout << "OpenCV version   : " << CV_VERSION          << std::endl;
  std::cout << "Major version    : " << CV_MAJOR_VERSION    << std::endl;
  std::cout << "Minor version    : " << CV_MINOR_VERSION    << std::endl;
  std::cout << "Subminor version : " << CV_SUBMINOR_VERSION << std::endl;

  if (CV_MAJOR_VERSION < 3) {
    // older OpenCV 2 code goes here
  } else {
    // newer OpenCV code goes here
  }

  return 0;
}




// cl.exe command line compilation on Windows:
// > "C:\Program Files (x86)\Microsoft Visual Studio\2019\BuildTools\VC\Auxiliary\Build\vcvars64.bat"
// > set PATH=C:\vcpkg\installed\x64-windows\debug\bin;%PATH%
// > cl /EHsc /I %VCPKG_ROOT%\installed\x64-windows\include 0_opencv_version.cpp opencv_core343d.lib /link /libpath:%VCPKG_ROOT%\installed\x64-windows\debug\lib
// 0_opencv_version
