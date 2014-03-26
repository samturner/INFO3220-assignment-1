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
    configuration(unsigned int m_xCoordinate = 0,
                  unsigned int m_yCoordinate = 0,
                  unsigned int m_radius = 0,
                  bool m_configEntered = false,
                  double m_gravity = 0.0,
                  double m_xVelocity = 0.0,
                  double m_yVelocity = 0.0,
                  QString m_color = "#F1C93C",
                  unsigned int m_windowHeight = 0,
                  unsigned int m_windowWidth = 0);

    bool readConfigFile();

    unsigned int getXCoordinate();
    unsigned int getYCoordinate();
    unsigned int getWindowHeight();
    unsigned int getWindowWidth();
    double getXVelocity();
    double getYVelocity();
    unsigned int getRadius();
    double getGravity();
    bool getConfigEntered();
    QString getColor();

private:
    unsigned int m_xCoordinate;
    unsigned int m_yCoordinate;
    unsigned int m_radius;
    unsigned int m_xVelocity;
    unsigned int m_yVelocity;

    unsigned int m_windowHeight;
    unsigned int m_windowWidth;

    double m_gravity;

    QString m_color;

    bool m_configEntered;
};

#endif // CONFIGURATION_H
