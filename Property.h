#ifndef PROPERTY_H
#define PROPERTY_H

#include <QString>
#include <QObject>

class Property
{
private:
    enum TypeOfWidget{QLineEdit, QCheckBox, QComboBox};
    enum PropertyGroup{};
    QString m_name, m_defVal;
    QStringList m_variants;
    TypeOfWidget m_type;
    bool m_isImp, m_isDanger;
public:
    Property(const QString name, const QString defVal, const QStringList variants,
             const TypeOfWidget flag, const bool isImp = false);
    Property(const Property&val);

    QString getName() const;
    QString getDefVal() const;
    QStringList getVariants() const;
    TypeOfWidget getTypeWidget() const;
    bool isImportant() const;

    void setName(const QString& name);
    void setDefVal(const QString& defVal);
    void setVariants(const QStringList& variants);
    void setTypeWidget(const TypeOfWidget type);
    void setIsImportant(bool flag);
};

#endif // PROPERTY_H
