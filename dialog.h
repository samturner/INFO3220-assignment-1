#ifndef DIALOG_H
#define DIALOG_H

#include <QPushButton>
#include "ball.h"
#include "configuration.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public slots:
    void nextFrame();
    void handlePause();

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

protected:
    void paintEvent(QPaintEvent *event);

private:
    Ui::Dialog *ui;
    Ball m_ball;
    configuration m_config;
    int m_counter;
    QTimer *m_timer;
    QPushButton *m_pauseButton;
};

#endif // DIALOG_H
