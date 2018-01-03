#include <QDateTime>
#include <QDir>
#include <QFile>

#include "debugform.h"
#include "ui_debugform.h"


DebugForm::DebugForm(QWidget *parent,const QString &log_name) :
    QWidget(parent),
    ui(new Ui::DebugForm)
{
    ui->setupUi(this);
    if(log_name != "none"){
        m_log_name = log_name;
        ui->logNamelabel->setText(m_log_name);
        QDateTime now = QDateTime::currentDateTime();
        m_dbg_list.push_back("log:"+ m_log_name +" starts:"+now.toString());
    }
    m_model.setStringList(m_dbg_list);
    ui->listView->setModel(&m_model);
}


void DebugForm::saveLog(QString file_name)
{
    QString dir = QDir::currentPath();
    dir += QDateTime::currentDateTime().toString()+ file_name+".log";
    QFile of_file(dir);

    for(auto &it : m_model.stringList() ){
        of_file.write(it.toUtf8());
        of_file.write("\r\n");
    }

    of_file.close();
}

void DebugForm::DebugForm::clearLog()
{
    m_dbg_list.clear();
    m_model.setStringList(m_dbg_list);
}


void DebugForm::addMsg(const QString &msg)
{
    addToModel(msg);
}

void DebugForm::addToModel(const QString &msg)
{
    if(m_model.insertRow(m_model.rowCount())) {
        QModelIndex index = m_model.index(m_model.rowCount() - 1, 0);
        m_model.setData(index, msg);
    }
}

void DebugForm::on_clearBtn_clicked()
{
    clearLog();
}

void DebugForm::on_saveBtn_clicked()
{
    saveLog(m_log_name);
}

void DebugForm:: setLogName(const QString& log_name)
{
    m_log_name = log_name;
    ui->logNamelabel->setText(m_log_name);
    QDateTime now = QDateTime::currentDateTime();
    m_dbg_list.push_back("log:"+ m_log_name +" starts:"+now.toString());

    ui->logNamelabel->setText(log_name);
}

