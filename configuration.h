#ifndef CONFIGURATION_H
#define CONFIGURATION_H

class configuration
{
public:
    configuration(unsigned int m_xCoordinate = 0,
                  unsigned int m_yCoordinate = 0,
                  unsigned int m_radius = 0,
                  bool m_configEntered = false);

    void setXCoordinate(unsigned int xCoordinate);
    void setYCoordinate(unsigned int yCoordinate);
    void setConfigEntered(bool configEntered);

    void setRadius(unsigned int radius);

    unsigned int getXCoordinate();
    unsigned int getYCoordinate();
    unsigned int getRadius();
    bool getConfigEntered();

private:
    unsigned int m_xCoordinate;
    unsigned int m_yCoordinate;
    unsigned int m_radius;

    bool m_configEntered;
};

#endif // CONFIGURATION_H
