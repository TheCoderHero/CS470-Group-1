/***********************************************************************
* COMPONENT:
*    MESSAGE
* Author:
*    Br. Helfrich, Osvaldo Carrillo Lira, Aaron Eiche, Zach Heiner, Collin Steel, John Tanner, Jordon Thompson
* Summary: 
*    This class stores the notion of a message
************************************************************************/

#pragma once

#include <string>    // for convenience
#include "control.h"

/**************************************************
 * MESSAGE
 * one message to be displayed to the user or not
 **************************************************/
class Message
{
public:
   // default constructor for an empty message
   Message();

   // the most commonly used constructor: create a message
   Message(const Control &assetControl,
           const std::string &text,
           const std::string &author,
           const std::string &date);

   // determine the unique ID of this message
   int getID() const { return id; }

   // determine the control level of the message
   Control getControl() const { return assetControl; }

   // display the properties but not content of the message
   void displayProperties() const;

   // display the content of the message
   void displayText() const;

   // update the text componnet of the message
   void updateText(const std::string &newText);

   // clear out a message
   void clear();

private:
   int id;               // the unique ID of this message
   static int idNext;    // the id of the next message created
   bool empty;           // is this message empty / cleared?
   Control assetControl; // to control the message
   std::string text;     // the textual content of this message
   std::string author;   // the author of this message
   std::string date;     // the date this message was created
};
