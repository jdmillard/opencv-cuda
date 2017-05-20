#include "example.h"


ExampleClass::ExampleClass()
{
  std::cout << "ExampleClass instantiated" << std::endl;
}


void ExampleClass::add_mat(cv::Mat inMat)
{
  // The uMat type is defined in the header depending on the existence of CUDA.
  // Assigning the uMat class member needs to consider this.

#if CUDA
  // uMat is cv::cuda::GpuMat
  cv::cuda::GpuMat myGpuMat;
  myGpuMat.upload(inMat);
  // myGpuMat is now a deep copy of inMat on the VRAM
  // assign class member universalMat1 to this
  universalMat1 = myGpuMat;
  // TODO shorten to one line: universalMat1.upload(inMat);
#else
  // uMat is cv::Mat
  universalMat1 = inMat;
  // unlike the GPU case above, this Mat lives in the RAM (not a deep copy)
#endif
}


void ExampleClass::operations()
{
  // perform operation on uMat class member
  std::cout << "starting operations" << std::endl;

  // timer
  auto start = std::chrono::high_resolution_clock::now();

  // here is the syntax for cv::Mat and cv::cuda::GpuMat
  // cv::threshold(      src, dst, 128.0, 255.0, CV_THRESH_BINARY);
  // cv::cuda::threshold(src, dst, 128.0, 255.0, CV_THRESH_BINARY);
  // using the universal namespace alias, this command represents both:
  ucv::threshold(universalMat1, universalMat2, 128.0, 255.0, CV_THRESH_BINARY);

  auto finish = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = finish - start;
  std::cout << "raw operation time: " << elapsed.count() << " s (excluding RAM/VRAM overhead)" << std::endl;
  
  std::cout << "operations complete" << std::endl;
}


cv::Mat ExampleClass::get_mat()
{
  // The uMat type is defined in the header depending on the existence of CUDA.
  // Getting the cv::Mat from the uMat class member needs to consider this.

#if CUDA
  // uMat is cv::cuda::GpuMat
  // retrieve a deep copy of universalMat2 of type cv::Mat
  cv::Mat result(universalMat2);
  return result;
#else
  // uMat is cv::Mat
  return universalMat2;
  // unlike the GPU case above, this Mat lives in the RAM (not a deep copy)
#endif
}