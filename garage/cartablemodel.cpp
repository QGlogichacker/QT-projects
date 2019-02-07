#include "cartablemodel.h"
#include <QDebug>

CarTableModel::CarTableModel(QObject *parent)
    : QAbstractTableModel(parent),colnum(3)
{
    QMap <QString, QString> car;
    car["color"] = "实例颜色";
    car["time"] = "实例时间";
    car["wat"] = "随便一个属性";
    car["added"] = "123";
    car["rande"] = "12263";
    carList.append(car);
    carList.append(car);
    carList.append(car);
    carList.append(car);

}

CarTableModel::CarTableModel(QMap<QString, QString> stad,QObject *parent)
    : QAbstractTableModel(parent),colnum(stad.count()),std(stad)
{
    carList.append(std);
}

QVariant CarTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role != Qt::DisplayRole){ //如果不是Display返回空
        return QVariant();
    }
    if (orientation == Qt::Horizontal)
    return currencyAt(section);   //返回列名
    else return section+1;        //返回行号(从1开始)
}


int CarTableModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
    return carList.count();  //返回行数
}

int CarTableModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    // FIXME: Implement me!
    return colnum;            //返回列数
}

QVariant CarTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    // FIXME: Implement me!
    if (role == Qt::TextAlignmentRole) {                 //role == Qt::TextAlignmentRole的时候请求的是对齐方式
        return int(Qt::AlignRight | Qt::AlignVCenter);    //返回水平居中
    } else if (role == Qt::DisplayRole||Qt::EditRole) {  //这个Qt::EditRole不加的时候会导致文本框拿到的是默认值
        int row = index.row();
        QString colname = currencyAt(index.column());
        return (*(carList.begin()+row)).value(colname);
    }
    return QVariant();
}

bool CarTableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (data(index, role) != value) {
        // FIXME: Implement me!
        (*(carList.begin()+index.row())).insert(currencyAt(index.column()), value.toString());
        emit dataChanged(index, index, QVector<int>() << role);
//        QMap<QString,QString> tmp;
//        foreach (tmp, carList) {
//            foreach(QString s,tmp){
//                qDebug() << s;
//            }qDebug() << endl;
//        }
        return true;
    }
    return false;
}

Qt::ItemFlags CarTableModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;
    if(index.row()!=0)
        return QAbstractItemModel::flags(index)|Qt::ItemIsEditable; // FIXME: Implement me!
    else return QAbstractTableModel::flags(index);
}


QString CarTableModel::currencyAt(int offset) const{
    return (carList.first().begin()+offset).key();
}

bool CarTableModel::addItem(QMap<QString,QString>item){
    beginResetModel();
    if(item.count()!=colnum)
        return false;
    carList.append(item);
    endResetModel();
    return true;
}

qint64 CarTableModel::removeItem(int row){
    if(row=0)
        return 0;
    beginResetModel();
    auto s = carList.erase(carList.begin()+row+1);
    endResetModel();
    return (*(s-1))["time"].toLongLong();
}

