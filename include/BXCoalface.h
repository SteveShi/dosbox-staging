#ifndef BOXER_STAGING_BXCOALFACE_H
#define BOXER_STAGING_BXCOALFACE_H

#include <cstdint>

// Define types used in declarations to avoid types.h conflicts
using Bitu   = uintptr_t;
using Bit16u = uint16_t;

class DOS_Shell;

#ifdef __cplusplus
extern "C" {
#endif

#if defined(BOXER) || defined(BOXER_DEBUG)
// Built as part of Boxer: declared here, defined in Boxer/BXCoalface.mm
void boxer_shellWillStart(DOS_Shell *shell);
void boxer_shellDidFinish(DOS_Shell *shell);
void boxer_shellWillStartAutoexec(DOS_Shell *shell);
void boxer_didReturnToShell(DOS_Shell *shell);
bool boxer_shellShouldRunCommand(DOS_Shell *shell, char* cmd, char* args);
void boxer_shellWillReadCommandInputFromHandle(DOS_Shell *shell, Bit16u handle);
void boxer_shellDidReadCommandInputFromHandle(DOS_Shell *shell, Bit16u handle);
bool boxer_handleShellCommandInput(DOS_Shell *shell, char *cmd, Bitu *cursorPosition, bool *executeImmediately);
bool boxer_hasPendingCommandsForShell(DOS_Shell *shell);
bool boxer_executeNextPendingCommandForShell(DOS_Shell *shell);
bool boxer_shellShouldDisplayStartupMessages(DOS_Shell *shell);
void boxer_shellWillExecuteFileAtDOSPath(DOS_Shell *shell, const char *canonicalPath, const char *arguments);
void boxer_shellDidExecuteFileAtDOSPath(DOS_Shell *shell, const char *canonicalPath);
void boxer_shellWillBeginBatchFile(DOS_Shell *shell, const char *canonicalPath, const char *arguments);
void boxer_shellDidEndBatchFile(DOS_Shell *shell, const char *canonicalPath);
bool boxer_shellShouldContinue(DOS_Shell *shell);
void boxer_setMouseActive(bool mouseActive);
void boxer_mouseMovedToPoint(float x, float y);
bool boxer_isMouseCaptured();
#else
// Built standalone in dosbox-staging Meson/Ninja CI without Boxer: provide inline dummy stubs
inline void boxer_shellWillStart(DOS_Shell *) {}
inline void boxer_shellDidFinish(DOS_Shell *) {}
inline void boxer_shellWillStartAutoexec(DOS_Shell *) {}
inline void boxer_didReturnToShell(DOS_Shell *) {}
inline bool boxer_shellShouldRunCommand(DOS_Shell *, char*, char*) { return true; }
inline void boxer_shellWillReadCommandInputFromHandle(DOS_Shell *, Bit16u) {}
inline void boxer_shellDidReadCommandInputFromHandle(DOS_Shell *, Bit16u) {}
inline bool boxer_handleShellCommandInput(DOS_Shell *, char *, Bitu *, bool *) { return false; }
inline bool boxer_hasPendingCommandsForShell(DOS_Shell *) { return false; }
inline bool boxer_executeNextPendingCommandForShell(DOS_Shell *) { return false; }
inline bool boxer_shellShouldDisplayStartupMessages(DOS_Shell *) { return false; }
inline void boxer_shellWillExecuteFileAtDOSPath(DOS_Shell *, const char *, const char *) {}
inline void boxer_shellDidExecuteFileAtDOSPath(DOS_Shell *, const char *) {}
inline void boxer_shellWillBeginBatchFile(DOS_Shell *, const char *, const char *) {}
inline void boxer_shellDidEndBatchFile(DOS_Shell *, const char *) {}
inline bool boxer_shellShouldContinue(DOS_Shell *) { return true; }
inline void boxer_setMouseActive(bool) {}
inline void boxer_mouseMovedToPoint(float, float) {}
inline bool boxer_isMouseCaptured() { return false; }
#endif

#ifdef __cplusplus
}
#endif

#endif // BOXER_STAGING_BXCOALFACE_H
