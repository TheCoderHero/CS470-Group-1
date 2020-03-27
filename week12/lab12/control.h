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
   Control authenticate(const string &userName,
                          const string &password)
   {
      if (userName == "AdmiralAbe" && password == "password")
         return SECRET;

      if (userName == "CaptainCharlie" && password == "password")
         return CONFIDENTIAL;

      if ((userName == "SeamanSam" || userName == "SeamanSue" || userName == "SeamanSly") && password == "password")
         return PRIVILEGED;

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

   Control subjectControl = authenticate("AdmiralAbe", "password");