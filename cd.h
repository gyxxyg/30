#ifndef CD_H
#define CD_H

#include <QDialog>

namespace Ui {
class cd;
}

class cd : public QDialog
{
    Q_OBJECT

public:
    explicit cd(QWidget *parent = 0);
    ~cd();
signals:
    void toclose();
    void tocontinue();
    void torestart();
    void tohelp();
private slots:
    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::cd *ui;
};

#endif // CD_H
