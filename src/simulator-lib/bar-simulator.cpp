#include "bar-simulator.h"
#include "Bar33.h"
#include "Student.h"


void simulate_bar(std::istream& input, std::ostream& output) {
    unsigned int capacity;
    unsigned int groupCapacity;
    unsigned int students;

    input >> capacity >> groupCapacity >> students;

    Bar bar(capacity, groupCapacity, output);

    unsigned int maxArrival = 0;


    for (size_t i = 0; i < students; i++) {
        Student student;
        input >> student;
        if (maxArrival > student.getArrival()) {
            throw incorrect_simulation("The time is not monotonic!");
        }
        maxArrival = student.getArrival();
        bar.addStudent(student);
    }

    bar.finishSimulation();

}
