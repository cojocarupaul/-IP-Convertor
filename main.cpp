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
    cout<<"8. inch"<<endl;
    cout<<"9. ft"<<endl;
    cout<<"10. yd"<<endl;
}

bool alegereUnitate(unsigned x,unsigned y, unsigned alegere)
{
    if (alegere>=x &&alegere<=y){return 1;}
    return 0;
}


void Lungime()
{
    cout<<"Selectati unitatea de masura din care doriti sa transformati"<<endl;
    UnitatiLungime();
    int dinCe;
    cin>>dinCe;
    while(alegereUnitate(1,10,dinCe)!=1){cout<<"Optiunea Dumneavoastra nu este printre cele de mai sus. Incercati din nou:";
                                        cin>>dinCe;}
    cout<<endl;
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
    if(dinCe==8){initial=initial/39.37007;}
    if(dinCe==9){initial=initial/3.28083;}
    if(dinCe==10){initial=initial/1.0936;}


    cout<<"Selectati unitatea de masura in care doriti sa transformati"<<endl;
    cout<<"0. De la inceput"<<endl;
    UnitatiLungime();
    int inCe;
    cin>>inCe;

    while(alegereUnitate(1,10,inCe)!=1){cout<<"Optiunea Dumneavoastra nu este printre cele de mai sus. Incercati din nou:";
                                        cin>>inCe;}
    cout<<endl;

    if (dinCe==0){ClearScreen();
                   Lungime();}

    /* Transformare in ceea ce dorim*/
    double finall;
    if(inCe<4){finall=initial*pow(10,4-inCe);}
        else {
                if(inCe<=7){finall=initial/pow(10,inCe-4);}
              }
    if(inCe==8){finall=initial*39.37007;}
    if(inCe==9){finall=initial*3.28083;}
    if(inCe==10){finall=initial*1.0936;}

    /* Afisarea */

    ClearScreen();
    char s[11][5];
    strcpy(s[1],"mm");strcpy(s[2],"cm");strcpy(s[3],"dm");strcpy(s[4],"m");strcpy(s[5],"dam");strcpy(s[6],"hm");
    strcpy(s[7],"km");strcpy(s[8],"inch");strcpy(s[9],"ft");strcpy(s[10],"yd");
    cout<<fixed<<copieinitial;
    cout<<" "<<s[dinCe]<<" -> ";
    cout<<fixed<<finall;
    cout<<" "<<s[inCe];
}

void UnitatiArie ()
{
    cout<<"1. mm^2"<<endl;
    cout<<"2. cm^2"<<endl;
    cout<<"3. dm^2"<<endl;
    cout<<"4. m^2"<<endl;
    cout<<"5. dam^2"<<endl;
    cout<<"6. hm^2"<<endl;
    cout<<"7. km^2"<<endl;
    cout<<"8. inch^2"<<endl;
    cout<<"9. ft^2"<<endl;
    cout<<"10. yd^2"<<endl;
}


void Arie ()
{
    cout<<"Selectati unitatea de masura din care doriti sa transformati"<<endl;
    cout<<"0. Inapoi la meniu"<<endl;
    UnitatiArie();
    int dinCe;
    cin>>dinCe;
    if (dinCe==0){ClearScreen();
                   meniu();}
    cout<<"Scrieti valoarea:";
    double initial;
    cin>>initial;
    int copieinitial=initial;
    ClearScreen();

    /* Transformare in metri^2 */
    if(dinCe<4){initial=initial/pow(pow(10,4-dinCe),2);}
        else {
                if(dinCe<=7){initial=initial*pow(pow(10,4-dinCe),2);}
              }
    if(dinCe==8){initial=initial/1550.003;}
    if(dinCe==9){initial=initial/10.76391;}
    if(dinCe==10){initial=initial/1.1960;}


    cout<<"Selectati unitatea de masura in care doriti sa transformati"<<endl;
    cout<<"0. De la inceput"<<endl;
    UnitatiArie();
    int inCe;
    cin>>inCe;
    if (dinCe==0){ClearScreen();
                   Arie();}

    /* Transformare in ceea ce dorim*/
    double finall;
    if(inCe<4){finall=initial*pow(pow(10,4-inCe),2);}
        else {
                if(inCe<=7){finall=initial/pow(pow(10,4-inCe),2);}
              }
    if(inCe==8){finall=initial*1550.003;}
    if(inCe==9){finall=initial*10.76391;}
    if(inCe==10){finall=initial*1.1960;}

    /* Afisarea */

    ClearScreen();
    char s[11][7];
    strcpy(s[1],"mm^2");strcpy(s[2],"cm^2");strcpy(s[3],"dm^2");strcpy(s[4],"m^2");strcpy(s[5],"dam^2");strcpy(s[6],"hm^2");
    strcpy(s[7],"km^2");strcpy(s[8],"inch^2");strcpy(s[9],"ft^2");strcpy(s[10],"yd^2");
    cout<<fixed<<copieinitial;
    cout<<" "<<s[dinCe]<<" -> ";
    cout<<fixed<<finall;
    cout<<" "<<s[inCe];
}

void parcurgereMeniu()
{   meniu();
    int x;
    cin>>x;
    while(alegereUnitate(1,11,x)!=1){ cout<<"Ati tastat gresit. Pentru a incerca din nou apasati tasta Enter"<<endl;
                                        cout<<"Alegere:";
                                        cin>>x;
                                        cout<<endl;
                                        }
    ClearScreen();
    if(x==1)Lungime();
    if(x==2) Arie();
    }



int main()
{
    parcurgereMeniu();
    return 0;
}
