#ifndef FINANCEFORM_H
#define FINANCEFORM_H

#include <QWidget>
#include <QStringListModel>

namespace Ui {
class financeForm;
}

class financeForm : public QWidget
{
    Q_OBJECT

    QStringList m_btc_log;
    QStringListModel *m_dbg_model;

public:
    explicit financeForm(QWidget *parent = 0);
    ~financeForm();


public slots:
    void setBtcAddress( QString addr);
    void setBtcBalance(QString balance);
    void setBtcLastDebug(QString dbg_info);
private:
    Ui::financeForm *ui;
    uint32_t m_satoshi;


};

#endif // FINANCEFORM_H
