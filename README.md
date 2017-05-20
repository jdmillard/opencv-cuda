## OpenCV Testing

This `OpenCV` project automatically detects if `CUDA` is installed, then compiles accordingly. Preprocessor directives are used to govern compilation such that the `cv::cuda::` namespace is used if possible. The result is a project that compiles, builds, and runs flawlessly with or without an available `CUDA` gpu.

### Some Specifics

If `CUDA` is detected, it is assumed that `OpenCV` was compiled from source using the default library installation directory, `/usr/local/share/OpenCV/`. If your library was installed elsewhere, simply create the following environment variable before running `cmake` as such:
```bash
export OpenCV_DIR=/custom/path/OpenCV/
```

### Run Commands
```bash
TODO
TOTO
cd build/
cmake ..
make
./opencv-cuda
```

### Resource Links
* [OpenCV 3.0+ Includes](https://stackoverflow.com/questions/19368244/compiling-error-cvgpu/19374970#19374970)