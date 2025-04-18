#include <Python.h>

static PyObject* foo(PyObject* self)
{
    return PyUnicode_FromString("bar");
}

static PyMethodDef methods[] = {
    {"foo", (PyCFunction)foo, METH_NOARGS, NULL},
    {NULL, NULL, 0, NULL},
};

static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "some_module",
    NULL,
    -1,
    methods,
};

PyMODINIT_FUNC PyInit_some_module(void)
{
    return PyModule_Create(&module);
}
