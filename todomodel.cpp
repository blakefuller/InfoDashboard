#include "todomodel.h"
#include <QFile>
#include <iostream>
#include <QMessageBox>
#include <QTextStream>

ToDoModel::ToDoModel(QObject *parent)
    :QAbstractTableModel (parent)
{

}

int ToDoModel::rowCount(const QModelIndex &parent) const
{
    return tasks.size();
}

int ToDoModel::columnCount(const QModelIndex &parent) const
{
    return 2;
}

QVariant ToDoModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        // display into tableview
        switch(index.column())
        {
            case 0: // tasks
                return tasks.at(index.row());
            case 1: //due dates
                return dueDates.at(index.row());
        }
    }

    return QVariant();
}

void ToDoModel::openFile(QString filePath)
{
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0,"error", file.errorString());
        return;
    }

    QTextStream in(&file);

    tasks.clear();
    dueDates.clear();

    while(!in.atEnd())
    {
        QString line = in.readLine();
        QStringList fields = line.split(",");

        tasks.push_back(fields[0]);
        dueDates.push_back(fields[1]);

    }

    file.close();

    emit layoutChanged();
}
