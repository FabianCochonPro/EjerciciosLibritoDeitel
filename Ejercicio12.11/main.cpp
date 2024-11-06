#include <iomanip>
#include <iostream>
#include <typeinfo>
#include <vector>

#include "Employee.h"
#include "SalariedEmployee.h"
#include "CommissionEmployee.h"
#include "BasePlusCommissionEmployee.h"

using namespace std;

const int CURRENT_MONTH{ 5 }; 

int main() {

   cout << fixed << setprecision( 2 );

   vector< Employee* > employees{
      new SalariedEmployee(
         "Joel", "Salas", "122-12-1221", 1, 3, 2002, 300 ),
      new CommissionEmployee(
         "Bender", "Rodrigues", "101-01-1010", 1, 19, 101010, 100, .01 ),
      new BasePlusCommissionEmployee(
         "Estafador", "Lewisss", "342-12-5645", 14, 21, 2000, 5120, .02, 200 ) };

   for ( Employee* employeePtr : employees ) {

      cout << employeePtr->toString() << endl;

      BasePlusCommissionEmployee* derivedPtr{
         dynamic_cast< BasePlusCommissionEmployee* >( employeePtr ) };

      if ( derivedPtr ) {
         derivedPtr->setBaseSalary( 1.1 * derivedPtr->getBaseSalary() );
         cout << "new base salary with 10% increase is: $"
            << derivedPtr->getBaseSalary() << endl;
      }

      if ( employeePtr )
         cout << "earned $" << employeePtr->earnings() +
            ( employeePtr->getBirthDate().getMonth() == ::CURRENT_MONTH ?
              100.0 : 0.0 ) << "\n\n";
   }

   for ( const Employee* employeePtr : employees ) {
      cout << "deleting object of " << typeid( *employeePtr ).name() << endl;
      delete employeePtr;
   }
}