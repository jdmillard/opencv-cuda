#include "example.h"


int main(int argc, char **argv)
{

  // instantiate the wrapper class
  ExampleClass example_object;


#if CUDA
  std::cout << "cuda-only portion accessed" << std::endl;
  // test creation of gpu mat
  // https://stackoverflow.com/questions/19368244/compiling-error-cvgpu/19374970#19374970
  cv::cuda::GpuMat frame2;
  // IDEAS:
  // create a function that can take either Mat of GpuMat
  // preprossor define the namespace for the operations
#endif


  // standard operation
  cv::namedWindow("Original", CV_WINDOW_AUTOSIZE);
  cv::namedWindow("Modified", CV_WINDOW_AUTOSIZE);
  cv::moveWindow("Original", 50, 50);
  cv::moveWindow("Modified", 700, 50);

  cv::Mat frame = cv::imread("../images/castle.jpg");
  cv::Mat frame_gray;
  cv::threshold(frame, frame_gray, 128.0, 255.0, CV_THRESH_BINARY);

  cv::imshow("Original", frame);
  cv::imshow("Modified", frame_gray);
  cv::waitKey();


  std::cout << "terminating main" << std::endl;
}