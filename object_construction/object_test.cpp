#include "object_construction.hpp"


void testCopyCtor(Object test){
    
}

int main(){
    
    Object obj;    
    Object object; 
    
    obj = object;  
    object = obj;  

    testCopyCtor(obj); 
    testCopyCtor(obj); 

   
    
    return 0;
}