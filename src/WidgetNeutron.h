#ifndef WIDGET_NEUTRON_H_
#define WIDGET_NEUTRON_H_

#include "application.h"

class WidgetNeutron : public WidgetBaseClass
{
    public:
        WidgetNeutron(uint8_t ucItem = 0);
        ~WidgetNeutron();
        void begin(void (*UserCallBack)(void) = NULL);
        void displayAcceleration(int x,int y, int z);
        void displayGyroscope(int x,int y, int z);
        void displayMagnetometer(int x,int y, int z);
        void displayPressure(int ucVal);
        void displayAltitude(int ucVal);
        void displayIllumination(int ucVal);
        void displayLoudness(int ucVal);
        uint8_t getSwitch(void);

    private:
        char pDataAccelerationTopic[64];
        char pDataGyroscopeTopic[64];
        char pDataMagnetometerTopic[64];
        char pDataPressureTopic[64];
        char pDataAltitudeTopic[64];
        char pDataIlluminationTopic[64];
        char pDataLoudnessTopic[64];
        char pCmdSwitchTopic[64];
        uint8_t _Item = 0;
        uint8_t _switchKey;
        
        aJsonClass aJson;
        
        void uploadData(char *topic,int x,int y,int z);

        void (*_EventCb)(void);
        void widgetBaseCallBack(uint8_t *payload, uint32_t len);
};

#endif
