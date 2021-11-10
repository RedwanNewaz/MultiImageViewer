#include "backend.h"
#include <QDebug>
BackEnd::BackEnd(QObject *parent) : QObject(parent)
{
    QString dir_path = "";
    for(int i = 0; i < WINDOW_SIZE; ++i)
    {
        counter_[i] = 0;
        load_image_names(dir_path, img_files_[i]);
        file_size_[i] = img_files_[i].size();
        //dirname contains all current director;
        dir_names_[i] = "";
    }
}

void BackEnd::setSideArrow(const QString &value)
{

    QStringList parser = value.split(",");
    bool clicked = parser[2].toInt();

    if(!clicked)return;

    int incr = parser[1].toInt()? 1 : -1;
    int index = parser[0].toInt();

    qDebug() << index << incr;

    if(incr < 0 && counter_[index] <= 0)
        return;

    if(incr > 0 && counter_[index] >= file_size_[index] - 1)
        return;

    counter_[index] += incr;

    switch (index) {
        case 0: winAimgName();break;
        case 1: winBimgName();break;
        case 2: winCimgName();break;
        case 3: winDimgName();break;
    }

}

QString BackEnd::winAimgName()
{
    int index = 0;
    QString nextFile = img_files_[index][counter_[index]];
    qDebug()<< nextFile;
    emit winAimgNameChanged(nextFile);
    return nextFile;
}

QString BackEnd::winBimgName()
{
    int index = 1;
    QString nextFile = img_files_[index][counter_[index]];
    qDebug()<< nextFile;
    emit winBimgNameChanged(nextFile);
    return nextFile;
}

QString BackEnd::winCimgName()
{
    int index = 2;
    QString nextFile = img_files_[index][counter_[index]];
    qDebug()<< nextFile;
    emit winCimgNameChanged(nextFile);
    return nextFile;
}

QString BackEnd::winDimgName()
{
    int index = 3;
    QString nextFile = img_files_[index][counter_[index]];
    qDebug()<< nextFile;
    emit winDimgNameChanged(nextFile);
    return nextFile;
}

void BackEnd::setMenuNew(const QString &dirname)
{
    QStringList parser = dirname.split(",");
    QString dir_path = parser[1];
    int i = parser[0].toInt();
    load_image_names(dir_path, img_files_[i]);
    dir_names_[i] = dir_path;
    file_size_[i] = img_files_[i].size();
    qDebug() << i << file_size_[i];

    switch (i) {
        case 0: winAimgName();break;
        case 1: winBimgName();break;
        case 2: winCimgName();break;
        case 3: winDimgName();break;
    }
}

void BackEnd::setMenuSave(const QString &dirname)
{
    QString fileName = "setting.txt";
    QFile file(fileName);
    if (dirname.compare("save") == 0)
    {
        qDebug() << "save " << dirname;

        if (!file.open(QIODevice::WriteOnly)) {
            qDebug() << "cannot save";
            return;
        }
        QTextStream out(&file);
        for(int i = 0; i < WINDOW_SIZE; ++i)
        {
             out << dir_names_[i] << "\n";
        }

    }
    else if (dirname.compare("open") == 0)
    {
        if (!file.open(QIODevice::ReadOnly)) {
            qDebug() << "cannot open";
            return;
        }

        QTextStream in(&file);

        for(int i = 0; i < WINDOW_SIZE; ++i)
        {
           QString dir_path = in.readLine();

           load_image_names(dir_path, img_files_[i]);
           dir_names_[i] = dir_path;
           file_size_[i] = img_files_[i].size();
           qDebug() << i << file_size_[i];

           switch (i) {
               case 0: winAimgName();break;
               case 1: winBimgName();break;
               case 2: winCimgName();break;
               case 3: winDimgName();break;
           }
        }

    }

     file.close();



}

void BackEnd::load_image_names(const QString &dir, QStringList &container)
{
    if(dir.length() < 1) {
        container << dir;
        return;
    }

    QDir current(dir);
    QStringList temp = current.entryList(QStringList() << "*.jpg" << "*.png", QDir::Files);
    // populate container
    container.clear();
    for(int i = 0; i < temp.size(); ++i)
    {
        QString path = "file:/" + current.absolutePath() + "/" + temp[i];
        container << path;
    }

}
