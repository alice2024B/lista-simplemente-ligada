#include <iostream>
#include "Cola.h"

int main()
{
    Cola MiCola;
    persona x;

    for(int i=0;i< 5; i++){
        std::cin>>x;
        MiCola.enqueue(x);
    }
    std::cout<<"\nConstancias:\n";
    for(int i=0;i< 5; i++){
        persona constancia = MiCola.dequeue();
        std::cout << constancia<<std::endl;
    }

    return 0;
}

