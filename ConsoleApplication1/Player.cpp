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

void Player::setProfession(std::string PlayerProfession) {
    profession = PlayerProfession;
}


std::string Player::getProfession() const {
    return profession;
}


void Player::printInfo() {
    std::cout << "Name: " << name << ", Profession: " << profession << ", Age: " << age << std::endl;
}

