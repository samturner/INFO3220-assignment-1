#include "configuration.h"

configuration::configuration(unsigned int xCoordinate, unsigned int yCoordinate, unsigned int radius, double xVelocity, double yVelocity, QString color, unsigned int windowHeight, unsigned int windowWidth) {
    m_xCoordinate = xCoordinate;
    m_yCoordinate = yCoordinate;
    m_radius = radius;
    m_xVelocity = xVelocity;
    m_yVelocity = yVelocity;
    m_color = color;
    m_windowHeight = windowHeight;
    m_windowWidth = windowWidth;

    QFile inputFile("config.txt");        // The config file location

     if (inputFile.open(QIODevice::ReadOnly)) {
        QTextStream configFile(&inputFile);

        while (!configFile.atEnd()) {               // If we're not at the end of a file
           QStringList opt = configFile.readLine().split(':');   // Read the line in and split on colon
           QString setting = opt[0].simplified();       // Make sure some weird whitespace doesn't mess it up

           if (setting == "Radius") {
               m_radius = opt[1].toInt();
           } else if (setting == "InitialX") {
               m_xCoordinate = opt[1].toInt();
           } else if (setting == "InitialY") {
               m_yCoordinate = opt[1].toInt();
           } else if (setting == "XVelocity") {
               m_xVelocity = opt[1].toDouble();
           } else if (setting == "YVelocity") {
               m_yVelocity = opt[1].toDouble();
           } else if (setting == "Color") {
               m_color = opt[1];
           } else if (setting == "WindowHeight") {
               m_windowHeight = opt[1].toInt();
           } else if (setting == "WindowWidth") {
               m_windowWidth = opt[1].toInt();
           }
        }

        inputFile.close();      // Close the file
     }
}

unsigned int configuration::getWindowHeight() const {
    return m_windowHeight;
}

unsigned int configuration::getWindowWidth() const {
    return m_windowWidth;
}

unsigned int configuration::getXCoordinate() const {
    return m_xCoordinate;
}

unsigned int configuration::getYCoordinate() const {
    return m_yCoordinate;
}

unsigned int configuration::getRadius() const {
    return m_radius;
}

double configuration::getXVelocity() const {
    return m_xVelocity;
}

double configuration::getYVelocity() const {
    return m_yVelocity;
}

QString configuration::getColor() const {
    return m_color;
}
