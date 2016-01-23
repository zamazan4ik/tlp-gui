#include <QComboBox>
#include <QCheckBox>
#include "QComboBoxItemDelegate.h"
#include "Contstants.h"
#include "TableModel.h"

QComboBoxItemDelegate::QComboBoxItemDelegate(QObject* parent) : QStyledItemDelegate(parent)
{
}

QWidget* QComboBoxItemDelegate::createEditor(QWidget *parent,
                            const QStyleOptionViewItem &option,
                            const QModelIndex &index) const
{
    if (index.column() == COL_VALUE)
    {
        const TableModel* ptr = qobject_cast<const TableModel*>(index.model());
        if(ptr->data1(index, Qt::DisplayRole).getTypeWidget() == Property::QComboBox)
        {
            QStringList values = ptr->data1(index,Qt::DisplayRole).getVariants();
            QComboBox* comboBox = new QComboBox(parent);
            comboBox->addItems(values);
            comboBox->setCurrentIndex(1);
            return comboBox;
        }
        else if(ptr->data1(index, Qt::DisplayRole).getTypeWidget() == Property::QCheckBox)
        {
            QCheckBox* checkbox = new QCheckBox(parent);
            checkbox->setChecked(ptr->data1(index, Qt::DisplayRole).isActive());
            return checkbox;
        }
        else
        {
            qDebug() << "QLineEdit\n";
            QLineEdit* line = new QLineEdit(parent);
            line->setText(ptr->data1(index, Qt::DisplayRole).getDefVal());
            return line;
        }
    }
    else
    {
        return QStyledItemDelegate::createEditor(parent, option, index);
    }
}

void QComboBoxItemDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                         const QModelIndex &index) const
{
    if(index.column() == COL_VALUE)
    {
        const TableModel* ptr = qobject_cast<const TableModel*>(index.model());
        if(ptr->data1(index, Qt::DisplayRole).getTypeWidget() == Property::QComboBox)
        {
            QComboBox* combobox = qobject_cast<QComboBox*>(editor);
            QString value = combobox->currentText();
            model->setData(index, value, Qt::EditRole);
        }
        else if(ptr->data1(index, Qt::DisplayRole).getTypeWidget() == Property::QCheckBox)
        {
            QCheckBox* checkbox = qobject_cast<QCheckBox*>(editor);
            model->setData(index, checkbox->isChecked(), Qt::EditRole);
        }
        else
        {
            QLineEdit* line = qobject_cast<QLineEdit*>(editor);
            model->setData(index, line->text(), Qt::EditRole);
        }
    }
    else
    {
        QStyledItemDelegate::setModelData(editor, model, index);
    }
}

void QComboBoxItemDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
        if(index.column() == COL_VALUE)
        {
            const TableModel* ptr = qobject_cast<const TableModel*>(index.model());
            if(ptr->data1(index, Qt::DisplayRole).getTypeWidget() == Property::QComboBox)
            {
                QComboBox* combobox = qobject_cast<QComboBox*>(editor);
                combobox->setCurrentText(ptr->data(index, Qt::EditRole).toString());
            }
            else if(ptr->data1(index, Qt::DisplayRole).getTypeWidget() == Property::QCheckBox)
            {
                QCheckBox* checkbox = qobject_cast<QCheckBox*>(editor);
                checkbox->setChecked(ptr->data1(index, Qt::DisplayRole).isActive());
            }
            else
            {
                QLineEdit* line = qobject_cast<QLineEdit*>(editor);
                line->setText(ptr->data1(index, Qt::DisplayRole).getCurVal());
            }
        }
        else
        {
            QStyledItemDelegate::setEditorData(editor, index);
        }
}
