/*
  This is an example code of using openCV on ROS.
  This package will display the designated picture file once it runs.

  This ROS Package is piled up on the termios code usage explained here: https://github.com/terrychenism/OpenCV_Coding_Expt/blob/master/mouse_event.cpp

  created by Ahn, Jeeho
  2018.04.21
*/

#include <ros/ros.h>
#include <ros/package.h>

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace cv;
using namespace std;

Mat srcImage;
void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
  if (event == EVENT_LBUTTONDOWN)
  {
    cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
  }
  else if (event == EVENT_RBUTTONDOWN)
  {
    cout << "Right button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
  }
  else if (event == EVENT_MBUTTONDOWN)
  {
    cout << "Middle button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;

  }

  else if (event == EVENT_MOUSEMOVE)
  {
    cout << "Mouse move over the window - position (" << x << ", " << y << ")" << endl;
  }

}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "ros_opencv");
  //ros::NodeHandle nh;

     // ros::spinOnce();

  srcImage = imread(ros::package::getPath("ros_opencv") + "/travel_pic.png", IMREAD_COLOR);

  if (srcImage.empty())
  {
      std::cout << "image empty" << std::endl;
    return -1;
  }

  std::cout << "srcImage.type= " << srcImage.type() << std::endl;
  std::cout << "size = " << srcImage.size() << std::endl;

  namedWindow("picture display", 1);
  setMouseCallback("picture display", CallBackFunc, NULL);
  imshow("picture display", srcImage);
  waitKey();

  return 0;
  }





