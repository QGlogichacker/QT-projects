#include "currencymodel.h"

CurrencyModel::CurrencyModel(QObject *parent):QAbstractTableModel(parent)
{
}

int CurrencyModel::rowCount(const QModelIndex &parent) const{
    return currencyMap.count();
}

int CurrencyModel::columnCount(const QModelIndex &parent) const{
    return currencyMap.count();
}

QVariant CurrencyModel::headerData(int section, Qt::Orientation orientation, int role) const{
    if(role != Qt::DisplayRole){
        return QVariant();
    }
    return currencyAt(section);
}

QString CurrencyModel::currencyAt(int offset) const{
    return (currencyMap.begin()+offset).key();
}

void CurrencyModel::setCurrencyMap(const QMap<QString, double> map){
    beginResetModel();
    currencyMap = map;
    endResetModel();
}

QVariant CurrencyModel::data(const QModelIndex &index, int role) const{//数据的INDEX，数据扮演的角色
    if(!index.isValid()){
        return QVariant();     //非法排除数据
    }
    if(role == Qt::TextAlignmentRole){               //如果是文本的对齐方式
        return int(Qt::AlignRight |Qt::AlignVCenter);
    }else if(role == Qt::DisplayRole||role == Qt::EditRole){               //如果是展示的话
        QString rowCurrency = currencyAt(index.row());
        QString columnCurrency = currencyAt(index.column());
        if(currencyMap.value(rowCurrency)==0.0){
            return "####";
        }
        double amount = currencyMap.value(columnCurrency)/currencyMap.value(rowCurrency);

        return QString("%1").arg(amount, 0, 'f', 4);
    }
    return QVariant();
}

Qt::ItemFlags CurrencyModel::flags(const QModelIndex &index) const{
    Qt::ItemFlags flags = QAbstractItemModel::flags(index);
    if(index.row()!=index.column()){
        flags |= Qt::ItemIsEditable;
    }
    return flags;
}

bool CurrencyModel::setData(const QModelIndex &index, const QVariant &value, int role){
    if(index.isValid()&&index.row()!=index.column()&&role==Qt::EditRole){
        QString colCurr = headerData(index.column(), Qt::Horizontal, Qt::DisplayRole).toString();
        QString rowCurr = headerData(index.row(), Qt::Vertical, Qt::DisplayRole).toString();
        currencyMap.insert(colCurr, value.toDouble() * currencyMap.value(rowCurr));
        emit dataChanged(index,index);
        return true;
    }
    return false;
}
