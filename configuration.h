#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <QDialog>
#include <QTimer>
#include <QString>
#include <QStringList>
#include <QFile>
#include <QTextStream>

class configuration
{
public:
    configuration(unsigned int m_xCoordinate = 100,
                  unsigned int m_yCoordinate = 100,
                  unsigned int m_radius = 20,
                  double m_xVelocity = 5.6,
                  double m_yVelocity = 7.4,
                  QString m_color = "#F1C93C",
                  unsigned int m_windowHeight = 500,
                  unsigned int m_windowWidth = 500);

    unsigned int getXCoordinate();
    unsigned int getYCoordinate();
    unsigned int getWindowHeight();
    unsigned int getWindowWidth();
    double getXVelocity();
    double getYVelocity();
    unsigned int getRadius();
    QString getColor();

private:
    unsigned int m_xCoordinate;
    unsigned int m_yCoordinate;
    unsigned int m_radius;
    unsigned int m_xVelocity;
    unsigned int m_yVelocity;

    unsigned int m_windowHeight;
    unsigned int m_windowWidth;

    QString m_color;
};

#endif // CONFIGURATION_H
