#include "image_loader.h"
#include <QDir>

image_loader::image_loader(QObject *parent) : QObject(parent)
{

}


void image_loader::load(const QString& filename)
{
    auto img = cv::imread(filename.toStdString());
    cv::resize(img, img, cv::Size(640, 480),cv::INTER_LINEAR);
    QPixmap main_img = cv_to_pixmap(img);
    emit send_image(main_img);
}

void image_loader::dirChanged(QString &dir)
{
    QDir current(dir);
    img_files_ = current.entryList(QStringList() << "*.jpg" << "*.png", QDir::Files);
    current_dir_ = dir;
}

QString image_loader::get_random_img_path()
{
    if (img_files_.size() < 1) return "";

    auto fileName = img_files_.front();
    img_files_.pop_front();
    return current_dir_ + "/" + fileName;
}


QPixmap image_loader::cv_to_pixmap(const cv::Mat& mat)
{
    QPixmap pixmap;
        if(mat.type()==CV_8UC1)
        {
            // Set the color table (used to translate colour indexes to qRgb values)
            QVector<QRgb> colorTable;
            for (int i=0; i<256; i++)
                colorTable.push_back(qRgb(i,i,i));
            // Copy input Mat
            const uchar *qImageBuffer = (const uchar*)mat.data;
            // Create QImage with same dimensions as input Mat
            QImage img(qImageBuffer, mat.cols, mat.rows, mat.step, QImage::Format_Indexed8);
            img.setColorTable(colorTable);
            pixmap = QPixmap::fromImage(img);
        }
        // 8-bits unsigned, NO. OF CHANNELS=3
        else if(mat.type()==CV_8UC3)
        {
            // Copy input Mat
            const uchar *qImageBuffer = (const uchar*)mat.data;
            // Create QImage with same dimensions as input Mat
            QImage img(qImageBuffer, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
            pixmap = QPixmap::fromImage(img.rgbSwapped());
        }

        return pixmap;
}
