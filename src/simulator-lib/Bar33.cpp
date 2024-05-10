#include "Bar33.h"
#include "List.hpp"
#include "Student.h"
#include "Group.h"

Bar::Bar(unsigned int capacity, unsigned int groupCapacity, std::ostream& output) : capacity(capacity), groupCapacity(groupCapacity), output(output) {}

void Bar::finishSimulation() {
	passStudents(previousArrival);

	while (inside.size() != 0) {
		int min = inside.begin()->departure();
		while (!inside.empty() && inside.begin()->departure() == min) {
			output << inside.begin()->departure() << ' ' << inside.begin()->getFN() << ' ' << "exit" << std::endl;
			inside.erase(inside.begin());
		}

		passStudents(min);
	}

	if (groups.size() > 0) {
		throw incorrect_simulation("There are people still waiting outside!");
	}
	
}

void Bar::passStudents(int arrival) {
	List<Group>::Iterator it = groups.begin();

	while (it != groups.end()) {
		if (it->size() <= capacity - inside.size()) {
			groupPtrs[it->getMajor()] = nullptr;

			while(it->begin() != it->end()) {
				output << arrival << ' ' << it->begin()->getFN() << ' ' << "enter" << std::endl;

				it->begin()->setArrival(arrival);

				if (inside.empty()) {
	
					inside.push_back(*it->begin());
				}
				else {
					
					if (it->begin()->departure() < inside.begin()->departure()) {
						inside.push_front(*it->begin());
					}
					else {
						bool flag = true;

						for (List<Student>::Iterator itInside = inside.begin(); itInside != inside.end(); ++itInside) {
							
							if (it->begin()->departure() < itInside->departure()) {
								inside.insert(itInside, *(it->begin()));
								flag = false;
								break;
							}
						}
						if (flag) {
							inside.push_back(*it->begin());
						}
					}
				}

				it->remove(it->begin());
			}

			groups.erase(it);
			it = groups.begin();
		}
		else {
			++it;
		}
	}

	
	
}

void Bar::addStudent(const Student& student) {
	if (previousArrival != -1 && student.getArrival() > previousArrival) {
		passStudents(previousArrival);
	}

	while (!inside.empty() && inside.begin()->departure() <= student.getArrival() ) {
		output << inside.begin()->departure() << ' ' << inside.begin()->getFN() << ' ' << "exit" << std::endl;
		inside.erase(inside.begin());
	}

	Group* group = nullptr;
	
	group = groupPtrs[student.getMajor()];

	if (group == nullptr || group->size() >= groupCapacity) {
		groups.push_back(Group(student.getMajor()));
		groupPtrs[student.getMajor()] = &*(--groups.end());

		group = groupPtrs[student.getMajor()];
	}
	
	

		

	group->addStudent(student);

	if (previousArrival != -1 && student.getArrival() > previousArrival) {
		passStudents(student.getArrival());
	}

	previousArrival = student.getArrival();

	
}