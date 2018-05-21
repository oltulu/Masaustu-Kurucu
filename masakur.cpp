#include "masakur.h"
#include "ui_masakur.h"
#include "QString"
#include "QFile"
#include "QTextStream"
#include "QProcess"
#include "QMessageBox"

MasaKur::MasaKur(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MasaKur)
{
    ui->setupUi(this);
}

MasaKur::~MasaKur()
{
    delete ui;
}

void MasaKur::on_comboBox_currentTextChanged(const QString &arg1)
{
    QString masaustu = ui->comboBox->currentText();

    QFile file("/opt/masakur/bilgi/"+masaustu);
    file.open(QFile::ReadOnly | QFile::Text);

    QTextStream ReadFile(&file);
    ui->MasaBilgi->setText(ReadFile.readAll());

    ui->Resim->setPixmap("/opt/masakur/resimler/" + ui->comboBox->currentText() + ".png");

}

void MasaKur::on_MasaKurButonu_clicked()
{
    QString masaustu = ui->comboBox->currentText();

    QFile kur("/opt/masakur/kur/"+masaustu);
    kur.open(QFile::ReadOnly | QFile::Text);

    QTextStream ReadFile(&kur);
     if(!kur.exists()) {
    QMessageBox::information(this, "Masaüstü Kurucu"," Kurmak için masaüstü seçmediniz.");
     }
       else
     {
     QProcess::execute("sudo pacman -S --noconfirm --needed "+ReadFile.readAll());
     }
}
