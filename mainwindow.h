#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <memory>
#include "image_loader.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButtonShow_clicked();

    void on_dirTxtBox_textChanged();

    void on_dirTxtBox_2_textChanged();

    void on_pushButtonShow_2_clicked();

    void on_pushButtonShowAll_clicked();

    void on_dirTxtBox_4_textChanged();

    void on_pushButtonShow_4_clicked();



    void on_dirTxtBox_3_textChanged();

    void on_pushButtonShow_3_clicked();

private:
    Ui::MainWindow *ui;
    std::unique_ptr<image_loader> img_loader_, img_loader_2_;
    std::unique_ptr<image_loader> img_loader_3_, img_loader_4_;
};
#endif // MAINWINDOW_H
