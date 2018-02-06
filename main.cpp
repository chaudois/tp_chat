#include <iostream>
#include "Client.h"

  #define PORT 11999
Client tcp;

void* listen(void* nothing){
    bool* continuer=(bool*)nothing;
   string message;

  while (true){
    message=tcp.receive();
      if(message==""){
          *continuer=false;
          break;
      }
    cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
    cout<<message<<endl;
  }
}
int main(int argc, char *argv[])
{


  while(true) {
      string ip = "";
      cout << "please enter server IP : " << endl;
      cin >> ip;

      pthread_t thread;
      bool continuer = true;
      if (tcp.setup(ip, PORT)) {
          cout << "connection successful " << endl;

          cout << "enter your name" << endl;


          string pseudo, message;
          cin >> pseudo;
          tcp.Send(pseudo);


          pthread_create(&thread, NULL, listen, &continuer);
          while (continuer) {
              getline(cin, message);
              tcp.Send(message);


          }


      } else {
          cout << "impossible to contact the server at " << ip << ":" << PORT << endl;

      }
  }

    exit(0);
    return 0;
 }
