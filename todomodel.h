#ifndef TODOMODEL_H
#define TODOMODEL_H

#include <QAbstractTableModel>

class ToDoModel : public QAbstractTableModel
{
public:
    ToDoModel(QObject *parent);

    // QAbstractItemModel interface
public:
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
};

#endif // TODOMODEL_H
