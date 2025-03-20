#include "Bus.h"
#include <nlohmann/json.hpp>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
using json = nlohmann::json;

int main()
{
    ifstream f("00.json");

    json data = json::parse(f);

    json init = data[0]["initial"];

    Bus bus;
    CPU cpu;

    cpu.ConnectBus(&bus);

    cpu.program_counter = init["pc"];
    cpu.stack_pointer = init["s"];
    cpu.accumulator = init["a"];
    cpu.x = init["x"];
    cpu.y = init["y"];
    cpu.status = init["p"];

    for (auto& ram : init["ram"]) {
        bus.write(ram[0], ram[1]);
    }

    json cycles = data[0]["cycles"];

    for (auto& cycle : cycles) {
        cpu.clock();

        string row = (string) cycle[2];

        if (!row.compare("read")) {
            int test = bus.read(cycle[0]);
        } else {
            bus.write(cycle[0], cycle[1]);
        }
    }

    json final = data[0]["final"];

    bool passed = true;

    for (auto& ram : final["ram"]) {
        if (bus.read(ram[0]) != ram[1]) {
            passed = false;
        }
    }

    cout << passed << '\n';

    if (cpu.program_counter != final["pc"] ||
        cpu.stack_pointer != final["s"] ||
        cpu.accumulator != final["a"] ||
        cpu.x != final["x"] ||
        cpu.y != final["y"] ||
        cpu.status != final["p"]) {
            cout << "PC: " << cpu.program_counter << " | " << final["pc"] << '\n';
            cout << "SP: " << (int) cpu.stack_pointer << " | " << final["s"] << '\n';
            cout << "A: " << (int) cpu.accumulator << " | " << final["a"] << '\n';
            cout << "X: " << (int) cpu.x << " | " << final["x"] << '\n';
            cout << "Y: " << (int) cpu.y << " | " << final["y"] << '\n';
            cout << "S: " << (int) cpu.y << " | " << final["p"] << '\n';
            passed = false;
    }

    cout << passed << '\n';

    if (passed) {
        cout << "Passed!\n";
    } else {
        cout << "Failed.\n";
    }
}
