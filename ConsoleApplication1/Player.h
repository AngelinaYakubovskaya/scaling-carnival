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
    Profession mProfession;
        
 
public:
    // ����������� ������
    Player(std::string PlayerName, Profession profession, int PlayerAge) : name(PlayerName), mProfession(profession), age(PlayerAge) {}

    // ����� ��� ��������� �������� �����
    void setName(std::string PlayerName);

    // ����� ��� ��������� �������� �����
    std::string getName() const;

    // ����� ��� ��������� �������� ��������
    void setAge(int PlayerAge);

    // ����� ��� ��������� �������� ��������
    int getAge() const;

    // ����� ��� ��������� �������� �����
    std::string getProfession() const;

    // ����� ��� ������ ���������� � ��������
    void printInfo();

    // � ����� ������� ����� �����
    Tasktheme getTaskTheme() const
    {
        return tasktheme;
    }

    virtual bool canAnswerOnQuistion(Tasktheme theme)
    {
        return false;
    }
};