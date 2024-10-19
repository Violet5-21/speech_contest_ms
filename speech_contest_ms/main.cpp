#include "Manager.h"

int main()
{
    srand(time(nullptr));
    Manager::show_menu();

    cout << "Please enter your choice: ";
    int choice;
    while (cin >> choice)
    {
        Manager manager;
        manager.load();
        switch (choice)
        {
            case 0:
                Manager::exit();
                break;
            case 1:
                manager.start_contest();
                break;
            case 2:
                manager.show();
                break;
            case 3:
                Manager::clear();
                break;
            default:
                cout << "Bad choice! \n";
                break;
        }
    }

    return 0;
}
