#include <iostream>
#include <math.h>
#include <chrono>
#include <opencv2/opencv.hpp>
// not sure if these two are needed:
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"


#if CUDA

// if CUDA is being used, include the appropriate headers
//#include <opencv2/gpu/gpu.hpp> // pre-3.0 method, don't use this !!
#include "opencv2/cudaarithm.hpp"
// define "universal Mat" as a Mat that lives in VRAM
typedef cv::cuda::GpuMat uMat;
// define namespace alias for operations (universal cv)
namespace ucv = cv::cuda;

#else

// define "universal Mat" as a Mat that lives in RAM
typedef cv::Mat uMat;
// define namespace alias for operations (universal cv)
namespace ucv = cv;

#endif


class ExampleClass
{
public:
  ExampleClass();
  void    add_mat(cv::Mat);
  void    operations();
  cv::Mat get_mat();

  uMat universalMat1, universalMat2;
private:
  int x_val_;
};