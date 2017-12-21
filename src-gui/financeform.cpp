#include "financeform.h"
#include "ui_financeform.h"

financeForm::financeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::financeForm)
{
    ui->setupUi(this);
}

financeForm::~financeForm()
{
    delete ui;
}
