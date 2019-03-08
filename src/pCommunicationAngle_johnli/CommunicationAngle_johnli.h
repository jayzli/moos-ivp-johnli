 /************************************************************/
/*    NAME: John Li                                              */
/*    ORGN: MIT                                             */
/*    FILE: CommunicationAngle_johnli.h                                          */
/*    DATE:                                                 */
/************************************************************/

#ifndef CommunicationAngle_johnli_HEADER
#define CommunicationAngle_johnli_HEADER

#include "MOOS/libMOOS/Thirdparty/AppCasting/AppCastingMOOSApp.h"
#include "math.h"
#include "stdint.h"

class CommunicationAngle_johnli : public AppCastingMOOSApp
{
 public:
   CommunicationAngle_johnli();
   ~CommunicationAngle_johnli();

 protected: // Standard MOOSApp functions to overload  
   bool OnNewMail(MOOSMSG_LIST &NewMail);
   bool Iterate();
   bool OnConnectToServer();
   bool OnStartUp();

 protected:
   void RegisterVariables();

 private: // Configuration variables

 private: // State variables
};

#endif 
