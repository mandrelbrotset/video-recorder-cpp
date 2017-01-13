//Sheriff Olaoye
//Program that reads from the webcam and writes it to a file Video.avi
//Open CV version 3.1.0
//Date completed : January 10:37PM , 2017
//Help from Kyle Hounslows youtube video
//              **      ****    ******  ***     **        ****     **       **
//           **    **   **  **  **      ** **   **      ***    **   **     **
//          **      **  ****    ******  **  **  **     ***           **   **
//           **    **   **      **      **   ** **      ***    **     ** **
//              **      **      ******  **    ****        ****         ***
//

#include <opencv2\highgui\highgui.hpp>
#include <opencv2\videoio\videoio.hpp>
#include <iostream>
#include <Windows.h>       //for sleep function on windows machines

using namespace cv;
using namespace std;

int main()
{
	//Create matrix to store image
	Mat frame;
	Mat flippedFrame;

	//initialize capture
	VideoCapture cap(0);
	cap.open(0);

	VideoWriter writer;

	if (cap.isOpened())
	{
		cout << "\a[INFO] WEBCAM SUCCESS!!!" << endl;
	}
	else
	{
		cout << "\a[INFO] INITIALIZING FAILED" << endl;
		return -1;
	}

	//Create window to show image
	namedWindow("window", CV_WINDOW_AUTOSIZE);

	/*arguments for the video writer*/
	// filename string
	string filename = "C:\Video.avi";

	//fourcc integer
	int fourcc = CV_FOURCC('D', 'I', 'V', '3');

	//add frames per sec double
	double FPS = 20;

	//frame size
	cv::Size imageSize(cap.get(CV_CAP_PROP_FRAME_WIDTH), cap.get(CV_CAP_PROP_FRAME_HEIGHT));

	//boolean
	bool isColor = true;

	//initialize the videowriter object
	writer = VideoWriter(filename, fourcc, FPS, imageSize, isColor);

	if (!writer.isOpened())
	{
		cout << "\a[INFO] ERROR WRITING TO FILE" << endl;

		return -1;
	}

	cout << "\a[INFO] PRESS \'ESC\' TO EXIT" << endl;

	while (1)
	{
		//copy webcam stream to image
		cap >> frame;
		
		//flip the streamed frame 
		flip(frame, flippedFrame, 1);

		//write flipped frame to video file
		writer.write(flippedFrame);

		//print image to screen
		imshow("window", flippedFrame);

		//delay 33ms
		int key = cvWaitKey(33);
		
		//exit if esc key is pressed
		if (key == 27) {
			cout << "\a" << endl;
			for(int i=3; i>0; i--){
				cout << "[INFO] EXITING IN " <<i<< " SECOND(S)..." <<endl;
				Sleep(500);
			}
			break;
		}
	}

	return 0;
}
