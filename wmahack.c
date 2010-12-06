#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main(int argc, char *argv[]) {
	HMODULE hDll;
	void *func;

	printf("Hello world\n");

	hDll = LoadLibraryA("/usr/lib/win32/wma9dmod.dll");

	func = GetProcAddress(hDll, "DllGetClassObject");

	return 0;
}

