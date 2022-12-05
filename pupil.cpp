/*!
\file
\brief Исходный файл с реализацией функций

Данный файл содержит в себе реализации основных методов
классов: Pupil и List - используемых в программе.
*/

#include "pupil.h"
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <typeinfo>

using namespace std;

/*!
* \brief Конструктор класса Pupil.
*/
Pupil::Pupil()
{
    Mark[0] = 0; Mark[1] = 0; Mark[2] = 0; Mark[3] = 0;
    Next = nullptr;
}
/*!
* \brief Деструктор списка.
*/
List::~List()
{
    while (Head != nullptr)
     {
        Pupil *Elm = Head->Next;
        delete Head;
        Head = Elm;
     }
    std::cout<<"List was deleted. "<<std::endl;
}


/*!
*\brief Метод класса List, предоставляющий пользователю возможность изменить поля элемента.
*\details Метод запрашивает номер элемента, который нужно изменить, и
 что именно нужно изменить в нем, а потом просит ввести новую информацию.
*
*Код выглядит следующим образом:
*\code
*{
    int Slct;
    cout<<"You have chosen changing of element."<<endl<<"Please, look at least of pupils:"<<endl;
    Show();
    int num;
    cout<<"And enter number of pupil you want to change: "<<endl<<"> ";
    cin >> num;
    Pupil *Elm = GetNth(num);
    if (Elm == nullptr) {return;}
    cout<<"Please, select what you want to change and enter appropriate number: "<<endl<<"0 - Exit;"<<\
          endl<<"1 - Surname;"<<endl<<"2 - Name;"<<endl<<"3 - Marks;"<<endl<<"4 - all informarion;"<<endl<<"> ";
    cin >> Slct;
    cout << endl;
    switch (Slct){
     case 0:
        return;
     case 1:
        Elm->SetSurname();
        break;
     case 2:
        Elm->SetName();
        break;
     case 3:
        Elm->SetMarks();
        break;
     case 4:
        Elm->SetSurname();
        Elm->SetName();
        Elm->SetMarks();
        break;
    default:
        cout<<"Something went wrong. No command with this number. Please, try again."<<endl;
        return;
    }
    cout<<endl;
}
*\endcode
*\author Петрухина Мария Сергеевна, группа 18-ПМ.
*\date 2019г.
*/
void List::Change()
{
    int Slct;
    cout<<"You have chosen changing of element."<<endl<<"Please, look at least of pupils:"<<endl;
    Show();
    int num;
    cout<<"And enter number of pupil you want to change: "<<endl<<"> ";
    cin >> num;
    Pupil *Elm = GetNth(num);
    if (Elm == nullptr) {return;}
    cout<<"Please, select what you want to change and enter appropriate number: "<<endl<<"0 - Exit;"<<\
          endl<<"1 - Surname;"<<endl<<"2 - Name;"<<endl<<"3 - Marks;"<<endl<<"4 - all informarion;"<<endl<<"> ";
    cin >> Slct;
    cout << endl;
    switch (Slct){
     case 0:
        return;
     case 1:
        Elm->SetSurname();
        break;
     case 2:
        Elm->SetName();
        break;
     case 3:
        Elm->SetMarks();
        break;
     case 4: 
        Elm->SetSurname();
        Elm->SetName();
        Elm->SetMarks();
        break;
    default:
        cout<<"Something went wrong. No command with this number. Please, try again."<<endl;
        return;
    }
    cout<<endl;
}

/*!
*\brief Метод класса List, предоставляющий пользователю возможность добавить один или несколько элементов в конец списка.
*\details Метод запрашивает количество новых элементов и информацию для каждого нового элемента.
*
*Код выглядит следующим образом:
*\code
*{
    int num;
    cout<<"You have chosen adding of elements."<<endl<<"Please, enter number of new pupil:"<<endl<<"> ";
    cin>>num;
    if (num < 0)
    {
        cout<<"Something went wrong."<<endl;
        return;
    }
    for (int i=0; i<num; i++)
    {
        Pupil *Elm = new Pupil;
        Elm->SetSurname();
        Elm->SetName();
        Elm->SetMarks();
        lenght++;
        Elm->Next = Head;
        Head = Elm;
    }
}
*\endcode
*\author Петрухина Мария Сергеевна, группа 18-ПМ.
*\date 2019г.
*/
void List::Add()
{
    int num;
    cout<<"You have chosen adding of elements."<<endl<<"Please, enter number of new pupil:"<<endl<<"> ";
    cin>>num;
    if (num < 0)
    {
        cout<<"Something went wrong."<<endl;
        return;
    }
    for (int i=0; i<num; i++)
    {
        Pupil *Elm = new Pupil;
        Elm->SetSurname();
        Elm->SetName();
        Elm->SetMarks();
        lenght++;
        Elm->Next = Head;
        Head = Elm;
    }
}

