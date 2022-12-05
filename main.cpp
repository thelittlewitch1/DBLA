/*!
*\file
*\brief Исходный файл с реализацией меню

*\details Данный файл содержит в себе реализацию
простого меню, так же вызываются многие
методы классов.
*/

#include <QCoreApplication>
#include <iostream>
#include "pupil.h"
#include <fstream>

using namespace std;

/*!
 * \brief Функция main()
 *
 * Функция-меню.
 *
 * Код выглядит следующим образом:
 * \code
    cout<<"Wellcome to Data Base: 'Lerning Achivment'!"<<endl;
    int Slct;
    List list;
    while (1)
    {
        cout<<endl<<"Please, select what you want to do and enter appropriate number:"<<endl<<"0 - Exit;"<<endl<<\
            "1 - Load from the file;"<<endl<<"2 - Add an element or elements;"<<endl<<"3 - Delete an element;"<<endl<<\
            "4 - Change an element;"<<endl<<"5 - Sort by name;"<<endl<<"6 - Sort by average score;"<<endl<<"7 - Print elements;"<<\
            endl<<"8 - Save into the file."<<endl<<"9 - Clean the Base"<< endl << "> ";
        cin >> Slct;
        cout << endl;
        switch (Slct){
         case 0:
            cout<<"Thank you for using Data Base: 'Lerning Achivment'!"<<endl;
            return 0;
         case 1:
                 list.Upload();
                 break;
         case 2:
                 list.Add();
                 break;
         case 3:
                 list.Delete();
                 break;
         case 4:
                 list.Change();
                 break;
         case 5:
                 list.SortByName();
                 break;
        case 6:
                 list.SortByAS();
                 break;
        case 7:
                 list.Show();
                 break;
         case 8:
                 list.Download();
                 break;
         case 9:
                 delete &list;
                 break;
         default:
                 cout<<"Something went wrong. No command with this number. Please, try again."<<endl;
                 break;
 * \endcode
 * \return 0 -При удачном завершении программы.
 */
int main()
{
    cout<<"Wellcome to Data Base: 'Lerning Achivment'!"<<endl;
    int Slct;
    List list;
    while (1)
    {
        cout<<endl<<"Please, select what you want to do and enter appropriate number:"<<endl<<"0 - Exit;"<<endl<<\
            "1 - Load from the file;"<<endl<<"2 - Add an element or elements;"<<endl<<"3 - Delete an element;"<<endl<<\
            "4 - Change an element;"<<endl<<"5 - Sort by name;"<<endl<<"6 - Sort by average score;"<<endl<<"7 - Print elements;"<<\
            endl<<"8 - Save into the file."<<endl<< "> ";
        cin >> Slct;
        cout << endl;
        switch (Slct){
         case 0:
            cout<<"Thank you for using Data Base: 'Lerning Achivment'!"<<endl;
            return 0;
         case 1:
                 list.Upload();
                 break;
         case 2:
                 list.Add();
                 break;
         case 3:
                 list.Delete();
                 break;
         case 4:
                 list.Change();
                 break;
         case 5:
                 list.SortByName();
                 break;
        case 6:
                 list.SortByAS();
                 break;
        case 7:
                 list.Show();
                 break;
         case 8:
                 list.Download();
                 break;
         default:
                 cout<<"Something went wrong. No command with this number. Please, try again."<<endl;
                 break;
        }
    }
}
