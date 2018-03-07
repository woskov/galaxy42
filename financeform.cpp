#include "financeform.h"
#include "ui_financeform.h"

financeForm::financeForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::financeForm)
{
    ui->setupUi(this);
     m_dbg_model = new QStringListModel(this);

    setBtcLastDebug("gui starts");
    ui->debugWidget->setLogName("finance log");
//    ui->debugWidget->addMsg()
//     m_dbg_model->setStringList(m_btc_log);
//    ui->debugView->setModel(m_dbg_model);

//    m_btc_log.push_back("program starts");
}

financeForm::~financeForm()
{
    delete ui;
}


void financeForm::setBtcAddress( QString addr)
{
    ui->btcLine->setText(addr);
    setBtcLastDebug("get btc address:"+addr);
//    m_btc_log.push_back("get btc address:"+addr);
  //  m_dbg_model.insertRow(m_btc_log.size());
}

void financeForm::setBtcBalance(QString balance)
{
    ui->balanceLine->setText(balance);
}

void financeForm::setBtcLastDebug(QString dbg_info)
{
    ui->debugWidget->addMsg(dbg_info);

//    m_dbg_model->dataChanged(m_dbg_model->createIndex(m_btc_log.size()-1,0),m_dbg_model->createIndex(m_btc_log.size(),1) );

//    m_dbg_model->insertRow(m_btc_log.size());
/**
     todo add debug info update
*/
}