/*!
*\brief Метод класса List, выводящий на экран содержимое списка.
*
*Код выглядит следующим образом:
*\code
*{
 Pupil *Elm=Head;
 int num=1;
 cout<<"Form of list: Surname, Name, two math marks and two informatic marks."<<endl<<"List of pupils: "<<endl;
 while (Elm != nullptr)
 {
  cout<<num<<". "<<Elm->GetSurname()<<" "<<Elm->GetName()<<", "<<Elm->GetMarks()[0]<<", "<<Elm->GetMarks()[1]<<\
        ", "<<Elm->GetMarks()[2]<<", "<<Elm->GetMarks()[3]<<";"<<endl;
  Elm = Elm->Next;
  num++;
 }
}
*\endcode
*\author Петрухина Мария Сергеевна, группа 18-ПМ.
*\date 2019г.
*/
void List::Show()
{
 Pupil *Elm=Head;
 int num=1;
 cout<<"Form of list: Surname, Name, two math marks and two informatic marks."<<endl<<"List of pupils: "<<endl;
 while (Elm != nullptr)
 {
  cout<<num<<". "<<Elm->GetSurname()<<" "<<Elm->GetName()<<", "<<Elm->GetMarks()[0]<<", "<<Elm->GetMarks()[1]<<\
        ", "<<Elm->GetMarks()[2]<<", "<<Elm->GetMarks()[3]<<";"<<endl;
  Elm = Elm->Next;
  num++;
 }
}

/*!
*\brief Метод класса List, удаляющий выбранный элемент списка.
*\details Метод запрашивает номер элемента, который нужно удаляет, и удаляет его.
*
*Код выглядит следующим образом:
*\code
*{
    cout<<"You have chosen deleting of element. "<<endl<<"Please, look at least of pupils."<<endl;
    Show();
    int num;
    cout<<"And enter number of pupil you want to delete: "<<endl<<"> ";
    cin >> num;
    Pupil *Elm = GetNth(num);
    if (Elm == nullptr) {return;}
    if (num==1)
    {
        Head = Elm->Next;
        delete Elm;
    }
    else
    {
        Pupil *Prev = GetNth(num-1);
        Prev->Next = Elm->Next;
        delete Elm;
    }
    cout<<"Pupil number "<<num<<" have deleted from the list."<<endl;
}
*\endcode
*\author Петрухина Мария Сергеевна, группа 18-ПМ.
*\date 2019г.
*/
void List::Delete ()
{
    cout<<"You have chosen deleting of element. "<<endl<<"Please, look at least of pupils."<<endl;
    Show();
    int num;
    cout<<"And enter number of pupil you want to delete: "<<endl<<"> ";
    cin >> num;
    Pupil *Elm = GetNth(num);
    if (Elm == nullptr) {return;}
    if (num==1)
    {
        Head = Elm->Next;
        delete Elm;
    }
    else
    {
        Pupil *Prev = GetNth(num-1);
        Prev->Next = Elm->Next;
        delete Elm;
    }
    cout<<"Pupil number "<<num<<" have deleted from the list."<<endl;
}


