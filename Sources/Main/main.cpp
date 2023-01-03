#include <opencv2/opencv.hpp>
#include <QApplication>
#include "../Interface/mainwindow.h"

using namespace cv;
using namespace std;

int main(int argc, char* argv[]) {


	QApplication a(argc, argv);
	MainWindow w;
	w.show();
	return a.exec();
	
}

/*VideoCapture cap(0);
	if (!cap.isOpened()) {
		cout << "Cannot open camera" << endl;
		return -1;
	}
	while(true) {
		Mat frame;
		cap.read(frame);
		imshow("Camera", frame);
		if (waitKey(30) == 'c')
		{
			Mat frame2;
			frame2 = frame.clone();
			imshow("Webcame Frame", frame2);
		}

		if (waitKey(30) == 27)
			break;


	}*/