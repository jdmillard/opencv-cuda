## Automatic CUDA Operations in OpenCV

This `OpenCV` project automatically detects if `CUDA` is installed, then compiles accordingly. Preprocessor directives are used to govern compilation such that the `cv::cuda::` namespace is used if possible. The result is a project that compiles, builds, and runs flawlessly with or without an available `CUDA` gpu.

### Configuring CUDA and OpenCV
You can **skip** this section if
* You already have the `CUDA` library installed and `CUDA-enabled` `OpenCV` library installed (the latter needs to be compiled by your machine from source) **OR**
* Your machine doesn't have a `CUDA` GPU and will only be running the software on CPU. (assuming you have ROS installed, providing the needed OpenCV library)

Otherwise, the following guide will install the required libraries.

1. Install `CUDA`. [Download](https://developer.nvidia.com/cuda-downloads) the appropriate `.deb` file for your hardware and distribution. Follow the installation instructions for your selection.
1. Add the following to your `.bashrc` (and remember to source it afterwards):
```bash
# CUDA Toolkit
export PATH="/usr/local/cuda-8.0/bin:$PATH"
export LD_LIBRARY_PATH="/usr/local/cuda-8.0/lib64:$LD_LIBRARY_PATH"
```
1. Download the `OpenCV` release and "contrib" source (below uses 3.2.0). This can be done anywhere; many people use the Downloads folder.
```bash
wget -O opencv.zip https://github.com/opencv/opencv/archive/3.2.0.zip
wget -O opencv_contrib.zip https://github.com/opencv/opencv_contrib/archive/3.2.0.zip
unzip opencv.zip
unzip opencv_contrib.zip
```
1. Configure CMake to enable `CUDA`. (adjust the last line to match the location of the previous step):
```bash
cd opencv-3.2.0
mkdir build
cd build
cmake -DCMAKE_INSTALL_PREFIX=/usr/local \
         -DCMAKE_BUILD_TYPE=RELEASE \
         -DWITH_CUDA=ON \
         -DENABLE_FAST_MATH=1 \
         -DCUDA_FAST_MATH=1 \
         -DWITH_CUBLAS=1 \
         -DINSTALL_PYTHON_EXAMPLES=ON \
         -DWITH_OPENMP=ON \
         -DWITH_NVCUVID=ON \
         -DOPENCV_EXTRA_MODULES_PATH=~/Downloads/opencv_contrib-3.2.0/modules ..
```
1. Build and install. This can take nearly an hour, so enter the 3 the commands together then find something else to do:
```bash
make -j8
sudo make install
sudo ldconfig  # update shared library cache
```

### Run
If `CUDA` is detected, the default `OpenCV` installation path will be used. There is no need to set an environment variable to specify the path unless you've installed it in a non-default location (see the next section for more details).
```bash
# cmake will echo helpful information about which libraries are being used
cd build/
cmake ..
make
./opencv-cuda
```

### Some Specifics

If `CUDA` is detected, it is assumed that `OpenCV` was compiled from source using the default library installation directory, `/usr/local/share/OpenCV/`. If your library was installed elsewhere, simply create the following environment variable before running `cmake` as such:
```bash
# specify non-default library installation directory
# (not required for standard installations)
export OpenCV_DIR=/your/custom/path/OpenCV/
```

At some point, it may be beneficial for a `CUDA-enabled` machine to ignore `CUDA` in order to compile and run using only the CPU for the sake of benchmarking. Alternatively, one might want to make sure that recent changes don't break the application for the CPU-only case. This is easily done by creating the appropriate environment variable:
```bash
# tell cmake to not use CUDA libraries
# (only for testing or benchmarking)
export IGNORE_CUDA=1
```

This project has been confirmed to work with `CUDA 8.0` and `OpenCV 3.2.0`.

### Resource Links
* [OpenCV 3.0+ Includes](https://stackoverflow.com/questions/19368244/compiling-error-cvgpu/19374970#19374970)