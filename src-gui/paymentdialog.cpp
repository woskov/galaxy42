#include "paymentdialog.h"
#include "ui_paymentdialog.h"

paymentDialog::paymentDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::paymentDialog)
{
    ui->setupUi(this);
}

paymentDialog::~paymentDialog()
{
    delete ui;
}
