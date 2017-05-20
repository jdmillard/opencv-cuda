#include "example.h"


int main(int argc, char **argv)
{
  // initialize windows
  cv::namedWindow("Original", CV_WINDOW_AUTOSIZE);
  cv::namedWindow("Modified", CV_WINDOW_AUTOSIZE);
  cv::moveWindow("Original", 50, 50);
  cv::moveWindow("Modified", 700, 50);

  // instantiate the class
  ExampleClass object;

  // load image
  cv::Mat frame = cv::imread("../images/castle.jpg");
  cv::Mat frame_thresh;

  // add frame to become data member
  object.add_mat(frame);

  // perform operations on image
  auto start = std::chrono::high_resolution_clock::now();
  object.operations();
  auto finish = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = finish - start;
  std::cout << "raw operation time: " << elapsed.count() << " s (excluding RAM/VRAM overhead)" << std::endl;


  // retrieve image
  frame_thresh = object.get_mat();

  cv::imshow("Original", frame);
  cv::imshow("Modified", frame_thresh);
  cv::waitKey();
}