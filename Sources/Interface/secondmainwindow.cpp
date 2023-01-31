#include "secondmainwindow.h"
#include "./ui_secondmainwindow.h"

SecondMainWindow::SecondMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::SecondMainWindow)
{
    ui->setupUi(this);
    
    //connect(ui->spinBox, &QSpinBox::textChanged, [this](const QString& val)->void {ui->horizontalSlider->setValue(val.toInt()); });
    //connect(ui->horizontalSlider, &QSlider::valueChanged, [this](const int& val)->void {ui->spinBox->setValue(static_cast<int>)});
    ui->spinBox->setRange(0, 359);
    ui->horizontalSlider->setRange(0, 359);
    ui->spinBox_2->setRange(0, 359);
    ui->horizontalSlider_2->setRange(0, 359);
    ui->spinBox_3->setRange(0, 255);
    ui->horizontalSlider_3->setRange(0, 255);
    ui->spinBox_4->setRange(0, 255);
    ui->horizontalSlider_4->setRange(0, 255);
    ui->spinBox_5->setRange(0, 255);
    ui->horizontalSlider_5->setRange(0, 255);
    ui->spinBox_6->setRange(0, 255);
    ui->horizontalSlider_6->setRange(0, 255);
    
    connect(ui->spinBox, SIGNAL(valueChanged(int)), ui->horizontalSlider, SLOT(setValue(int)));
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->spinBox, SLOT(setValue(int)));

    connect(ui->spinBox_2, SIGNAL(valueChanged(int)), ui->horizontalSlider_2, SLOT(setValue(int)));
    connect(ui->horizontalSlider_2, SIGNAL(valueChanged(int)), ui->spinBox_2, SLOT(setValue(int)));

    connect(ui->spinBox_3, SIGNAL(valueChanged(int)), ui->horizontalSlider_3, SLOT(setValue(int)));
    connect(ui->horizontalSlider_3, SIGNAL(valueChanged(int)), ui->spinBox_3, SLOT(setValue(int)));

    connect(ui->spinBox_4, SIGNAL(valueChanged(int)), ui->horizontalSlider_4, SLOT(setValue(int)));
    connect(ui->horizontalSlider_4, SIGNAL(valueChanged(int)), ui->spinBox_4, SLOT(setValue(int)));

    connect(ui->spinBox_5, SIGNAL(valueChanged(int)), ui->horizontalSlider_5, SLOT(setValue(int)));
    connect(ui->horizontalSlider_5, SIGNAL(valueChanged(int)), ui->spinBox_5, SLOT(setValue(int)));

    connect(ui->spinBox_6, SIGNAL(valueChanged(int)), ui->horizontalSlider_6, SLOT(setValue(int)));
    connect(ui->horizontalSlider_6, SIGNAL(valueChanged(int)), ui->spinBox_6, SLOT(setValue(int)));
}


SecondMainWindow::~SecondMainWindow()
{
    delete ui;
}

void SecondMainWindow::on_pushbutton_clicked()
{
    
}

