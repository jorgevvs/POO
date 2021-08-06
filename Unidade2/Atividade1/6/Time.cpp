#include <iostream>
using std::cout;
using std::endl;

//biblioteca que permite alguns controles sobre a saída
#include <iomanip>
using std::setfill; 
using std::setw;

#include "Time.h"

Time::Time()
{
  hour = minute = second = 0;
}

void Time::setTime(int h, int m, int s)
{
  hour = (h >=0 && h < 24) ? h : 0;     //valida horas
  minute = (m >= 0 && m < 60) ? m : 0;  //valida minutos
  second = (s >= 0 && s < 60) ? s : 0;  //valida segundos
}

void Time::printUniversal()
{
  cout << setfill('0') << setw(2) << hour << ":" <<
  setw(2) << minute << ":" << setw(2) << second << endl;
}

void Time::printStandard()
{
  cout << ( (hour == 0 || hour == 12) ? 12 : hour % 12) << ":" << setfill('0') << setw(2) << minute << ":" << setw(2) << second << (hour < 12 ? " AM" : " PM") << endl;
}

void Time::tick(){
  if(second == 59){
    second = 0;
    if(minute == 59){
      minute = 0;
      if(hour == 23){
        hour = 0;
      }else{
        hour++;
      }
    }else{
      minute++;
    }
  }else{
    second++;
  }
}