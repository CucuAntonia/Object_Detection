#include <QMainWindow>
#include <opencv2/opencv.hpp>
#include "Camera.h"
#include <QFileDialog>
#include "Utils.h"

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

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionOpen_triggered();

    void on_actionSave_triggered();

    void on_actionExit_triggered();

    void DisplayWebcam();

    void on_startweb_button_clicked();

    void on_objdet_btn_clicked();

private:
    Ui::MainWindow *ui;
};

