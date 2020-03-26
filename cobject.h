#include <stdlib.h>
#include <stdio.h>
#include <memory.h>

#define CLog(string, ...) fprintf(stdout, string "\n", ## __VA_ARGS__)

#define id void*

// build a function vtable
typedef struct CObject_vtable
{
  id (*alloc)(void);
  void (*dealloc)(id);
  id (*retain)(id);
  void (*release)(id);
  const char* (*description)(id);
} CObject_vtable;


// merge the vtable with members to create a class
typedef struct CObject_ivars
{
  id self;
  id super;
  const char* name;
  const char* parent;
  int retainCount;
} CObject_ivars;


// merge the vtable with members to create a class
typedef struct CObject_class
{
  CObject_ivars;
  CObject_vtable;
} CObject_class;

typedef CObject_class CObject;

extern CObject_class *CObject_base;

int CObject_bootstrap(void);

id CObject_alloc(void);
id CObject_dealloc(id self);
const char* CObject_description(id self);
