#include "settings.h"
#include "ui_settings.h"
#include <QMessageBox>
Settings::Settings(QWidget *parent) :
    QMainWindow(0),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    this->parent=parent;
}

Settings::~Settings()
{
    delete ui;
}

void Settings::on_pushButton_clicked()
{
    ui->filepath->setText(QFileDialog::getOpenFileName(0,QString(),QString(),tr("XML files(*.xml);;"))) ;
}


void Settings::closeEvent(QCloseEvent *event)
{
    this->setVisible(false);
    this->parent->setVisible(true);
}

void Settings::on_cancel_button_clicked()
{
    this->setVisible(false);
    this->parent->setVisible(true);
}

void Settings::on_load_button_clicked()
{
    if((QFile(ui->filepath->text())).exists())
    {
        this->setVisible(false);
        this->parent->setVisible(true);
        emit sendData(ui->filepath->text(), ui->cellSize->text().toInt());
    }
}
void Settings::openSettings()
{
    this->setVisible(true);

}
