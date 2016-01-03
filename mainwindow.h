#pragma once

#include <QtWidgets>
#include <QSettings>
#include "SystemTray.h"

class SystemTray;

class MainWindows : public QWidget
{
    Q_OBJECT
private:
    static const int columnTable = 2;

    QList<QPair<QString, QStringList> > keyword;

    QVBoxLayout* pvbx;
    QHBoxLayout* phbx;
    QPushButton* pbtn, *pAC, *pBAT, *pbtnTab;
    QMenuBar* pbar;
    QTableWidget* ptable;
    SystemTray* st;
    QTextBrowser lbl;
    QSettings m_sett;

    bool state;
    QString curProf;
    QString pathToProf;

    void readSettings();
    void writeSettings();
    void createQMenuBar();
    void createQMenuFile(QMenu*);
    void createQMenuHelp(QMenu*);
    void fillTable();
    void loadTempFile(QMap<QString, QStringList>&);//TODO : Only for studying and testing

public :
    MainWindows(QWidget* parent = 0);
    ~MainWindows();

    friend SystemTray;
public slots:
    void slotSaveTable();
    void slotOpenFile();
    void slotSaveFile();
    void slotCallEditor();
    void slotSwitchMode();
    void slotSettings();
    void slotAC();
    void slotBAT();

};
