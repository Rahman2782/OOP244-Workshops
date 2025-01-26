#include <iostream>
#include "cstr.h"
#include "CC.h"
using namespace std;
namespace seneca {
   void CC::prnNumber(unsigned long long no) const {
      cout << no / 1000000000000ull << " ";
      no %= 1000000000000ull;
      cout.fill('0');
      cout.width(4);
      cout.setf(ios::right);
      cout << no / 100000000ull << " ";
      no %= 100000000ull;
      cout.width(4);
      cout << no / 10000ull << " ";
      no %= 10000ull;
      cout.width(4);
      cout << no;
      cout.unsetf(ios::right);
      cout.fill(' ');
   }
   void CC::display(const char* name, unsigned long long number, short expYear, short expMon, short cvv) const{
      char lname[31]{};
      strcpy(lname, name, 30);
      cout << "| ";
      cout.width(30);
      cout.fill(' ');
      cout.setf(ios::left);
      cout << lname << " | ";
      prnNumber(number);
      cout << " | " << cvv << " | ";
      cout.unsetf(ios::left);
      cout.setf(ios::right);
      cout.width(2);
      cout << expMon << "/" << expYear << " |" << endl;
      cout.unsetf(ios::right);
   }

   //validate definition was not provided - vaidates card info (if good, returns true)
   bool CC::validate(const char* name, unsigned long long cardNo, short cvv, short expMon, short expYear) const {
           if (name == nullptr || strlen(name) <= 2) {
               return false;
           }
           else if (cardNo > 4099999999999999ull || cardNo < 4000000000000000ull) {
               return false;
           }
           else if (cvv < 100) {
               return false;
           }
           else if (expMon > 12 || expMon < 1) {
               return false;
           }
           else if (expYear > 32 || expYear < 24) {
               return false;
           }
       return true;
   }

   void CC::set() { //safe empty state
       name = nullptr;//dont do char* name, shadows class name var
       CVV = 0;
       expiryMonth = 0;
       ccNumber = 0;
       expiryYear = 0;
   }

   void CC::cleanUp() {
       freeMem(name);
       CC::set();
   }

   bool CC::isEmpty() const {
       return (name == nullptr && ccNumber == 0 && CVV == 0 && expiryMonth == 0 && expiryYear == 0);
   }

   void CC::set(const char* cc_name, unsigned long long cc_no, short cvv, short expMon, short expYear) {
       CC::cleanUp();
       
       if (CC::validate(cc_name, cc_no, cvv, expMon, expYear)) {
           alocpy(name, cc_name);
           CVV = cvv;
           ccNumber = cc_no;
           expiryMonth = expMon;
           expiryYear = expYear;
       }
   }

   void CC::display() const {
       if (isEmpty()) {
           cout << "Invalid Credit Card Record\n";
       }
       else if (name != nullptr) {
           CC::display(name, ccNumber, expiryYear, expiryMonth, CVV); //originally incorrect argument order
       }


   }

}