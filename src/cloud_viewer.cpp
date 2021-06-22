#include <iostream>
#include <pcl/io/io.h>
#include <string>
#include <pcl/io/pcd_io.h>
#include <pcl/point_types.h>
#include <pcl/registration/icp.h>
#include <pcl/console/time.h>   // TicToc
#include <pcl/visualization/pcl_visualizer.h>

#include <pcl/visualization/cloud_viewer.h>


using namespace std;


// int main (int argc, char** argv)
// {   

    // //Creates two pcl::PointCloud<pcl::PointXYZ> boost shared pointers and initializes them
    // pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_in  (new pcl::PointCloud<pcl::PointXYZ>);
    // pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_out (new pcl::PointCloud<pcl::PointXYZ>);
	

	// // pcl::io::loadPCDFile("./STN6xyzi(re).pcd", *cloud_in);
	// // pcl::io::savePCDFile("./STN7xyzi(re).pcd", *cloud_out);

    // // Fill in the CloudIn data
    // cloud_in->width    = 5;
    // cloud_in->height   = 1;
    // cloud_in->is_dense = false;
    // cloud_in->points.resize (cloud_in->width * cloud_in->height);
    // for (size_t i = 0; i < cloud_in->points.size (); ++i)
    // {
    //     cloud_in->points[i].x = 1024 * rand () / (RAND_MAX + 1.0f);
    //     cloud_in->points[i].y = 1024 * rand () / (RAND_MAX + 1.0f);
    //     cloud_in->points[i].z = 1024 * rand () / (RAND_MAX + 1.0f);
    // }


    // *cloud_out = *cloud_in;

    // //performs a simple rigid transform on the point cloud
    // for (size_t i = 0; i < cloud_in->points.size (); ++i)
    //     cloud_out->points[i].x = cloud_in->points[i].x + 1.5f;

    // //creates an instance of an IterativeClosestPoint and gives it some useful information
 	// pcl::IterativeClosestPoint<pcl::PointXYZ, pcl::PointXYZ> icp;
    // icp.setInputCloud(cloud_in);
    // icp.setInputTarget(cloud_out);

    // //Creates a pcl::PointCloud<pcl::PointXYZ> to which the IterativeClosestPoint can save the resultant cloud after applying the algorithm
    // pcl::PointCloud<pcl::PointXYZ> Final;

    // //Call the registration algorithm which estimates the transformation and returns the transformed source (input) as output.
    // icp.align(Final);

    // //Return the state of convergence after the last align run. 
    // //If the two PointClouds align correctly then icp.hasConverged() = 1 (true). 
    // std::cout << "has converged: " << icp.hasConverged() <<std::endl;

    // //Obtain the Euclidean fitness score (e.g., sum of squared distances from the source to the target) 
    // std::cout << "score: " <<icp.getFitnessScore() << std::endl; 
    // std::cout << "----------------------------------------------------------"<< std::endl;

    // //Get the final transformation matrix estimated by the registration method. 
    // std::cout << icp.getFinalTransformation() << std::endl;

	




//     return (0);
// }

typedef pcl::PointXYZRGBA PointT;

void viewerOneOff (pcl::visualization::PCLVisualizer& viewer)
{
    // set background to black (R = 0, G = 0, B = 0)
    viewer.setBackgroundColor (255, 255, 255);
}

void viewerPsycho (pcl::visualization::PCLVisualizer& viewer)
{
    // you can add something here, ex:  add text in viewer
}

int main (int argc, char *argv[])
{
    pcl::PointCloud<PointT>::Ptr cloud (new pcl::PointCloud<PointT>);

    // Load .pcd file from argv[1]
    int ret = pcl::io::loadPCDFile (argv[1], *cloud);
    if (ret < 0) {
        PCL_ERROR("Couldn't read file %s\n", argv[1]);
        return -1;
    }

    pcl::visualization::CloudViewer viewer("Cloud Viewer");

    // blocks until the cloud is actually rendered
    viewer.showCloud(cloud);

    // use the following functions to get access to the underlying more advanced/powerful
    // PCLVisualizer

    // This will only get called once
    viewer.runOnVisualizationThreadOnce (viewerOneOff);

    // This will get called once per visualization iteration
    viewer.runOnVisualizationThread (viewerPsycho);
    while (!viewer.wasStopped ()) {
        // you can also do cool processing here
        // FIXME: Note that this is running in a separate thread from viewerPsycho
        // and you should guard against race conditions yourself...
    }

    return 0;
}