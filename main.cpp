#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include "GeometryFigure.h"
#include "Vector2D.h"
#include "PhysObject.h"
#include "Printable.h"
#include "BaseObject.h"
#include "Circle.h"
#include "Rectangle.h"
#include "utils.h"
#include <map>
#include <unordered_map>

using namespace std;

vector<Rectangle> rectangles;
vector<Circle> circles;

void show(char *str) {
    cout << str << endl;
}

void showHelp() {
    show("exit - exitCommand");
    show("rect [x] [y] [a] [b] - add rectangle");
    show("circle [x] [y] [radius]- add circle");
    show("showall - show all");
    show("square- sum s");
    show("perimetr - sum p");
    show("memory - common memory");
    show("sort - sortCommand");
}


bool help(vector<string> args) {
    showHelp();
    return true;
}


bool exitCommand(vector<string> args) {
    exit(0);
    return true;
}

//x,y,a,b
bool addRectangle(vector<string> args) {
    Rectangle A(0, 0, 0, 0);
    A.initFromDialog(args);
    A.draw();
    rectangles.push_back(A);
    rectangles[rectangles.size() - 1].mass();
    return true;
}

bool addCircle(vector<string> args) {
    Circle A(0, 0, 0);
    A.initFromDialog(args);
    A.draw();
    circles.push_back(A);
    circles[circles.size() - 1].mass();
    return true;
}

bool showAll(vector<string> args) {
    cout << "amount: " << (rectangles.size() + circles.size()) << '\n';
    for (auto x : rectangles) {
        x.draw();
        cout << '\n';
    }

    for (auto x : circles) {
        x.draw();
        cout << '\n';
    }
    return true;
}

bool countSquare(vector<string> args) {
    double S = 0;
    for (auto x : rectangles)
        S += x.square();
    for (auto x : circles)
        S += x.square();
    cout << S << endl;
    return true;
}

bool countPerimeter(vector<string> args) {
    double P = 0;
    for (auto x : rectangles)
        P += x.perimeter();
    for (auto x : circles)
        P += x.perimeter();
    cout << P << endl;
    return true;
}

bool countMemory(vector<string> args) {
    double mem = 0;
    for (auto x : rectangles)
        mem += x.size();
    for (auto x : circles)
        mem += x.size();
    cout << mem << endl;
    return true;
}


bool sortCommand(vector<string> args) {
    sort(circles.begin(), circles.end(), utils::comparator_circle);
    sort(rectangles.begin(), rectangles.end(), utils::comparator_rectangle);
    for (auto x : rectangles)
        x.draw();
    for (auto x : circles)
        x.draw();
    return true;
}

bool tootoo(vector<string> args) {
    system("sl");
    return true;
}

std::unordered_map<string, function<bool(vector<string>)>> commandMap = {{"exit", exitCommand},
                                                                         {"rect", addRectangle},
                                                                         {"circle", addCircle},
                                                                         {"showall", showAll},
                                                                         {"square", countSquare},
                                                                         {"perimeter", countPerimeter},
                                                                         {"memory", countMemory},
                                                                         {"sort", sortCommand},
                                                                         {"wasdaspace", tootoo}};


int main() {
    showHelp();
    string current;
    while (true) {
        getline(std::cin, current);
        vector<std::string> splited = utils::split(current, ' ');
        string command = splited[0];
        function<bool(vector<string>)> &function = commandMap[command];
        if (function == nullptr) {
            show("Unknown command!");
            continue;
        }
        try {
            bool res = function(splited);
            if (!res) {
                show("Function finished with error!");
                std::exit(1);
            }
        } catch (std::exception &e) {
            std::cerr << "Exception caught : " << e.what() << std::endl;
            std::exit(2);
        }
    }
}