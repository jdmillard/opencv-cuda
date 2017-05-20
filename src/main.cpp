#include "example.h"


int main(int argc, char **argv)
{
  // initialize windows
  cv::namedWindow("Original", CV_WINDOW_AUTOSIZE);
  cv::namedWindow("Modified", CV_WINDOW_AUTOSIZE);
  cv::moveWindow("Original", 50, 50);
  cv::moveWindow("Modified", 700, 50);

  // instantiate the class
  ExampleClass example_object;

  // load image
  cv::Mat frame = cv::imread("../images/castle.jpg");
  cv::Mat frame_thresh2;

  // add frame to become data member
  example_object.add_mat(frame);
  example_object.example_operation();
  frame_thresh2 = example_object.get_mat();

  cv::imshow("Original", frame);
  cv::imshow("Modified", frame_thresh2);
  cv::waitKey();
}