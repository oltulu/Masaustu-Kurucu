#ifndef MASAKUR_H
#define MASAKUR_H

#include <QMainWindow>

namespace Ui {
class MasaKur;
}

class MasaKur : public QMainWindow
{
    Q_OBJECT

public:
    explicit MasaKur(QWidget *parent = 0);
    ~MasaKur();

private slots:
    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_MasaKurButonu_clicked();


private:
    Ui::MasaKur *ui;
};

#endif // MASAKUR_H
