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
    // ����������� ������
    Player(std::string PlayerName, std::string PlayerProfession, int PlayerAge) : name(PlayerName), profession(PlayerProfession), age(PlayerAge) {}

    // ����� ��� ��������� �������� �����
    void setName(std::string PlayerName);

    // ����� ��� ��������� �������� �����
    std::string getName() const;

    // ����� ��� ��������� �������� ��������
    void setAge(int PlayerAge);

    // ����� ��� ��������� �������� ��������
    int getAge() const;

    void setProfession(std::string PlayerProfession);

    // ����� ��� ��������� �������� �����
    std::string getProfession() const;

    // ����� ��� ������ ���������� � ��������
    void printInfo();

    // � ����� ������� ����� �����
    Tasktheme getTaskTheme() const
    {
        return tasktheme;
    }
};