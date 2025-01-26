#ifndef SENECA_CC_H_
#define SENECA_CC_H_
#include <iostream>
namespace seneca {
   class CC {
   private:
       //attributes
       char* name; //cardholders name - dynamic c string
       short int CVV;
       short int expiryMonth, expiryYear;
       unsigned long long int ccNumber;
 
      void display(const char* name, 
          unsigned long long number, 
          short expYear, 
          short expMon, 
          short cvv) const;
      bool validate(const char* name, 
          unsigned long long cardNo, 
          short cvv, 
          short expMon, 
          short expYear) const;
      void prnNumber(unsigned long long no) const;

   public:
       void set();
       void set(const char* cc_name,
           unsigned long long cc_no,
           short cvv,
           short expMon = 12,
           short expYear = 24);
       void cleanUp();
       bool isEmpty() const;
       void display() const;

   };

}
#endif // !SENECA_CC_H_


