#ifndef CARTABLEMODEL_H
#define CARTABLEMODEL_H

#include <QAbstractTableModel>
#include <QLinkedList>

class CarTableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit CarTableModel(QObject *parent = nullptr);
    explicit CarTableModel(QMap<QString,QString> std,QObject *parent = nullptr);
    // Header:
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) override;

    Qt::ItemFlags flags(const QModelIndex& index) const override;
    // operateItem
    bool addItem(QMap<QString,QString>item);
    qint64 removeItem(int row);
    QMap<QString,QString> std;
    QString currencyAt(int offset) const;
    QLinkedList<QMap<QString, QString> > carList;
    int colnum;

};

#endif // CARTABLEMODEL_H
