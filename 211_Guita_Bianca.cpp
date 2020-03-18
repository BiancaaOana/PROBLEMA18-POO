#include <iostream>
#include <math.h>
using namespace std;

class Film
{

private:

    char **denumirefilm;
    char **gen;
    char **regizor;
    float rating;

public:

    Film(char *denumirefilm, char *gen, char *regizor, float rating); ///constructor initializare

    Film(Film&); ///constructor copiere
    ~Film() ; ///destructor

    Film() {};
    void set_denumirefilm(char*);                     ///set
    void set_gen(char*);
    void set_regizor(char*);
    void set_rating(float);
    char get_denumirefilm()
    {
        return **denumirefilm;
    };           ///get
    char get_gen()
    {
        return **gen;
    };
    char get_regizor()
    {
        return **regizor;
    };
    float get_rating()
    {
        return rating;
    };

    void afisare(ostream &out);
    void citire(istream &in);

    friend istream& operator>>(istream &in, Film& x);  ///supraincarcare pe >>  //fluxul de intrare
    friend ostream& operator<<(ostream &out, Film& x); ///supraincarcare pe <<  //flx iesire
    void operator=(Film &z); ///supraincarcarea operatorului de atribuire (doar ca metoda nu ca functie friend)
    bool operator==(Film x1);
    bool operator<(Film x1); /// supraincarcare operator <
    bool operator>(Film x1);   /// operatorii iau un singur argument.
    void comparare(Film x);
};
Film::Film(char *denumirefilm, char *gen, char *regizor, float rating=0)
{
    this->denumirefilm = new char *(denumirefilm);
    this->gen = new char *(gen);
    this->regizor = new char *(regizor);
    this->rating = rating;
}

Film::Film(Film &x)
{
    this->denumirefilm = x.denumirefilm;
    this->gen = x.gen;
    this->regizor = x.regizor;
    this->rating = x.rating;
}

Film::~Film()
{
    delete[] denumirefilm;
    delete[] gen;
    delete[] regizor;


    /*
    this->denumirefilm = " ";
    this->gen = " ";
    this->regizor = " ";
    this->rating = 0;
    */
    cout<< "S-a apelat destructorul"<<" ";
}

void Film::set_denumirefilm(char *m)
{
    **denumirefilm = *m;
}
void Film::set_gen(char *n1)
{
    **gen = *n1;
}
void Film::set_regizor(char *o)
{
    **regizor = *o;
}
void Film::set_rating(float p)
{
    rating = p;
}
void Film::citire(istream &in)
{
    char *temp;
    cout<<"Care este denumirea filmului? ";
    denumirefilm = new char *[1];
    *denumirefilm = new char [100];
    in>>*denumirefilm;
    cout<<"Ce gen este filmul ales? ";
    gen = new char *[1];
    *gen = new char [100];
    in>>*gen;
    cout<<"Cine a regizat filmul propus? ";
    regizor = new char *[1];
    *regizor = new char [100];
    in>>*regizor;
    cout<<"Ce nota i-ai da filmului? ";
    in>>rating;
}

istream& operator>>(istream& in,Film &x)
{
    x.citire(in);
    return in;
}

void Film::afisare(ostream &out)
{

    out<<*denumirefilm<<" "<<*gen<<" "<<*regizor<<" "<<rating<<endl;


}

ostream& operator<<(ostream& out, Film& x)
{
    x.afisare(out);
    return out;
}

void Film::operator=(Film &x)
{
    denumirefilm=x.denumirefilm;
    gen=x.gen;
    regizor=x.regizor;
    rating=x.rating;
}

