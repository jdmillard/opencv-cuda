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
  cv::namedWindow("Modified2", CV_WINDOW_AUTOSIZE);
  cv::moveWindow("Original", 50, 50);
  cv::moveWindow("Modified", 700, 50);
  cv::moveWindow("Modified2", 50, 500);

  cv::Mat frame = cv::imread("../images/castle.jpg");
  cv::Mat frame_thresh;
  cv::threshold(frame, frame_thresh, 128.0, 255.0, CV_THRESH_BINARY);

  example_object.add_mat(frame);
  example_object.example_operation();
  cv::Mat frame_thresh2 = example_object.get_mat();

  cv::imshow("Original", frame);
  cv::imshow("Modified", frame_thresh);
  cv::imshow("Modified2", frame_thresh2);
  cv::waitKey();


  std::cout << "terminating main" << std::endl;
}