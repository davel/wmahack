#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void bail(const char *err) {
	fprintf(stderr, "%s", err);
	exit(1);
}

int main(int argc, char *argv[]) {
	HMODULE hDll;
	void *DllGetClassObject;

	printf("Hello world\n");

	hDll = LoadLibraryA("/usr/lib/win32/wma9dmod.dll");

	DllGetClassObject = GetProcAddress(hDll, "DllGetClassObject");
	if (!DllGetClassObject) bail("Bad COM DLL");
	

	return 0;
}