/*!
*\brief Метод класса List, сортирующий список по содержимому полей Surname и Name класса Pupil.
*\details Склеивает Surname и Name текущего элемента и соседнего с ним элемента в одну строку, сравнивает их и, если они идут в неправильном порядке, то меняет их местами.
*
*Код выглядит следующим образом:
*\code
*{
    cout<<"You have chosen sorting of list."<<endl;
    Pupil* ptr = Head, *tmp = nullptr, *prev = nullptr;
    bool flag = false;
    if(Head)
    {
        do
        {
            flag = false;
            ptr = Head;
            while(ptr->Next)
            {
                char *str1 = new char[41], *str2 = new char[41];
                strcat (str1, ptr->GetSurname());
                strcat (str1, " ");
                strcat (str1, ptr->GetName());
                strcat (str2, ptr->Next->GetSurname());
                strcat (str2, " ");
                strcat (str2, ptr->Next->GetName());
                if(stricmp(str1, str2) > 0)
                {
                    if(ptr == Head)
                    {
                        tmp = ptr;
                        ptr = tmp->Next;
                        tmp->Next = ptr->Next;
                        ptr->Next = tmp;
                        Head = ptr;
                        flag = true;
                    }
                    else
                    {
                        tmp = ptr;
                        ptr = tmp->Next;
                        tmp->Next = ptr->Next;
                        ptr->Next = tmp;
                        prev->Next = ptr;
                        flag = true;
                    }
                }
                prev = ptr;
                ptr = ptr->Next;
                delete [] str1;
                delete [] str2;
            }
        }
        while(flag);
        cout<<"List was sorted. "<<endl;
    }
    else
        cout<<"List is empty. List cannot be sorted."<<endl;
    cout<<endl;
}
*\endcode
*\author Петрухина Мария Сергеевна, группа 18-ПМ.
*\date 2019г.
*/
void List::SortByName()
{
    cout<<"You have chosen sorting of list."<<endl;
    Pupil* ptr = Head, *tmp = nullptr, *prev = nullptr;
    bool flag = false;
    if(Head)
    {
        do
        {
            flag = false;
            ptr = Head;
            while(ptr->Next)
            {
                char *str1 = new char[41], *str2 = new char[41];
                strcat (str1, ptr->GetSurname());
                strcat (str1, " ");
                strcat (str1, ptr->GetName());
                strcat (str2, ptr->Next->GetSurname());
                strcat (str2, " ");
                strcat (str2, ptr->Next->GetName());
                if(stricmp(str1, str2) > 0)
                {
                    if(ptr == Head)
                    {
                        tmp = ptr;
                        ptr = tmp->Next;
                        tmp->Next = ptr->Next;
                        ptr->Next = tmp;
                        Head = ptr;
                        flag = true;
                    }
                    else
                    {
                        tmp = ptr;
                        ptr = tmp->Next;
                        tmp->Next = ptr->Next;
                        ptr->Next = tmp;
                        prev->Next = ptr;
                        flag = true;
                    }
                }
                prev = ptr;
                ptr = ptr->Next;
                delete [] str1;
                delete [] str2;
            }
        }
        while(flag);
        cout<<"List was sorted. "<<endl;
    }
    else
        cout<<"List is empty. List cannot be sorted."<<endl;
    cout<<endl;
}
/*!
*\brief Метод класса List, сортирующий список по среднему значению массива Mark.
*\details Находит среднее значение текущего элемента и соседнего с ним элемента, сравнивает их и, если они идут в неправильном порядке, то меняет их местами.
*
*Код выглядит следующим образом:
*\code
*{
    cout<<"You have chosen sorting of list by average score. Pupil with the highest value will in the begining. "<<endl;
    Pupil* ptr = Head, *tmp = nullptr, *prev = nullptr;
    bool flag = false;
    float AS1 = 0.0, AS2 = 0.0;
    if(Head)
    {
        do
        {
            flag = false;
            ptr = Head;
            while(ptr->Next)
            {
                AS1=(ptr->GetMarks()[0]+ptr->GetMarks()[1]+ptr->GetMarks()[2]+ptr->GetMarks()[3])/4;
                AS2=(ptr->Next->GetMarks()[0]+ptr->Next->GetMarks()[1]+ptr->Next->GetMarks()[2]+ptr->Next->GetMarks()[3])/4;
                if(AS1<AS2)
                {
                    if(ptr == Head)
                    {
                        tmp = ptr;
                        ptr = tmp->Next;
                        tmp->Next = ptr->Next;
                        ptr->Next = tmp;
                        Head = ptr;
                        flag = true;
                    }
                    else
                    {
                        tmp = ptr;
                        ptr = tmp->Next;
                        tmp->Next = ptr->Next;
                        ptr->Next = tmp;
                        prev->Next = ptr;
                        flag = true;
                    }
                }
                prev = ptr;
                ptr = ptr->Next;
            }
        }
        while(flag);
        cout<<"List was sorted. "<<endl;
    }
    else
        cout<<"List is empty. List cannot be sorted."<<endl;
    cout<<endl;
}
*\endcode
*\author Петрухина Мария Сергеевна, группа 18-ПМ.
*\date 2019г.
*/
void List::SortByAS()
{
    cout<<"You have chosen sorting of list by average score. Pupil with the highest value will in the begining. "<<endl;
    Pupil* ptr = Head, *tmp = nullptr, *prev = nullptr;
    bool flag = false;
    float AS1 = 0.0, AS2 = 0.0;
    if(Head)
    {
        do
        {
            flag = false;
            ptr = Head;
            while(ptr->Next)
            {
                AS1=(ptr->GetMarks()[0]+ptr->GetMarks()[1]+ptr->GetMarks()[2]+ptr->GetMarks()[3])/4;
                AS2=(ptr->Next->GetMarks()[0]+ptr->Next->GetMarks()[1]+ptr->Next->GetMarks()[2]+ptr->Next->GetMarks()[3])/4;
                if(AS1<AS2)
                {
                    if(ptr == Head)
                    {
                        tmp = ptr;
                        ptr = tmp->Next;
                        tmp->Next = ptr->Next;
                        ptr->Next = tmp;
                        Head = ptr;
                        flag = true;
                    }
                    else
                    {
                        tmp = ptr;
                        ptr = tmp->Next;
                        tmp->Next = ptr->Next;
                        ptr->Next = tmp;
                        prev->Next = ptr;
                        flag = true;
                    }
                }
                prev = ptr;
                ptr = ptr->Next;
            }
        }
        while(flag);
        cout<<"List was sorted. "<<endl;
    }
    else
        cout<<"List is empty. List cannot be sorted."<<endl;
    cout<<endl;
}


