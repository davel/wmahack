#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void bail(const char *err) {
	fprintf(stderr, "%s", err);
	exit(1);
}

typedef HRESULT (*GETCLASSOBJECT) (REFCLSID clsid, REFIID iid, LPVOID* ppv);

static const CLSID wma9d = { 0x27ca0808, 501, 20090,{ 0x8b, 5, 0x87, 0xf8, 7, 0xa2, 0x33, 0xd1 } };

int main(int argc, char *argv[]) {
	HMODULE hDll;
	HRESULT hr;
	GETCLASSOBJECT DllGetClassObject = NULL;
    LPVOID factory;
	REFCLSID filter_guid = wma9d;
	printf("Hello world\n");

	hDll = LoadLibraryA("/usr/lib/win32/wma9dmod.dll");

	DllGetClassObject = (GETCLASSOBJECT) (GetProcAddress(hDll, "DllGetClassObject"));
	if (!DllGetClassObject) bail("Bad COM DLL");

	hr = DllGetClassObject(

filter_guid,

IID_IClassFactory,

&factory

);
	if (hr) bail("could not get class object");

	return 0;
}

