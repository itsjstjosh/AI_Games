#!/bin/bash

cp $OPENCV_ROOT/../sources/samples/data/blox.jpg .
cp $OPENCV_ROOT/../sources/samples/data/lena.jpg .
convert blox.jpg blox.png
convert lena.jpg lena.png
convert blox.png -gravity Center -crop 50x50%+0+0 blox_crop.png
convert lena.png -gravity Center -crop 50x50%+0+0 lena_crop.png
convert lena_crop.png             -rotate 180 lena_crop_180.png
