#include <cobjects/cobject.h>

int main (int argc, const char * argv[]) 
{
  CLog("%s", __FUNCTION__);
  CObject_bootstrap();
  
  CObject *obj = CObject_base->alloc();
  obj->description(obj);
  obj->dealloc(obj);
}
