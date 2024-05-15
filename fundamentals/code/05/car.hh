#ifndef CAR_H
#define CAR_H

#include <string>

class Engine
{
    public:
        Engine(std::string manufacturer, int horse_power);
        int get_hp();
        std::string get_brand();
        void display();
    private:
        std::string manufacturer;
        int horse_power;
};


class Car
{
    public:
        Car
          (
            std::string brand,
            std::string type,
            std::string engine_manufacturer,
            int horse_power
          );
        Car
          (
            std::string brand,
            std::string type,
            Engine engine
          );

        std::string 
            get_brand();

        std::string 
            get_type();
        int get_hp();
        std::string get_engine();
        void display();
    private:
        Engine engine;
        std::string brand;
        std::string type;
};


#endif // !CAR_H