/*!
*\brief Метод класса List, загружающий список из файла.
 *\details Метод открывает файл на чтение в формате бинарного и создает новые элементы в списке.
 *
 *Код выглядит следующим образом:
 *\code
 *{
    cout<<"You have chosen uploading of list from the file."<<std::endl;
    ifstream fin;
    fin.open("C:\\Prog\\build-DBLA1-Desktop_Qt_5_12_3_MinGW_64_bit-Debug\\Pupils.bin", ios_base::binary | ios_base::in);
    if (!fin.is_open())
            {
                cout<<"The file cannot be open"<<endl;
                exit (-1);
            }
    while (!fin.eof())
        {
            Pupil *Elm = new Pupil;
            Elm->read(fin);
            if(fin.eof())
            {
                delete Elm;
                break;
            }
            lenght++;
            Elm->Next = Head;
            Head = Elm;
        }
    cout<<"List have uploaded from the file."<<endl;
    Show();
    fin.close();
}
 *\endcode
 *\author Петрухина Мария Сергеевна, группа 18-ПМ.
 *\date 2019г.
*/
void List::Upload()
{
    cout<<"You have chosen uploading of list from the file."<<std::endl;
    ifstream fin;
    fin.open("Pupils.bin", ios_base::binary | ios_base::in);
    if (!fin.is_open())
            {
                cout<<"The file cannot be open"<<endl;
                exit (-1);
            }
    while (!fin.eof())
        {
            Pupil *Elm = new Pupil;
            Elm->read(fin);
            if(fin.eof())
            {
                delete Elm;
                break;
            }
            lenght++;
            Elm->Next = Head;
            Head = Elm;
        }
    cout<<"List have uploaded from the file."<<endl;
    Show();
    fin.close();
}
/*!
*\brief Метод класса List, загружающий список в файл.
 *\details Метод открывает файл на запись в формате бинарного и загружает каждый элемент файл.
 *
 *Код выглядит следующим образом:
 *\code
 *{
    cout<<"You have chosen downloading of list into the file."<<endl;
    ofstream fout;
    string FName = "C:\\Prog\\build-DBLA1-Desktop_Qt_5_12_3_MinGW_64_bit-Debug\\Pupils.bin";
    fout.open(FName, ios_base::binary | ios_base::out);
    if (!fout.is_open())
            {
                cout<<"The file cannot be open"<<endl;
                return;
            }
    Pupil *Elm=Head;
    while (Elm)
    {
        Elm->write(fout);
        Elm = Elm->Next;
    }
    fout.close();
    cout<<"List have downloaded into the file."<<endl;
}
 *\endcode
 *\author Петрухина Мария Сергеевна, группа 18-ПМ.
 *\date 2019г.
*/
void List::Download()
{
    cout<<"You have chosen downloading of list into the file."<<endl;
    ofstream fout;
    string FName = "Pupils.bin";
    fout.open(FName, ios_base::binary | ios_base::out);
    if (!fout.is_open())
            {
                cout<<"The file cannot be open"<<endl;
                return;
            }
    Pupil *Elm=Head;
    while (Elm)
    {
        Elm->write(fout);
        Elm = Elm->Next;
    }
    fout.close();
    cout<<"List have downloaded into the file."<<endl;
}


