#include "Portative.h"

Portative::Portative() : VMachine()
{
    this->battery = 0;
}

Portative::Portative(int battery, string model) : VMachine(model)
{
    this->battery = battery;
}

Portative::Portative(const Portative& object) : VMachine(object)
{
    this->battery = object.battery;
}

Portative::~Portative()
{
}

int Portative::getBattery() const
{
    return this->battery;
}

void Portative::setBattery(int battery)
{
    this->battery = battery;
}

void Portative::write(std::ostream& f)
{
    VMachine::write(f);
    f.write((char*)&battery, sizeof(battery));
}

void Portative::read(std::istream& f)
{
    VMachine::read(f);
    f.read((char*)&battery, sizeof(battery));
}

istream& operator>>(istream& in, Portative& obj)
{
    in >> dynamic_cast<VMachine&>(obj);

    obj.battery = GetCorrectNumber<int>(in, "Enter battery mAh value (ex. 1700): ", 1500, 100000);

    return in;
}

ostream& operator<<(ostream& os, const Portative& obj)
{
    return os << dynamic_cast<const VMachine&>(obj) << setw(10) << obj.battery;
}


fstream& operator<<(fstream& out, Portative& obj)
{
    out << dynamic_cast<VMachine&>(obj);
    out << obj.battery << " ";
    return out;
}

fstream& operator>>(fstream& in, Portative& obj)
{
    in >> dynamic_cast<VMachine&>(obj);
    in >> obj.battery;
    return in;
}

ofstream& operator<<(ofstream& out, Portative& obj)
{
    out << dynamic_cast<VMachine&>(obj);
    out.write(reinterpret_cast<char*>(&obj.battery), sizeof(obj.battery));
    return out;
}

ifstream& operator>>(ifstream& in, Portative& obj)
{
    in >> dynamic_cast<VMachine&>(obj);
    in.read(reinterpret_cast<char*>(&obj.battery), sizeof(obj.battery));
    return in;
}


