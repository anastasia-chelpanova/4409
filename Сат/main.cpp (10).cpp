#include <iostream>
#include <iomanip>
#include "header.h (10).h"

int main()
{
    int choice;
    double x, y, z;

    do
    {
        std::cout << "\n   MENU:\n";
        std::cout << "1. Vvesti x, y i proverit uravnenie\n";
        std::cout << "2. Proverka: 10 testov\n";
        std::cout << "3. Vihod\n";
        std::cout << "Vibor: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            enter_dannih(x, y);
            z = raschet(x, y);

            std::cout << std::fixed << std::setprecision(5);
            vivod_dannih(z);
            break;

        case 2:
            std::cout << "\n Testirovanie: \n";
            std::cout << std::fixed << std::setprecision(5);

            // TEST 1
            x = -2; y = 1;
            std::cout << "Test 1: x=-2, y=1\n";
            vivod_dannih(raschet(x,y));

            // TEST 2
            x = 0; y = 3;
            std::cout << "Test 2: x=0, y=3\n";
            vivod_dannih(raschet(x,y));

            // TEST 3
            x = 1; y = 2;
            std::cout << "Test 3: x=1, y=2\n";
            vivod_dannih(raschet(x,y));

            // TEST 4
            x = 2; y = -3;
            std::cout << "Test 4: x=2, y=-3\n";
            vivod_dannih(raschet(x,y));

            // TEST 5
            x = 2; y = 1;
            std::cout << "Test 5: x=2, y=1\n";
            vivod_dannih(raschet(x,y));

            // TEST 6
            x = 3; y = 1;
            std::cout << "Test 6: x=3, y=1\n";
            vivod_dannih(raschet(x,y));

            // TEST 7
            x = -1; y = -2;
            std::cout << "Test 7: x=-1, y=-2\n";
            vivod_dannih(raschet(x,y));

            // TEST 8
            x = 0.5; y = -1;
            std::cout << "Test 8: x=0.5, y=-1\n";
            vivod_dannih(raschet(x,y));

            // TEST 9
            x = 4; y = 2;
            std::cout << "Test 9: x=4, y=2\n";
            vivod_dannih(raschet(x,y));

            // TEST 10
            x = -3; y = 0.5;
            std::cout << "Test 10: x=-3, y=0.5\n";
            vivod_dannih(raschet(x,y));

            break;

        case 3:
            std::cout << "programma zavershena.\n";
            break;

        default:
            std::cout << "OSHIBKA! Viberite ot 1-3.\n";
        }

    } while (choice != 3);

    return 0;
}
