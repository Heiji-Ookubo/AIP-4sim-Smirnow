#include <iostream>
#include <string>
#include <limits>

using namespace std;

class Train {
private:
    double pricePerSeat;
    int availableSeats;
    int trainNumber;
    int carriageCount;

public:
    Train() : pricePerSeat(0.0), availableSeats(0), trainNumber(0), carriageCount(0) {
        cout << "Train() - konstruktor bez parametrov" << endl;
    }

    Train(double price, int seats, int number, int carriages)
            : pricePerSeat(price), availableSeats(seats), trainNumber(number), carriageCount(carriages) {
        cout << "Train(parameters) - konstruktor s parametrami" << endl;
    }

    Train(const Train& other)
            : pricePerSeat(other.pricePerSeat), availableSeats(other.availableSeats),
              trainNumber(other.trainNumber), carriageCount(other.carriageCount) {
        cout << "Train(const Train&) - konstruktor kopirovaniya" << endl;
    }

    ~Train() {
        cout << "~Train() - destruktor dlya poezda #" << trainNumber << endl;
    }

    void setPricePerSeat(double price) {
        pricePerSeat = price;
    }

    void setAvailableSeats(int seats) {
        availableSeats = seats;
    }

    void setTrainNumber(int number) {
        trainNumber = number;
    }

    void setCarriageCount(int count) {
        carriageCount = count;
    }

    double getPricePerSeat() const {
        return pricePerSeat;
    }

    int getAvailableSeats() const {
        return availableSeats;
    }

    int getTrainNumber() const {
        return trainNumber;
    }

    int getCarriageCount() const {
        return carriageCount;
    }

    void sellTickets(int count) {
        if (count <= availableSeats) {
            availableSeats -= count;
            cout << "Prodano " << count << " biletov. Ostalos mest: " << availableSeats << endl;
        } else {
            cout << "Nedostatochno svobodnyh mest!" << endl;
        }
    }

    int calculateTotalSeats() const {
        return availableSeats;
    }

    void serveTea() const {
        cout << "Chay raznositsya po vagonam poezda #" << trainNumber << endl;
    }

    void announceRoute() const {
        cout << "Obyavlenie marshruta sledovaniya poezda #" << trainNumber << endl;
    }

    Train& operator=(const Train& other) {
        cout << "operator= - prisvaivanie" << endl;
        if (this != &other) {
            pricePerSeat = other.pricePerSeat;
            availableSeats = other.availableSeats;
            trainNumber = other.trainNumber;
            carriageCount = other.carriageCount;
        }
        return *this;
    }

    bool operator==(const Train& other) const {
        return (trainNumber == other.trainNumber);
    }

    bool operator!=(const Train& other) const {
        return !(*this == other);
    }

    Train& operator[](int extraCarriages) {
        carriageCount += extraCarriages;
        availableSeats += extraCarriages * 50;
        cout << "operator[]: dobavleno " << extraCarriages << " vagonov. Teper vagonov: " << carriageCount
             << ", mest: " << availableSeats << endl;
        return *this;
    }

    Train& operator*() {
        if (carriageCount > 0) {
            carriageCount--;
            availableSeats -= 50;
            if (availableSeats < 0) availableSeats = 0;
            cout << "operator*: ubran posledniy vagon. Vagonov: " << carriageCount
                 << ", mest: " << availableSeats << endl;
        } else {
            cout << "Net vagonov dlya udaleniya!" << endl;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Train& t);
    friend istream& operator>>(istream& is, Train& t);
};

ostream& operator<<(ostream& os, const Train& t) {
    os << "Poezd #" << t.trainNumber << endl;
    os << "Cena mesta: " << t.pricePerSeat << endl;
    os << "Svobodnyh mest: " << t.availableSeats << endl;
    os << "Kolichestvo vagonov: " << t.carriageCount << endl;
    return os;
}

istream& operator>>(istream& is, Train& t) {
    cout << "Vvedite nomer poezda: ";
    is >> t.trainNumber;
    cout << "Vvedite cenu mesta: ";
    is >> t.pricePerSeat;
    cout << "Vvedite kolichestvo svobodnyh mest: ";
    is >> t.availableSeats;
    cout << "Vvedite kolichestvo vagonov: ";
    is >> t.carriageCount;
    return is;
}

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    cout << "========================================" << endl;
    cout << "   Programma dlya raboty s poezdami    " << endl;
    cout << "========================================" << endl;

    Train t1;
    Train t2(100.0, 200, 123, 8);
    Train t3(t2);

    int choice;
    do {
        cout << "\n=============== MENU =================" << endl;
        cout << "1. Vvod dannyh poezda" << endl;
        cout << "2. Vyvod dannyh poezda" << endl;
        cout << "3. Prodat bilety" << endl;
        cout << "4. Vychislit obshee kolichestvo mest" << endl;
        cout << "5. Raznesti chay" << endl;
        cout << "6. Dat obyavlenie o marshrute" << endl;
        cout << "7. Dobavit vagony (operator[])" << endl;
        cout << "8. Ubrat posledniy vagon (operator*)" << endl;
        cout << "9. Prisvaivanie (operator=)" << endl;
        cout << "10. Sravnenie (operator== i operator!=)" << endl;
        cout << "0. Vyhod" << endl;
        cout << "=======================================" << endl;
        cout << "Vyberite punkt: ";

        cin >> choice;
        clearInput();

        switch (choice) {
            case 1: {
                cout << "--- Vvod dannyh ---" << endl;
                cin >> t1;
                cout << "Dannye uspeshno vvedeny!" << endl;
                break;
            }
            case 2: {
                cout << "--- Dannye poezda ---" << endl;
                cout << t1;
                break;
            }
            case 3: {
                int count;
                cout << "Skolko biletov prodat? ";
                cin >> count;
                t1.sellTickets(count);
                break;
            }
            case 4: {
                cout << "Obshee kolichestvo mest: " << t1.calculateTotalSeats() << endl;
                break;
            }
            case 5: {
                t1.serveTea();
                break;
            }
            case 6: {
                t1.announceRoute();
                break;
            }
            case 7: {
                int n;
                cout << "Skolko vagonov dobavit? ";
                cin >> n;
                t1[n];
                break;
            }
            case 8: {
                *t1;
                break;
            }
            case 9: {
                t1 = t2;
                cout << "Prisvoili t1 = t2. Teper t1:" << endl;
                cout << t1;
                break;
            }
            case 10: {
                cout << "Sravnenie poezdov:" << endl;
                if (t1 == t2)
                    cout << "Poezda ravny (po nomeru)" << endl;
                else
                    cout << "Poezda raznye" << endl;

                if (t1 != t3)
                    cout << "t1 != t3" << endl;
                else
                    cout << "t1 == t3" << endl;
                break;
            }
            case 0:
                cout << "Vyhod iz programmy. Do svidaniya!" << endl;
                break;
            default:
                cout << "Oshibka: nevernyy punkt menu!" << endl;
        }
    } while (choice != 0);

    return 0;
}