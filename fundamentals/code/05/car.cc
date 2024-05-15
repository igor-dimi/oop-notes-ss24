#include "car.hh"
#include <iostream>

Engine::Engine(std::string _brand, int _hp) : 
    manufacturer(_brand), 
    horse_power(_hp) {}

std::string Engine::get_brand() {return manufacturer;}
int Engine::get_hp() {return horse_power;}
void Engine::display()
{

std::cout << "manufacturer: " << get_brand() << std::endl
          << "horse power: " << get_hp() << std::endl;
}

Car::Car
    ( //constructor arguments
        std::string _brand,
        std::string _type,
        std::string engine_manufacturer,
        int hp
    ) : //initializer list
            brand(_brand),
            type(_type),
            engine(engine_manufacturer, hp) {}

Car::Car
    (
        std::string _brand,
        std::string _type,
        Engine _engine
    ) :
            brand(_brand),
            type(_type),
            engine(_engine) {};

std::string Car::get_brand(){return brand;}
std::string Car::get_type() {return type;}
std::string Car::get_engine() {return engine.get_brand();}
int Car::get_hp() {return engine.get_hp();}
void Car::display()
{
std::cout << "brand: " << get_brand() << std::endl
          << "type: " << get_type() << std::endl
          << "  engine: " << std::endl;
          engine.display();
}







