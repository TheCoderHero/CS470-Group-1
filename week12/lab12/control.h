/***********************************************************************
 * COMPONENT:
 *    CONTROL
 * Author:
 *    Br. Helfrich, <your name here if you made a change>
 * Summary:
 *    This class stores the notion of Bell-LaPadula
 ************************************************************************/

#pragma once
#include <map>
#include <string>

// levels of secrecy
enum Control
{
   PUBLIC,
   CONFIDENTIAL,
   PRIVILEGED,
   SECRET
};

Control subjectControl;
// Authenticate function
Control authenticateControl(const std::string &userName,
                     const std::string &password)
{
   // std::map<string, Control>::iterator it;
   std::map<std::string, Control> perm;
   perm["AdmiralAbe"] = SECRET;
   perm["CaptainCharlie"] = PRIVILEGED;
   perm["SeamanSam"] = CONFIDENTIAL;
   perm["SeamanSue"] = CONFIDENTIAL;
   perm["SeamanSly"] = CONFIDENTIAL;
   if (perm[userName] && password == "password")
      return perm[userName];

   return PUBLIC;   
}

Control convertControl(std::string key)
{
   std::map<std::string, Control> perm;
   perm["PUBLIC"] = PUBLIC;
   perm["CONFIDENTIAL"] = CONFIDENTIAL;
   perm["PRIVILEGED"] = PRIVILEGED;
   perm["SECRET"] = SECRET;
   
   if(perm[key])
      return perm[key];

   return PUBLIC;   
}
bool securityConditionRead(const Control &controlAsset,
                           const Control &controlSubject)
{
   return controlSubject >= controlAsset;
}

bool securityConditionWrite(const Control &controlAsset,
                            const Control &controlSubject)
{
   return controlSubject <= controlAsset;
}