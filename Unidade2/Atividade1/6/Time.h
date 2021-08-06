//impede que múltiplas inclusões ocorram
#ifndef TIME_H
#define TIME_H

class Time 
{
public:
  Time(); //construtor
  void setTime(int , int, int); //protótipo
  void printUniversal();
  void printStandard();
  void tick();

private:
  int hour;
  int minute;
  int second;
};

#endif