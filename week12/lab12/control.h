/***********************************************************************
 * COMPONENT:
 *    CONTROL
 * Author:
 *    Br. Helfrich, <your name here if you made a change>
 * Summary:
 *    This class stores the notion of Bell-LaPadula
 ************************************************************************/

#pragma once

// levels of secrecy
enum Control
{
   PUBLIC,
   CONFIDENTIAL,
   PRIVILEGED,
   SECRET
};

// Authenticate function

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