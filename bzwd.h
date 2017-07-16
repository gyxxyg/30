#ifndef BZWD_H
#define BZWD_H

#include <QDialog>

namespace Ui {
class bzwd;
}

class bzwd : public QDialog
{
    Q_OBJECT

public:
    explicit bzwd(QWidget *parent = 0);
    ~bzwd();

private:
    Ui::bzwd *ui;
};

#endif // BZWD_H
