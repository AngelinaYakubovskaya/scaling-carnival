#include "Player.h"


void Player::setName(std::string PlayerName) {
    name = PlayerName;
}


std::string Player::getName() const {
    return name;
}


void Player::setAge(int PlayerAge) {
    age = PlayerAge;
}


int Player::getAge() const {
    return age;
}


std::string Player::getProfession() const {
    std::string professionString;
    switch (mProfession)
    {
    case Profession::ArtistPro:
        professionString = "Artist";
        break;

    case Profession::SientistPro:
        professionString = "Scientist";
        break;

    case Profession::SportsmanPro:
        professionString = "Sportsman";
        break;

    default:
        break;

    }
    return professionString;
}

void Player::printInfo() {
 
    std::cout << "Name: " << name << ", Profession: " << getProfession() << ", Age: " << age << std::endl;
}

