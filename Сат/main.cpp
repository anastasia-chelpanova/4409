#include <iostream>
#include <cmath>
#include <iomanip>

double raschet(double x, double y)
{
    return (x*x-y*y+2*std::fabs(x*y))/(1+x*x+y*y);
}
int main()
{
    int choice;
    double x, y, z;

    {
        std::cout << "\n   MENU:\n";
        std::cout << "1. Vvesti x, y i proverit uravnenie\n";
        std::cout << "2. Proverka: 5 testov\n";
        std::cout << "3. Vihod\n";
        std::cout << "Vibor: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            std::cout << "enter x: ";
            std::cin >> x;
            std::cout << "enter y: ";
            std::cin >> y;

            z = raschet(x, y);

            std::cout << std::fixed << std::setprecision(5);
            std::cout << "result z = " << z << std::endl;
            break;

        case 2:
            std::cout << "\n testirovanie \n";

            // TEST 1
            x = 1; y = 1;
            std::cout << "Test 1: x=1, y=1\n";
            std::cout << "ruchnoi: z = 0.5\n";
            std::cout << "PC:      z = " << raschet(x, y) << "\n\n";

            // TEST 2
            x = 2; y = 1;
            std::cout << "Test 2: x=2, y=1\n";
            std::cout << "ruchnoi: z = 0.66667\n";
            std::cout << "PC:      z = " << raschet(x, y) << "\n\n";

            // TEST 3
            x = -1; y = 2;
            std::cout << "Test 3: x=-1, y=2\n";
            std::cout << "ruchnoi: z = 0.5\n";
            std::cout << "PC:      z = " << raschet(x, y) << "\n\n";

            // TEST 4
            x = 0; y = 3;
            std::cout << "Test 4: x=0, y=3\n";
            std::cout << "ruchnoi: z = -0.9\n";
            std::cout << "PC:      z = " << raschet(x, y) << "\n\n";

            // TEST 5
            x = 2; y = -2;
            std::cout << "Test 5: x=2, y=-2\n";
            std::cout << "ruchnoi: z = 0.5\n";
            std::cout << "PC:      z = " << raschet(x, y) << "\n";
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
