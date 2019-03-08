#--------------------------------------------------------
# The CMakeLists.txt for:                       pCommunicationAngle_johnli
# Author(s):                              John Li
#--------------------------------------------------------

SET(SRC
  CommunicationAngle_johnli.cpp
  CommunicationAngle_johnli_Info.cpp
  main.cpp
)

ADD_EXECUTABLE(pCommunicationAngle_johnli ${SRC})

TARGET_LINK_LIBRARIES(pCommunicationAngle_johnli
   ${MOOS_LIBRARIES}
   mbutil
   m
   pthread)

