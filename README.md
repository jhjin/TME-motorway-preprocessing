# TME Motorway dataset preprocessing

This repository contains a preprocessing script that converts raw images from TME Motor dataset to those in RGB format.
The dataset can be found in [here](http://cmp.felk.cvut.cz/data/motorway/).
OpenCV library is reqruied to run this script.

## Compile

```sh
g++ preprocess.cpp -o preprocess -I/usr/local/include/opencv2 -L/usr/local/lib -lm -lopencv_core -lopencv_highgui -lopencv_imgproc
```

## Run

```sh
./preprocess 1 left   # or right
```
