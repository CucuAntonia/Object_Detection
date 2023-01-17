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
	ui->startweb_button->setFixedHeight(40);
	ui->objdet_btn->setFixedHeight(40);
	
	
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::processFrameAndUpdateGUI()
{
	OpenCamera(m_capWebcam, m_frame);

	if (m_frame.empty() == true)
		return;
	bool conversion_result = Utils::ConvertMat2QImage(m_frame, qimage_frame);
	ui->original_vid->setPixmap(QPixmap::fromImage(qimage_frame).scaled(ui->original_vid->size(), Qt::KeepAspectRatio, Qt::SmoothTransformation));
	ui->original_vid->setFixedSize(qimage_frame.size());
	
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

void MainWindow::on_actionOpen_Help_Page_triggered()
{
	QMessageBox::information(this, "Information", "This application was designed by Cucu Ioana-Antonia. Work in progress!");
}

void MainWindow::on_startweb_button_clicked()
{
	ui->objdet_btn->setEnabled(true);
	ui->original_vid->setVisible(true);

	if (CheckIfCameraCanBeOpen(m_capWebcam) == true)
	{
		ui->statusbar->showMessage("Webcam opened", 5000);
		timer = new QTimer(this);
		connect(timer, SIGNAL(timeout()), this, SLOT(processFrameAndUpdateGUI()));
		timer->start(20);
	}
	else
		ui->statusbar->showMessage("Error opening webcam", 5000);
}


void MainWindow::on_objdet_btn_clicked()
{
	close();
}


	

    


