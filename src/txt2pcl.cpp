#include <iostream>
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>
#include <pcl/visualization/cloud_viewer.h>


using namespace std;

int main()
{
	typedef struct TXT_Point_XYZ
	{
		double x;
		double y;
		double z;
	}TOPOINT_XYZ;

	//讀取txt文件
	int num_txt;
	FILE *fp_txt;
	TXT_Point_XYZ txt_points;
	vector<TXT_Point_XYZ> my_vTxtPoints;
	fp_txt = fopen("STN7xyzi(re).txt","r");

	if (fp_txt)
	{
		while (fscanf(fp_txt, "%lf %lf %lf", &txt_points.x, &txt_points.y, &txt_points.z) != EOF)
		{
			my_vTxtPoints.push_back(txt_points);
		}
	}
	else
		cout << "讀取txt文件失敗"<<endl;

	num_txt = my_vTxtPoints.size();

	//寫入點雲數據
	pcl::PointCloud<pcl::PointXYZ> ::Ptr cloud(new pcl::PointCloud<pcl::PointXYZ>);
	cloud->width = num_txt;
	cloud->height = 1;
	cloud->is_dense = false;
	cloud->points.resize(cloud->width*cloud->height);
	for (int i = 0; i < cloud->points.size(); ++i)
	{
		cloud->points[i].x = my_vTxtPoints[i].x;
		cloud->points[i].y = my_vTxtPoints[i].y;
		cloud->points[i].z = my_vTxtPoints[i].z;
	}
	pcl::io::savePCDFileASCII("STN7xyzi(re).pcd", *cloud);
	cout<< "從 txt_pcd.txt讀取" << cloud->points.size() << "點寫入txt_pcd.pcd" << endl;
	
    cout << "_________________________________" << endl;
	for (size_t i = 0; i < cloud->points.size(); ++i)
		cout << "    " << cloud->points[i].x
		<< " " << cloud->points[i].y
		<< " " << cloud->points[i].z << endl;

	return 0;
}