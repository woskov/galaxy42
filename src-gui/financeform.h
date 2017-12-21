#ifndef FINANCEFORM_H
#define FINANCEFORM_H

#include <QWidget>

namespace Ui {
class financeForm;
}

class financeForm : public QWidget
{
    Q_OBJECT

public:
    explicit financeForm(QWidget *parent = 0);
    ~financeForm();

public slots:
    /*
    void setBtcAddress( QString addr);
    void setBtcBalance(QString balance);
    void setBtcLastDebug(QString dbg_info);
*/
private:
    Ui::financeForm *ui;
};

#endif // FINANCEFORM_H
