/************************************************************/
/*    NAME: John Li        
                                      */
/*    ORGN: MIT                                             */
/*    FILE: PrimeFactor.cpp                                        */
/*    DATE:                                                 */
/************************************************************/

#include <iterator>
#include "MBUtils.h"
#include "PrimeFactor.h"

using namespace std;
 
//---------------------------------------------------------
// Constructor

PrimeFactor::PrimeFactor()
{
  m_input_number = 0;
  m_string = " ";
  m_result = "";
  list<string> m_string_list;
}

//---------------------------------------------------------
// Destructor

PrimeFactor::~PrimeFactor()
{
}

//---------------------------------------------------------
// Procedure: OnNewMail

bool PrimeFactor::OnNewMail(MOOSMSG_LIST &NewMail)
{
  MOOSMSG_LIST::iterator p;
   
  for(p=NewMail.begin(); p!=NewMail.end(); p++) 
    {
    CMOOSMsg &msg = *p;

#if 0 // Keep these around just for template
    string key   = msg.GetKey();
    string comm  = msg.GetCommunity();
    double dval  = msg.GetDouble();
    string sval  = msg.GetString(); 
    string msrc  = msg.GetSource();
    double mtime = msg.GetTime();
    bool   mdbl  = msg.IsDouble();
    bool   mstr  = msg.IsString();
#endif

    string key   = msg.GetKey();
  
   if (key == "NUM_VALUE")
     { m_string = msg.GetString(); 
       m_string_list.push_back(m_string);
     }
  
   }
    return(true);
}

//---------------------------------------------------------
// Procedure: OnConnectToServer

bool PrimeFactor::OnConnectToServer()
{
   // register for variables here
   // possibly look at the mission file?
   // m_MissionReader.GetConfigurationParam("Name", <string>);
   // m_Comms.Register("VARNAME", 0);	
   RegisterVariables();
   return(true);
}

//---------------------------------------------------------
// Procedure: Iterate()
//            happens AppTick times per second

bool PrimeFactor::Iterate()
{
   list<string>::iterator q;
   for(q=m_string_list.begin(); q!=m_string_list.end(); q++)
     { string str = *q;
       m_input_number = strtoul(str.c_str(), NULL, 0);
       for (int n=2; n>0; n++)
       {
         if (m_input_number % n == 0)
	 { m_input_number = m_input_number/n;
	   m_result = m_result + to_string(n) + ", ";
           n--;
         }
       else if (m_input_number == 1)
	 {cout<<"Factorization complete";
          q= m_string_list.erase(q);
          Notify("NUM_RESULT", m_result);
          m_result = "";
          n = -1;
         } 
       } 
     }
   return(true);
   }

//---------------------------------------------------------
// Procedure: OnStartUp()
//            happens before connection is open

bool PrimeFactor::OnStartUp()
{
  list<string> sParams;
  m_MissionReader.EnableVerbatimQuoting(false);
  if(m_MissionReader.GetConfiguration(GetAppName(), sParams)) {
    list<string>::iterator p;
    for(p=sParams.begin(); p!=sParams.end(); p++) {
      string original_line = *p;
      string param = stripBlankEnds(toupper(biteString(*p, '=')));
      string value = stripBlankEnds(*p);
      
      if(param == "FOO") {
        //handled
      }
      else if(param == "BAR") {
        //handled
      }
    }
  }
  
  RegisterVariables();	
  return(true);
}

//---------------------------------------------------------
// Procedure: RegisterVariables

void PrimeFactor::RegisterVariables()
{
  // Register("FOOBAR", 0);
  Register("NUM_VALUE", 0);
  Register("NUM_RESULT", 0);
}

 
