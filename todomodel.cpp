#include "todomodel.h"

ToDoModel::ToDoModel(QObject *parent)
    :QAbstractTableModel (parent)
{

}

int ToDoModel::rowCount(const QModelIndex &parent) const
{
    return 2;
}

int ToDoModel::columnCount(const QModelIndex &parent) const
{
    return 3;
}

QVariant ToDoModel::data(const QModelIndex &index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        return QString ("Row%1, Column%2")
                .arg(index.row())
                .arg(index.column());
    }

    return QVariant();
}
