#include "example.h"




//using namespace std;

ExampleClass::ExampleClass()
{
  std::cout << "instantiated" << std::endl;

}


void ExampleClass::add_mat(cv::Mat inMat)
{

  // The type uMat is defined in header based on the existence of CUDA.
  // Assigning the uMat class member needs to consider this.

#if CUDA

  // uMat is cv::cuda::GpuMat
  std::cout << "assigning to GpuMat" << std::endl;
  cv::cuda::GpuMat onGpuMat;
  onGpuMat.upload(inMat);
  // onGpuMat is now an OpenCV Mat on the VRAM
  // assign class member universalMat1 to this
  universalMat1 = onGpuMat;

#else

  // uMat is cv::Mat
  std::cout << "assigning to Mat" << std::endl;
  universalMat1 = inMat;

#endif

}

void ExampleClass::example_operation()
{
  // perform operation on uMat class member

  // here is the syntax for cv::Mat and cv::cuda::GpuMat
  // cv::threshold(      src, dst, 128.0, 255.0, CV_THRESH_BINARY);
  // cv::cuda::threshold(src, dst, 128.0, 255.0, CV_THRESH_BINARY);




  std::cout << "starting operations" << std::endl;
  ucv::threshold(universalMat1, universalMat2, 128.0, 255.0, CV_THRESH_BINARY);
  std::cout << "operations complete" << std::endl;


}