/*!
*\brief Вспомогательный метод класса List, находящий элемент в списке по его номеру.
 *
 *Код выглядит следующим образом:
 *\code
 *{
    if ((N<1) && (N>lenght))
    {
        cout<<"Something went wrong. No pupil with this number."<<endl;
        return nullptr;
    }
    int counter = 1;
    //N = lenght - N + 1;
    Pupil *Elm = Head;
    while ((counter < N) && (Elm))
    {
        Elm = Elm->Next;
        counter++;
    }
    return Elm;
}
 *\endcode
 *\param N Номер искомого элемента.
 *\return Указатель на элемент под номером N
 *\author Петрухина Мария Сергеевна, группа 18-ПМ.
 *\date 2019г.
*/
Pupil* List::GetNth (int N)
{
    if ((N<1) && (N>lenght))
    {
        cout<<"Something went wrong. No pupil with this number."<<endl;
        return nullptr;
    }
    int counter = 1;
    //N = lenght - N + 1;
    Pupil *Elm = Head;
    while ((counter < N) && (Elm))
    {
        Elm = Elm->Next;
        counter++;
    }
    return Elm;
}

/*!
*\brief Метод класса Pupil, изменяющий поля элемента.
 *
 *Код выглядит следующим образом:
 *\code
 *{
    if (strlen(Surname)<20) {strcpy (this->Surname, Surname);}
                 else {
                    cout<<"Something went wrong. We cannot keep Surname longer that 20 chars. Sorry."<<endl;
                    return;
                      }
    if (strlen(Name)<20) {strcpy (this->Name, Name);}
                 else {
                    cout<<"Something went wrong. We cannot keep Name longer that 20 chars. Sorry."<<endl;
                    return;
                      }
    for (int i=0;i<4;i++)
    {
        this->Mark[i]=Marks[i];
    }
}
 *\endcode
 *\param Surname строка, содержащая фамилию.
 *\param Name строка, содержащая имя.
 *\param Marks[4] массив целых чисел, содержащий оценки.
 *\author Петрухина Мария Сергеевна, группа 18-ПМ.
 *\date 2019г.
*/
void Pupil::SetPupil(char* Surname, char* Name, int Marks[4])
{
    if (strlen(Surname)<20) {strcpy (this->Surname, Surname);}
                 else {
                    cout<<"Something went wrong. We cannot keep Surname longer that 20 chars. Sorry."<<endl;
                    return;
                      }
    if (strlen(Name)<20) {strcpy (this->Name, Name);}
                 else {
                    cout<<"Something went wrong. We cannot keep Name longer that 20 chars. Sorry."<<endl;
                    return;
                      }
    for (int i=0;i<4;i++)
    {
        this->Mark[i]=Marks[i];
    }
}

