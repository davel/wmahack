#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void bail(const char *err) {
	fprintf(stderr, "%s", err);
	exit(1);
}

typedef HRESULT (*_DllGetClassObject) (struct *IClassFactory);

int main(int argc, char *argv[]) {
	HMODULE hDll;
	HRESULT hr;
	void *DllGetClassObject = NULL;
    struct IClassFactory* factory = NULL;

	printf("Hello world\n");

	hDll = LoadLibraryA("/usr/lib/win32/wma9dmod.dll");

	DllGetClassObject = GetProcAddress(hDll, "DllGetClassObject");
	if (!DllGetClassObject) bail("Bad COM DLL");

	hr = DllGetClassObject((void *)&factory);
	if (hr) bail("could not get class object");

	return 0;
}

