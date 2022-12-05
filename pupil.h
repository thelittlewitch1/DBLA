/*!
\file
\brief Заголовочный файл с описанием классов

Данный файл содержит в себе определения основных
классов: Pupil и List - используемых в программе
*/
#include <iostream>

#ifndef PUPIL_H
#define PUPIL_H

/*!
  \brief Класс для структуризации данных.

   \details В классе представлена информация о студенте, такая как имя, фамилия и 4 оценки, а так же функции для работы с этими данными. Дружественен классу List.
   Код выглядит следующим образом:
   \code
class Pupil
{
private:
    char Surname[20], Name[20];
     int Mark[4];
   Pupil *Next;

   Pupil ();
    void SetPupil(char* Surname, char* Name, int* Narks);
    void SetSurname ();
    void SetName ();
    void SetMarks ();
   char* GetSurname ();
   char* GetName ();
    int* GetMarks ();
    bool write(std::ostream& os);
    bool read (std::istream& is);

  friend class List;
};
   \endcode
   \author Петрухина Мария Сергеевна, группа 18-ПМ
   \date 2019г
*/
class Pupil
{
private:
    char Surname[20], Name[20];
     int Mark[4];
public:
   Pupil *Next;

   Pupil ();
    void SetPupil(char* Surname, char* Name, int* Narks);
    void SetSurname ();
    void SetName ();
    void SetMarks ();
   char* GetSurname ();
   char* GetName ();
    int* GetMarks ();
    bool write(std::ostream& os);
    bool read (std::istream& is);
};

#endif // PUPIL_H


#ifndef LIST_H
#define LIST_H

/*!
  \brief Класс представляющий из себя односвязный список.

   \details Данный класс содержит все методы, а так же указатель на голову списка и его длину. Дружественен классу Pupil.
   Код выглядит следующим образом:
   \code
class List
{
public:
    List (){lenght=0; Head=nullptr;}
    ~List ();                //Деструктор, удаление списка
    void Show ();            //Показать весь список
    void Change ();          //Изменить элемент
    void SortByName ();      //Сортировка по имени
    void SortByAS ();        //Сортировка по среднему баллу
    void Delete ();          //Удаление элемента
    void Upload ();          //Загрузка элемента из файла
    void Download ();        //Загрузка элемента в файл
    void Add();              //Добавление элемента в список

private:
    Pupil *Head;
    int lenght;
    Pupil* GetNth (int N);   //Найти Н-ный элемент
};
   \endcode
   \author Петрухина Мария Сергеевна, группа 18-ПМ
   \date 2019г
*/
class List: public Pupil
{
public:
    List (){lenght=0; Head=nullptr;}
    ~List ();                //Деструктор, удаление списка
    void Show ();            //Показать весь список
    void Change ();          //Изменить элемент
    void SortByName ();      //Сортировка по имени
    void SortByAS ();        //Сортировка по среднему баллу
    void Delete ();          //Удаление элемента
    void Upload ();          //Загрузка элемента из файла
    void Download ();        //Загрузка элемента в файл
    void Add();              //Добавление элемента в список

private:
    Pupil *Head;
    int lenght;
    Pupil* GetNth (int N);   //Найти Н-ный элемент
};

#endif // LIST_H
