#include "benchmark/benchmark_api.h"
#include <set>
#include <vector>
#include <chrono>


#include "example.h"

static void BM_Manual(benchmark::State& state) {

  // load image
  cv::Mat frame = cv::imread("../images/castle.jpg");
  cv::Mat frame_thresh;

  // instantiate the class
  ExampleClass object;
  
  // add frame to become data member
  object.add_mat(frame);

#if CUDA
  state.SetLabel("CUDA GPU");
#else
  state.SetLabel("CPU Only");
#endif


  while(state.KeepRunning()) {

    auto start = std::chrono::high_resolution_clock::now();

    // perform operations on image
    object.operations();

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    state.SetIterationTime(elapsed.count());
  }
  
    // retrieve image
    // frame_thresh = object.get_mat();
}
BENCHMARK(BM_Manual)->UseManualTime()->MinTime(0.000000001)->Unit(benchmark::kMicrosecond);
BENCHMARK(BM_Manual)->UseManualTime();


BENCHMARK_MAIN();