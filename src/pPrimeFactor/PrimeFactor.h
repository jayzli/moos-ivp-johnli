/************************************************************/
/*    NAME: John Li                                         */
/*    ORGN: MIT                                             */
/*    FILE: PrimeFactor.h                                   */
/*    DATE: MAR 2019                                        */
/************************************************************/

#ifndef PrimeFactor_HEADER
#define PrimeFactor_HEADER

#include "MOOS/libMOOS/MOOSLib.h"
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <string>
#include <list>

using namespace std;

class PrimeFactor : public CMOOSApp
{
 public:
   PrimeFactor();
   ~PrimeFactor();

 protected: // Standard MOOSApp functions to overload  
   bool OnNewMail(MOOSMSG_LIST &NewMail);
   bool Iterate();
   bool OnConnectToServer();
   bool OnStartUp();

 protected:
   void RegisterVariables();
   uint64_t m_input_number;
   string m_string;
   string m_result;
   list<string> m_string_list;

 private: // Configuration variables

 private: // State variables
};

#endif 
