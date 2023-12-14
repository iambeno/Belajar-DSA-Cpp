#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Deklarasi Struktur Data
struct Employee {
    string name;
    string position;
    string supervisor;
};

struct Shift {
    string time;
    vector<Employee> baristas;
    vector<Employee> waiters;
    vector<Employee> kitchenStewards;
    string supervisor;
};

// Fungsi-fungsi untuk Manajemen Kedai Kopi
void assignPersonnel(Shift& shift, const string& position, const vector<string>& personnel) {
    if (position == "Supervisor") {
        shift.supervisor = personnel[0];
    } else if (position == "Barista") {
        for (const auto& person : personnel) {
            Employee barista;
            barista.name = person;
            barista.position = position;
            barista.supervisor = shift.supervisor;
            shift.baristas.push_back(barista);
        }
    } else if (position == "Waiter") {
        for (const auto& person : personnel) {
            Employee waiter;
            waiter.name = person;
            waiter.position = position;
            waiter.supervisor = shift.supervisor;
            shift.waiters.push_back(waiter);
        }
    } else if (position == "Kitchen Steward") {
        for (const auto& person : personnel) {
            Employee kitchenSteward;
            kitchenSteward.name = person;
            kitchenSteward.position = position;
            kitchenSteward.supervisor = shift.supervisor;
            shift.kitchenStewards.push_back(kitchenSteward);
        }
    }
}

void displayShift(const Shift& shift) {
    cout << "Shift Time: " << shift.time << "\n";
    cout << "Supervisor: " << shift.supervisor << "\n";

    cout << "Baristas:\n";
    for (const auto& barista : shift.baristas) {
        cout << "  - " << barista.name << " (Supervised by: " << barista.supervisor << ")\n";
    }

    cout << "Waiters:\n";
    for (const auto& waiter : shift.waiters) {
        cout << "  - " << waiter.name << " (Supervised by: " << waiter.supervisor << ")\n";
    }

    cout << "Kitchen Stewards:\n";
    for (const auto& kitchenSteward : shift.kitchenStewards) {
        cout << "  - " << kitchenSteward.name << " (Supervised by: " << kitchenSteward.supervisor << ")\n";
    }

    cout << "\n";
}


int main() {
  system("cls");
    vector<Shift> schedule;

    // Menyusun Jadwal Shift
    Shift morningShift;
    morningShift.time = "Morning (7-11)";
    schedule.push_back(morningShift);

    Shift afternoonShift;
    afternoonShift.time = "Afternoon (11-15)";
    schedule.push_back(afternoonShift);

    Shift eveningShift;
    eveningShift.time = "Evening (16-19)";
    schedule.push_back(eveningShift);

    Shift nightShift;
    nightShift.time = "Night (20-22)";
    schedule.push_back(nightShift);

    // Mengatur Personel untuk Setiap Shift
    assignPersonnel(schedule[0], "Supervisor", {"Greg"});
    assignPersonnel(schedule[0], "Barista", {"John", "Jane", "Mark"});
    assignPersonnel(schedule[0], "Waiter", {"Susanne"});
    assignPersonnel(schedule[0], "Kitchen Steward", {"Ben"});

    assignPersonnel(schedule[1], "Supervisor", {"Jen"});
    assignPersonnel(schedule[1], "Barista", {"Rob", "Susan"});
    assignPersonnel(schedule[1], "Waiter", {"Alex", "George"});
    // Tidak ada Kitchen Steward untuk Shift Siang

    // Menampilkan Jadwal Shift dan Personel
    for (const auto& shift : schedule) {
        displayShift(shift);
    }

    return 0;
}
