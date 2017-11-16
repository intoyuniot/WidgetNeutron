#include "WidgetNeutron.h"


WidgetNeutron::WidgetNeutron(uint8_t ucItem)
{
    _Item=ucItem;
    memset(pDataAccelerationTopic,0,sizeof(pDataAccelerationTopic));
    memset(pDataGyroscopeTopic,0,sizeof(pDataGyroscopeTopic));
    memset(pDataMagnetometerTopic,0,sizeof(pDataMagnetometerTopic));
    memset(pDataPressureTopic,0,sizeof(pDataPressureTopic));
    memset(pDataAltitudeTopic,0,sizeof(pDataAltitudeTopic));
    memset(pDataIlluminationTopic,0,sizeof(pDataIlluminationTopic));
    memset(pDataLoudnessTopic,0,sizeof(pDataLoudnessTopic));
    memset(pCmdSwitchTopic,0,sizeof(pCmdSwitchTopic));
    sprintf(pDataAccelerationTopic,"channel/neutron_%d/data/acceleration",_Item);
    sprintf(pDataGyroscopeTopic,"channel/neutron_%d/data/gyroscope",_Item);
    sprintf(pDataMagnetometerTopic,"channel/neutron_%d/data/magnetometer",_Item);
    sprintf(pDataPressureTopic,"channel/neutron_%d/data/pressure",_Item);
    sprintf(pDataAltitudeTopic,"channel/neutron_%d/data/altitude",_Item);
    sprintf(pDataIlluminationTopic,"channel/neutron_%d/data/illumination",_Item);
    sprintf(pDataLoudnessTopic,"channel/neutron_%d/data/loudness",_Item);
    sprintf(pCmdSwitchTopic,"channel/neutron_%d/cmd/switch",_Item);
    
}

WidgetNeutron::~WidgetNeutron()
{
}

void WidgetNeutron::begin(void (*UserCallBack)(void))
{
    _EventCb = UserCallBack;
    IntoRobot.subscribe(pCmdSwitchTopic,NULL,this);
}

void WidgetNeutron::displayAcceleration(int x,int y, int z)
{
    uploadData(pDataAccelerationTopic,x,y,z);
}

void WidgetNeutron::displayGyroscope(int x,int y, int z)
{
    uploadData(pDataGyroscopeTopic,x,y,z);
}

void WidgetNeutron::displayMagnetometer(int x,int y, int z)
{
    uploadData(pDataMagnetometerTopic,x,y,z);
}

void WidgetNeutron::uploadData(char *topic,int x,int y,int z)
{
    aJsonObject* root = aJson.createObject();
    if (root == NULL)
    {
        return;
    }
    
    aJson.addNumberToObject(root, "x",x);
    aJson.addNumberToObject(root, "y",y);
    aJson.addNumberToObject(root, "z",z);
    
    char* str = aJson.print(root);
    
    IntoRobot.publish(topic,str);
    free(str);
    aJson.deleteItem(root);
}

void WidgetNeutron::displayPressure(int ucVal)
{
    IntoRobot.publish(pDataPressureTopic,ucVal);
}

void WidgetNeutron::displayAltitude(int ucVal)
{
    IntoRobot.publish(pDataAltitudeTopic,ucVal);
}

void WidgetNeutron::displayIllumination(int ucVal)
{
    IntoRobot.publish(pDataIlluminationTopic,ucVal);
}

void WidgetNeutron::displayLoudness(int ucVal)
{
    IntoRobot.publish(pDataLoudnessTopic,ucVal);
}

uint8_t WidgetNeutron::getSwitch(void)
{
    return _switchKey;
}

void WidgetNeutron::widgetBaseCallBack(uint8_t *payload, uint32_t len)
{
    if(payload[0] == '1')
    {
        _switchKey = 1;
    }
    else
    {
        _switchKey = 0;
    }
    
    _EventCb();
}

