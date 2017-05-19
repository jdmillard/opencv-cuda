#include "example.h"


int main(int argc, char **argv)
{

  // instantiate the wrapper class
  ExampleClass example_object;


  cv::Mat frame = cv::imread("../images/castle.jpg");

  cv::imshow("Display", frame);
  cv::waitKey();


  std::cout << "terminating main" << std::endl;
}