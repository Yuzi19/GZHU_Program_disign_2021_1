#include "addstu.h"
#include "ui_addstu.h"
#include "QString"
#include "QDebug"
#include "QMessageBox"
#include "QFile"

addstu::addstu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addstu)
{
    ui->setupUi(this);
}

addstu::~addstu()
{
    delete ui;
}

void addstu::on_buttonBox_accepted()
{
    QString name=this->ui->add_stu_name->text();
    QString age=this->ui->add_stu_age->text();
    QString number=this->ui->add_stu_num->text();
    QString gender=this->ui->add_stu_gender->text();
    QString math=this->ui->add_stu_math->text();
    QString cpp=this->ui->add_stu_cpp->text();

    QString info=number+" "+name+" "+gender+" "+age+" "+math+" "+cpp;


    QFile mFile("student.txt");
    if(!mFile.open(QIODevice::Append|QIODevice::Text))
    {
        QMessageBox::critical(this,"错误","文件打开失败，信息没有写入","确认");
        return;
    }
    QTextStream out(&mFile);
    out<<info<<"\n";
    mFile.flush();
    mFile.close();
    return;
}


void addstu::on_buttonBox_rejected()
{
    this->close();
}

