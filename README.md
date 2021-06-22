# ICP Registration

## Makefile
    cd build
    cmake ..

## txt to Pcd
    **put your txt to the file**
    cd build
    ./txt2pcl ../{therfile}.txt

## run icp
    cd build
    ./ icp ../STN6xyzi(re).pcd STN7xyzi(re).pcd

## run cloud viewer
    cd build
    ./ cloud_viewer ../1.pcd 