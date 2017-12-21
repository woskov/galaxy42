#ifndef PAYMENTDIALOG_H
#define PAYMENTDIALOG_H

#include <QDialog>

namespace Ui {
class paymentDialog;
}

class paymentDialog : public QDialog
{
    Q_OBJECT

public:
    explicit paymentDialog(QWidget *parent = 0);
    ~paymentDialog();

private:
    Ui::paymentDialog *ui;
};

#endif // PAYMENTDIALOG_H
