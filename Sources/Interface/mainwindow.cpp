#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPixmap>
#include <QImageReader>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->original_vid->setVisible(false);
	
	
	
}

MainWindow::~MainWindow()
{
    delete ui;
    
}


void MainWindow::on_actionOpen_triggered()
{
    close();
}


void MainWindow::on_actionSave_triggered()
{
    close();
    
}


void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_startweb_button_clicked()
{
	
	ui->original_vid->setVisible(true);
	DisplayWebcam();
}

void MainWindow::DisplayWebcam()
{
	cv::VideoCapture cap(0);
	if (!cap.isOpened()) {
		std::cout << "Cannot open camera" << std::endl;
		
	}

	while (true) {
		cv::Mat frame(1000, 600, CV_8UC3);
		cap.read(frame);
		QImage qimage_frame;
		/*QImage img = QImage((const unsigned char*)(frame.data),
			frame.cols, frame.rows,
			QImage::Format_RGB888);
		ui->originalvid->setPixmap(QPixmap::fromImage(img));*/
		
		
		bool conversion_result = Utils::ConvertMat2QImage(frame, qimage_frame);
		ui->original_vid->setPixmap(QPixmap::fromImage(qimage_frame));
		//ui->originalvid->resize(ui->originalvid->pixmap()->size());
		ui->original_vid->setFixedSize(1000, 600);
		if (cv::waitKey(30) == 27)
			break;
		///cv::waitKey(50);
		
	}
	
}

    


