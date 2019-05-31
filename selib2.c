#include <Python.h>

#include "rot13.c"


static PyObject* pyrot13(PyObject *self, PyObject *args) {
    char *input;

    if (!PyArg_ParseTuple(args, "s", &input)) {
        return NULL;
    }

    char *result = rot13(input);
    PyObject *ret = Py_BuildValue("s", result);
    free(result);

    return ret;
}

static PyMethodDef selib2Methods[] = {
    {"rot13", pyrot13, METH_VARARGS, "Rotate by 13 places (ROT13) encryption."},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef selib2 = {
    PyModuleDef_HEAD_INIT,
    "selib2",
    "Simple Encryption Library version 2",
    -1,
    selib2Methods
};

PyMODINIT_FUNC PyInit_selib2(void) {
    return PyModule_Create(&selib2);
}
