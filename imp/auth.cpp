#include <Python.h>
#include <string>
 
using namespace std;

unsigned int djb_hash(const string &id) 
{
    size_t i;
    unsigned int h;

    h = 5381;

    for (i = 0; i < id.size(); i++) {
      h = (h << 5) + h + id[i];
    }

    return h;
}

unsigned int auth_key(char* netID)
{
  return djb_hash(netID);
}

// fuck python and Guido van Rossum
static PyObject* auth_code(PyObject* self,PyObject* args)
{
  char *id;
    
  if(!PyArg_ParseTuple(args, "s", &id) )
    return NULL;
  else
    return  Py_BuildValue("I", auth_key(id));
}

// method defenitions
static PyMethodDef myMethods[] = {{"auth_code", auth_code, METH_VARARGS, "gives a hash key"}, {NULL, NULL, 0, NULL}
};

// module defenitions
static struct PyModuleDef UTKeyGen = {
  PyModuleDef_HEAD_INIT,
  "myModule",
  "Fibonacci Module",
  -1,
  myMethods
};

PyMODINIT_FUNC PyInit_UTKeyGen(void)
{
  return PyModule_Create(&UTKeyGen);
}