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
	ui->objdet_btn->setEnabled(false);
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
	ui->objdet_btn->setEnabled(true);
	ui->original_vid->setVisible(true);
	DisplayWebcam();
}

void MainWindow::on_objdet_btn_clicked()
{
	close();
}

void MainWindow::DisplayWebcam()
{
	cv::VideoCapture cap(0);
	if (!cap.isOpened()) {
		std::cout << "Cannot open camera" << std::endl;
		ui->statusbar->showMessage("Error opening webcam", 5000);
	}

    int ok = 1;
	while (true) 
	{
		if (ok==1)
		{
			ui->statusbar->showMessage("Webcam opened", 5000);
			ok = 0;
		}
		cv::Mat frame;
		cap.read(frame);
		QImage qimage_frame;
	    bool conversion_result = Utils::ConvertMat2QImage(frame, qimage_frame);
		ui->original_vid->setPixmap(QPixmap::fromImage(qimage_frame).scaled(ui->original_vid->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
		ui->original_vid->setFixedSize(qimage_frame.size());
		if (cv::waitKey(30) == 27)
			break;
	}
}

    


