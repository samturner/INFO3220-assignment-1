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
    // Default values for the configuration
    configuration(unsigned int m_xCoordinate = 100,
                  unsigned int m_yCoordinate = 100,
                  unsigned int m_radius = 20,
                  double m_xVelocity = 5.6,
                  double m_yVelocity = 7.4,
                  QString m_ballColor = "#F1C93C",
                  QString m_backgroundColor = "#232323",
                  unsigned int m_windowHeight = 500,
                  unsigned int m_windowWidth = 500);

    ~configuration();

    unsigned int getXCoordinate() const;
    unsigned int getYCoordinate() const;
    unsigned int getWindowHeight() const;
    unsigned int getWindowWidth() const;
    double getXVelocity() const;
    double getYVelocity() const;
    unsigned int getRadius() const;
    QString getBallColor() const;
    QString getBackgroundColor() const;

private:
    unsigned int m_xCoordinate;
    unsigned int m_yCoordinate;
    unsigned int m_radius;
    unsigned int m_xVelocity;
    unsigned int m_yVelocity;

    unsigned int m_windowHeight;
    unsigned int m_windowWidth;

    QString m_ballColor;
    QString m_backgroundColor;
};

#endif // CONFIGURATION_H
