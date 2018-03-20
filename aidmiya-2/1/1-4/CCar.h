#ifndef __CCAR_H__
#define __CCAR_H__

class CCar {
  public:
    CCar();
    CCar(int);
    ~CCar();
    void run();
    int getFuel();
    void setFuel(int);
  private:
    int fuel;
};

#endif
