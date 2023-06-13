#include "ProxySensy.h"
#include "readLine.h"
#include "Motors.h"

class Block{
    private:
        ProxySensy PS;
        readLine& blockRL;
        Motors motor;
   
        // bool voor logic
        bool blockLinedUp;

        // lees proxy sensor uit
        void readProxy();  

    public: 
        Block(readLine&);
        ~Block() = default;

        // vind het block door area te scannen
        bool findBlock();
        // als blockLinedUp duw block 
        void pushBlock();
        // als blockLinedUp en line geregistreerd stop
        bool checkWin();     
};
