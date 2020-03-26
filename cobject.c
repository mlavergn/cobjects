#include <cobjects/cobject.h>

CObject *CObject_base;

const char* CObject_description(id self) {
  CLog("%s", __FUNCTION__);
  CObject* this = (CObject*)self;
  CLog("%s", this->name);
  return this->name;
}

id CObject_alloc(void) {
  CLog("%s", __FUNCTION__);
  CObject *self = calloc(1, sizeof(CObject));
  memcpy(self, CObject_base, sizeof(CObject));
  return self;
}

id CObject_dealloc(id this) {
  CLog("%s", __FUNCTION__);
  CObject *self = (CObject*)this;
  free(self);
  return 0;
}

int CObject_bootstrap(void) {
  CLog("%s", __FUNCTION__);

  CObject *self = malloc(sizeof(CObject));
  self->name = strdup("CObject");
  self->alloc = CObject_alloc;
  self->description = CObject_description;
  self->alloc();
  self->description(self);

  CObject_base = self;
  return 0;  
}