/*!
*\brief Метод класса Pupil, изменяющий поле Surname.
 *\details Метод просит на ввод строку, проверяет её на соответствию формату и, если соответствует, то копирует в поле Surname.
 *
 *Код выглядит следующим образом:
 *\code
 *{
    char str[20];
    cout<<"Enter pupil's surname:"<<endl<<"> ";
    cin>>str;
    if (strlen(str)<20) {strcpy (this->Surname, str);}
                 else {
                    cout<<"Something went wrong. We cannot keep Surname longer that 20 chars. Sorry."<<endl;
                    return;
                      }
}
 *\endcode
 *\author Петрухина Мария Сергеевна, группа 18-ПМ.
 *\date 2019г.
*/
void Pupil::SetSurname ()
{
    char str[20];
    cout<<"Enter pupil's surname:"<<endl<<"> ";
    cin>>str;
    if (strlen(str)<20) {strcpy (this->Surname, str);}
                 else {
                    cout<<"Something went wrong. We cannot keep Surname longer that 20 chars. Sorry."<<endl;
                    return;
                      }
}
/*!
*\brief Метод класса Pupil, изменяющий поле Name.
 *\details Метод просит на ввод строку, проверяет её на соответствию формату и, если соответствует, то копирует в поле Name.
 *
 *Код выглядит следующим образом:
 *\code
 *
 *\endcode
 *\author Петрухина Мария Сергеевна, группа 18-ПМ.
 *\date 2019г.
*/
void Pupil::SetName ()
{
    char str[20];
    cout<<"Enter pupil's name:"<<endl<<"> ";
    cin>>str;
    if (strlen(str)<20) {strcpy (this->Name, str);}
                 else {
                    cout<<"Something went wrong. We cannot keep Name longer that 20 chars. Sorry."<<endl;
                    return;
                      }
}
/*!
*\brief Метод класса Pupil, изменяющий поле Mark.
 *\details Метод просит ввести 4 числа и сохраняет их в поле Mark.
 *
 *Код выглядит следующим образом:
 *\code
 *{
    cout<<"Please, enter four the pupil's marks (two math marks and two informatic marks): "<<endl<<"> ";
    cin>>this->Mark[0]>>this->Mark[1]>>this->Mark[2]>>this->Mark[3];
}
 *\endcode
 *\author Петрухина Мария Сергеевна, группа 18-ПМ.
 *\date 2019г.
*/
void Pupil::SetMarks ()
{
    cout<<"Please, enter four the pupil's marks (two math marks and two informatic marks): "<<endl<<"> ";
    cin>>this->Mark[0]>>this->Mark[1]>>this->Mark[2]>>this->Mark[3];
}

/*!
*\brief Метод класса Pupil, возвращающий содержимое поля Surname.
 *
 *Код выглядит следующим образом:
 *\code
 *{return this->Surname;}
 *\endcode
 *\return содержимое информационного поля "Surname".
 *\author Петрухина Мария Сергеевна, группа 18-ПМ.
 *\date 2019г.
*/
char* Pupil::GetSurname () {return this->Surname;}
/*!
*\brief Метод класса Pupil, возвращающий содержимое поля Name.
 *
 *Код выглядит следующим образом:
 *\code
 *{return this->Name;}
 *\endcode
 *\return содержимое информационного поля "Name".
 *\author Петрухина Мария Сергеевна, группа 18-ПМ.
 *\date 2019г.
*/
char* Pupil::GetName () {return this->Name;}
/*!
*\brief Метод класса Pupil, возвращающий содержимое поля Mark.
 *
 *Код выглядит следующим образом:
 *\code
 *{return this->Mark;}
 *\endcode
 *\return содержимое информационного поля "Mark".
 *\author Петрухина Мария Сергеевна, группа 18-ПМ.
 *\date 2019г.
*/
int* Pupil::GetMarks () {return this->Mark;}


/*!
*\brief Метод класса Pupil, упрощающий запись в файл.
 *
 *Код выглядит следующим образом:
 *\code
 *{
      os.write((reinterpret_cast<char *>(this)), sizeof(Pupil));
      return os.good();
}
 *\endcode
 *\return false если произошла какая-либо ошибка и true в ином случае.
 *\author Петрухина Мария Сергеевна, группа 18-ПМ.
 *\date 2019г.
*/
bool Pupil::write(ostream& os)
{
      os.write((reinterpret_cast<char *>(this)), sizeof(Pupil));
      return os.good();
}
/*!
*\brief Метод класса Pupil, упрощающий чтение из файла.
 *
 *Код выглядит следующим образом:
 *\code
 *{
    is.read((reinterpret_cast<char *>(this)), sizeof(Pupil));
    return is.good();
}
 *\endcode
 *\return false если произошла какая-либо ошибка и true в ином случае.
 *\author Петрухина Мария Сергеевна, группа 18-ПМ.
 *\date 2019г.
*/
bool Pupil::read (istream& is)
{
    is.read((reinterpret_cast<char *>(this)), sizeof(Pupil));
    return is.good();
}
