#ifndef IMAGE_LOADER_H
#define IMAGE_LOADER_H

#include <QObject>
#include <QString>
#include <QPixmap>
#include <QFile>
#include <QDebug>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
class image_loader : public QObject
{
    Q_OBJECT
public:
    explicit image_loader(QObject *parent = nullptr);
    void load(const QString& filename);
    void dirChanged(QString& dir);
    QString get_random_img_path();

signals:
    void send_image(QPixmap);



protected:
    QPixmap cv_to_pixmap(const cv::Mat& mat);

private:
    QString current_dir_;
    QStringList img_files_;
};

#endif // IMAGE_LOADER_H
