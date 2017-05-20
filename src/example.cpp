#include "example.h"

//using namespace std;

ExampleClass::ExampleClass()
{
  std::cout << "instantiated" << std::endl;

}


void ExampleClass::add_mat(cv::Mat inMat)
{



#if CUDA

  std::cout << "assigning to GpuMat" << std::endl;
  cv::cuda::GpuMat onGpuMat;
  onGpuMat.upload(inMat);
  // onGpuMat is now an OpenCV Mat on the VRAM
  // assign class member universalMat to this
  universalMat = onGpuMat;

#else

  std::cout << "assigning to Mat" << std::endl;
  universalMat = inMat;

#endif


}