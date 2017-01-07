#include <iostream>
#include<windows.h>
#include<math.h>
#include<string.h>

using namespace std;

void ClearScreen()
{
    HANDLE                                   hStdOut;
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    DWORD                                    count;
    DWORD                                    cellCount;
    COORD                                    homeCoords = { 0, 0 };
    hStdOut = GetStdHandle( STD_OUTPUT_HANDLE );
    if (hStdOut == INVALID_HANDLE_VALUE) return;
/* Obține numărul de celule din buffer-ul curent */
    if (!GetConsoleScreenBufferInfo( hStdOut, &csbi )) return;
    cellCount = csbi.dwSize.X *csbi.dwSize.Y;
/* Umple întregul buffer cu spații */
    if (!FillConsoleOutputCharacter(
    hStdOut,
    (TCHAR) ' ',
    cellCount,
    homeCoords,
        &count
    )) return;
/* Umple întregul buffer cu culorile curente și atributele */
    if (!FillConsoleOutputAttribute(
    hStdOut,
    csbi.wAttributes,
    cellCount,
    homeCoords,
    &count
    )) return;
/* Muta cursorul acasă */
    SetConsoleCursorPosition( hStdOut, homeCoords );
}

void meniu()
{
    cout<< "Selectati o marime fizica de mai jos:"<<endl;
    cout<<"1. Lungime"<<endl;
    cout<<"2. Arie"<<endl;
    cout<<"3. Volum"<<endl;
    cout<<"4. Timp"<<endl;
    cout<<"5. Viteza"<<endl;
    cout<<"6. Temperatura"<<endl;
    cout<<"7. Masa"<<endl;
    cout<<"8. Energie"<<endl;
    cout<<"9. Presiune"<<endl;
    cout<<"10. Densitate"<<endl;
    cout<<"11. Consum combustibil"<<endl;
    int inputMeniu;
    cin>>inputMeniu;
    if(inputMeniu>11 || inputMeniu<1) { cout<<"Ati tastat gresit. Pentru a incerca din nou apasati tasta Enter"<<endl;
                                        system("pause");
                                        ClearScreen();
                                        meniu();
                                        }
    ClearScreen();
}

void UnitatiLungime()
{
    cout<<"1. mm"<<endl;
    cout<<"2. cm"<<endl;
    cout<<"3. dm"<<endl;
    cout<<"4. m"<<endl;
    cout<<"5. dam"<<endl;
    cout<<"6. hm"<<endl;
    cout<<"7. km"<<endl;
    cout<<"8. in"<<endl;
    cout<<"9. ft"<<endl;
    cout<<"10. yd"<<endl;
}

void Lungime()
{
    cout<<"Selectati unitatea de masura din care doriti sa transformati"<<endl;
    cout<<"0. Inapoi la meniu"<<endl;
    UnitatiLungime();
    int dinCe;
    cin>>dinCe;
    if (dinCe==0){ClearScreen();
                   meniu();}
    cout<<"Scrieti valoarea:";
    double initial;
    cin>>initial;
    int copieinitial=initial;
    ClearScreen();

    /* Transformare in metri */
    if(dinCe<4){initial=initial/pow(10,4-dinCe);}
        else {
                if(dinCe<=7){initial=initial*pow(10,dinCe-4);}
              }
    if(dinCe==8){initial=initial*0.0006452;}
    if(dinCe==9){initial=initial*0.0929;}
    if(dinCe==10){initial=initial*0.836127816;}


    cout<<"Selectati unitatea de masura in care doriti sa transformati"<<endl;
    cout<<"0. De la inceput"<<endl;
    UnitatiLungime();
    int inCe;
    cin>>inCe;
    if (dinCe==0){ClearScreen();
                   Lungime();}

    /* Transformare in ceea ce dorim*/
    double finall;
    if(inCe<4){finall=initial*pow(10,4-inCe);}
        else {
                if(inCe<=7){finall=initial/pow(10,inCe-4);}
              }
    if(inCe==8){finall=initial/0.0006452;}
    if(inCe==9){finall=initial/0.0929;}
    if(inCe==10){finall=initial/0.836127816;}

    /* Afisarea */

    ClearScreen();
    char s[11][4];
    strcpy(s[1],"mm");strcpy(s[2],"cm");strcpy(s[3],"dm");strcpy(s[4],"m");strcpy(s[5],"dam");strcpy(s[6],"hm");
    strcpy(s[7],"km");strcpy(s[8],"in");strcpy(s[9],"ft");strcpy(s[10],"yd");
    cout<<copieinitial<<" "<<s[dinCe]<<" -> "<<finall<<" "<<s[inCe];
}




int main()
{
    Lungime();
    return 0;
}
