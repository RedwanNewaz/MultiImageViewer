#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("ImageViewer 2.0");
    this->setFixedSize(QSize(1480, 1092));
    img_loader_ = std::unique_ptr<image_loader>(new image_loader);
    connect(img_loader_.get(), SIGNAL(send_image(QPixmap)), ui->window1, SLOT(setPixmap(QPixmap)));

    img_loader_2_ = std::unique_ptr<image_loader>(new image_loader);
    connect(img_loader_2_.get(), SIGNAL(send_image(QPixmap)), ui->window1_2, SLOT(setPixmap(QPixmap)));

    img_loader_3_ = std::unique_ptr<image_loader>(new image_loader);
    connect(img_loader_3_.get(), SIGNAL(send_image(QPixmap)), ui->window1_3, SLOT(setPixmap(QPixmap)));

    img_loader_4_ = std::unique_ptr<image_loader>(new image_loader);
    connect(img_loader_4_.get(), SIGNAL(send_image(QPixmap)), ui->window1_4, SLOT(setPixmap(QPixmap)));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonShow_clicked()
{
//    QString path = "/home/redwan/Pictures/dummy.jpg";
    auto path = img_loader_->get_random_img_path();
    if(path.length() < 1) return;
    qDebug() << path;
    img_loader_->load(path);
}

void MainWindow::on_dirTxtBox_textChanged()
{
    QString dirName = ui->dirTxtBox->toPlainText();
    img_loader_->dirChanged(dirName);
    qDebug() << dirName;
}

void MainWindow::on_dirTxtBox_2_textChanged()
{
    QString dirName = ui->dirTxtBox_2->toPlainText();
    img_loader_2_->dirChanged(dirName);
    qDebug() << dirName;
}

void MainWindow::on_pushButtonShow_2_clicked()
{
    auto path = img_loader_2_->get_random_img_path();
    if(path.length() < 1) return;
    qDebug() << path;
    img_loader_2_->load(path);
}

void MainWindow::on_pushButtonShowAll_clicked()
{

    on_pushButtonShow_clicked();
    on_pushButtonShow_2_clicked();
    on_pushButtonShow_3_clicked();
    on_pushButtonShow_4_clicked();
}

void MainWindow::on_dirTxtBox_4_textChanged()
{
    QString dirName = ui->dirTxtBox_4->toPlainText();
    img_loader_4_->dirChanged(dirName);
    qDebug() << dirName;
}

void MainWindow::on_pushButtonShow_4_clicked()
{
    auto path = img_loader_4_->get_random_img_path();
    if(path.length() < 1) return;
    qDebug() << path;
    img_loader_4_->load(path);
}



void MainWindow::on_dirTxtBox_3_textChanged()
{
    QString dirName = ui->dirTxtBox_3->toPlainText();
    img_loader_3_->dirChanged(dirName);
    qDebug() << dirName;
}

void MainWindow::on_pushButtonShow_3_clicked()
{
    auto path = img_loader_3_->get_random_img_path();
    if(path.length() < 1) return;
    qDebug() << path;
    img_loader_3_->load(path);
}
