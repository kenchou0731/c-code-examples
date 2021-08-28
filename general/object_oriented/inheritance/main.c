typedef struct BaseStruct
{
  char *name;
  void (*update) (struct BaseStruct self, const float dt);
}
BaseStruct;

BaseStruct *BaseStruct_new(const char *name)
{
  //allocate memory
  BaseStruct *bs = (BaseStruct *) malloc(sizeof(BaseStruct));
 
  //initialize data members
  BaseStruct_init(bs, name);
 
  return bs;
}
 
void BaseStruct_init(BaseStruct *self, const char *name)
{
  //initialize name
  self->name = (char *) malloc(sizeof(char) * (strlen(name) + 1));
  strcpy(self->name, name);
 
  //initialize member function pointer
  self->update = BaseStruct_update;
}

void udpateStructure(BaseStruct bs, const float dt)
{
  bs->update(bs, dt);
}

typedef struct DerivedStruct
{
  BaseStruct super;
  char *message;
}
DerivedStruct;

DerivedStruct *DerivedStruct_new
(
  const char *name,
  const char *message
)
{
  //memory allocation
  DerivedStruct*ds =
    (DerivedStruct*) malloc(sizeof(DerivedStruct));
 
  //initialize data members
  DerivedStruct_init(ds, name, message);
 
  return ds;
}
 
void DerivedStruct_init
(
  DerivedStruct*self,
  const char *name,
  const char *message
)
{
  //super constructor
  BaseStruct_init(&(self->super), name);
 
  //initialize message
  self->message =
    (char *) malloc(sizeof(char) * (strlen(message) + 1));
 
  strcpy(self->message, message);
 
  //function overriding
  ds->super.update = DerivedStruct_update;
}

void BaseStruct_dispose(BaseStruct *self)
{
  //de-allocate name
  free(self->name);
}
 
void DerivedStruct_dispose(DerivedStruct *self)
{
  //de-allocate name
  free(self->message);
 
  //super deconstructor
  BaseStruct_dispose(&(self->super));
}

int main(void) {
DerivedStruct *ds = DerivedStruct_new("myName", "myMessage");
 
//invoked the derived structure version
udpateStructure(ds, 1.0f / 60.0f);
}
