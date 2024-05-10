#include "Student.h"
#include <iostream>
#include "bar-simulator.h"
#include <string>
#include <algorithm>




	unsigned int Student::getFN() const {
		return fn;
	}

	unsigned int Student::getArrival() const {
		return arrival;
	}

	Major Student::getMajor() const {
		return major;
	}

	unsigned int Student::getEnthusiasm() const {
		return enthusiasm;
	}


	unsigned int Student::departure() const {
		return arrival + enthusiasm;
	}

	void Student::setArrival(unsigned int arrival) {
		this->arrival = arrival;
	}

	std::istream& operator>> (std::istream& is, Student& student) {
		int checkFN;
		is >> checkFN;
		if (checkFN < 0) {
			throw incorrect_simulation("Incorrect FN");
		}
		student.fn = checkFN;
		is >> student.arrival;
		std::string specialty;
		std::string specialty2;
		is >> specialty;
		is >> specialty2;
		if (std::all_of(specialty2.begin(), specialty2.end(), std::isdigit)) {
			student.enthusiasm = std::stoi(specialty2);
		}
		else {
			specialty += ' ';
			specialty += specialty2;
			is >> student.enthusiasm;
		}


		 if (specialty == "Fraud") {
				student.major = Major::Fraud;
			}
		 else if (specialty == "International Schemes") {
			 student.major = Major::InternationalSchemes;
		 }
		 else if (specialty == "Creative Nihilism") {
			 student.major = Major::CreativeNihilism;
		 }
		 else if (specialty == "Subjective Researches") {
			 student.major = Major::SubjectiveResearches;
		 }
		 else if (specialty == "File Analizis") {
			 student.major = Major::FileAnalizis;
		 }
		 else if (specialty == "Micromanagement") {
			 student.major = Major::Micromanagement;
		 }
		 else if (specialty == "Applied Materialization") {
			 student.major = Major::AppliedMaterialization;
		 }
		 else if (specialty == "Subjectivistics") {
			 student.major = Major::Subjectivistics;
		 }
		 else if (specialty == "Magnetismand Clearing") {
			 student.major = Major::MagnetismandClearing;
		 }
		 else {
			 throw incorrect_simulation("There is no such major!");
		 }
		
	}