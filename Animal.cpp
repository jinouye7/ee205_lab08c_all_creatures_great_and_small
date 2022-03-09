///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab08c_all_creatures_great_and_small - EE 205 - Spr 2022
///
/// @file Animal.cpp
/// @version 1.0
///
/// @author Jared Inouye <jinouye7@hawaii.edu>
/// @date   08_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Animal.h"

using namespace std;

const string Animal::kingdom = "Animalia";

Animal::Animal(const string &newSpecies) : species(newSpecies) {
    setSpecies( newSpecies );
}
//constructor for species and gender
Animal::Animal(const string &newSpecies, Gender gender) : species(newSpecies), gender(gender) {
    setSpecies( newSpecies );
}
//constructor for species, gender, and newWeight
Animal::Animal(const string &newSpecies, Gender gender, float newWeight) : species(newSpecies), gender(gender), weight(newWeight) {
    setWeight(newWeight);
    setSpecies( newSpecies );
}
//constructor for species, and newWeight
Animal::Animal(const string &species, float newWeight) : species(species), weight(newWeight) {
    setWeight(newWeight);
}


const string &Animal::getKingdom() {
    return kingdom;
}

const string &Animal::getSpecies() const {
    return species;
}

Gender Animal::getGender() const {
    return gender;
}

void Animal::setGender(Gender newGender) {
    if(gender != UNKNOWN_GENDER && newGender != UNKNOWN_GENDER ) {
        throw logic_error("Previous gender must be UNKNOWN_GENDER");

    }
    Animal::gender = newGender;
}

float Animal::getWeight() const {
    return weight;
}

void Animal::setWeight(float newWeight) {
    if( !validateWeight(newWeight)){
        throw invalid_argument("weight must be > 0");
    }
    Animal::weight = weight;
}

void Animal::printInfo() {
    cout << "Animal Fields" << endl;
    cout << " Kingdom = [" << getKingdom() << "]" << endl;
    cout << " Species = [" << getSpecies() << "]" << endl;
    cout << " Weight = [" << getWeight() << "]" << endl;
    cout << " Gender = [" << getGender() << "]" << endl;
}

bool Animal::isValid() {
    if( !validateWeight(weight))
        return false;

    return false;
}

bool Animal::validateWeight(const float newWeight) {
    if( newWeight == UNKNOWN_WEIGHT )
        return true;
    if( newWeight > 0 )
        return true;

    //all other cases return false
    return false;
}

bool Animal::validateSpecies(const std::string newSpecies) {
    if( newSpecies.empty())
        return false;

    return true;
}

void Animal::setSpecies(const std::string newSpecies) {
    if( !validateSpecies( newSpecies ))
        throw invalid_argument("A species can't be empty.");

    Animal::species = newSpecies ;
}
