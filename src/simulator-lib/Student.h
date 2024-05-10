#pragma once
#include <iostream>
#include"bar-simulator.h"

enum Major {
	Fraud,
	InternationalSchemes,
	CreativeNihilism,
	SubjectiveResearches,
	FileAnalizis,
	Micromanagement,
	AppliedMaterialization,
	Subjectivistics,
	MagnetismandClearing

};

class Student {
	
	unsigned int fn;
	unsigned int arrival;
	Major major;
	unsigned int enthusiasm;

public:
	unsigned int getFN() const;
	unsigned int getArrival() const;
	Major getMajor() const;
	unsigned int getEnthusiasm() const;
	unsigned int departure() const;
	void setArrival(unsigned int arrival);



	friend std::istream& operator>> (std::istream& is, Student& student);

};