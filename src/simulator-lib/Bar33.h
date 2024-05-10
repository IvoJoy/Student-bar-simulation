#pragma once
#include "Student.h"
#include <iostream>
#include "List.hpp"
#include "Group.h"



class Bar {
	List<Group> groups;
	List<Student> inside;

	Group* groupPtrs[9]{ nullptr };

	unsigned int capacity;
	unsigned int groupCapacity;
	unsigned int currentVisitors = 0;
	unsigned int currentWaiting = 0;
	std::ostream& output;
	int previousArrival = -1;


public:
	Bar(unsigned int capacity, unsigned int groupCapacity, std::ostream& output);
	void addStudent(const Student& student);
	void passStudents(int arrival);
	void finishSimulation();
};
