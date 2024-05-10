#pragma once
#include "List.hpp"
#include "Student.h"

class Group {
	List<Student> list;
	Major major;

public:
	Group() {}

	Group(Major major) : major(major) {}

	void addStudent(const Student& student);

	List<Student>::Iterator begin();

	List<Student>::Iterator end();

	void remove(List<Student>::Iterator it);

	int size() const;

	Major getMajor() const;
};