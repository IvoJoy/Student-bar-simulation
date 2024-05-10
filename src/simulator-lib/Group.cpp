#include "Group.h"

void Group::addStudent(const Student& student) {
	list.push_back(student);
}

List<Student>::Iterator Group::begin() {
	return list.begin();
}

List<Student>::Iterator Group::end() {
	return list.end();
}

void Group::remove(List<Student>::Iterator it) {
	list.erase(it);
}

int Group::size() const {
	return list.size();
}

Major Group::getMajor() const {
	return major;
}