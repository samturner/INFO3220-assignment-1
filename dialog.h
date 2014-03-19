#ifndef DIALOG_H
#define DIALOG_H

#include "ball.h"
#include <QDialog>
#include <QTimer>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public slots:
    void nextFrame();

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

protected:
    void paintEvent(QPaintEvent *event);

private:
    Ui::Dialog *ui;
    Ball m_ball;
    int m_counter;

};

#endif // DIALOG_H
