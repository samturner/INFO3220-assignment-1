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
        QTextStream configFile(&inputFile);         // Open the file

        while (!configFile.atEnd()) {               // If we're not at the end of a file
           QStringList opt = configFile.readLine().split(':');   // Read the line in and split on colon

           if (opt[0] == "Radius") {
               m_radius = opt[1].toInt();
           } else if (opt[0] == "InitialX") {
               m_xCoordinate = opt[1].toInt();
           } else if (opt[0] == "InitialY") {
               m_yCoordinate = opt[1].toInt();
           } else if (opt[0] == "XVelocity") {
               m_xVelocity = opt[1].toDouble();
           } else if (opt[0] == "YVelocity") {
               m_yVelocity = opt[1].toDouble();
           } else if (opt[0] == "Color") {
               m_color = opt[1];
           } else if (opt[0] == "WindowHeight") {
               m_windowHeight = opt[1].toInt();
           } else if (opt[0] == "WindowWidth") {
               m_windowWidth = opt[1].toInt();
           }
        }

        inputFile.close();      // Close the file
     }
}

unsigned int configuration::getWindowHeight() {
    return m_windowHeight;
}

unsigned int configuration::getWindowWidth() {
    return m_windowWidth;
}

unsigned int configuration::getXCoordinate() { 
    return m_xCoordinate;
}

unsigned int configuration::getYCoordinate() {
    return m_yCoordinate;
}

unsigned int configuration::getRadius() {
    return m_radius;
}

double configuration::getXVelocity() {
    return m_xVelocity;
}

double configuration::getYVelocity() {
    return m_yVelocity;
}

QString configuration::getColor() {
    return m_color;
}
