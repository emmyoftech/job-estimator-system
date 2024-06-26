#include <iostream>

using namespace std;

/*
* A class representing paints with property of paint name and price
* 
 */
class Paint {
    public:
        string paint_name;

    public:
        double paint_price;

        Paint(string name, double price) {
            paint_name = name;
            paint_price = price;
        }
};

/*
* Prototype for error handler 
*/
int throwError(string msg);

/*
* Prototype for app initialization
*/
int initApp();

/*
* A function to get the area of any given wall
*
 */
static double GetArea(double length, double height) {
    return length * height;
}

/*
* A function that validates the lengths passed to it
*
 */
static void lenghtCheck(double len) {
    if (len < 1 || len > 25) {
        throwError("Length of wall cannot be less than 1 or greater than 25");
    }
}

/*
* A function to get the area of all four walls
*
 */
static double GetWallsArea(int wallHeight) {

    cout << "\n";
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++";
    cout << " \n";


    cout << "Length of four walls (min: 1, max: 25) in meters\n";

    cout << " \n";

    double lenghtOfWall_1;

    cout << "Enter length of wall 1 \n";

    cin >> lenghtOfWall_1;

    lenghtCheck(lenghtOfWall_1);

    double lenghtOfWall_2;

    cout << "Enter length of wall 2 \n";

    cin >> lenghtOfWall_2;

    lenghtCheck(lenghtOfWall_2);

    double lenghtOfWall_3;

    cout << "Enter length of wall 3 \n";

    cin >> lenghtOfWall_3;

    lenghtCheck(lenghtOfWall_3);

    double lenghtOfWall_4;

    cout << "Enter length of wall 4 \n";

    cin >> lenghtOfWall_4;

    lenghtCheck(lenghtOfWall_4);

    return GetArea(lenghtOfWall_1, wallHeight) + GetArea(lenghtOfWall_2, wallHeight) + GetArea(lenghtOfWall_3, wallHeight) + GetArea(lenghtOfWall_4, wallHeight);
}

/*
* A function to get user selected paint price
*
 */
static double GetPaintPrice() {
   const int arraySize = 3;

    Paint paints[arraySize] = { Paint("Luxury quality", 2.75), Paint("Standard quality", 2.00), Paint("Economy quality", 0.55)};

    cout << "\n";
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++";
    cout << "\n";

    cout << "Choose paint quality: \n";

    for (int i = 0; i < arraySize; ++i) {
        Paint paint = paints[i];

        cout  << "Enter " << (i + 1) << " for " << paint.paint_name << " ($ " << paint.paint_price << "): \n";

        if (i < 2) {
            cout << "\n";
        }
    }

    int selectedPaint;

    cin >> selectedPaint;

    if (selectedPaint < 1 || selectedPaint > 3) return throwError("Wrong input: only numbers between (1) and (3) are allowed");

   return paints[selectedPaint - 1].paint_price;
}

/*
* A function to get the cost of the total tins entered
*
 */
static double GetUnderCoatCost(string name) {

    cout << "\n";
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++";
    cout << "\n";

    cout << name << ", would you like to use undercoat paint (price: $8.99 per tin): (Y / N) ";

    double coatCost = 0;

    double tinCostPerCoat = 8.99f;

    string ans;

    cin >> ans;

    if (ans == "Y" || ans == "y") {
        cout << "How many tins of paint would you be using?: ";

        double numOfTins;

        cin >> numOfTins;

        if (numOfTins < 1) {
            cout << "Error:: Number of tins cannot be less than 1 ";

            coatCost =  GetUnderCoatCost(name);
        }
        else {
            coatCost = numOfTins * tinCostPerCoat;
        }
    }
    
    return coatCost;
}

/*
* A error handler to prompt a message and restart process
*/
static int throwError(string msg) {
    system("cls"); // To clear terminal

    cout << "Error: " << msg << endl;
    cout << "\n" << endl;

    string value;

    cout << "Enter any key to restart app \n";

    cin >> value;

    system("cls"); // To clear terminal

    initApp();

    return 0;
}

/*
* A function to initiate job Estmator process
*/
static int Estimator() {

    cout << "\n";
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++";
    cout << "\n";

    cout << "Enter name: \n";

    string name;

    cin >> name;

    cout << "Enter estimate date: \n";

    string date;

    cin >> date;

    size_t found = date.find("-");

    if (found == string::npos) return throwError("Enter a correct date pattern using \'-\' as your seperator \n");

    int roomHeight;

    cout << "Enter height of the room (min: 2, max: 6) meters: \n";

    cin >> roomHeight;

    if (roomHeight < 2 || roomHeight > 6) return throwError("Room height cannot be less than 2 or greater than 6");

    double wallsArea = GetWallsArea(roomHeight);


    double panitPrice = GetPaintPrice();

    double totalAmontWithoutUnderCoat = wallsArea * panitPrice;

    double underCoatCost = GetUnderCoatCost(name);

    cout << "\n";
    cout << "++++++++++++++++++++++++++++++++++++++++++++++++++";
    cout << "\n";


    cout << "Estimate:: \n";
    cout << "\n";
    cout << "Customer Name: " << name << endl;
    cout << "\n";
    cout << "Estimate Date: " << date << endl;
    cout << "\n";
    cout << "Walls Area: " << wallsArea << "m" << endl;
    cout << "\n";
    cout << "Walls cost: " << "$" << totalAmontWithoutUnderCoat << endl;
    cout << "\n";
    cout << "UnderCoat Cost: " << "$" << underCoatCost << endl;
    cout << "+++++++++++++++++++++++++++++++++++\n";
    cout << "Grand Total: " << "$" << (totalAmontWithoutUnderCoat + underCoatCost) << endl;

    return 0;
}

/*
* A function to initiate help section
*/
static int Help() {
    cout << "Just fill in all the requird fields and you will get your estimate or visit: www.designsolutions.com" << endl;
    cout << "\n";

    cout << "Enter any key to go back \n";

    string bck;

    cin >> bck;

    system("cls"); // Clear the terminal

    initApp();

    return 0;
}

static int initApp()
{
    cout << "<< Welcome to Estimator >> \n";
    cout << "\n";
    cout << "MENU \n";
    cout << "\n";
    cout << "(1) >> Help\n";
    cout << "\n";
    cout << "(2) >> Job Estmator\n";
    cout << "\n";
    cout << "(3) >> Exit\n";
    cout << "\n";


    int stage;

    cin >> stage;

    if (stage == 1) {
        Help();

    }
    else if (stage == 2) {
        Estimator();

    }
    else if (stage == 3) {
        system("exit");
    }
    else {
        cout << "No menu option is associated with \"" << stage << "\" \n";

        system("exit");
    }

    return 0;
}

int main() {
    initApp();
}