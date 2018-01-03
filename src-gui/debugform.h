#ifndef DEBUGFORM_H
#define DEBUGFORM_H

#include <QWidget>
#include <QStringListModel>


namespace Ui {
class DebugForm;
}

class DebugForm : public QWidget
{
    Q_OBJECT
public:
    explicit DebugForm( QWidget *parent = 0,const QString &log_name = "none");

    void setLogName(const QString& log_name);

public slots:
    void addMsg(const QString &msg);

private slots:

    void on_clearBtn_clicked();

    void on_saveBtn_clicked();

private:
    void addToModel(const QString &msg);
    void saveLog(QString file_name);
    void clearLog();
    Ui::DebugForm *ui;

    QStringList m_dbg_list;
    QStringListModel m_model;
    QString m_log_name;
};

#endif // DEBUGFORM_H
