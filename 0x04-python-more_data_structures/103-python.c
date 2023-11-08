#include <Python.h>
/**
 * print_python_list - Print information about a Python list
 * @p: A Python object
*/
void print_python_list(PyObject *p)
{
	Py_ssize_t size, i;
	PyObject *item;

	if (PyList_Check(p))
	{
		size = PyList_Size(p);
		printf("[*] Python list info\n");
		printf("[*] Size of the Python List = %ld\n", size);
		printf("[*] Allocated = %ld\n", ((PyListObject *)p)->allocated);

		for (i = 0; i < size; i++)
		{
			item = PyList_GetItem(p, i);
			printf("Element %ld: %s\n", i, Py_TYPE(item)->tp_name);
			if (PyBytes_Check(item))
				print_python_bytes(item);
		}
	}
	else
	{
		printf("Invalid Bytes Object\n");
	}
}

/**
 * print_python_bytes - Print information about a Python bytes object
 * @p: A Python object
*/
void print_python_bytes(PyObject *p)
{
	Py_ssize_t size, i;
	unsigned char *str;

	if (PyBytes_Check(p))
	{
		size = PyBytes_Size(p);
		str = (unsigned char *)((PyBytesObject *)p)->ob_sval;

		printf("[.] bytes object info\n");
		printf("  size: %ld\n", size);
		printf("  trying string: %s\n", PyUnicode_IS_READY(str) ? PyBytes_AS_STRING(p) : "");
		printf("  first %ld bytes: ", size > 10 ? 10 : size);

		for (i = 0; i < (size > 10 ? 10 : size); i++)
		{
			printf("%02x ", str[i]);
		}
		printf("\n");
	}
	else
	{
		printf("[ERROR] Invalid Bytes Object\n");
	}
}
