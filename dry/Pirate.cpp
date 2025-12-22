
#include "Pirate.h"


Pirate::Pirate(const string& name, int bounty): name(name), bounty(bounty) {}


void Pirate::setName(const string& name){
    this->name = name;
}

std::string Pirate::getName(){
    return name;
}

void Pirate::setBounty(int bounty) {
    this->bounty = bounty;
}

int Pirate::getBounty() {
    return bounty;
}

std::ostream &operator<<(std::ostream &os, const Pirate &pirate){
    os << pirate.name << " (Bounty: " << pirate.bounty << ")";
    return os;
}
