/***********************************************************************
 * COMPONENT:
 *    MESSAGES
 * Author:
 *    Br. Helfrich, Osvaldo Carrillo Lira, Aaron Eiche, Zach Heiner, Collin Steel, John Tanner, Jordon Thompson
 * Summary:
 *    This class stores the notion of a collection of messages
 ************************************************************************/

#include <string>     // for convenience
#include <list>       // to store the messages
#include <iostream>   // standard input and output
#include <fstream>    // the messages are read from a file
#include <cassert>    // because I am paraniod
#include "messages.h" // a collection messages

using namespace std;

/***********************************************
 * MESSAGES :: DISPLAY
 * display the list of messages
 ***********************************************/
void Messages::display() const
{
   for (list<Message>::const_iterator it = messages.begin();
        it != messages.end();
        ++it)  
      if (securityConditionRead(it->getControl(), subjectControl)){
         it->displayProperties();
      }
      
}

/***********************************************
 * MESSAGES :: SHOW
 * show a single message
 **********************************************/
void Messages::show(int id) const
{
   for (list<Message>::const_iterator it = messages.begin();
        it != messages.end();
        ++it)
      if (it->getID() == id){
          if(securityConditionRead(it->getControl(), subjectControl)){
              it->displayText();
		  }
          else{
			  cout << "User does not have adequate permissions to read the message\n";
		  }
	  }
        
}

/***********************************************
 * MESSAGES :: UPDATE
 * update one single message
 ***********************************************/
void Messages::update(int id, const string &text)
{
   for (list<Message>::iterator it = messages.begin(); it != messages.end(); ++it) 
   {
      if (it->getID() == id) 
      {
         if (securityConditionWrite(it->getControl(), subjectControl))
         {
            it->updateText(text);
         }
         else
         {
            cout << "User permissions are to high to update message\n";
         }
      }
      
   }
}

 /***********************************************
 * MESSAGES :: REMOVE
 * remove a single message
 **********************************************/
   void Messages::remove(int id)
   {
      for (list<Message>::iterator it = messages.begin();
           it != messages.end();
           ++it)
         if (it->getID() == id)
            if (securityConditionWrite(it->getControl(), subjectControl))
            {
               it->clear();
            }
            else
            {
               cout << "User does not have adequate permissions to remove message\n";
            }
   }

 /***********************************************
 * MESSAGES :: ADD
 * add a new message
 **********************************************/
   void Messages::add(const string &textControl,
                      const string &text,
                      const string &author,
                      const string &date)
   {
      Control assetControl = convertControl(textControl);
      if (securityConditionWrite(assetControl, subjectControl))
      {
         Message message(assetControl, text, author, date);
         messages.push_back(message);
      }
      else
         cout << "User does not have adequate permissions to add messag." << endl;
   }

   /***********************************************
 * MESSAGES :: READ MESSAGES
 * read the messages from a file
 ***********************************************/
   void Messages::readMessages(const char *fileName)
   {
      // open the file
      ifstream fin(fileName);
      if (fin.fail())
      {
         cout << "ERROR! Unable to open file "
              << fileName
              << endl;
         return;
      }

      // continue reading until we fail
      while (!fin.fail() && !fin.eof())
      {
         string author;
         string date;
         string text;
         string textControl;
         getline(fin, textControl, '|');
         getline(fin, author, '|');
         getline(fin, date, '|');
         getline(fin, text);

         Control assetControl = convertControl(textControl);

         if (!fin.fail())
         {
            Message message(assetControl, text, author, date);
            messages.push_back(message);
         }
      }

      // close up shop!
      fin.close();
   }