bool Film::operator==(Film x1)
{
    if(rating == x1.rating)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Film::operator>(Film x1)
{

    if(rating > x1.rating)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Film::operator<(Film x1)
{
    /*
    Film *x = new Film;
    x->rating = x1.rating < x2.rating;
    return *x;
    */
    if(rating < x1.rating)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Film::comparare(Film x)
{

    if(rating == x.rating)
    {
        cout << "Filmele au rating egal \n";
    }
    if(rating > x.rating)
    {
        cout <<"Filmul cu rating mai mare este...:" << endl;
        cout <<*denumirefilm <<endl;
    }
    else
    {
        cout <<"Filmul cu rating mai mare este...: "<< endl;
        cout <<*x.denumirefilm <<endl;
    }
}





void menu()
{
    int choice;///optiunea aleasa din meniu
    bool MenuFilm  = true;
    int n = 0; ///numarul de filme
    Film *a_vec;
    while (MenuFilm != false)
    {
        cout<< "Guita Bianca Oana 211 - Proiect - Nume proiect: Tema 18"<<endl;
        cout<<" "<<"MENIU:"<<endl;
        cout<< "****************************\n";
        cout<<" 1. Vreau sa adaug filme \n";
        cout<<" 2. Modificati, daca doriti, informatiile unui film adaugat\n";
        cout<<" 3. Comparati doua filme.\n";
        cout<<" 4. Iesiti din meniu.\n";
        cout<<" Introduceti alegerea dumneavoastra! : ";

        cin>>choice;

        switch(choice)
        {
            while(choice>=1 && choice<4)
                if(n != 0)
                {
                    cout<< "Denumire film ********* Gen ********* Regizor ********** Rating\n";
                    /// for(int i=1; i<=n; i++)
                    /// char **a[i]++;


                }
                else
                    cout<<"Nu avem ce sa afisam:( \n";
        case 1:
            cout<<" Acestea sunt toate filmele disponibile: \n";
            cout<<" Alegeti numarul de filme pe care doriti sa le adaugati?\n";
            int i,k;
            cin>>n;

            a_vec = new Film[n];

            for(i=1; i<=n; i++)


                cin>>a_vec[i];
            for(i=1; i<=n; i++)


               cout<<a_vec[i];



            break;
        case 2:
            int filmModif;

            char Alegere[100];
            if(n!=0)
            {cout<<"Ati ales sa modificati un film...\n";
                cout<<"Care este filmul pe care doriti sa il modificati?\n";

                cin>>filmModif;
                if(filmModif<1)
                {
                    cout<<"Imi pare rau, nu exista filmul selectat! Mai incearca odata!\n";
                    cin>>filmModif;
                }
                if(filmModif>n)
                {
                    cout<<"Imi pare rau, nu exista filmul selectat! Mai incearca odata!\n";
                    cin>>filmModif;
                }


            cout<<"Filmul ales de dvs este: \n";
            cout<<a_vec[filmModif]<<" "<<endl;
            cout<<"Doresc sa editez: \n";
            cout<<"1. Denumirea filmului"<<endl<<"2. Genul"<<endl<<"3. Regizorul"<<endl<<"4. Ratingul"<<endl;
            int filmModifModif;
            cin>>filmModifModif;
            if(filmModifModif<1)
            {
                cout<<"Imi pare rau, nu este posibil! Mai incearca odata!\n";
                cin>>filmModifModif;
            }
            if(filmModifModif>4)
            {
                cout<<"Imi pare rau, nu este posibil! Mai incearca odata!\n";
                cin>>filmModifModif;
            }

            if(filmModifModif == 1)
            {
                cout<<"Denumirea noua a filmului: "<<endl;
                cin>>Alegere;
                a_vec[filmModif-1].set_denumirefilm(Alegere);
                    for(i=1;i<=n;i++)
                    cout<<a_vec[i];

            }



            if(filmModifModif == 2)
            {
                cout<<"Genul nou al filmului este..: \n";
                cin>>Alegere;
                {a_vec[filmModif-1].set_gen(Alegere);
                for(i=1;i<=n;i++)
                    cout<<a_vec[i]<<" ";
            }}
            if(filmModifModif == 3)
            {
                cout<<"Regizorul nou al filmului este.. :\n";
                cin>>Alegere;
          a_vec[filmModif-1].set_regizor(Alegere);
                for(i=1;i<=n;i++)
                    cout<<a_vec[i]<<" ";
        }
            if(filmModifModif == 4)
            {
                float numar;
                cout<<"Ratingul nou...: \n";
                cin>>numar;
                {a_vec[filmModif-1].set_rating(numar);
                for(i=1;i<=n;i++)
                    cout<<a_vec[i]<<" ";
            }}

       }
            if(n == 0)
                cout<<"Ups! Nu am gasit filme salvate !\n";




            break;

                case 3:
            if(n == 0)
                cout<<"Ups! Nu am gasit filme salvate !\n";
            if(n!=0)
            {

                int film1,film2;
                bool ok=1;
                cout<<"Aleg urmatoarele filme: ";
                for (int i = 1 ; i <=n; i++)
                    cout<<i<<" "<<a_vec[i]<<endl;
                cout<<"Alegeti filmul"<<endl;
                cin>>film1>>film2;
                if (film1 < 1 && film2 < 1)
                {
                    ok = 0;
                    cout<<"Invalid"<<endl;
                }
                if (film1 > n && film2 > n)
                {
                    ok = 0;
                    cout<<"Invalid"<<endl;
                }
                if (film1 < 1 && film2 > n)
                {
                    ok = 0;
                    cout<<"Invalid"<<endl;
                }
                if (film1 > n && film2 < 1)
                {
                    ok = 0;
                    cout<<"Invalid"<<endl;
                }
                if (ok == 1)
                {
                    a_vec[film1-1].comparare(a_vec[film2-1]);
                }
            }


            break;
        case 4:
            if (choice == 4)
            {
                cout<<"EXIT! ";
            }
            if (choice<1||choice>4)
            {
                cout<<"Selectie invalida";
            }
            cout<<endl;
break;
        }
    }
}

int main()
{
    menu();
    return 0;
}
