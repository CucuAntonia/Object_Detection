#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include "Camera.h"
#include <QFileDialog>
#include "Utils.h"
#include <qtimer.h>
#include "secondmainwindow.h"



#ifdef UI_EXPORT
#define UI_API __declspec(dllexport)
#else
#define UI_API __declspec(dllimport)
#endif

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class UI_API MainWindow : public QMainWindow
{
    Q_OBJECT
        QTimer _timer;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void processFrameAndUpdateGUI();

private slots:
    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionExit_triggered();

    void on_startweb_button_clicked();

    void on_objdet_btn_clicked();

    void on_actionOpen_Help_Page_triggered();

    
    

private:
    Ui::MainWindow *ui;
    cv::Mat m_frame; 
    cv::VideoCapture m_capWebcam;
    QImage qimage_frame;
    QTimer* timer;
    SecondMainWindow* secondMW;
};

