#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QString>
#include <qqml.h>
#include <iostream>
#include <array>
#include <QDir>
#include <QDataStream>

#define WINDOW_SIZE (4)

class BackEnd : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString SideArrow  WRITE setSideArrow )
    Q_PROPERTY(QString winAimgName READ winAimgName NOTIFY winAimgNameChanged)
    Q_PROPERTY(QString winBimgName READ winBimgName NOTIFY winBimgNameChanged)
    Q_PROPERTY(QString winCimgName READ winCimgName NOTIFY winCimgNameChanged)
    Q_PROPERTY(QString winDimgName READ winDimgName NOTIFY winDimgNameChanged)

    Q_PROPERTY(QString MenuNew   WRITE setMenuNew )
    Q_PROPERTY(QString MenuSave   WRITE setMenuSave)



public:
    explicit BackEnd(QObject *parent = nullptr);
    void setSideArrow(const QString &value);
    QString winAimgName();
    QString winBimgName();
    QString winCimgName();
    QString winDimgName();

    void setMenuNew(const QString& dirname);
    void setMenuSave(const QString& dirname);


signals:
    void winAimgNameChanged(QString);
    void winBimgNameChanged(QString);
    void winCimgNameChanged(QString);
    void winDimgNameChanged(QString);

private:
    std::array<int, WINDOW_SIZE> counter_, file_size_;
    std::array<QStringList, WINDOW_SIZE> img_files_;
    std::array<QString, WINDOW_SIZE> dir_names_;

protected:
    void load_image_names(const QString& dir, QStringList& container);

};

#endif // BACKEND_H
