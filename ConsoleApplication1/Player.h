#pragma once

#include <iostream>
#include <string>
#include "consts.h"

class Player {
private:
    std::string name;
    std::string profession;
    int age;

protected:
    Tasktheme tasktheme;

public:
    // Конструктор класса
    Player(std::string PlayerName, std::string PlayerProfession, int PlayerAge) : name(PlayerName), profession(PlayerProfession), age(PlayerAge) {}

    // Метод для установки значения имени
    void setName(std::string PlayerName);

    // Метод для получения значения имени
    std::string getName() const;

    // Метод для установки значения возраста
    void setAge(int PlayerAge);

    // Метод для получения значения возраста
    int getAge() const;

    void setProfession(std::string PlayerProfession);

    // Метод для получения значения имени
    std::string getProfession() const;

    // Метод для вывода информации о человеке
    void printInfo();

    // В какой области игрок силен
    Tasktheme getTaskTheme() const
    {
        return tasktheme;
    }
};