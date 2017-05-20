#include <iostream>
#include <math.h>
#include <opencv2/opencv.hpp>
// not sure if these two are needed:
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"

// cuda-only includes
#if CUDA
//#include <opencv2/gpu/gpu.hpp> // pre-3.0 method
#include "opencv2/cudaarithm.hpp" // this one needs preprocessor 'if'
#endif


class ExampleClass
{
public:
  ExampleClass();
private:
  int x_val_;
};