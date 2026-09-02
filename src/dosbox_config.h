/*
 * Xcode direct-build configuration for Boxer.
 *
 * DOSBox Staging normally generates this file with Meson. Boxer embeds the
 * DOSBox core directly in its Xcode target, so keep this aligned with the
 * macOS arm64 configuration used by the app.
 */

#ifndef DOSBOX_DOSBOX_CONFIG_H
#define DOSBOX_DOSBOX_CONFIG_H

#define DOSBOX_VERSION "0.83.0"
#define DOSBOX_VERSION_SHORT "0.83"
#define BUILD_GIT_HASH "boxer-v0.83.0"

#if defined(__APPLE__)
#define MACOSX 1
#endif

#if defined(__aarch64__) || defined(__arm64__)
#define C_TARGETCPU ARMV8LE
#define C_TARGET_CPU_ARM 1
#define C_TARGET_CPU_X86 0
#define C_DYNREC 1
#define C_DYNAMIC_X86 0
#elif defined(__x86_64__) || defined(_M_X64)
#define C_TARGETCPU X86_64
#define C_TARGET_CPU_ARM 0
#define C_TARGET_CPU_X86 1
#define C_DYNREC 0
#define C_DYNAMIC_X86 1
#endif
#define C_UNALIGNED_MEMORY 1
#define C_PER_PAGE_W_OR_X 1
#define C_FPU 1
#define C_CORE_INLINE 1

#define C_OPENGL 0
#define C_DEBUGGER 0
#define C_HEAVY_DEBUGGER 0
#define C_MT32EMU 0
#define C_MANYMOUSE 0
#define SUPPORT_XINPUT2 0
#define C_OPUS 0
#define C_FLUIDSYNTH 0
#define C_SHOWPIC 0

#if defined(__APPLE__)
#define C_COREAUDIO 1
#define C_COREMIDI 1
#define C_COREFOUNDATION 1
#define C_CORESERVICES 1

#define HAVE_CLOCK_GETTIME 1
#define HAVE_BUILTIN_AVAILABLE 1
#define HAVE_BUILTIN_CLEAR_CACHE 1
#define HAVE_MPROTECT 1
#define HAVE_MMAP 1
#define HAVE_MAP_JIT 1
#define HAVE_PTHREAD_WRITE_PROTECT_NP 1
#define HAVE_SYS_ICACHE_INVALIDATE 1
#define HAVE_PTHREAD_SETNAME_NP 1
#define HAVE_SETPRIORITY 1
#define HAVE_STRNLEN 1
#define HAVE_STRUCT_DIRENT_D_TYPE 1

#define HAVE_LIBGEN_H 1
#define HAVE_NETINET_IN_H 1
#define HAVE_STRINGS_H 1
#define HAVE_SYS_SOCKET_H 1
#define HAVE_SYS_TYPES_H 1
#define HAVE_SYS_XATTR_H 1
#endif

#define HAVE_STDLIB_H 1

#define CUSTOM_DATADIR ""

#endif // DOSBOX_DOSBOX_CONFIG_H
