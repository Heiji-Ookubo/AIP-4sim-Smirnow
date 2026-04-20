#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <ctime>
#include <cstdlib>
#include <typeinfo>

using namespace std;

class PrintedProduct {
protected:
    int pages;
    string theme;
    string author;
    string title;

public:
    PrintedProduct() : pages(0), theme(""), author(""), title("") {}

    PrintedProduct(int p, const string& th, const string& a, const string& t)
            : pages(p), theme(th), author(a), title(t) {}

    PrintedProduct(const PrintedProduct& other)
            : pages(other.pages), theme(other.theme), author(other.author), title(other.title) {}

    virtual ~PrintedProduct() {}

    void setPages(int p) { pages = p; }
    void setTheme(const string& th) { theme = th; }
    void setAuthor(const string& a) { author = a; }
    void setTitle(const string& t) { title = t; }

    int getPages() const { return pages; }
    string getTheme() const { return theme; }
    string getAuthor() const { return author; }
    string getTitle() const { return title; }

    virtual void read() const = 0;
    virtual string getRandomQuote() const = 0;
    virtual void openRandomPage() const = 0;
    virtual void printClassName() const = 0;
    virtual string toString() const = 0;
};

class Book : public PrintedProduct {
private:
    string genre;

public:
    Book() : PrintedProduct(), genre("") {}
    Book(int p, const string& th, const string& a, const string& t, const string& g)
            : PrintedProduct(p, th, a, t), genre(g) {}
    Book(const Book& other) : PrintedProduct(other), genre(other.genre) {}
    ~Book() {}

    void setGenre(const string& g) { genre = g; }
    string getGenre() const { return genre; }

    void read() const override {
        cout << "Chitayu knigu \"" << title << "\" avtora " << author << endl;
    }

    string getRandomQuote() const override {
        return "\"Znanie - sila!\"";
    }

    void openRandomPage() const override {
        int randomPage = rand() % pages + 1;
        cout << "Otkryvayu knigu na stranitse " << randomPage << " iz " << pages << endl;
    }

    void printClassName() const override {
        cout << "Klass: Kniga";
    }

    string toString() const override {
        return "Kniga | " + title + " | " + author + " | " + theme + " | " + to_string(pages) + " str. | Zhanr: " + genre;
    }

    void addBookmark(int page) const {
        cout << "Zakladka na stranitse " << page << " v knige \"" << title << "\"" << endl;
    }
};

class Comic : public PrintedProduct {
private:
    string illustrator;

public:
    Comic() : PrintedProduct(), illustrator("") {}
    Comic(int p, const string& th, const string& a, const string& t, const string& ill)
            : PrintedProduct(p, th, a, t), illustrator(ill) {}
    Comic(const Comic& other) : PrintedProduct(other), illustrator(other.illustrator) {}
    ~Comic() {}

    void setIllustrator(const string& ill) { illustrator = ill; }
    string getIllustrator() const { return illustrator; }

    void read() const override {
        cout << "Chitayu komiks \"" << title << "\", khudozhnik: " << illustrator << endl;
    }

    string getRandomQuote() const override {
        return "\"S velikoy siloy prikhodit velikaya otvetstvennost!\"";
    }

    void openRandomPage() const override {
        int randomPage = rand() % pages + 1;
        cout << "Otkryvayu komiks na stranitse " << randomPage << endl;
    }

    void printClassName() const override {
        cout << "Klass: Komiks";
    }

    string toString() const override {
        return "Komiks | " + title + " | " + author + " | " + theme + " | " + to_string(pages) + " str. | Khudozhnik: " + illustrator;
    }

    void showCover() const {
        cout << "Oblozhka komiksa \"" << title << "\" ot " << illustrator << endl;
    }
};

class Newspaper : public PrintedProduct {
private:
    string editor;

public:
    Newspaper() : PrintedProduct(), editor("") {}
    Newspaper(int p, const string& th, const string& a, const string& t, const string& ed)
            : PrintedProduct(p, th, a, t), editor(ed) {}
    Newspaper(const Newspaper& other) : PrintedProduct(other), editor(other.editor) {}
    ~Newspaper() {}

    void setEditor(const string& ed) { editor = ed; }
    string getEditor() const { return editor; }

    void read() const override {
        cout << "Chitayu gazetu \"" << title << "\", redaktor: " << editor << endl;
    }

    string getRandomQuote() const override {
        return "\"Segodnya v mire vazhnye sobytiya!\"";
    }

    void openRandomPage() const override {
        int randomPage = rand() % pages + 1;
        cout << "Otkryvayu gazetu na stranitse " << randomPage << endl;
    }

    void printClassName() const override {
        cout << "Klass: Gazeta";
    }

    string toString() const override {
        return "Gazeta | " + title + " | " + author + " | " + theme + " | " + to_string(pages) + " str. | Redaktor: " + editor;
    }

    void checkFreshness() const {
        cout << "Gazeta \"" << title << "\" segodnyashnyaya!" << endl;
    }
};

