#include "configuration.h"
#include "iostream"

configuration::configuration(unsigned int xCoordinate, unsigned int yCoordinate, unsigned int radius, bool configEntered) {
    m_xCoordinate = xCoordinate;
    m_yCoordinate = yCoordinate;
    m_radius = radius;
    m_configEntered = configEntered;
}

void configuration::setConfigEntered(bool configEntered) {
    m_configEntered = configEntered;
}

void configuration::setXCoordinate(unsigned int xCoordinate) {
    m_xCoordinate = xCoordinate;
}

void configuration::setYCoordinate(unsigned int yCoordinate) {
    m_yCoordinate = yCoordinate;
}

void configuration::setRadius(unsigned int radius) {
    m_radius = radius;
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

bool configuration::getConfigEntered() {
    return m_configEntered;
}
