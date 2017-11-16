/*
************************************************************************
* 作者:  IntoRobot Team    
* 版本:  V1.0.0
* 日期:  03-30-15
************************************************************************
功能描述：
IntoRobot Neutron原始数据显示

所需器件:
1.IntoRobot Neutron
*/

/*该头文件引用由IntoRobot自动添加.*/
#include <WidgetNeutron.h>

#define LED_PIN    D7

WidgetNeutron neutron;

int a = 1000;
int b = -771;
int c = 8888;

void SwitchCb(void)
{
    if(neutron.getSwitch())
    {
        digitalWrite(LED_PIN,HIGH);
    }
    else
    {
        digitalWrite(LED_PIN,LOW);
    }
}

void setup() 
{
// put your setup code here, to run once.
    pinMode(LED_PIN,OUTPUT);
    neutron.begin(SwitchCb);
}

void loop() 
{
// put your main code here, to run repeatedly.
    neutron.displayAcceleration(a,b,c);
    neutron.displayGyroscope(a,b,c);
    neutron.displayMagnetometer(a,b,c);
    neutron.displayPressure(a);
    neutron.displayAltitude(b);
    neutron.displayIllumination(c);
    neutron.displayLoudness(100);
    delay(2000);
}