class Brochure : public PrintedProduct {
private:
    string organization;

public:
    Brochure() : PrintedProduct(), organization("") {}
    Brochure(int p, const string& th, const string& a, const string& t, const string& org)
            : PrintedProduct(p, th, a, t), organization(org) {}
    Brochure(const Brochure& other) : PrintedProduct(other), organization(other.organization) {}
    ~Brochure() {}

    void setOrganization(const string& org) { organization = org; }
    string getOrganization() const { return organization; }

    void read() const override {
        cout << "Chitayu broshyuru \"" << title << "\" ot " << organization << endl;
    }

    string getRandomQuote() const override {
        return "\"Uspeyte kupit so skidkoy!\"";
    }

    void openRandomPage() const override {
        int randomPage = rand() % pages + 1;
        cout << "Otkryvayu broshyuru na stranitse " << randomPage << endl;
    }

    void printClassName() const override {
        cout << "Klass: Broshyura";
    }

    string toString() const override {
        return "Broshyura | " + title + " | " + author + " | " + theme + " | " + to_string(pages) + " str. | Organizatsiya: " + organization;
    }

    void fold() const {
        cout << "Broshyura \"" << title << "\" slozhena" << endl;
    }
};

void showMenu() {
    cout << "\n===== MENU =====" << endl;
    cout << "1. Dobavit ob'ekt" << endl;
    cout << "2. Prochitat vse" << endl;
    cout << "3. Sluchaynaya tsitata dlya vsekh" << endl;
    cout << "4. Otkryt sluchaynyu stranitsu" << endl;
    cout << "5. Pokazat vsyu informatsiyu" << endl;
    cout << "6. Unikalnyy metod dlya ob'ekta" << endl;
    cout << "0. Vykhod" << endl;
    cout << "Vybor: ";
}

int main() {
    srand(time(nullptr));
    vector<shared_ptr<PrintedProduct>> products;

    products.push_back(make_shared<Book>(350, "Roman", "Tolstoy", "Voyna i mir", "Epopeya"));
    products.push_back(make_shared<Comic>(120, "Supergeroi", "Sten Li", "Chelovek-pauk", "Stiv Ditko"));
    products.push_back(make_shared<Newspaper>(24, "Novosti", "Petrov", "Vechernie novosti", "Sidorova"));
    products.push_back(make_shared<Brochure>(16, "Reklama", "OOO Romashka", "Nashi uslugi", "OOO Romashka"));
    products.push_back(make_shared<Book>(280, "Fentezi", "Tolkin", "Khobbit", "Priklyucheniya"));
    products.push_back(make_shared<Comic>(90, "Yumor", "Gosinni", "Asteriks", "Uderzo"));

    int choice;
    do {
        showMenu();
        cin >> choice;

        switch (choice) {
            case 1: {
                int type;
                cout << "Tip (1-Kniga,2-Komiks,3-Gazeta,4-Broshyura): ";
                cin >> type;
                int p;
                string th, a, t, extra;
                cout << "Stranits: "; cin >> p;
                cin.ignore();
                cout << "Tematika: "; getline(cin, th);
                cout << "Avtor: "; getline(cin, a);
                cout << "Nazvanie: "; getline(cin, t);
                cout << "Dop. pole: "; getline(cin, extra);

                switch (type) {
                    case 1: products.push_back(make_shared<Book>(p, th, a, t, extra)); break;
                    case 2: products.push_back(make_shared<Comic>(p, th, a, t, extra)); break;
                    case 3: products.push_back(make_shared<Newspaper>(p, th, a, t, extra)); break;
                    case 4: products.push_back(make_shared<Brochure>(p, th, a, t, extra)); break;
                    default: cout << "Oshibka\n";
                }
                break;
            }
            case 2:
                for (auto& obj : products) obj->read();
                break;
            case 3:
                for (auto& obj : products) cout << obj->getRandomQuote() << endl;
                break;
            case 4:
                for (auto& obj : products) obj->openRandomPage();
                break;
            case 5:
                for (size_t i = 0; i < products.size(); i++)
                    cout << i + 1 << ". " << products[i]->toString() << endl;
                break;
            case 6: {
                int idx;
                cout << "Nomer ob'ekta (1-" << products.size() << "): ";
                cin >> idx;
                if (idx < 1 || idx > (int)products.size()) break;
                auto& obj = products[idx - 1];

                if (typeid(*obj) == typeid(Book))
                    dynamic_cast<Book*>(obj.get())->addBookmark(42);
                else if (typeid(*obj) == typeid(Comic))
                    dynamic_cast<Comic*>(obj.get())->showCover();
                else if (typeid(*obj) == typeid(Newspaper))
                    dynamic_cast<Newspaper*>(obj.get())->checkFreshness();
                else if (typeid(*obj) == typeid(Brochure))
                    dynamic_cast<Brochure*>(obj.get())->fold();
                break;
            }
        }
    } while (choice != 0);

    return 0;
}