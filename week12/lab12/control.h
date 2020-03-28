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

extern Control subjectControl;
// Authenticate function

Control authenticateControl(const std::string& userName,
   const std::string& password);
Control convertControl(std::string key);
bool securityConditionRead(const Control& controlAsset,
   const Control& controlSubject);

bool securityConditionWrite(const Control& controlAsset,
   const Control& controlSubject);